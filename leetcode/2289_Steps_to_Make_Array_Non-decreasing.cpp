#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int stepsToMakeArrayNonDecreasing(vector<int>& nums) {
        int steps = 0;

        while (true) {
            bool removed = false;
            vector<int> newNums = {nums[0]}; // initialize with the first element
            
            for (int i = 1; i < nums.size(); ++i) {
                if (nums[i] >= newNums.back()) {
                    newNums.push_back(nums[i]);
                } else {
                    removed = true;
                }
            }

            if (!removed) { // if no elements were removed, break
                break;
            }
            
            nums = newNums; // update nums
            steps++; // increment the number of steps
        }
        
        return steps;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    // vector<int> nums = {5,3,4,4,7,3,6,11,8,5,11};
    // vector<int> nums = {4,5,7,7,13};
    vector<int> nums = {15,3,4,4,7,3,6,11,8,5,11};
    // vector<int> nums = {15,13,7,7,5,4};
    // vector<int> nums = {15,13,7,6,5,4};
    cout << "count = " << s.stepsToMakeArrayNonDecreasing(nums) << endl;
    return 0;
}
