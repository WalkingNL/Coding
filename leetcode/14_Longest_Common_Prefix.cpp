#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if (strs.size() == 0) {
            return "";
        }

        string prefix = strs[0];

        for (int i=1; i<strs.size(); i++) {
            int j = 0;
            for (; j<prefix.size() && j<strs[i].size(); j++) {
                if (prefix[j] != strs[i][j]) {
                    break;
                }
            }
            prefix = prefix.substr(0, j);
        }

        return prefix;
    }
};

int main(int argc, char* argv[]) {

    Solution s;

    vector<string> strs = {"flower","flow","flight"};
    // vector<string> strs = {"dog","racecar","car"};

    cout << s.longestCommonPrefix(strs) << endl;

    return 0;
}
