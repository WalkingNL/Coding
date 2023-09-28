#include <iostream>
#include <vector>
using namespace std;

bool compare(string a, string b) {
    if (a.size() <= b.size()) {
        return false;
    }
    return true;
}

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        for (int i=0; i<wordDict.size(); i++) {

            // exclude the word which is longer than s 
            if (s.size() < wordDict[i].size()) {
                continue;
            }

            // s.size() == wordDict[i].size()
            if (s.size() == wordDict[i].size()) {
                if (s == wordDict[i]) {
                    return true;
                }
                continue;
            }

            // wordDict[i] is not a substring of s
            if (s.find(wordDict[i]) == string::npos) {
                continue;
            }

            string str = wordDict[i];
            
            // only one word in wordDict[i]
            while (s.find(str) != string::npos && str != s) {
                str += wordDict[i];
            }
            if (str == s) {
                return true;
            }

            str = wordDict[i];
            // int key = 0;

            // catsandogcat
            // "cats","dog","sand","and","cat","an"

            // applepenapple
            // "apple", "pen"
            for (int j=i+1; j<wordDict.size(); ) {
                // exclude the word which is longer than s
                if ((s.size() - str.size()) < wordDict[j].size()) {
                    j++;
                    continue;
                }
                // wordDict[j] is not a substring of s
                if (s.find(wordDict[j]) == string::npos) {
                    j++;
                    continue;
                }
                // wordDict[i] + wordDict[j] == s
                if (str + wordDict[j] == s || wordDict[j] + str == s) {
                    return true;
                }
                // s.find(str + wordDict[j]) != string::npos || s.find(wordDict[j] + str) != string::npos
                while (s.find(str + wordDict[j]) != string::npos && str != s) {
                    str += wordDict[j];
                    // key = j;
                }
                while (s.find(wordDict[j] + str) != string::npos && str != s) {
                    str = wordDict[j] + str;
                    // key = j;
                }

                if (str == s) {
                    return true;
                }

                if (str != wordDict[i]) {
                    if (j > i+1) {
                        j = i+1;
                    } else {
                        j++;
                    }
                    continue;
                }
                j++;
            }
            
            while (s.find(str + wordDict[i]) != string::npos && str != s) {
                str += wordDict[i];
            }

            while (s.find(wordDict[i] + str) != string::npos && str != s) {
                str = wordDict[i] + str;
            }

            if (str == s) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    // vector<string> vec = {"abcd", "eft", "hijklmn", "csa", "xyza"};

    // vector<string> vec = {"a", "abc", "b", "cd"};
    // vector<string> vec = {"pen","apple"};
    // vector<string> vec = {"bc","cb"};
    // vector<string> vec = {"cc","bb","aa","bc","ac","ca","ba","cb"};
    vector<string> vec = {"bc","ca"};

    // string s = "abcd";
    // string s = "applepenapple";
    // string s = "ccbb";
    // string s = "ccacccbcab";
    string s = "cbca";

    Solution sol;
    cout << sol.wordBreak(s, vec) << endl;

    // sort(vec.begin(), vec.end(), compare);

    return 0;
}