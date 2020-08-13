/*
    Time Complexity:
    Result::: 69% - https://app.codility.com/demo/results/trainingU8J2W9-WSE/
    Reference::: https://codility.com/media/train/10-Gcd.pdf
*/

int gcd(int a, int b)
{
    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

int solution(vector<int>& A, vector<int>& B) {

    int cnt = 0;

    for (int i = 0; i < A.size(); i++)
    {
        //Find min, max
        int min = A[i], max = B[i];
        if (A[i] > B[i])    swap(min, max);

        //Find Greatest common factor (최대공약수) : Greatest common divisor
        int gcf = gcd(max, min);

        //Is Same?
        if (min % (max / gcf) == 0)
            cnt++;

    }

    return cnt;
}
