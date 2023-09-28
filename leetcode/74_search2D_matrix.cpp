#include <iostream>
#include <vector>
using namespace std;

bool find_target(vector<int> vec, int start, int end, int target);

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (auto vecs : matrix) {
            if (vecs[vecs.size()-1] > target) {
                return find_target(vecs, 0, vecs.size(), target);
            } else if (vecs[vecs.size()-1] == target) {
                return true;
            }
        }
        return false;
    }
};

bool find_target(vector<int> vec, int start, int end, int target) {
    if (start > end) {
        return false;
    }
    int index = (start + end) / 2;
    if (vec[index] == target) {
        return true;
    }
    if (vec[index] < target) {
        return find_target(vec, index+1, end, target);
    }
    if (vec[index] > target) {
        return find_target(vec, start, index-1, target);
    }
    return false;
}

int main(int argc, char* argv[]) {

    vector<vector<int>> matrix = {
                                    {1,3,5,7},
                                    {10,11,16,20},
                                    {23,30,34,60}
                                };

    Solution s;

    if (s.searchMatrix(matrix, 33)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}