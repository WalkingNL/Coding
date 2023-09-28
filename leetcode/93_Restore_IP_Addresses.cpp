#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        std::vector<std::string> result;
        std::string current;
        backtrack(s, 0, 0, current, result);
        return result;
    }
    // 25525511135
    void backtrack(const std::string& s, int start, int segment, std::string& current, std::vector<std::string>& result) {
        if (start == s.size() && segment == 4) {
            result.push_back(current.substr(0, current.size()-1)); // remove the trailing dot and add to results
            return;
        }
        if (start == s.size() || segment == 4) return; // base cases
        for (int len = 1; len <= 3 && start + len <= s.size(); ++len) {
            if (s.size() - start - len > 3 * (4 - segment - 1)) continue; // pruning
            std::string snapshot = s.substr(start, len);
            if ((snapshot.size() > 1 && snapshot[0] == '0') || // leading zero
                (snapshot.size() == 3 && snapshot > "255")) continue; // out of valid range
            current += snapshot + ".";
            cout << current << endl;
            // return;
            backtrack(s, start+len, segment+1, current, result);
            current.erase(current.size()-len-1, len+1); // backtrack
            cout << current << endl;
        }
    }
};

int main() {
    Solution sol;
    std::string s = "25525511135";
    std::vector<std::string> result = sol.restoreIpAddresses(s);
    for (const std::string &ip : result) {
        std::cout << ip << std::endl;
    }
    return 0;
}
