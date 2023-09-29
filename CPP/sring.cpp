#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {

    string str = "hello world";

    cout << "before: " << str << endl;
    str.erase(str.begin() + 5);

    cout << "after: " << str << endl;

    return 0;
}