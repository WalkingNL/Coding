#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        if (nums.size() == 1) {
            return nums[0] == target;
        }
        if (nums.size() == 2) {
            if (nums[0] > nums[1]) {
                swap(nums[0], nums[1]);
            }
            return nums[0] == target || nums[1] == target;
        }
        int start = 0;
        int end = nums.size() - 1;
        // 2 5 6 0 0 1 2
        int i;
        bool flag = false;
        if (nums[start]==target || nums[end]==target) {
            flag = true;
        }
        for (i=1; i<nums.size(); ) {
            if (nums[i] >= nums[i-1]) {
                if (!flag && nums[i]==target) {
                    flag = true;
                }
                i++;
                continue;
            }
            break;
        }

        if (i == nums.size()) {
            return binary_search(nums.begin(), nums.end(), target);
        } else {
            start = i - 1;
            if (start>0 && nums[0]<nums[end]) {
                return false;
            }
        }
        
        for (i=nums.size()-2; i>=0; ) {
            if (nums[i] <= nums[i+1]) {
                if (!flag && nums[i]==target) {
                    flag = true;
                }
                i--;
                continue;
            }
            break;
        }
        end = i + 1;

        cout << "start: " << start << " end: " << end << endl;

        vector<int> vec;
        if (start == end-1 && flag) {
            int i;
            if (start+1 <= nums.size()-end) {
                int count = nums.size() - 1;
                for (i=0; i<=start; i++) {
                    vec.push_back(nums[i]);
                    nums[i] = nums[end++];
                }
                while (end < nums.size()) {
                    nums[i++] = nums[end++];
                }
                for (auto v : vec) {
                    nums[i++] = v;
                }
            } else {
                i = nums.size() - 1;
                while(i >= end) {
                    vec.push_back(nums[i]);
                    nums[i--] = nums[start--];
                }
                while (start >= 0) {
                    nums[i--] = nums[start--];
                }
                for (auto v : vec) {
                    nums[i--] = v;
                }
            }
            return true;
        }
        return false;
    }
};

int main(int argc, char* argv[]) {

    // vector<int> vec = {2,5,6,0,0,1,2};
    // vector<int> vec = {1,3};
    // vector<int> vec = {1,2,3,4};
    // vector<int> vec = {2,2,2,3,2,2,2};
    vector<int> vec = {3,5,1};
    
    Solution s;
    cout << s.search(vec, 3) << endl;

    cout << "Result: ";
    for (auto v : vec) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
