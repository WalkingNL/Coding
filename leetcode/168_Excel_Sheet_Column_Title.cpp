#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        vector<int> t_char = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        string str;

        int div = columnNumber--;
        int mod = 0;

        // cout << "out: " << mod << " " << div << endl;
        stack<int> s;
        while (div/26 >= 0) {
            mod = div % 26;
            cout << div << " " << mod << endl;
            if (div < 26) {
                str.push_back(t_char[div-1]);
                if (s.empty() && columnNumber>26) {
                    str.push_back(t_char[mod-1]);
                } else {
                    while (!s.empty()) {
                        str.push_back(t_char[s.top()-1]);
                        s.pop();
                    }
                }
                break;
            }
            if (mod == 0) {
                mod = 26;
                if (div/26 == 26) {
                    div = 26;
                    s.push(mod);
                    continue;
                } else if (div/26 < 26){
                    div /= 26;
                    div -= 1;
                    s.push(mod);
                    continue;
                }
            }
            s.push(mod);
            div /= 26;
        }

        return str;
        
    }
};

int main() {
    Solution s;
    int columnNumber = 26*26*26;
    // int columnNumber = 943566;
    // int columnNumber = 701;
    string str = s.convertToTitle(columnNumber);
    cout << str << endl;

    return 0;
}
