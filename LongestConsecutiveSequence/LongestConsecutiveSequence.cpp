#include <iostream>
#include <vector>
#include <set>
#include <assert.h>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> sortedNums(nums.begin(), nums.end());
        int i = 0, length = 0, maxLength = INT_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            if (sortedNums.find(nums[i] - 1) == sortedNums.end()) {
                length = 0;

                while (sortedNums.find(nums[i] + length) != sortedNums.end())
                {
                    length++;
                }
                maxLength = max(maxLength, length);
            }
        }

        return maxLength;
    }
};


int main()
{
    Solution s;
    vector<int> vec{200, 4, 100, 1, 3, 2};
    assert(s.longestConsecutive(vec) == 4);
}