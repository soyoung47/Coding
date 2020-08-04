/*
    Time Complexity:
    Result:::
    Reference:::
*/
#include <vector>
using namespace std;

//40%(https://app.codility.com/demo/results/training5J45DK-FJW/)
int solution(vector<int>& A) {

    vector<int> peak, dist;
    int max = 0;
    int size = A.size();

    if (size < 3)  return 0;

    //Find Peaks
    int front, back;
    for (int p = 1; p < size - 1; p++)
    {
        //Check first & last element
        //if (p == 0)    front = -1;
        //else if (p == size - 1)  back = -1;
        //else
        //{
        //    
        //}
        front = A[p - 1];
        back = A[p + 1];
        if (A[p] > front && A[p] > back)
            peak.push_back(p);
    }

    //Calculate Distance between two peaks
    for (int i = 1; i < peak.size(); i++)
    {
        dist.push_back(peak[i] - peak[i - 1]);
    }

    //Number of Max Flags
    for (int i = dist.size(); i > 0 ; i--)
    {
        int k = dist.size();
        int min = dist[i-1];
        int ind = i-1;
        for (int j = k-1; j >= 0; j--)
        {
            if (min > dist[j])
            {
                min = dist[j];
                ind = j;
            }
            if (dist[j] < k)
            {
                if (j > 0) dist[j - 1] += dist[j];
                dist.erase(dist.begin() + j);
            }

            if (j == 0)    return dist.size();
        }
    }

    return dist.size();
}

int main()
{
    vector<int> v = { 0, 0, 0, 0, 0, 1, 0, 1, 0, 1 };
    int a = solution(v);
}