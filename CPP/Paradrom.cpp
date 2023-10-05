#include <iostream>
#include <string>
#include <cassert>
using namespace std;
class Solution {
public:
    string shortestPalindrome(string s) {

        if (s.size() <= 1)
            return s;
        int high = s.size() - 1;
        int i, j;
        int count = 0;
        bool b = true;
        for (i = 1; i <= high; i++)
        {
            if (b || s[0] == s[i])
            {
                count++;
            }
            else
            {
                b = false;
            }
        }
        int tmp_count = count;
        int flag = 0;
        for (i = s.size() - 1; i >= 0; )
        {
            if (s[0] == s[i])
            {
                count--;
                continue;
            }
            if (count > 0)
            {
                i--;
                flag = i;
                count = tmp_count;
            }
            
        }
        
        while (high > 0)
        {
            for (i = 0, j = high; i <= j; )
            {
                if (s[i] == s[j])
                {
                    ++i;
                    --j;
                }
                else
                {
                    high--;
                    break;
                }
            }
            if (j < i)
            {
                break;
            }
        }

        char* str = nullptr;

        int length = 2 * s.size() - high;
        str = (char*)malloc(sizeof(char) * length);
        if (str == nullptr)
        {
            cerr << "memory allocated failure!" << endl;
            assert(str);
        }
        str[length - 1] = '\0';

        j = 0;
        for (i = s.size() - 1; i > high; i--)
        {
            str[j++] = s[i];
        }
        for (i = 0; i < s.size(); i++)
        {
            str[j++] = s[i];
        }

        return string(str);
    }
};

int main(int argc, char* argv[]) {

    Solution s;
    string str = "aacecaaa";
    cout << s.shortestPalindrome(str) << endl;
    
    return 0;
}
