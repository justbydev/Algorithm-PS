/*BOJ 2637*/
/*topological sort*/
/*using of map*/
/*using of vector<map>*/
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
int N, M, X, Y, K;
int indegree[101];
typedef struct _info {
	int number;
	int cnt;
}info;
vector<info> product[101];
vector<map<int, int>> res[101];
void topological_sort(void) {
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < product[now].size(); i++) {
			int number = product[now][i].number;
			int cnt = product[now][i].cnt;
			indegree[number]--;
			if (indegree[number] == 0) {
				q.push(number);
			}
			if (res[now].size() == 0) {
				if (res[number].size() == 0) {
					map<int, int> mp;
					mp[now] = cnt;
					res[number].push_back(mp);
				}
				else {
					res[number][0][now] = cnt;
				}
			}
			else {
				if (res[number].size() == 0) {
					map<int, int> mp;
					map<int, int> now_map = res[now][0];
					for (auto it = now_map.begin(); it != now_map.end(); it++) {
						int key = it->first;
						int value = it->second;
						mp[key] = value * cnt;
					}
					res[number].push_back(mp);
				}
				else {
					map<int, int> now_map = res[now][0];
					for (auto it = now_map.begin(); it != now_map.end(); it++) {
						if (res[number][0][it->first]) {
							res[number][0][it->first] += (it->second) * cnt;
						}
						else {
							res[number][0][it->first] = (it->second) * cnt;
						}
					}
				}
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		indegree[i] = 0;
	}
	for (int i = 0; i < M; i++) {
		cin >> X >> Y >> K;
		product[Y].push_back({ X, K });
		indegree[X]++;
	}
	topological_sort();
	map<int, int> r = res[N][0];
	for (auto it = r.begin(); it != r.end(); it++) {
		cout << it->first << " " << it->second << "\n";
	}
	return 0;
}