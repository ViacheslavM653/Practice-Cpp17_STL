#include <iostream>
#include <complex>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <valarray>
#include <cmath>

using namespace std;

using cmplx = complex<double>;
using csignal = vector<cmplx>;

class num_iterator{
    size_t i;
public:
    explicit num_iterator(size_t position)
    : i{position}
    {}
    size_t operator*() const {
        return i;
    }
    num_iterator& operator++(){
        ++i;
        return *this;
    }

    bool operator!=( const num_iterator &other) const {
        return i != other.i;
    }

};

csignal fourier_transform(const  csignal &s, bool back = false) {
    csignal t(s.size());
    const double pol {2.0 * M_1_PI * (back ? -1.0 : 1.0)};
    const double div {back ? 1.0 : double(s.size())};

    auto sum_up([=, &s](size_t j){
        return [=, &s] (cmplx c, size_t k) {
            return c + s[k] * polar(1.0, pol * k * j / double (s.size()));
        };
    });
    auto to_ft([=, &s](size_t j){
        return accumulate(num_iterator{0}, num_iterator{s.size()}, cmplx{}, sum_up(j))/div;
    });

    transform(num_iterator{0} ,num_iterator{s.size()}, begin(t), to_ft);
    return t;

}