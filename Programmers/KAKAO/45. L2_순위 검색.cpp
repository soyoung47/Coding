//https://programmers.co.kr/learn/courses/30/lessons/72412
//시간초과

#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

string split(string str, char delimiter)
{
    string arr;
    stringstream ss(str);
    string tmp = "";

    while (getline(ss, tmp, delimiter))
    {
        if (tmp == "and")  continue;

        if (tmp == "cpp" || tmp == "chicken")
            arr += 'C';
        else if (tmp == "java" || tmp == "junior")
            arr += 'J';
        else if (tmp == "python" || tmp == "pizza")
            arr += 'P';
        else if (tmp == "backend")
            arr += 'B';
        else if (tmp == "frontend")
            arr += 'F';
        else if (tmp == "senior")
            arr += 'S';
        else if (tmp == "-")
            arr += '-';
        else
        {
            int len = 6-tmp.size();
            while (len > 0)
            {
                arr += '0';
                len--;
            }
            arr += tmp;
        }
            
    }

    return arr;   
}

int check[4] = { 0 };
bool cmp(string a, string b) {
    
    for (int i = 0; i < 4; i++)
    {
        if (check[i] == 0)   continue;
        a[i] = b[i] = 'A';
    }

    return a < b;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    for (int i = 0; i < info.size(); i++)
        info[i] = split(info[i], ' ');

    int ind = 0, lower, upper;
    for (int i = 0; i < query.size(); i++)
    {
        string q = split(query[i], ' ');
        int size = q.size();

        vector<string> a = info;

        //'-' 있는 위치 파악
        for (int i = 0; i < 4; i++)
        {
            if (q[i] == '-')   check[i] = 1;
            else check[i] = 0;
        }
        sort(info.begin(), info.end(), cmp);

        lower = lower_bound(info.begin(), info.end(), q, cmp) - info.begin();

        q.replace(4, 6, 6, '9');
        upper = upper_bound(info.begin(), info.end(), q, cmp) - info.begin();

        answer.push_back(upper - lower);
    }

    return answer;
}

int main()
{
    vector<int> a = solution({ "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" }, { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" });
}