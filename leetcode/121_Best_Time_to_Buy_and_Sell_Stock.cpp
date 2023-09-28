#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i=1; i<prices.size(); i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } else if (prices[i]-minPrice > maxProfit) {
                maxProfit = prices[i] - minPrice;
            }
        }

        return maxProfit;
    }
};

int main(int argc, char* argv[]) {

    // vector<int> v = {7,4,5,11,1,9,8};
    // vector<int> v = {2,1,2,1,0,1,2};
    vector<int> v = {7,1,5,3,6,4};
    // vector<int> v = {7,6,4,3,1};
    // vector<int> v = {2,1,4};
    // vector<int> v = {1, 2};

    Solution s;

    cout << "max_profit = " << s.maxProfit(v) << endl;

    return 0;
}

/**
 * 
 * int maxProfit(vector<int>& prices) {
        int max_profit = 0;

        if (prices.size() <= 1) return max_profit;

        if (prices.size() == 2) {
            if (prices[1] > prices[0]) {
                return prices[1] - prices[0];
            }
        }

        int mid_pos = 1;

        int mini_index = 0;
        // int max_index = prices.size() - 1;
        multiset<int, std::greater<int>> set_max_list;

        for (int j=prices.size() - 1; j>=mid_pos; j--) {
            set_max_list.insert(prices[j]);
        }

        if (max_profit < (*set_max_list.begin() - prices[mini_index])) {
            max_profit = *set_max_list.begin() - prices[mini_index];
        }
        // 7,4,5,11,1,9,8
        while (mid_pos <= (prices.size() - 1)) {

            auto it = set_max_list.find(prices[mid_pos]);
            if (it != set_max_list.end()) {
                if (set_max_list.erase(it) == set_max_list.end()) {
                    continue;
                }
            }

            if ((prices[mid_pos] < prices[mini_index])) {
                mini_index = mid_pos;
            }

            if (max_profit < (*set_max_list.begin() - prices[mini_index])) {
                max_profit = *set_max_list.begin() - prices[mini_index];
            }

            mid_pos++;
        }

        // time limit exceeded
        // for (int i=0, j=prices.size()-1; i<(prices.size()-1) && j>i;) {
        //     if (prices[j] <= prices[i]) {
        //         j--;
        //         if (j == i) {
        //             i++;
        //             j = prices.size() - 1;
        //         }
        //         continue;
        //     }
        //     if (max_profit < (prices[j] - prices[i])) {
        //         max_profit = prices[j] - prices[i];
        //     }
        //     if ((j-1) == i) {
        //         i++;
        //         j=prices.size();
        //     }
        //     j--;
        // }

        return max_profit;
    }
*/
