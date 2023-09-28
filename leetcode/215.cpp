#include <iostream>
#include <vector>
using namespace std;

/**
 * The selected text is a C++ code snippet that is used to speed up input 
 * and output operations. It does this by disabling the synchronization 
 * between the C++ standard streams and their corresponding C streams1. 
 * This can result in faster execution times, but it also means that 
 * you should not mix C and C++ style I/O operations1. The cin.tie(0) unties cin 
 * from cout, which can also improve performance, but you need to be careful to 
 * manually flush cout when necessary
*/
static const auto fast_io = []{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return nullptr;
}();

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // sort(nums.begin(), nums.end());
        // return nums[nums.size() - k];
        int mini = INT_MAX, mx = INT_MIN;

        for (auto& x : nums) {
            mini = min(x, mini);
            mx = max(x, mx);
        }

        vector<int> cnt(mx - mini + 1, 0);
        for (auto& x : nums) {
            cnt[x - mini]++;
        }

        for (int i = cnt.size() - 1; i >= 0; --i) {
            k -= cnt[i];
            if (k <= 0) return i + mini;
        }
        return -1;
    }
};