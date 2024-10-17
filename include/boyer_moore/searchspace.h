#pragma once

#include <string>
#include <vector>

namespace boyer_moore {

class Pattern;

struct SearchResult {
    int row;
    int col;

    std::string to_string() const;
};

class Searchspace {
public:
    Searchspace(const std::string& searchspace);
    static Searchspace from_file(const std::string& filepath);

    /* A pattern searching function that uses Bad
       Character Heuristic of Boyer Moore Algorithm */
    std::vector<SearchResult> search(Pattern& pattern);

    std::size_t size() const { return searchspace.size(); }
    const std::string& string() const { return searchspace; }

private:
    void line_search(const std::string& line, const Pattern& pattern, int row, std::vector<SearchResult>& results);

    std::string searchspace;
};

}
