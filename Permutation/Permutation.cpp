#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void heap_permuation(vector<int>& nums, int k) {
        if (k == 1) {
            permutations.push_back(nums);
        }
        for (short i = 0; i < k; i++)
        {
            heap_permuation(nums, k - 1);
            if (k & 1) {
                swap(nums[0], nums[k - 1]);
            }
            else {
                swap(nums[i], nums[k - 1]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        heap_permuation(nums, nums.size());
        return permutations;
    }

    vector<vector<int>> permutations;

};

int main()
{
    
}
