#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> m;
        for (auto num : nums) {
            if (m.find(num) == m.end()) {
                m[num] = 1;
            } else {
                m[num]++;
            }
        }
        int num = 0;
        for (auto n : m) {
            if (n.second > nums.size()/2) {
                num = n.first;
                break;
            }
        }
        return num;
    }
};

int main(int argc, char* argv[]) {

    vector<int> nums = {2,2,1,1,1,2,2};

    Solution s;
    cout << s.majorityElement(nums) << endl;

    return 0;
}