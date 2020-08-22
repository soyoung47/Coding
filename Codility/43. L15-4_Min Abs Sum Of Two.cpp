/*
    Time Complexity:
    Result:::
    Reference:::
*/

#include <map>

int solution(vector<int>& A)
{
    int N = A.size();
    if (N == 1)  return abs(A[N-1]*2);

    //Insert array A into map
    map<int, int> m;
    bool plus = false, minus = false;
    for (int i = 0; i < N; i++)
    {
        //isPlus
        if (A[i] >= 0)
        {
            if (m[A[i]] == -1)   return 0;
            m[A[i]] = 1;
            plus = true;
        }
        //isMinus
        else
        {
            if (m[abs(A[i])] == 1)   return 0;
            m[abs(A[i])] = -1;
            minus = true;
        }
    }
}