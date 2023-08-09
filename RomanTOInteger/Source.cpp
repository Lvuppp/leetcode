#include<iostream>
#include<string>
using namespace std;


class Solution {
public:
    int romanToInt(string s) {
        short index = s.size() - 1, num = 0;

        while (index > -1) {
            switch (s[index]) {
            case 'I':
                if (index < s.size() - 1) {
                    if (s[index + 1] == 'V' && s[index + 1] == 'X') {
                        num--;
                        break;
                    }
                }
                num++;
                break;
            case 'V':
                num += 5;
                break;
            case 'X':
                if (index < s.size() - 1) {
                    if (s[index + 1] == 'L' && s[index + 1] == 'C') {
                        num -= 10;
                        break;
                    }
                }
                num += 10;
                break;
            case 'L':
                num += 50;
                break;
            case 'C':
                if (index < s.size() - 1) {
                    if (s[index + 1] == 'D' && s[index + 1] == 'M') {
                        num -= 100;
                        break;
                    }
                }
                num += 100;
                break;
            case 'D':
                num += 500;
                break;
            case 'M':
                num += 1000;
                break;
            }
            index--;
        }
        return num;
    }
};

int main() {
    Solution s;
    s.romanToInt("MCMXCIV");
}