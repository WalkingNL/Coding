/**
 * Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
 * Return the sum of the three integers.
 * You may assume that each input would have exactly one solution.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closer = INT_MAX;
        int ans = 0;
        int n = nums.size();
        
        for (int i=0; i<n-2; i++) {
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (abs(target-sum) < closer) {
                    closer = abs(target - sum);
                    ans = sum;
                } else if (sum < target)
                    left++;
                else
                    right--;
            }
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {

    return 0;
}
