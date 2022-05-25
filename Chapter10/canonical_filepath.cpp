#include <iostream>
#include <filesystem>

using namespace std;
using namespace filesystem;

int main()
{
    path p {"C:/Users/v_martsinyshen/Documents/debug.log"};
    path cp {current_path()};
    cout << "curent_path        : " << current_path()
         << "\ncurent_path in wrapper absolute_path : " << absolute(cp)
         << "\nabsolute_path    : " << absolute(p)
         << "\nsystem_complete  : " 
         << "\ncanonocal(p)     : " << canonical(p) << '\n';

    cout << absolute( path {L"C:\\Users\\v_martsinyshen\\Documents"} / "debug.log") << '\n';

    // cout << "canonocal testdirt : "
    //      << canonical("debug.log", 
    //                     current_path() / "C:/Users/v_martsinyshen/Documents")
    //      << "\ncanonocal testdir 2 : "
    //      << canonical(p, current_path() / "C:/Users/v_martsinyshen/Documents/..")
    //      << '\n';

    cout << "equivalence: "
         << equivalent("C:/Users/v_martsinyshen/Documents/debug.log", "C:/Users/v_martsinyshen/../Documents/debug.log")
         << '\n';
}