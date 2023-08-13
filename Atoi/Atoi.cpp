#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int index = 0, num = 0, flag = 1, maxNum = INT_MAX;

        while (s[index] != '-' && s[index] != '+' && (s[index] > 58 || s[index] < 47)) {
            index++;
        }

        if (s[index] == '-') {
            index++;
            while (index < s.size() && s[index] < 58 && s[index] > 47) {
                if (INT_MIN / 10 > num || INT_MIN / 10 == num && s[index] - 48 > 8) {
                    return INT_MIN;
                }

                num *= 10;
                num -= s[index++] - 48;
            }
        }
        else {
            if (s[index] == '+') {
                index++; 
            }

            while (index < s.size() && s[index] < 58 && s[index] > 47) {
                if (INT_MAX / 10 < num || INT_MAX / 10 == num && s[index] - 48 > 7) {
                    return INT_MAX;
                }

                num *= 10;
                num += s[index++] - 48;
            }
        }

        return num * flag;
    }
};

int main()
{
    std::cout << "Hello World!\n";
    Solution s;
    std::cout << s.myAtoi("-2147483649");
}
