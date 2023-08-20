// DailyTemperature.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<stack>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> dif;
        vector<int> answer(temperatures.size(), 0);
        int j = 0;

        for (int i = 0; i < temperatures.size(); i++) {
            while (!dif.empty() && dif.top().first < temperatures[i]) {
                answer[dif.top().second] = i - dif.top().second;
                dif.pop();
            }
            dif.push(make_pair(temperatures[i], i));
        }
        return answer;
    }
};


int main()
{
    vector<int> vec{73, 74, 75, 71, 69, 72, 76, 73};
    Solution s;
    for (auto a : s.dailyTemperatures(vec)) {
        cout << a << " ";
    }
}
