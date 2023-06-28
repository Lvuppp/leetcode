#include<iostream>
#include <unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

bool isPalindrome(int x) {
    if (x < 0)
        return false;

    long long reverse = 0, tmp = x;

    while (tmp) {
        reverse *= 10;
        reverse += tmp % 10;
        tmp /= 10;
    }

    if (x == reverse)
        return true;

    return false;
}

int main() {
    cout << isPalindrome(123123);
}