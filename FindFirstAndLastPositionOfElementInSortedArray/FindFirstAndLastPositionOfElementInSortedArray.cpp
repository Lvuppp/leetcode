#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int start = 0, end = nums.size() - 1, middle;
    
    while (end >= start)
    {
        middle = (start + end) / 2;

        if (nums[start] == target && nums[end] == target) {
            return vector<int>{start, end};
        }

        if (nums[middle] > target) {
            end = middle ;
        }
        else if(nums[middle] < target){
            start = middle; 
        }
        else {
            if (nums[start] ) {

            }
            else {

            }
        }
    }

    return vector<int>{-1, -1};
      
}

int main()
{
    vector<int> vec{1,2,2,3,5,6,7,7}, vec1 = searchRange(vec,2);
    
    std::cout << vec1[0] << " " << vec[1];
}
