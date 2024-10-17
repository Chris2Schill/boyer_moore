#include <boyer_moore/searchspace.h>
#include <boyer_moore/pattern.h>

#include <fstream>
#include <sstream>
#include <spdlog/spdlog.h>

namespace boyer_moore {

std::string SearchResult::to_string() const {
    std::stringstream ss;
    ss << "SearchResult{ .row = " << row << ", .col = " << col << " }";
    return ss.str();
}

std::vector<SearchResult> Searchspace::search(Pattern& pattern) {
    pattern.preprocess();

    std::vector<SearchResult> results;
    std::string line;
    std::istringstream input(searchspace);
    int row = 0;
    while (std::getline(input, line, '\n')) {
        line_search(line, pattern, row, results);
        row++;
    }

    return results;
}

void Searchspace::line_search(const std::string& line, const Pattern& pattern, int row, std::vector<SearchResult>& results) {
    int m = pattern.size();
    int n = line.size();

    const int (&badchar)[NO_OF_CHARS] = pattern.badchar;

    int s = 0; // s is the shift of the pattern with
               // respect to text
    while (s <= (n - m))
    {
        int j = m - 1;

        /* Keep reducing index j of the pattern while
           characters of the pattern and text are
           matching at this shift s */
        while (j >= 0 && pattern[j] == line[s + j])
            j--;

        /* If the pattern is present at the current
           shift, then index j will become -1 after
           the above loop */
        if (j < 0)
        {
            results.emplace_back(SearchResult{.row = row, .col = s});

            /* Shift the pattern so that the next
               character in the text aligns with the last
               occurrence of it in the pattern.
               The condition s+m < n is necessary for
               the case when the pattern occurs at the end
               of the text */
            s += (s + m < n) ? m - badchar[line[s + m]] : 1;
        }
        else
        {
            /* Shift the pattern so that the bad character
               in the text aligns with the last occurrence of
               it in the pattern. The max function is used to
               make sure that we get a positive shift.
               We may get a negative shift if the last
               occurrence of the bad character in the pattern
               is on the right side of the current
               character. */
            s += std::max(1, j - badchar[line[s + j]]);
        }
    }
}

Searchspace::Searchspace(const std::string& searchspace) : searchspace(searchspace)
{
}

Searchspace Searchspace::from_file(const std::string& filepath) {
    std::ifstream ifs(filepath);
    return std::string(std::istreambuf_iterator<char>{ifs}, {});
}

} // end namespace boyer_moore
