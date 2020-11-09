//https://programmers.co.kr/learn/courses/30/lessons/42860?language=cpp

#include <string>
#include <algorithm>
using namespace std;

int solution(string name) {
    int answer = 0;

    //�� �ڸ����� �ּ� �̵� Ƚ�� (��/�Ʒ�:���ĺ� ã��)
    for (char alpha : name)
    {
        if (alpha == 'A')    continue;
        answer += min(alpha - 'A', 'Z' - alpha + 1);
    }   

    //Ŀ�� �ּ� �̵� Ƚ�� (��/��)
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