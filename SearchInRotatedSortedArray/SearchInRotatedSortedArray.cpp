#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int search(vector<int>& nums, int target) {
    int start = 0, end = nums.size() - 1, middle = (start + end) / 2;

    if (nums[0] > nums[nums.size() - 1]) {
        if (nums.size() > 2) {
            while (end >= start) {
                middle = (start + end) / 2;

                if (middle == nums.size() - 1 || nums[middle] < nums[middle + 1] && nums[middle] < nums[middle - 1]) {
                    if (target >= nums[0]) {
                        start = 0;
                        end = middle - 1;
                    }
                    else {
                        start = middle;
                        end = nums.size() - 1;
                    }
                    break;
                }

                if (nums[middle] < nums[0]) {
                    end = middle - 1;
                }
                else {
                    start = middle + 1;
                }
            }
        }
        else {
            for (size_t i = 0; i < nums.size(); i++)
            {
                if (nums[i] == target) {
                    return i;
                }
            }
            return -1;
        }
        
    }

    while (end >= start) {
        middle = (start + end) / 2;

        if (nums[middle] == target) {
            return middle;
        }

        if (nums[middle] > target) {
            end = middle - 1;
        }
        else{
            start = middle + 1;
        }
    }

    return -1;
}

int main()
{

    vector<int> vec{4, 5, 6, 7, 9, 10, 2};
    cout << search(vec, 5);
}
