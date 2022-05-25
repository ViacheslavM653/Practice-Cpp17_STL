#include <iostream>
#include <filesystem>

using namespace std;
using namespace filesystem;

int main(int argc, char *argv[])
{
    if(argc != 2){
        cout << "Usage: " << argv[0] << " <path>\n";
        return 1;
    }
    const path dir {argv[1]};
    if(!exists(dir)){
        cout << "Path " << dir << " does not exist.\n";
        return 1;
    }
    cout << canonical(dir).string() << '\n';
}