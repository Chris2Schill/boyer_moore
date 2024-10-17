
# Boyer Moore String Search Algorithm

## Search a string
```C++
#include <boyer_moore/boyer_moore.h>

boyer_moore::Searchspace searchspace("ABCZZCBA");
boyer_moore::Pattern pattern("ZZ");

auto results = searchspace.search(pattern);
for (const auto& res : results) {
    int row = res.row; // 0
    int col = res.col; // 3
}
```

## Search a file
```C++
#include <boyer_moore/boyer_moore.h>

boyer_moore::Searchspace searchspace = boyer_moore::Searchspace::from_file("searchspace.txt");
boyer_moore::Pattern pattern("BOYER_MOORE");

auto results = searchspace.search(pattern);
for (const auto& res : results) {
    int row = res.row;
    int col = res.col;
}
```

## How to Build
```bash
git clone https://github.com/Chris2Schill/boyer_moore.git
cd boyer_moore
./build.sh
```
