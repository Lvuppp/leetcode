#include <iostream>
#include <vector>
#include <unordered_map>
#include <assert.h>

using namespace std;

class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> amountMap;
        vector<vector<int>> numsCount(nums.size() + 1, vector<int>());
        vector<int> answer;

        for (const int& num : nums) {
            if (amountMap.count(num)) {
                amountMap[num]++;
            }
            else {
                amountMap.insert(make_pair(num, 0));
            }
        }

        for (const pair<int, int>& amount : amountMap) {
            numsCount[amount.second].push_back(amount.first);
        }

        for (int i = numsCount.size() - 1; i >= 0 && k > 0; i--)
        {
            for (int j = 0; j < numsCount[i].size() && k > 0; j++)
            {
                answer.push_back(numsCount[i][j]);
                k--;
            }
        }

        return answer;
    }
};
int main()
{
    vector<int> vec{1, 1, 1, 2, 3, 4, 5, 5};
    Solution s;
    vector<int> ans{1, 2};
    assert(s.topKFrequent(vec, 2) == ans);
}
