#include <iostream>
#include <string>
#include <vector>

using namespace std;

string firstPalindrome(vector<string>& words) {
		bool flag = true;
		for (size_t i = 0; i < words.size(); i++)
		{
			for (size_t j = 0; j < words[i].size() / 2; j++)
			{
				if (words[i][j] != words[i][words[i].size() - j - 1]) {
					break;
				}
			}
			if (flag) {
				return words[i];
			}
		}

		return "";
}

int main()
{
    std::cout << "Hello World!\n";
}
