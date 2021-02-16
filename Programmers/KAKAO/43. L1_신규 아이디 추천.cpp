//https://programmers.co.kr/learn/courses/30/lessons/72410

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string new_id) {
    string answer = "";

    //1단계: 소문자로 치환
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);

    //2단계: 소문자, 숫자, -, _, . 제외한 모든 문자 제거
    string tmp = "";
    for (int i = 0; i < new_id.size(); i++)
    {
        char ch = new_id[i];
        if (isalpha(ch) || isdigit(ch) || ch == '-' || ch == '_' || ch == '.')
            tmp += ch;
    }
    new_id = tmp;

    //3단계: 2번 이상 연속된 .를 하나의 .로 치환
    bool check = false;
    tmp = "";
    for (int i = 0; i < new_id.size(); i++)
    {
        char ch = new_id[i];
        if (ch == '.')
        {
            if (check)   continue;
            check = true;
        }
        else if (check)
            check = false;

        tmp += ch;
    }
    new_id = tmp;

    //4단계: 처음 혹은 끝에 위치한 . 제거
    if (new_id[0] == '.')
        new_id = new_id.substr(1);
    if (new_id[new_id.size() - 1] == '.')
        new_id.pop_back();

    //5단계: 빈문자열이면, new_id에 'a' 대입
    if (new_id.empty())  new_id = "a";

    //6단계: 길이가 16자 이상이면, 첫 15개의 문자 제외한 나머지 문자 모두 제거
    if (new_id.size() >= 16) new_id = new_id.substr(0, 15);
    if (new_id[new_id.size() - 1] == '.')   new_id.pop_back();

    //7단계: 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될때까지 반복해서 끝에 추가
    if (new_id.size() <= 2)
    {
        char last = new_id[new_id.size() - 1];
        while (new_id.size() < 3)
        {
            new_id += last;
        }
    }

    answer = new_id;

    return answer;
}