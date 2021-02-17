//https://programmers.co.kr/learn/courses/30/lessons/72411

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<string, int> m[11];

string str;
bool visit[11];
void combination(int ind, int cnt, int comb)
{
    if (cnt == comb)
    {
        string menu = "";
        for (int i = 0; i < str.size(); i++)
        {
            if (visit[i])    menu += str[i];
        }
        m[comb][menu] += 1;
        return;
    }

    for (int i = ind; i < str.size(); i++)
    {
        if (visit[i])    continue;
        visit[i] = true;
        combination(i, cnt + 1, comb);
        visit[i] = false;
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;    

    for (int i = 0; i < orders.size(); i++)
    {
        //주문 메뉴 알파벳 오름차순 정렬
        sort(orders[i].begin(), orders[i].end());

        str = orders[i];

        //단품 조합 구성
        for (int j = 0; j < course.size(); j++)
        {
            if (str.size() < course[j])    continue;
            combination(0, 0, course[j]);
        }            
    }
    
    //코스요리 구성가능한 단품메뉴 조합 추가
    for (int i = 2; i <= course[course.size()-1]; i++)
    {
        if (m[i].empty())    continue;
        
        int max_cnt = 0;
        for (auto it = m[i].begin(); it != m[i].end(); it++)
            max_cnt = max(max_cnt, it->second);

        if (max_cnt < 2) continue;
        for (auto it = m[i].begin(); it != m[i].end(); it++)
        {
            if (it->second == max_cnt)
                answer.push_back(it->first);
        }
    }    

    //사전 순으로 오름차순 정렬
    sort(answer.begin(), answer.end());
    
    return answer;
}