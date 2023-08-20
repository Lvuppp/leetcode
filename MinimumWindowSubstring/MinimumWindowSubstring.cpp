#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>tLetters(255, 0), sLetters(255, 0);
        int start = 0, end = 0, minStart = 0, minEnd = INT_MAX;
        string minStr;

        for (const char& letter : t) {
            tLetters[letter]++;
        }

        while (end < s.size()) {
            sLetters[s[end]]++;
            end++;

            while (start < end && compareVectorElements(sLetters, tLetters)){
                sLetters[s[start]]--;
                start++;
            }

        }

        return string(s.begin() + start - 1, s.begin() + end);
    }

    bool compareVectorElements(const vector<int>& vec1, const vector<int>& vec2) {
        for (int i = 0; i < vec1.size(); i++) {
            if (vec2[i] > vec1[i]) {
                return false;
            }
        }
        return true;
    }
};




int main()
{
    Solution s;
    cout << s.minWindow("ADOBECODEBANC", "ABC");
}
