#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        short index = 0, pIndex = 0;
        bool flag = false;
        while (index < s.size() && pIndex < p.size()) {
            if (s[index] == p[pIndex] || p[pIndex] == '.') {
                pIndex++;
                flag = false;
            }
            else if (p[pIndex] == '*') {
                pIndex++;
                flag = true;
                continue;
            }
            else if (!flag) {
                pIndex = 0;
            }
            index++;
        }

        return p.size() - 1 == pIndex;
    }
};

int main()
{
    Solution s;
    s.isMatch("aaaa", "a*");
}
