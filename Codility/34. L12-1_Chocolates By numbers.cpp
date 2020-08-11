/*
    Time Complexity:
    Result:::
    Reference:::
*/

//75% : https://app.codility.com/demo/results/trainingSAVPCH-6GC/

#include <vector>

int solution(int N, int M) {

    vector<bool> choco(N, true);
    int cnt = 0;

    int x = 0;
    while(x < N)
    {
        //Is Wrapper: STOP
        if (!choco[x])   break;

        //Eat Chocolate
        choco[x] = false;
        cnt++;

        //Next Chocolate index
        x = (x + M) % N;
    }

    return cnt;
}