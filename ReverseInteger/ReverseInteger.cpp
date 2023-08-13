#include <iostream>
#include <string>


class Solution {
public:
    int reverse(int x) {
        int num = 0;

        while (x) {
            if (INT_MAX / 10 < num && INT_MIN / 10 ) {
                return 0;
            }

            num *= 10;
            num += x % 10;
            x /= 10;
        }
        return num;
    }
};

int main()
{
    Solution s;
    s.reverse(-123);
}
