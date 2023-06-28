#include<iostream>
#include <unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    short startIt = 0, endIt = nums.size() - 1;

    while (nums[startIt] + nums[endIt] != target) {
        if (nums[startIt] + nums[endIt] < target) {
            startIt++;
        }
        else {
            endIt--;
        }
    }

    return vector<int>{startIt + 1, endIt + 1};
}


int main() {
    vector<int> tmpVec{2, 7, 11, 15};
    auto vec = twoSum(tmpVec, 9);
    cout << vec[0] << " " << vec[1];
}