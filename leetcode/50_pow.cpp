#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {

        if (abs(abs(x) - 1.0) <= 0.0000000000000001) {
            if (x > 0) {
                return 1.0;
            } else {
                if (n % 2 == 0) {
                    return 1.0;
                } else {
                    return -1.0;
                }
            }
        }

        int N = n/2;
        bool flag = false;
        double x_n = 1.0;
        if (N <= 0) {
            N *= -1;
            flag = true;
        }
        
        for (int i=0; i<N; i++) {
            if (flag) {
                x_n *= (1/x);
            } else {
                x_n *= x;
            }
        }

        if ((n % 2 == 1) || (n % 2 == -1)) {
            if (flag) {
                x_n *= (x_n * (1/x));
                
            } else {
                x_n *= (x_n * x);
            }
        } else {
                x_n *= x_n;
        }

        return x_n;
    }
};

int main(int argc, char* argv[]) {

    Solution s;
    double d = s.myPow(0.44894, -5);


    cout << "d = " << d << endl;

    return 0;
}
