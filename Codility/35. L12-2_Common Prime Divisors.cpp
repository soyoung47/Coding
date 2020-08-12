/*
    Time Complexity: O(Z * (max(A) + max(B)))
    Result::: 53% - https://app.codility.com/demo/results/trainingU7BKHF-B9J/
    Reference:::
*/
using namespace std;

#include <vector>
#include <math.h>
#include <algorithm>

int solution(vector<int>& A, vector<int>& B) {

    int cnt = 0;

    for (int i = 0; i < A.size(); i++)
    {
        //Find min, max
        int min = A[i], max = B[i];
        if (A[i] > B[i])    swap(min, max);

        //Find divisor(min의 약수)
        vector<int> div;
        for (int i = 1; i <= sqrt(min); i++)
        {
            if (min % i == 0)
            {
                div.push_back(i);
                if (i != sqrt(min))
                    div.push_back(min / i);
            }
        }
        sort(div.begin(), div.end());

        //Find Greatest common factor (최대공약수)
        int gcf = 0;
        for (int i = div.size() - 1; i >= 0; i--)
        {
            if (min % div[i] == 0 && max % div[i] == 0)
            {
                gcf = div[i];
                break;
            }
        }

        //Is Same?
        if (min % (max / gcf) == 0)
            cnt++;
    }

    return cnt;
}
