/**
 * Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
 * 0 <= a, b, c, d < n
 * a, b, c, and d are distinct.
 * nums[a] + nums[b] + nums[c] + nums[d] == target
 * You may return the answer in any order.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> vecs;
        for (int i=0; i<nums.size()-3; i++) {
            int target0 = target - nums[i];
            if (i>0 && nums[i] == nums[i-1]) continue;
            for (int j=i+1; j<nums.size()-2; j++) {
                if (j>(i+1) && nums[j] == nums[j-1]) continue;
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    if (((long long)nums[j] + (long long)nums[left] + (long long)nums[right]) == target0) {
                        vecs.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left<right && nums[left]==nums[left+1]) left += 1;
                        while (left<right && nums[right]==nums[right-1]) right -= 1;
                        left += 1;
                        right -= 1;
                    } else if (((long long)nums[j] + (long long)nums[left] + (long long)nums[right]) < target0) {
                        left += 1;
                    } else {
                        right -= 1;
                    }
                }
            }
        }
        return vecs;
    }
};

int main(int argc, char* argv[]) {
    return 0;
}
