#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k == nums.size()) {
            return;
        }
        int i=nums.size()-1;
        int size = nums.size();
        for (; i>=0; ) {
            if (i-k >= 0) {
                int tmp = nums[i];
                nums[i] = nums[i-k];
                nums[i-k] = tmp;
                i--;
                // k_round--;
                continue;
            }
            if (i > 0 && size%k != 0) {
                k = k - size % k;
                size = i + 1;
                continue;
            }
            break;
            
            cout << "i: " << i << ", k: " << k << ", size: " << size << endl;
            for (auto num : nums) {
                cout << num << " ";
            }
            cout << endl << endl;
        }
    }
};

int main(int argc, char* argv[]) {

    vector<int> nums = {-1,-100,3,99};
    // vector<int> nums = {1,2,3,4,5,6,7};
    int k = 2;

    Solution s;
    s.rotate(nums, k);

    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
