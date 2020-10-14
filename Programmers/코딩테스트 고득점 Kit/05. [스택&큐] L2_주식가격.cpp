//https://programmers.co.kr/learn/courses/30/lessons/42584

#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int size = prices.size();
    for (int i = 0; i < size - 1; i++)
    {
        stack<int> st;
        int price = prices[i];
        for (int j = i + 1; j < size; j++)
        {
            st.push(prices[j]);

            if (price > prices[j]) break;
        }
        answer.push_back(st.size());
    }

    answer.push_back(0);
    return answer;
}