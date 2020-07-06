#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int sum = 0;
    int n = x;

    while (n)
    {
        sum += n % 10;
        n /= 10;
    }

    printf("%d", sum);

    if (x % sum != 0) return false;
    else return true;
}