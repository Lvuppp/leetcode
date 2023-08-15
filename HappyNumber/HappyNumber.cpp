#include <iostream>

    class Solution {
    public:
        bool isHappy(int n) {
            if (n < 10) {
                return n == 1 ? 1 : 0;
            }
            int tmp = 0;

            while (n) {
                tmp += (n % 10) * (n % 10);
                n /= 10;
            }

            std::cout << tmp << " ";

            return isHappy(tmp);
        }
    };

int main()
{
    std::cout << "Hello World!\n";
    Solution s;
    s.isHappy(19);
}
