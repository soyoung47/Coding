//https://www.acmicpc.net/problem/2248
//


//dp[][] 이차배열 사용
//메모리 초과
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int countOne(int num)
{
	int cnt = 0;
	while (num != 0)
	{
		num &= num - 1;
		cnt++;
	}

	return cnt;
}

int main()
{
	int n, l, ind;
	cin >> n >> l >> ind;

	vector<int> v;

	int num = 0;
	while (1)
	{
		if (v.size() == ind)	break;

		if (countOne(num) <= l)
			v.emplace_back(num);

		num += 1;
	}

	//이진수로 변환
	int tmp = v.back();
	string ans = to_string(tmp % 2);
	while (tmp /= 2)
	{
		ans = to_string(tmp % 2) + ans;
	}

	cout << ans;
}


//(bit operation)ref:::https://kylog.tistory.com/6
//int countOne(int num)
//{
//	int cnt = 0;
//	while (num != 0)
//	{
//		num &= num - 1;
//		cnt++;
//	}
//
//	return cnt;
//}


//0		0
//1		1
//--------
//10	1	
//11	2
//--------
//100	1
//101	2
//110	2
//111	3
//--------
//1000	1
//1001	2
//1010	2
//1011	3
//1100	2
//1101	3	
//1110	3
//1111	4

////메모리 초과
//
//#include <iostream>
//#include <vector>
//#include <math.h>
//#include <string>
//using namespace std;
//
//int main()
//{
//	int n, l, ind;
//	cin >> n >> l >> ind;
//
//	vector<int> one = { 0,1 };
//	vector<int> v = { 0, 1 };
//
//	for (int i = 1; i < n; i++)
//	{
//		for (int j = 0; j < pow(2, i); j++)
//		{
//			int cnt = one[j] + 1;
//			one.emplace_back(cnt);
//			if (cnt <= l)
//			{
//				v.emplace_back(pow(2, i) + j);
//				if (v.size() == ind)
//				{
//					i = n + 1;
//					break;
//				}
//			}
//		}
//	}
//
//	//이진수로 변환
//	int tmp = v[ind];
//	string ans = to_string(tmp % 2);
//	while (tmp /= 2)
//	{
//		ans = to_string(tmp % 2) + ans;
//	}
//
//	cout << ans;
//}