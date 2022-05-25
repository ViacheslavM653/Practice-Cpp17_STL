#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <functional>

using namespace std;



template <typename Itr>
static void print(Itr it, size_t chars)
{
    copy_n(it, chars, ostream_iterator<char>{cout});
    cout << '\n';
}

int main()
{
    const string long_srting {
        "Lorem ipsum dolor sit amet, consetetur"
        " sadipscing elitr, sed diam nonumy eirmod"};
    const string needle {"elitr"};

    {
        auto match (search(begin(long_srting), end(long_srting), 
                           begin(needle), end(needle)));
        print(match, 5);
    }

    {
        auto match (search(begin(long_srting), end(long_srting),
                            default_searcher(begin(needle), end(needle))));
        print(match, 5);
    }

    {
        auto match ((begin(long_srting), end(long_srting), 
                    boyer_moore_searcher(begin(needle), end(needle))));
        print(match, 5);

    }

    {
        auto match ((begin(long_srting), end(long_srting), 
                    boyer_moore_horspool_searcher(begin(needle), end(needle))));
        print(match, 5);

    }
}
