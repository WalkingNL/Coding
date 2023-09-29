#include <iostream>
#include <string>
#include <map>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {

        if (s.size() <= 1 || (s.size() % 2 != 0))
            return false;

        map<char, char> m{ {'(', ')'}, 
                            {'[', ']'},
                            {'{', '}'}
                        };

        stack<char> s_tmp;
        s_tmp.push(s[0]);

        char top_element = s_tmp.top();
        // map<char, char>::iterator iter = m.find(top_element);
        // (){}}{
        // ()[]{}
        for (int i = 1; i < s.size(); i++) {
            // cout << top_element << " : " << m.find(top_element)->second << " : " << s[i] << endl;
            if (m.find(top_element)->second == s[i]) {
                // cout << top_element << " : " << s[i] << endl;
                s_tmp.pop();
                if (!s_tmp.empty()) {
                    top_element = s_tmp.top(); 
                    continue; 
                }

                if ((i+1) < s.size()) {
                    s_tmp.push(s[++i]);
                    top_element = s_tmp.top();
                }

            } else {
                if (m.find(s[i]) == m.end())
                    return false;
                s_tmp.push(s[i]);
                top_element = s[i];
            }
        }

        if (s_tmp.empty()) 
            return true;
        else
            return false;
    }
};

int main(int argc, char* argv[]) {

    map<char, char> m{ {'(', ')'}, 
                            {'[', ']'},
                            {'{', '}'}
                        };

    // cout << "size: " << m.size() << "\t" << m['('] << "\t" << m['*'] << endl;

    // map<char, char>::iterator x = m.find('*');
    // if (x == m.end()) {
    //     cout << "not found" << endl;
    // }

    // string s = "(){}[]";
    string s = "(){}}{";

    Solution sol;
    if(sol.isValid(s))
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    // cout << "size = " << m.size() << "\t" << "x = " << x << endl;

    return 0;
}
