#include<iostream>
#include <unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

int searchInsert(vector<int>& nums, int target) {

	if (target > nums[nums.size() - 1])
		return nums.size();

	if (target < nums[0])
		return 0;

	int start = 0, end = nums.size() - 1, middle = (end + start) / 2;

	while (end >= start) {
		middle = (end + start) / 2;

		if (nums[middle] == target) {
			return middle;
		}
		if (nums[middle] < target) {
			start = middle + 1;
		}
		else {
			end = middle;
		}
	}

	return nums[middle] >= target ? middle : middle + 1;
}

int main() { 
	vector<int> vec1{1, 3, 5, 7, 11, 13};
	for (size_t i = 0; i < 20; i++)
	{
		cout << i  << "-" << searchInsert(vec1, i) << endl;

	}
}