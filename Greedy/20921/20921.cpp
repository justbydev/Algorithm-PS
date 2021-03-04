/*BOJ 20921*/
/*Greedy*/
/*�̹� ����� ���� ���� ���� ū ���� ���*/
/*N���� ���ڰ� �ִٸ� ���� ū ���� ���� �տ� �� �� ������ ����� ���� N-1��*/
/*���� �̷��� �ϴ� ���� N-1������ ũ�ٸ� ���� ū ���� ���� �տ�*/
/*���� �̷��� �ϴ� ���� N-1������ �۴ٸ� ���� ���� ���� ���� �տ�*/
/*���� �̷��� �ϴ� ���� N-1����� ���� ū �� �տ� �ΰ� �ڿ��� ���� �� ������������*/
#include<iostream>
#include<vector>
using namespace std;
int N, K;
vector<int> res;
int maximum, minimum;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	maximum = N;
	minimum = 1;
	if (K == 0) {
		for (int i = 1; i <= N; i++) {
			res.push_back(i);
		}
	}
	else {
		while (1) {
			if (K == 0) {
				break;
			}
			if (K > (N - 1)) {
				res.push_back(maximum);
				maximum -= 1;
				K -= (N - 1);
				N--;
			}
			else if (K == (N - 1)) {
				res.push_back(maximum);
				for (int i = minimum; i < maximum; i++) {
					res.push_back(i);
				}
				K = 0;
			}
			else if (K < (N - 1)) {
				res.push_back(minimum);
				minimum += 1;
				N--;
			}
		}
	}
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	return 0;
}