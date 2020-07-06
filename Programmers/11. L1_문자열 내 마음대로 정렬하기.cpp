#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int k;
bool comp(string& a, string& b)
{
    //false: 
    if (a[k] > b[k]) return false;
    else if (a[k] < b[k]) return true;
    else if (a[k] == b[k])
    {
        if (a > b)   return false;
        else return true;
    }
}

vector<string> solution(vector<string> strings, int n) {

    k = n;
    sort(strings.begin(), strings.end(), comp);

    return strings;
}