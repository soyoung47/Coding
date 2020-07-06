#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    string str = "";
    for (int i = 0; i < s.length(); i++)
    {
        str += s[i];

        if (s[i] == ' ' || i == s.length() - 1)
        {
            for (int j = 0; j < str.length(); j++)
            {
                if (j % 2 == 0) str[j] = toupper(str[j]);
                else str[j] = tolower(str[j]);
            }
            answer += str;
            str = "";
        }
    }

    return answer;
}