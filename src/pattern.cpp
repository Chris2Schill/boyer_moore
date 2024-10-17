#include <boyer_moore/pattern.h>

namespace boyer_moore {

// The preprocessing function for Boyer Moore's
// bad character heuristic
void bad_char_heuristic(const std::string& str, int size, int badchar[NO_OF_CHARS])
{
    // Initialize all occurrences as -1
    for (int i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;

    // Fill the actual value of last occurrence
    // of a character
    for (int i = 0; i < size; i++)
        badchar[(int)str[i]] = i;
}

Pattern::Pattern(const std::string& pat) :pattern(pat) {
}

void Pattern::preprocess() {
    if (!preprocessed) {
        /* Fill the bad character array by calling
           the preprocessing function bad_char_heuristic()
           for the given pattern */
        bad_char_heuristic(pattern, pattern.size(), badchar);
        preprocessed = true;
    }
}



}
