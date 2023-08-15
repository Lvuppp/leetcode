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
                    
            }
            else {

            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        return permutations;
    }

    vector<vector<int>> permutations;

};

int main()
{
    
}
