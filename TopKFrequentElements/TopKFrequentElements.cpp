#include <iostream>
#include <vector>
#include <set>

using namespace std;
class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        auto cmp = [](const pair<int, int>& left,
            const pair<int, int>& right)
        {
            return left.second > right.second;
        };

        multiset<pair<int,int>, decltype(cmp)> frequentElements;
        vector<int> topKElements;

        for (int i = 0; i < nums.size(); i++) {
            topKElements.
        }


        return topKElements;
    }
};
int main()
{
    vector<int> vec{1, 1, 1, 2, 3, 4, 5, 5};
    std::cout << "Hello World!\n";


}
