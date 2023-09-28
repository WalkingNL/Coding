#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        if (n == 1 && m == 0) {
            nums1[0] = nums2[0];
            return;
        }
        
        int k = m + n - 1;
        // int count = m - 1;

        for (int i=n-1; i>=0; i--) {
            cout << "i = " << i << endl;
            while (m > 0) {
                if (nums2[i] >= nums1[m-1]) {
                    nums1[k--] = nums2[i];
                    break;
                } else {
                    nums1[k--] = nums1[m-1];
                    m--;
                }
            }
            if (m == 0) {
                nums1[k--] = nums2[i];
            }
        }
    }
};

int main(int argc, char* argv[]) {

    // vector<int> nums1 = {2,0};
    // vector<int> nums2 = {1};

    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {1,5,6};

    // vector<int> nums1 = {4,5,6,0,0,0};
    // vector<int> nums2 = {1,2,3};

    Solution s;
    s.merge(nums1, 3, nums2, 3);

    for (auto num1 : nums1) {
        cout << num1 << " ";
    }
    cout << endl;

    return 0;
}