#include<string>
#include <iostream>

using namespace std;
 

class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0, j = 0;

        if (haystack.size() < needle.size())
            return -1;

        while (i < haystack.size()) {
            while (needle[j] == haystack[i + j]) {
                if (j == needle.size() - 1) {
                    return i;
                }
                j++;
            }
            j = 0;
            i++;
        }
        return -1;
    }
};


int main()
{
    Solution s;
    cout << s.strStr("mississippi", "issip");
    cout << s.strStr("sssi", "si");
}