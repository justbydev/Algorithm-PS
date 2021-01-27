/*BOJ 2212*/
/*Greedy*/
/*인접한 센서들의 길이를 측정하여 그 중 긴 순서대로 K-1개 제거*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, K;
int num;
vector<int> locate;
vector<int> length;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	cin >> K;
	for (int i = 0; i < N; i++) {
		cin >> num;
		locate.push_back(num);
	}
	if (N <= K) {
		cout << 0;
	}
	else {
		sort(locate.begin(), locate.end());
		for (int i = 0; i < N - 1; i++) {
			length.push_back(locate[i + 1] - locate[i]);
		}
		sort(length.begin(), length.end());
		int res = 0;
		for (int i = 0; i < N - K; i++) {
			res += length[i];
		}
		cout << res;
	}
	return 0;
}