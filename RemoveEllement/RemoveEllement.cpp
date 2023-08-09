#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int offset = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                offset++;
                continue;
            }
            nums[i - offset] = nums[i];
        }

        return nums.size() - offset;
    }
};

int main()
{
    Solution s;
    vector<int> vec{0, 1, 2, 2, 3, 0, 4, 2};
    s.removeElement(vec,2);
}
