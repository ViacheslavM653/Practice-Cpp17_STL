#include <iostream>
#include <fstream>
#include <system_error>
#include <cstring>

using namespace std;

int main()
{
    ifstream f;
    f.exceptions(f.failbit | f.badbit);

    try{
        f.open("non_existant.txt");
        int i;
        f >> i ;
        cout << "integer has value: " << i << '\n';
    }
    catch(ios_base::failure& e){
        cerr << "Caugth error: ";
        if (errno){
            cerr <<  strerror(errno) << '\n';
        }else{
            cerr << e.what() << '\n';
        }
    }
}