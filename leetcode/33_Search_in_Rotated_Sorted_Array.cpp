#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        if (nums.size() == 0) return -1;
        if (nums.size() == 1) {
            if (nums[0] == target) return 0;
            else return -1;
        }

        int left = 0;
        int right = nums.size() - 1;
        int mid = (left + right) / 2;

        while (left <= right) {
            if (nums[mid] == target) return mid;

            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                    mid = (left + right) / 2;
                } else {
                    left = mid + 1;
                    mid = (left + right) / 2;
                }
            } else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                    mid = (left + right) / 2;
                } else {
                    right = mid - 1;
                    mid = (left + right) / 2;
                }
            }
        }

        return -1;
    }
};

int main(int argc, char* argv[]) {

    // vector<int> vec = {4};
    vector<int> vec = {4,6,5,7,0,1,2};

    Solution s;
    cout << s.search(vec, 0) << endl;

    return 0;
}
