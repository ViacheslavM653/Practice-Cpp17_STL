#include <iostream>
#include <memory>

using namespace std;

class Foo
{
public:
    string name;
    Foo(string n)
        : name{move(n)}
    { cout << "CTOR " << name << endl;}
    
    ~Foo(){
        cout << "DTOR " << name << endl;
    }
};

void f(shared_ptr<Foo> sp)
{
    cout << "f: use counter at " << sp.use_count() << endl;
}

int main()
{
    shared_ptr<Foo> fa;

    {
        cout << "Inner scope begin\n";
        shared_ptr<Foo> f1 {new Foo{"foo"}};
        auto            f2 (make_shared<Foo>("bar"));
        cout << "f1's use counter at " << f1.use_count() << endl;
        fa = f1;
        cout << "f1's use counter at " << f1.use_count() << endl;
    }
    cout << "Back to outer scope\n";
    cout << fa.use_count() << endl;

    cout << "first f() call\n";
    f(fa);
    cout << "second f() call\n";
    f(move(fa));
    cout << "end of main()\n";
}