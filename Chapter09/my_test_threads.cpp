#include <iostream>
#include <thread>
#include <vector>
#include <thread>
#include <random>
#include <algorithm>
#include <execution>
#include <mutex>

using namespace std;
using namespace chrono_literals;

// vector<mutex> mutx_vect;
mutex mx1;

static bool odd(int n){
    return n % 2;
}

long long doFunc(long long a,  long long b)
{
    // //scoped_lock{mx1};

    return (a + b);
    // vector<int> d (5000);
    // mt19937 gen;
    // uniform_int_distribution<int> dis(0, 100000);
    // auto rand_num ([=]() mutable { return dis(gen); });
    // generate( begin(d), end(d), rand_num);
    // sort(begin(d), end(d));
    // reverse(begin(d), end(d));
    // auto odds(count_if(begin(d), end(d), odd));
        
    // return (100.0 * odds / d.size());
    // // cout << (100.0 * odds / d.size())
    //      << "% of the numbers are odd.\n";

    // cout << "Start doFunc: ------------" << '\n';
    // this_thread::sleep_for(2000ms);
    // cout << "End doFunct: -------------" << '\n';
}
 



int main() 
{
    int t_c {4}; // numbers of threads
    int cnt {3};// number of tasks
    int m = t_c - 1;//id for mutexs

    // for( int i {0}; i <t_c ; i++){
    //     mutex mx;

    //     mutx_vect.push_back(mx);
    // }

    long long rezult = doFunc(4434835453453544353, 5545453434556477756); 
    cout << rezult << endl;


    for(int i {0}; i < cnt; i = i+t_c){
        cout << i << '\n';
        int b = i + t_c;
        if((cnt - b)>=0){
            for(int a{i}; a < b; a++, m--){
                cout << "instal - "<< a << " mtx " << m <<endl; 
                // long long rezult = doFunc(4434835453453544353, 5545453434556477756); 
                // cout << rezult << endl;
                // thread t1 {doFunc};  
                // t1.join();
            }
        }else{
            
            for(int a{i}; a < cnt; a++, m--){
                cout << "instal - "<< a << " mtx " << m <<endl;   
        }
        
        }
        m =t_c -1;
        
    }
    return 0;

}