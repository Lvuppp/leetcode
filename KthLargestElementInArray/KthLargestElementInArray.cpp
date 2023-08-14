#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickselect(nums, 0, nums.size() - 1, k);
    }

    int quickselect(vector<int>& nums, int left, int right, int k) {
        if (left == right)
            return nums[left];

        int pivotIndex = left + (right - left) / 2;
        partition(nums, left, right, pivotIndex);

        if (nums.size() - pivotIndex - 1 > k) {
            return quickselect(nums, pivotIndex + 1, right, k);
        }
        else if(nums.size() - pivotIndex - 1 > k) {
            return quickselect(nums, left, pivotIndex - 1, k);
        }
        else {
            return nums[pivotIndex];
        }
    }

    int partition(vector<int>& nums, int left, int right, int pivotIndex) {

        int pivot = nums[pivotIndex];
        swap(nums[pivotIndex], nums[left]);

        while (left < right) {
            if (nums[right] < pivot) {
                swap(nums[right], nums[pivotIndex]);
                pivotIndex--;
            }
            right--;
        }
        swap(nums[left], nums[pivotIndex]);

        return pivotIndex;
    }
};

int main()
{
    vector<int> vec {3, 2, 1, 5, 6, 4};
    Solution s;
    cout << s.findKthLargest(vec, 2);
}
