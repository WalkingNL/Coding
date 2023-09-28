#include <iostream>
#include <string>
using namespace std;

bool isChar(char ch) {
    if ((ch>=48 && ch<=57) || (ch>=65 && ch<=90) || (ch>=97 && ch<=122)) {
        return true;
    }
    return false;
}

class Solution {
public:
    bool isPalindrome(string s) {
        int low = 0;
        int high = s.size() - 1;

        while (low <= high) {

            cout << "low = " << low << ", high = " << high << endl;
            if (low == high) {
                return true;
            }

            if (!isChar(s[low])) {
                low++;
                continue;
            }
            if (!isChar(s[high])) {
                high--;
                continue;
            }

            if (tolower(s[low]) == tolower(s[high])) {
                low++;
                high--;
            } else {
                return false;
            }
        }
        if (low >= high) {
            return true;
        }

        return false;
    }
};

int main(int argc, char* argv[]) {

    Solution sol;



    // string s = "A man, a plan, a canal: Panama";
    // string s = "race a car";
    string s = "ab_ca";
    char ch = 'a';

    if(sol.isPalindrome(s)) {
        cout << "is palindrome" << endl;
    } else {
        cout << "is not palindrome" << ", ch: " << int(ch) << endl;
    }

    return 0;
}
