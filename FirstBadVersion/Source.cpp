#include<iostream>
#include <unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

bool isBadVersion(int n) {
    if (n > 4)
        return true;
    return false;
}

int firstBadVersion(int n) {
    if (n == 1)
        return 1;

    int offset = n / 2 + n % 2;
    n -= offset;

    while (offset) {
        offset = offset / 2 + offset % 2;
        bool tmp = isBadVersion(n);

        if (tmp && !isBadVersion(n - 1)) {
            break;
        }
        else if (tmp) {
            n -= offset;
            continue;
        }

        n += offset;
    }

    return n;
}
int main() {
    cout << firstBadVersion(100);
}