#include <iostream>
using namespace std;

// 2^31 = 2,147,483,648

class Solution {
public:
    int reverse(int x) {
        
        int result = 0;

        while (x!=0) {
            if (result > 214748364 || result < -214748364) {
                return 0;
            }
            result = result*10 + x%10;
            x /= 10;
        }

        return result;
    }
};

int main(int argc, char* argv[]) {
    
        Solution s;
    
        cout << s.reverse(123) << endl;
        cout << s.reverse(-123) << endl;
        cout << s.reverse(120) << endl;
        cout << s.reverse(0) << endl;
        cout << s.reverse(1534236469) << endl;
    
        return 0;
}
