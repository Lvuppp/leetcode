#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;

        int tmp = 0;

        for(auto it = tokens.begin(); it < tokens.end(); it++)
        {
            if (*it == "+" ) {
                tmp = nums.top();
                nums.pop();
                nums.top() += tmp;
            }
            else if (*it == "-"){
                tmp = nums.top();
                nums.pop();
                nums.top() -= tmp;
            }
            else if (*it == "*") {
                tmp = nums.top();
                nums.pop();
                nums.top() *= tmp;
            }
            else if (*it == "/") {
                tmp = nums.top();
                nums.pop();
                nums.top() /= tmp;
            }
            else
            {
                nums.push(atoi((*it).c_str()));
            }
        }

        return nums.top();
    }
};

int main()
{
    Solution s;
    vector<string> vec{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << s.evalRPN(vec);
}
