#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    vector<int> dp(10, -1);

    vector<int> vec;

    cout << "initial size: " << vec.size() << endl;
    cout << "initial capacity: " << vec.capacity() << endl;

    vec.push_back(100);
    cout << "first size: " << vec.size() << endl;
    cout << "first capacity: " << vec.capacity() << endl;
    
    vec.push_back(200);
    cout << "second size: " << vec.size() << endl;
    cout << "second capacity: " << vec.capacity() << endl;

    vec.push_back(300);
    cout << "third size: " << vec.size() << endl;
    cout << "third capacity: " << vec.capacity() << endl;

    vec.push_back(400);
    cout << "forth size: " << vec.size() << endl;
    cout << "forth capacity: " << vec.capacity() << endl;

    vec.push_back(500);
    cout << "forth size: " << vec.size() << endl;
    cout << "forth capacity: " << vec.capacity() << endl;

    cout << "len = " << dp.size() << endl;
    for (auto a : dp) {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}