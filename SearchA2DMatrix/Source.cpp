#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int start = 0, end = matrix[0].size() - 1, row = 0, middle;

	while (row < matrix.size()){
		if (matrix[row][end] >= target) {
			if (matrix[row][0] <= target) {
				while (end >= start) {

					middle = (start + end) / 2;

					if (matrix[row][middle] == target) {
						return true;
					}

					if (matrix[row][middle] < target) {
						start = middle + 1;
					}
					else {
						end = middle - 1;
					}
				}
			}
			return false;
		}
		row++;
	}

    return false;
}

int main() {
	vector<vector<int>> vec{ {1, 3, 5, 7, 8},
		{ 10, 11, 15, 16, 20 }, {23, 26, 30, 34, 60}};
	cout << searchMatrix(vec, 9);
}