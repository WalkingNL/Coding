/**
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
 * 
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            int first = *it;
            for (auto it2 = it + 1; it2 != nums.end(); ++it2) {
                int second = *it2;
                if (first + second == target) {
                    return {int(it - nums.begin()), int(it2 - nums.begin())};
                }
            }
        }

        // If no solution is found, you might want to return an empty vector or handle it differently.
        return {};
    }
};

int main(int argc, char const *argv[]) {
    Solution solution;
    // vector<int> nums = {3, 2, 4};
    vector<int> nums = {3, 2, 3};
    // vector<int> nums = {2, 7, 11, 15};
    int target = 6;
    
    vector<int> result = solution.twoSum(nums, target);
    if (result.size() == 2) {
        cout << "Indices: " << result[0] << " " << result[1] << endl;
    } else {
        cout << "No solution found." << endl;
    }
    
    return 0;
}
