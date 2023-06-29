#include<iostream>
#include <unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

bool isPerfectSquare(int num) {
	if (num == 1)
		return 1;

	int start = 1, end = num / 2, middle;


	while (end - start >= 0)
	{
		middle = (end - start) / 2 + start;

		if (num / middle == middle && num % middle == 0) {
			return true;
		}
		else if (num / middle < middle) {
			end -= (end - start) / 2 + 1;
		}
		else {
			start += (end - start) / 2 + 1;
		}

	}

	return false;
}

int main() {
    cout << isPerfectSquare(100);
}