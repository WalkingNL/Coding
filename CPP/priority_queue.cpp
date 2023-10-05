#include <iostream>
#include <queue>
#include <map>
#include <set>
using namespace std;

int main(int argc, char* argv[]) {

    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(4);
    pq.push(5);

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    map<int, int, greater<int>> m;
    m.insert({1, 1});
    m.insert({2, 2});
    m.insert({3, 3});
    m.insert({4, 4});
    m.insert({5, 5});

    for (auto it = m.begin(); it != m.end(); it++) {
        if (it++ == m.end())
            cout << "(" << it->first << ", " << it->second << ")";
        else
            cout << "(" << it->first << ", " << it->second << "),";
    }
    cout << endl;

    set<int, greater<int>> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);

    for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
