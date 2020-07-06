#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int len = s.length();

    int pos = len / 2;
    if (len % 2 == 0)
        answer = s.substr(pos - 1, 2);
    else
        answer = s[pos];

    return answer;
}