// #include <string>
#include <iostream>
using namespace std;

/**
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 */

// abccbcbb
class Solution {
 public:
  int lengthOfLongestSubstring(const string &s) {
    constexpr int letters = numeric_limits<char>::max() + 1;
    const int n = static_cast<int>(s.size());
    int duplicates = 0;
    int letter_to_count[letters]{};
    int start = 0;
    for (int end = 0; end < n; ++end) {
      if (++letter_to_count[s[end]] == 2) {
        ++duplicates;
      }
      if (duplicates > 0) {
        if (--letter_to_count[s[start++]] == 1) {
          --duplicates;
        }
      }
    }
    return n - start;
  }
};

int main(int argc, char* argv[]) {

    Solution s;

    string str = "abccbcbb";
    // string str = "au";
    
    int length = s.lengthOfLongestSubstring(str);

    cout << "length = " << length << endl;

    return 0;
}
