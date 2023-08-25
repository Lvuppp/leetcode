#include <iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size() - 1, startMiddle, endMiddle;

        while (start < end) {
            startMiddle = start + (end - start) / 3;
            endMiddle = end - (end - start) / 3;

            if (nums[startMiddle] < nums[endMiddle]) {
                start = startMiddle;
            }
            else {
                end = endMiddle;
            }
        }

        return start;
    }
};
int main()
{
    vector<int> vec{3, 4, 5, 1, 2};
    Solution s;
    s.findMin(vec);
}
