//https://www.acmicpc.net/problem/2110

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, C;
	cin >> N >> C;

	vector<long long> house(N, 0);
	for (int i = 0; i < N; i++)
		cin >> house[i];

	sort(house.begin(), house.end());

	long long start = 0, end = house.back() - house[0], mid, max = 0;

	while (start <= end)
	{
		mid = (start + end) / 2;

		//공유기 설치
	}

	cout << max;
}