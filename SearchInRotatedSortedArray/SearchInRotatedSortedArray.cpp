#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int search(vector<int>& nums, int target) {
    int start = 0, end = nums.size() - 1, middle = (start + end) / 2;

    while (end >= start) {
        middle = (start + end) / 2;

        if (nums[middle] == target) {
            return middle;
        }

        if (nums[middle] > target && target < nums[0] && nums[middle] >= nums[0] ||
            nums[middle] < target && target < nums[0] && nums[middle] <= nums[0] ||
            nums[middle] < target && target > nums[0] && nums[middle] >= nums[0]) {
            start = middle + 1;
        }
        else{
            end = middle - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> vec{1,3};

    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << search(vec, vec[i]);
    }
    cout << search(vec, 3);
}
