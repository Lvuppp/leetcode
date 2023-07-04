#include <vector>
#include <iostream>

using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    int start = 0, end = arr.size() - 1, middle = (start + end) / 2;;

	while (end >= start)
	{
		if (arr[middle] > arr[middle - 1] && arr[middle] > arr[middle + 1]) {
			return middle;
		}

		if (arr[middle] > arr[middle - 1] && arr[middle] < arr[middle + 1]) {
			start = middle ;
		}
		else {
			end = middle ;
		}

		middle = (start + end) / 2;
	}
	return middle;
}

int main()
{
	vector<int> vec{3, 5, 3, 2, 0};
	cout << peakIndexInMountainArray(vec);
}