#include <iostream>
#include <map>
using namespace std;

int main(int argc, char* argv[]) {

    map<int,int> m1 = {{1,2}};
    map<int,int> m2 = {{1,2}};
    map<int,int> m3 = {{1,3}};
    map<map<int,int>,int> m;
    m[m1] = 1;
    m[m2] = 2;
    m[m3] = 3;

    cout << m.size() << endl;

    if (m1 == m2) {
        cout << "m1 == m2" << endl;
    } else {
        cout << "m1 != m2" << endl;
    }

    for (auto iter=m.begin(); iter != m.end(); iter++) {
        for (auto iter2=iter->first.begin(); iter2 != iter->first.end(); iter2++) {
            cout << iter2->first << " : " << iter2->second << endl;
        }
    }

    return 0;
}
