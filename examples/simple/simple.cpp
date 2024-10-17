#include <boyer_moore/boyer_moore.h>

#include <spdlog/spdlog.h>

/* Driver code */
int main()
{
    boyer_moore::Searchspace searchspace = boyer_moore::Searchspace::from_file("searchspace.txt");
    boyer_moore::Pattern pattern("BOYER_MOORE");

    auto results = searchspace.search(pattern);
    for (const auto& res : results) {
        spdlog::info("{}", res.to_string());
    }

    getchar();
    return 0;
} 
