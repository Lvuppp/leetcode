#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size())
            swap(a, b);

        int i = a.size() - 1, j = b.size() - 1, flag = 0;

        while (i >= 0) {
            if (j >= 0) {
                a[i] += b[j] - 48 + flag;
                j--;
            }
            else {
                a[i] += flag;
            }

            flag = 0;

            if (a[i] > '1') {
                a[i] -= 2;
                flag = 1;
            }
            i--;
        }

        if (flag) {
            a = '1' + a;
        }

        return a;
    }
};

int main()
{
    std::cout << "Hello World!\n";
    Solution s;
    s.addBinary("1010", "1011");
}
