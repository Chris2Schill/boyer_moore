#pragma once

#include <string>

namespace boyer_moore {

static const std::size_t NO_OF_CHARS = 256;

class Pattern {
public:
    using value_type = char;

    Pattern(const std::string& str);

    void preprocess();
    std::size_t size() const { return pattern.size(); }

    const value_type& operator[](std::size_t idx) const {
        return pattern[idx];
    }

private:
    friend class Searchspace;

    value_type& operator[](std::size_t idx) {
        return const_cast<std::string::value_type&>(const_cast<const Pattern*>(this)->operator[](idx));
    }

    std::string pattern;
    int badchar[NO_OF_CHARS];
    bool preprocessed = false;
};

}
