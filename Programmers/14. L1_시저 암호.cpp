#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ') continue;

        if (islower(s[i]) && !islower(s[i] + n)) s[i] += n - 26;    //(s[i] <= 'z') && (s[i]+ n > 'z')
        else if (isupper(s[i]) && !isupper(s[i] + n)) s[i] += n - 26;   //(s[i] <= 'Z') && (s[i]+ n > 'Z')
        else s[i] += n;
    }

    return s;
}