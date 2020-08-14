/*
    Time Complexity: O(Z * log(max(A) + max(B))**2)
    Result::: https://app.codility.com/demo/results/trainingV4FT86-FAB/
    Reference::: https://codility.com/media/train/10-Gcd.pdf, https://blog.naver.com/wideeyed/220859563821, https://blog.naver.com/simjy07/221800006275
*/

int findGCD(int a, int b)
{
    if (a % b == 0)
        return b;
    else
        return findGCD(b, a % b);
}

int solution(vector<int>& A, vector<int>& B) {

    int cnt = 0;

    for (int i = 0; i < A.size(); i++)
    {
        int a = A[i], b = B[i];

        if (a == b)
        {
            cnt++;
            continue;
        }

        //Find Greatest common divisor (최대공약수)
        int gcd = findGCD(A[i], B[i]);

        if (gcd == 1)  continue;

        //Quotient == 1 : include in GCD

        a /= gcd;
        while (a != 1)
        {
            int gcd_a = findGCD(a, gcd);
            if (gcd_a == 1)    break;
            a /= gcd_a;
        }

        b /= gcd;
        while (b != 1)
        {
            int gcd_b = findGCD(b, gcd);
            if (gcd_b == 1)    break;
            b /= gcd_b;
        }

        if (a == 1 && b == 1)    cnt++;

    }

    return cnt;
}