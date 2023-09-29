#include <map>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {

    multimap<char, int> mm;
    mm.insert({'b',1});
    mm.insert({'b',2});
    mm.insert({'c',1});

    auto ref = mm.find('b');
    cout << ref->first << " " << ref->second << endl;

    cout << mm.count('b') << endl;
    // cout << mm['b'] << endl;

    for (auto it = mm.begin(); it != mm.end(); ++it) {
        cout << it->first << " " << it->second << " ";
    }
    cout << endl;

    auto range = mm.equal_range('b');
    for (auto it = range.first; it != range.second; ++it) {
        cout << it->first << " " << it->second << endl;
    }


    return 0;
}