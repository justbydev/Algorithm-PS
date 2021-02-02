/*BOJ 11985*/
/*DP*/
/*total[i]=i��°���� �������� ���� ���� �ּڰ�*/
/*i��°���� ���� �� �ݵ�� i��° �������� �����Ͽ� j���� �� ���ڿ� ������*/
/*�׶��� ���� i��°���� j�� ���� ������ ��+dp[i-j]*/
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
		mx = mn = orange_size[i];//�� ���ڿ� ���� �� �ִ�, �ּ� ũ��
		for (int j = 1; j <= M; j++) {
			if (i - j < -1) {
				break;
			}
			if (i - j == -1) {//0~i��°���� �� ���ڿ� ��� ���
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