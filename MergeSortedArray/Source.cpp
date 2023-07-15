#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	
	while (n > 0)
	{
		while (m > 0 && (m == 0 || m > 0 && nums1[m - 1] < nums2[n - 1])) {
			nums1[m + n - 1] = nums2[n - 1];
			n--;
		}
		if (m > 0) {
			nums1[m + n - 1] = nums1[m - 1];
			m--;
		}
	}
}

int main() {
	vector<int> vec(1);
	vector<int> vec1{1};
	merge( vec,0,vec1,1 );
}