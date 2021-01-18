/*BOJ 2825*/
/*bit mask*/
/*��� ���ڸ� 0~9�� 10�ڸ��� �̷���� �������� ǥ�� ����*/
/*�̷��� ��ȯ�� ���� �ִ� 1023*/
/*�Է¹޴� ���� ������ 10^18�̱⿡ long long int �ʿ�*/
/*���� ���� N<=1000000�̱� ������ int ���� �Ѿ ���ɼ� ����*/
/*���� ���� ���� long long int*/
/*�߰� �߰� ���� long long int ĳ���� ���ϸ�*/
/*�߰����� int ���� �Ѿ�� ���� overflow ���ܼ� �̻��� ���� ���� ������*/
/*���� �߻��ϹǷ� ���� �� ������ �߰� ���鵵 ���� long long int ĳ���� �ʿ�*/
#include<iostream>
using namespace std;
int num[1024];
int N;
long long int input;
int change_to_tenbit(long long int now) {
	int ret = 0;
	while (1) {
		if (now <= 0) {
			break;
		}
		int now_digit = (1 << (now % 10));
		if (!(ret&now_digit)) {
			ret += now_digit;
		}
		now = now / 10;
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	for (int i = 0; i <= 1023; i++) {
		num[i] = 0;
	}
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> input;
		num[change_to_tenbit(input)]++;
	}
	long long int res = 0;
	for (int i = 1; i <= 1023; i++) {
		if (num[i]) {
			res += (long long int)num[i] * (long long int)(num[i] - 1) / 2;
			for (int j = i + 1; j <= 1023; j++) {
				if (num[j] && (i&j)) {
					res += (long long int)num[i] * (long long int)num[j];
				}
			}
		}
	}
	cout << res;
	return 0;
}