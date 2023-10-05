#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (edges.size() <= 0) {
            if (source == 0 && destination == 0) return true;
        }
        int i = 0;
        set<int> s_cache;
        stack<vector<int>> stk;
        unordered_map<int,int> u_cache;
        // stk.push({-1,source});
        while (true) {
            while (i < edges.size()) {
                if (u_cache.find(i) != u_cache.end()) {
                    i += 1;
                    continue;
                }
                if (!stk.empty()) {
                    source = stk.top()[1];
                }
                if ((edges[i][0] == source && edges[i][1] == destination) || (edges[i][1] == source && edges[i][0] == destination)) {
                    return true;
                }
                if (edges[i][0] == stk.top()[1] || edges[i][1] == stk.top()[1]) {

                    if (edges[i][0] == stk.top()[1]) {
                        source = edges[i][1];
                    } else {
                        source = edges[i][0];
                    }
                    // cout << i << " : " << source << endl;
                    if (s_cache.find(source) != s_cache.end()) {
                        u_cache.insert({i,source});
                        i += 1;
                        continue;
                    }
                    cout << i << " : " << source << endl;
                    vector<int> vec = {i,source};
                    stk.push(vec);
                    s_cache.insert(source);
                    u_cache.insert({i,source});
                    i = 0;
                    continue;
                }
                
                i += 1;
            }
            if (i >= edges.size()) {
                if (!stk.empty()) stk.pop();
            }
            if (stk.empty()) {
                cout << "empty" << endl;
                break;
            } else {
                i = stk.top()[0];
                cout << "i = " << i << endl;
            }
        }
        
        return false;
    }
};

int main(int argc, char* argv[]) {
    

    return 0;
}
