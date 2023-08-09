#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int longestSubstringWithoutRepeating = 0, i = 0, j = 0;
    set<char> set;
    vector<int> a(10, 0);

    while (j < s.size()) {
        while (!set.count(s[j]) && j < s.size()) {
            set.insert(s[j]);
            j++;
        }

        
        if(longestSubstringWithoutRepeating < j - i){
            longestSubstringWithoutRepeating = max(longestSubstringWithoutRepeating,j - i;
        }

        set.erase(s[i]);
        i++;
    }
    return longestSubstringWithoutRepeating;
}

int main()
{

    std::cout << "Hello World!\n";
}
