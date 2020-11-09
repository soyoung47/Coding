//https://programmers.co.kr/learn/courses/30/lessons/42860?language=cpp

#include <string>
#include <algorithm>
using namespace std;

int solution(string name) {
    int answer = 0;

    //각 자릿수의 최소 이동 횟수 (위/아래:알파벳 찾기)
    for (char alpha : name)
    {
        if (alpha == 'A')    continue;
        answer += min(alpha - 'A', 'Z' - alpha + 1);
    }   

    //커서 최소 이동 횟수 (오/왼)
    char start = name[0];
    sort(name.begin(), name.end());

    int ind = name.find_first_of(start);
    int begin = name.find_last_of('A');

    answer += (name.size() - 1 - ind) + (ind - begin - 1) * 2;
    if (begin < 0)  answer -= (ind - begin - 1);        

    return answer;
}

int main()
{
    int a = solution("JEZ");
}