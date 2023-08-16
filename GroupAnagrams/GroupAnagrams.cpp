#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groupAnagrams;
        vector<short> letters(26, 0);
        unordered_map<string, vector<string>> anagrams;
        string anagram;

        for (int i = 0; i < strs.size(); i++) {
            for (short j = 0; j < strs[i].size(); j++) {
                letters[strs[i][j] - 97]++;
            }   

            for (short j = 0; j < 26; j++) {
                anagram += j;
                anagram += letters[j];
                letters[j] = 0;
            }

            if (anagrams.find(anagram) == anagrams.end()) {
                anagrams.insert(make_pair(anagram, vector<string>{strs[i]}));
            }
            else {
                anagrams[anagram].push_back(strs[i]);
            }
            anagram = "";
        }

        for (auto it : anagrams) {
            groupAnagrams.push_back(it.second);
        }

        return groupAnagrams;
    }
};

int main()
{
    vector<string>vec{ "eat", "tea", "tan", "ate", "nat", "bat"};
    Solution s;
    s.groupAnagrams(vec);

}

