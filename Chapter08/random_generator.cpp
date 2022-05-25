#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <iomanip>
#include <limits>
#include <cstdio>
#include <algorithm>

using namespace std;

template <typename RD>
void histogram(size_t partitions, size_t samples)
{
    using rand_t = typename RD::result_type; 
    partitions = max<size_t>(partitions, 10);

    RD rd;
    rand_t div((double(RD::max()) + 1) / partitions);

    vector<size_t> v (partitions);
    for (size_t i {0}; i < samples; ++i){
        ++v[rd()/div];
    }

    rand_t max_elm (*max_element(begin(v), end(v)));
    rand_t max_div (max(max_elm/100, rand_t(1)));

    for(size_t i {0}; i < partitions; ++i){
        cout << setw(2) << i << ": "
             << string(v[i]/max_div, '*') << endl;
    }
}

int main(int argc, char **argv)
{
    if(argc != 3){
        cout << "Usage: " << argv[0]
             << " <partitins> <samples>\n";
        return 1;
    }

    size_t partitions {stoull(argv[1])};
    size_t samples    {stoull(argv[2])};

    cout << "random_device" << endl;
    histogram<random_device>(partitions, samples);
    
    cout << "ndeafult_random_engine" << endl;
    histogram<default_random_engine>(partitions, samples);

    cout << "nminstd_rand0" << endl;
    histogram<minstd_rand0>(partitions, samples);

    cout << "nminstd_rand" << endl;
    histogram<minstd_rand>(partitions, samples);
    
    cout << "nmt19937" << endl;
    histogram<mt19937>(partitions, samples);
    
    cout << "nmt19937_64" << endl;
    histogram<mt19937_64>(partitions, samples);
    
    cout << "nranlux24_base" << endl;
    histogram<ranlux24_base>(partitions, samples);

    cout << "nranlux48_base" << endl;
    histogram<ranlux48_base>(partitions, samples);    

    cout << "nranlux24" << endl;
    histogram<ranlux24>(partitions, samples);

    cout << "nranlux48" << endl;
    histogram<ranlux48>(partitions, samples); 
    
    cout << "nknuth_b" << endl;
    histogram<knuth_b>(partitions, samples); 
}