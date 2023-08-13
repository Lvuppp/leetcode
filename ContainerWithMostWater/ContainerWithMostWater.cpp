#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0, end = height.size() - 1, maxSquare = INT_MIN;

        while (start < end) {
            while (start < end && height[end] < height[start]) {
                maxSquare = max(maxSquare, (end - start) * min(height[start], height[end]));
                end--;
            }

            maxSquare = max(maxSquare, (end - start) * min(height[start], height[end]));
            start++;
        }

        return maxSquare;
    }
};


int main()
{
    vector<int> vec{};
    Solution s;
    cout << s.maxArea(vec);
}
