/*BOJ 13308*/
/*Dijkstra+DP*/
/*1. Dijkstra의 원리: minheap에서 먼저 나온 경우는 반드시 더 짧은 경우이기 때문에*/
/*                    DP 배열에 있는 것과 비교해서 더 크면 그냥 continue*/
/*2. DP의 설정을 어떤 걸로 하는지 매우 중요*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int N, M, st, ed, length;
int cost[2501];
typedef struct _info {
	int vertex;
	int length;
}info;
vector<info> graph[2501];
long long int dp[2501][2501];
//2번 정의: dp[i][j]=1부터 i까지 갈 때 들른 곳들 중 기름값의 최솟값이 j일때의 최소 비용
void gas_dijkstra(void) {
	priority_queue<pair<long long int, pair<int, int>>> minheap;
	minheap.push({ 0, {1, cost[1]} });
	while (!minheap.empty()) {
		pair<long long int, pair<int, int>> now = minheap.top();
		minheap.pop();
		long long int total = -now.first;
		int now_v = now.second.first;
		int now_mingas = now.second.second;
		if (dp[now_v][now_mingas]!=-1&&dp[now_v][now_mingas] < total) {//1번의 원리
			continue;
		}
		for (int i = 0; i < graph[now_v].size(); i++) {
			int next_v = graph[now_v][i].vertex;
			int next_l = graph[now_v][i].length;
			int next_mingas = min(now_mingas, cost[now_v]);
			if (dp[next_v][next_mingas] == -1 || dp[next_v][next_mingas] > total + next_l*next_mingas) {
				dp[next_v][next_mingas] = total + next_l * next_mingas;
				minheap.push({ -dp[next_v][next_mingas], {next_v, next_mingas} });
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> st >> ed >> length;
		graph[st].push_back({ ed, length });
		graph[ed].push_back({ st, length });
	}
	for (int i = 0; i <= 2500; i++) {
		for (int j = 0; j <= 2500; j++) {
			dp[i][j] = -1;
		}
	}
	dp[1][0] = 0;
	gas_dijkstra();
	long long int res = -1;
	for (int i = 1; i <= 2500; i++) {
		if (dp[N][i] == -1) {
			continue;
		}
		if (res == -1) {
			res = dp[N][i];
		}
		else {
			res = min(res, dp[N][i]);
		}
	}
	cout << res;
	return 0;
}