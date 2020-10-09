/***solution 1***/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    sort(s.begin(), s.end(), greater<char>());
    return s;
}

/***solution 2***/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(char& a, char& b) { return (a > b); }
string solution(string s) {
    sort(s.begin(), s.end(), comp);
    return s;
}