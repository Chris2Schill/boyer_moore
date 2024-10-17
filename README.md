
# Boyer Moore String Search Algorithm

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
git clone https://github.com/Chris2Schill/shared_mem.git
cd shared_mem
./build.sh
```
