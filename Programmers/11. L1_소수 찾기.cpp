#include <math.h>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v(n + 1);
    for (int k = 2; k <= n; k++)  v[k] = k;

    //�����佺�׳׽��� ü
    for (int i = 2; i <= sqrt(n); i++)   //i: ������ ��
    {
        if (v[i] == 0) continue;
        for (int j = i * 2; j <= n; j += i) //i �����ϰ� i��� ����
            v[j] = 0;
    }

    for (int z = 2; z <= n; z++)
    {
        if (v[z] != 0)
            answer++;
    }

    return answer;
}