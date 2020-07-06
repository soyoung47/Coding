#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;

    if (arr.size() == 1)
        answer.push_back(-1);
    else
    {
        int min = arr[0];
        int ind = 0;
        for (int i = 1; i < arr.size(); i++)
        {
            if (min > arr[i])
            {
                min = arr[i];
                ind = i;
            }
        }
        arr.erase(arr.begin() + ind);
        answer = arr;
    }
    return answer;
}