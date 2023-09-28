#include <iostream>
#include <vector>
using namespace std;

// 0,0,1,1,1,2,2,3,3,4
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if (nums.size() == 1) {
            return 1;
        }

        int reset = 0;
        int count = 0;
        int special_num = nums[0];

        for (int i=1; i<nums.size(); i++) {
            if (nums[i] == special_num) {
                count++;
                // reset++;
            } else {
                special_num = nums[i];
                // if (reset > 0) {
                nums[i-count] = nums[i];
                    // reset = 0;
                // }
            }
        }

        nums.erase(nums.end()-count, nums.end());

        return count;
    }
};

int main(int argc, char* argv[]) {

    vector<int> nums = {1,1,2};
    // vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    // vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    Solution s;
    int len = s.removeDuplicates(nums);
    cout << "len = " << len << endl;

    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
