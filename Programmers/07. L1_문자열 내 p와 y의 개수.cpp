#include <string>
using namespace std;

bool solution(string s)
{
    int cntP = 0;
    int cntY = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'p' || s[i] == 'P')  cntP++;
        if (s[i] == 'y' || s[i] == 'Y')  cntY++;
    }

    if (cntP == cntY)
        return true;
    else
        return false;
}