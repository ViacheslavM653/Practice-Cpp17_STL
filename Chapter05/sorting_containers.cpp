#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <random>

using namespace std;

static void print(const vector<int> &v)
{
    copy(begin(v), end(v), ostream_iterator<int>{cout, ", "});
    cout << '\n';
}

int main()
{
    vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    random_device rd;
    mt19937 g {rd()};

    cout << "Vevtor v is_sorted: " << is_sorted(begin(v), end(v)) << ". \n";

    shuffle(begin(v), end(v), g);

    cout << "Vevtor v is_sorted: " << is_sorted(begin(v), end(v)) << ". \n";
    print(v);

    shuffle(begin(v), end(v), g);
    partition(begin(v), end(v), [] (int i) { return i < 5; });
    print(v);

    shuffle(begin(v), end(v), g);
    auto midle (next(begin(v), int(v.size() / 2)));
    partial_sort(begin(v), midle, end(v));
    print(v);

    struct mystruct
    {
        int a;
        int b;
    };
    
    vector<mystruct> mv { {5, 100}, {1, 50}, {-123, 1000}, 
                        {3, 70}, {-10, 20}};

    sort(begin(mv), end(mv), [] (const mystruct &lhs, const mystruct &rhs) 
                    {
                        return lhs.b < rhs.b;
                    });

    for (const auto &[a, b] : mv) {
        cout << "{" << a << ", " << b << "} ";
    }    
    cout << '\n';

}