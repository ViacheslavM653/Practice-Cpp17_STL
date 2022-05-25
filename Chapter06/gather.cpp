#include <iostream>
#include <algorithm>
#include <string>
#include <functional>

using namespace std;

template <typename It, typename F>
pair<It, It> gather(It first, It last, It gather_pos, F predicate)
{
    return {stable_partition(first, gather_pos, not_fn(predicate)),
           stable_partition(gather_pos, last, predicate)};
}

template <typename It, typename F>
void gather_sort(It first, It last, It gather_pos, F comp_func){
    auto inv_comp_func ([&](const auto & ...p){
        return !comp_func(p...);
    });
    stable_sort(first, gather_pos, inv_comp_func);
    stable_sort(gather_pos, last, comp_func);
}

int main()
{
    auto is_a ([](char c){return c == 'a'; });
    string a {"a_a_a_a_a_a_a_a_a_a_a_a_a"};

    auto midle(begin(a) + a.size() / 2);

    gather(begin(a), end(a), midle, is_a );
    cout << a <<'\n';

    gather(begin(a), end(a), begin(a), is_a);
    cout << a << '\n';

    gather(begin(a), end(a), end(a), is_a);
    cout << a << '\n';

    string b {"_9_2_4_7_3_8_1_6_5_0_"};
    gather_sort(begin(b), end(b), begin(b) + b.size() / 2, less<char>{});
    cout << b << '\n';
}