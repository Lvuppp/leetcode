#include <iostream>
#include <vector>

using namespace std;    

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0, j = 0, maxPrice = INT_MIN, dif = 0;

        while (i < prices.size()) {
            while (j < prices.size() && prices[i] <= prices[j]) {
                dif = max(dif, prices[j] - prices[i]);
                j++;
            }

            i = j;
            i++;
            j = i;
            maxPrice = INT_MIN;
        }

        return dif;
    }
};

int main() {
    vector<int> vec{9,6,5,3,1};

    Solution s;
    cout << s.maxProfit(vec);
}