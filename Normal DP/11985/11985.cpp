/*BOJ 11985*/
/*DP*/
/*total[i]=i번째까지 오렌지를 담을 때의 최솟값*/
/*i번째까지 담을 때 반드시 i번째 오렌지를 포함하여 j개를 한 상자에 담으면*/
/*그때의 값은 i번째에서 j개 담은 상자의 값+dp[i-j]*/
#include<iostream>
#include<algorithm>
using namespace std;
long long int N, M, K;
long long int orange_size[20000];
long long total[20000];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i< N; i++) {
		cin >> orange_size[i];
		total[i] = -1;
	}
	total[0] = K;
	for (int i = 1; i < N; i++) {
		long long int mx, mn;
		mx = mn = orange_size[i];//한 상자에 담을 때 최대, 최소 크기
		for (int j = 1; j <= M; j++) {
			if (i - j < -1) {
				break;
			}
			if (i - j == -1) {//0~i번째까지 한 상자에 담는 경우
				total[i] = min(total[i], K + (mx - mn)*j);
			}
			if (total[i] == -1) {
				total[i] = K + (mx - mn)*j + total[i - j];
			}
			else {
				total[i] = min(total[i], K + (mx - mn)*j + total[i - j]);
			}
			mx = max(mx, orange_size[i - j]);
			mn = min(mn, orange_size[i - j]);
		}
	}
	cout << total[N - 1];
	return 0;
}