#include<iostream>
#include<vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int first = 1;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i - 1]) {
            nums[first] = nums[i];
            first++;
        }

    }
    return first ;
}


int main() {
    vector<int> vec1{1, 1, 2};
    vector<int> vec{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << removeDuplicates(vec);
    cout << removeDuplicates(vec1);
}