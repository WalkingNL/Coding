#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        
        if (x < 0) {
            return false;
        }

        if (x/10 == 0) {
            return true;
        }
        int original = x;
        int reverse = 0;
        
        int count = 0;

        while (x) {
            // std::cout << "x = " << x << std::endl;
            // reverse = (reverse * 10) + (x % 10); // risk of overflow
            count++;
            x /= 10;
        }
        x = original;
        bool flag = false;

        int mid = count/2;
        if (count % 2 == 1) {
            flag = true;
            mid++;
        }
        
        while(count-- > mid) {
            // count--;
            reverse = (reverse * 10) + (x % 10);

            x /= 10;

            std::cout << "reverse = " << reverse << std::endl;
        }

        if (flag) {
            x /= 10;
        }
        std::cout << "x = " << x << std::endl;
        if (reverse == x) {
            return true;
        }

        return false;
    }
};

int main(int argc, char* argv[]) {

    Solution s;

    if (s.isPalindrome(123456789)) {
        std::cout << "is prime" << std::endl;
    } else {
        std::cout << "not prime" << std::endl;
    }

    return 0;
}

