/**
 * Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. 
 * Return the maximized sum.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i=0; i<nums.size(); i += 2) {
            sum += nums[i];
        }
        return sum;
        
    }
};

int main(int argc, char* argv[]) {
    Solution sol;
    // vector<int> vec = {4,2,1,3};
    // vector<int> vec = {6,2,6,5,1,2};
    vector<int> vec = {7,3,1,0,0,6};

    cout << "the maximized val: " << sol.arrayPairSum(vec) << endl;
    return 0;
}

