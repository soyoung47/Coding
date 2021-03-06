/*
    [solution 2]
    Time Complexity: O(N * log(log(N)))
    Result:::https://app.codility.com/demo/results/trainingZXVZVE-HRK/
    Reference::: http://dal4segno.github.io/algorithm/codility-10-primes-and-composite-numbers/
*/
int solution(vector<int>& A) {

    vector<int> peak;
    int size = A.size();

    if (size < 3)  return 0;

    //Find Peaks
    for (int p = 1; p < size - 1; p++)
    {
        if (A[p] > A[p - 1] && A[p] > A[p + 1])
            peak.push_back(p);
    }

    //Find Maximum number of blocks
    int peak_size = peak.size();
    if (peak_size < 2)   return peak_size;

    for (int k = peak_size; k > 0; k--)
    {
        if (size % k != 0) continue;

        int div_ind = size / k;
        int cnt = 0;
        for (int i = 0; i < peak_size; i++) //-> for(int p : peak), peak[i] -> p
        {
            if (peak[i] >= cnt * div_ind && peak[i] < (cnt + 1) * div_ind)
            {
                cnt++;
            }
        }

        if (cnt == k)   return cnt;
    }
}

/*
    [solution 1]
    Time Complexity: O(N * log(log(N)))
    Result:::https://app.codility.com/demo/results/training67H57R-MPD/
    Reference::: https://blog.naver.com/PostView.nhn?blogId=yeokyeong46&logNo=221600296267&parentCategoryNo=&categoryNo=7&viewDate=&isShowPopularPosts=false&from=postView
*/
int solution(vector<int>& A) {

    vector<int> peak;

    int size = A.size();

    if (size < 3)  return 0;

    //Find Peaks
    for (int p = 1; p < size - 1; p++)
    {
        if (A[p] > A[p - 1] && A[p] > A[p + 1])
            peak.push_back(p);
    }

    //Find Maximum number of blocks
    int peak_size = peak.size();
    if (peak_size < 2)   return peak_size;

    int max_div = 1;
    for (int k = max_div; k <= peak_size; k++)
    {
        if (size % k != 0) continue;

        int div_ind = size / k;
        int i = 1, j = 0;
        bool check = false;
        while (i <= k && j < peak_size)
        {
            if (peak[j] >= (i - 1) * div_ind && peak[j] < i * div_ind)
            {
                j++;
                check = true;
            }
            else
            {
                if (!check)  break;

                i++;
                check = false;
            }

            if (j >= peak_size && i < k)
            {
                check = false;
            }
        }

        if (check)
            max_div = k;
    }

    return max_div;
}


//{ 1, 4, 3, 4, 3, 2, 1, 2, 3, 4, 6, 2 };   //3
//{ 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 };   //1    
//{ 1, 2, 3, 4, 3, 4, 1, 2, 3, 4, 6, 2 };   //2
//{ 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0 };   //4
