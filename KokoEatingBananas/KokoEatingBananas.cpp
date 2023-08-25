#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int endPiles = INT_MIN, startPiles = 1, k, hours;

        for (const int& pile : piles) {
            endPiles = max(endPiles, pile);
        }

        if (piles.size() == h) {
            return endPiles;
        }

        while (startPiles + 1 <= endPiles) {
            k = (startPiles + endPiles) / 2;
            hours = 0;

            for (const int& pile : piles) {
                hours += pile / k;

                if (pile % k) {
                    hours++;
                }
            }

            if (hours > h) {
                startPiles = k + 1;
            }
            else {
                endPiles = k;
            }
        }

        return endPiles;
    }
};


int main()
{
    vector<int> vec{21};

    Solution s;
    s.minEatingSpeed(vec, 20);

}
