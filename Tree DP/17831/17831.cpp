/*BOJ 17831*/
/*Tree DP*/
/*mentor==0: no mentor-mentee relationship*/
/*mentor==1: this is mentor*/
/*mentor==2: this is mentee*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, num;
int syn[200001];
int dp[200001][3];
vector<int> tree[200001];
int tree_dp(int now, int mentor) {
	if (dp[now][mentor] != -1) {
		return dp[now][mentor];
	}
	int ret = 0;
	if (mentor == 0) {
		for (int i = 0; i < tree[now].size(); i++) {
			int next = tree[now][i];
			ret += max(tree_dp(next, 0), tree_dp(next, 1));
		}
	}
	else if (mentor == 1) {
		int sm = 0;
		vector<int> temp;
		for (int i = 0; i < tree[now].size(); i++) {
			int next = tree[now][i];
			int tmp=max(tree_dp(next, 0), tree_dp(next, 1));
			temp.push_back(tmp);
			sm += tmp;
		}
		for (int i = 0; i < tree[now].size(); i++) {
			int next = tree[now][i];
			int mentee = syn[now] * syn[next] + tree_dp(next, 2);
			ret = max(ret, sm - temp[i] + mentee);
		}
	}
	else if (mentor == 2) {
		for (int i = 0; i < tree[now].size(); i++) {
			int next = tree[now][i];
			ret += max(tree_dp(next, 0), tree_dp(next, 1));
		}
	}
	return dp[now][mentor] = ret;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	dp[1][0] = dp[1][1] = dp[1][2] = -1;
	for (int i = 2; i <= N; i++) {
		cin >> num;
		tree[num].push_back(i);
		dp[i][0] = dp[i][1] = dp[i][2] = -1;
	}
	for (int i = 1; i <= N; i++) {
		cin >> syn[i];
	}
	tree_dp(1, 0);
	tree_dp(1, 1);
	int res = max(dp[1][0], dp[1][1]);
	if (res == -1) {
		cout << 0;
	}
	else {
		cout << res;
	}
	return 0;
}