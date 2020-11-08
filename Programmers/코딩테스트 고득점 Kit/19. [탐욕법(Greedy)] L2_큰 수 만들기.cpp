//https://programmers.co.kr/learn/courses/30/lessons/42883

#include <string>
#include <algorithm>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    string str = number;
    char max;
    int start = 0, ind;
    while(1)
    {
        if(k == str.size() || k == 0) return answer;

        max = *max_element(str.begin() + start, str.begin() + k + 1);
        ind = str.find_first_of(max);
        k -= ind - start;
        
        if (start == 1)   answer += str[0];
        
        str = str.substr(ind);
        start = 1;
    }
}

int main()
{
    string a = solution("41736122", 4);
}
