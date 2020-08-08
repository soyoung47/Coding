//77% : https://app.codility.com/demo/results/trainingN9ANYU-FH8/

#include <unordered_map>
#include <algorithm>

vector<int> solution(vector<int>& A) {

    int size = A.size();
    vector<int> ans;
    unordered_map<int, int> m, num;

    //Sort array v & Count elements
    vector<int> v = A;
    sort(v.begin(), v.end());
        
    for (int i = 0; i < size; i++)
    {
        num[v[i]]++;
    }

    int min_cnt = num[v[0]];
    m[v[0]] = size - min_cnt;

    //Count Non Divisors
    for (int i = 1; i < size; i++)
    {
        int elemt = v[i];
        if (m.find(elemt) != m.end())   continue;
        
        int cnt = 0;
        for (int j = 0; j < i; j++)
        {
            if (elemt % v[j] != 0)
                cnt++;
        }
        
        m[v[i]] = cnt + size - i - num[v[i]];
    }

    //Push answers
    for (int i = 0; i < size; i++)
    {
        ans.push_back(m[A[i]]);
    }

    return ans;
}