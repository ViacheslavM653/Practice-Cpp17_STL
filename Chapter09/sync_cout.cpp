#include <iostream>
#include <thread>
#include <mutex>
#include <sstream>
#include <vector>

using namespace std;

struct pcout : public stringstream{
    static inline mutex cout_mutex;
    ~pcout(){
        lock_guard<mutex> l {cout_mutex};
        cout << rdbuf();
        cout.flush();
    }
};

static void print_cout(int id)
{
    cout << "cout hello from " << id << '\n';
    for(int i {0}; i < 5; i++){
        for(int a {0}; a < 10; a++){
            cout << "@";
        }
        cout << '\n';
    }
}
static void print_pcout(int id)
{
    static mutex cout_mutex;
    lock_guard<mutex> l {cout_mutex};
    cout <<"pcout hello from " << id << '\n';
     for(int i {0}; i < 5; i++){
        for(int a {0}; a < 10; a++){
            cout << "#";
        }
        cout << '\n';
    }
}

int main()
{
    vector<thread> v;
    for (size_t i {0}; i < 4; ++i){
        v.emplace_back(print_cout, i);
    }
    for (auto &t : v){
        t.join();
    }

    cout << "===========================\n";
    v.clear();
    for(size_t i {0}; i < 4; ++i){
        v.emplace_back(print_pcout, i);
    }
    for (auto &t : v){
        t.join();
    }
}