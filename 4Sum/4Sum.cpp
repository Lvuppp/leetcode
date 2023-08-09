#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>>quadruplets;
    sort(nums.begin(), nums.end());

    int first = 0, fourth = nums.size() - 1, second, third, halfPartOfSum, sum;

    while (first + 2 < nums.size() - 1)
    {
        second = first + 1;

        while (second + 1 < nums.size() - 1)
        {
            halfPartOfSum = nums[first] + nums[second];
            third = second + 1;
            fourth = nums.size() - 1;

            while (third < fourth)
            {
                sum = halfPartOfSum + nums[third] + nums[fourth];

                if (sum == target) {
                    quadruplets.push_back(vector<int>{nums[first], nums[second], nums[third], nums[fourth]});
                    
                    do {
                        third++;
                    } while (third < fourth && nums[third] == nums[third - 1]);

                    do {
                        fourth--;
                    } while (third < fourth && nums[fourth] == nums[fourth + 1]);
                    continue;
                }

                if (sum < target) {
                    do {
                        third++;
                    } while (third < fourth && nums[third] == nums[third - 1]);
                }
                else {
                    do {
                        fourth--;
                    } while (third < fourth && nums[fourth] == nums[fourth + 1]);
                }

            }

            do {
                second++;
            } while (second + 1 < nums.size() - 1 && nums[second] == nums[second - 1]);
        }

        do {
            first++;
        } while (first + 2 < nums.size() - 1 && nums[first] == nums[first - 1]);

    }

    return quadruplets;
}
int main()
{
    std::cout << "Hello World!\n";
    vector<int>vec{ -3, -3, -2, -2, -1, -1, 0, 0, 1, 1, 2, 2, 3, 3};
    fourSum(vec, 0);

}
