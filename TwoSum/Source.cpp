#include<iostream>
#include <unordered_map>
#include<vector>
#include<algorithm>

using namespace std;


vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++)
    {
        if (map.find(target - nums[i]) != map.end()) {
            return vector<int>{i, map[target - nums[i]]};
        }
        else {
            map.emplace(nums[i], i);
        }
    }
    return vector<int>();
}

int main() {
    vector<int> tmpVec{3, 2, 4};
    auto vec = twoSum(tmpVec, 6);
    cout << vec[0] << " " << vec[1];
}