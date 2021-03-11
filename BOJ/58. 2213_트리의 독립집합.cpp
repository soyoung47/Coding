//https://www.acmicpc.net/problem/2213
//108308KB, 1592ms

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> edge;	//edge[정점][정점]
vector<vector<int>> dp;	//dp[정점][독립집합 포함여부]
vector<int> w;	//가중치

void go(int cur)
{
	dp[cur][0] = 0, dp[cur][1] = w[cur];

	for (int next : edge[cur])
	{
		if (dp[next][0] == -1)
		{
			go(next);
			dp[cur][0] = max(dp[next][1], w[next]);	//포함하지 않는 경우
			dp[cur][1] = dp[next][0] + w[cur];	//포함하는 경우
		}			
	}
}

int main()
{
	int n, u, v;
	cin >> n;

	w.resize(n + 1, 0);
	edge.resize(n + 1);
	dp.assign(n + 1, vector<int>(2, -1));

	for (int i = 0; i < n; i++)
		cin >> w[i];

	for (int i = 1; i < n; i++)
	{
		cin >> u >> v;
		edge[u].emplace_back(v);
		edge[v].emplace_back(u);
	}

	go(1);

	cout << max(dp[n][0], dp[n][1]);
}