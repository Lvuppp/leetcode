#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> triplets;
    sort(nums.begin(), nums.end());

    int start = 0, end = nums.size() - 1, middle, sum;

    while (end > start + 1) {
        middle = start + 1;
        end = nums.size() - 1;

        while (end > middle) {
            sum = nums[start] + nums[middle] + nums[end];

            if (sum == 0) {
                triplets.push_back(vector<int>{nums[start], nums[middle], nums[end]});

                do {
                    ++middle;
                } while (end > middle && nums[middle] == nums[middle - 1]);

                do {
                    --end;
                } while (end > middle && nums[end] == nums[end + 1]);
            }
            else if (sum < 0) {
                middle++;
            }
            else {
                end--;
            }
        }

        do {
            ++start;
        } while (nums[start] == nums[start - 1] && end > start + 1);
    }

    return triplets;
}

int main()
{
    vector<vector<int>>vec{{-2, 0, 1, 1, 2}};

    for (size_t i = 0; i < vec.size(); i++)
    {
        threeSum(vec[i]);
    }
}
