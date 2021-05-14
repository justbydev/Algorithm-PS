/*BOJ 2879*/
/*Divide and conquer*/
/*Greedy*/
/*�ᱹ �׷� ���� �� �ִ� ���� ���������� ���ϴ� intent ������ ũ�ų� �����͵�*/
/*�׷��� ��� �׷� ��� ��°�� ���̴� greedy ��� ���*/
/*����, ���ÿ����� ..234..�� ..110..���� ����� ���� 234�� �׷����� �׷��� ���������� ���� ������*/
/*���� ..324..�� ..110..���� ����� �ʹٸ� divide and conquer�� ����ؾ� �Ѵ�.*/
/*��, ���� ..324..�� 2�� ���� �۱� ������ ..213..�� �Ǵµ� ���� 1�� �������� ..2, 3..���� �������� �ȴ�*/
/*�׷��� ..2�� ���ؼ� �ѹ�, 3..�� ���ؼ� �ѹ� �ؼ� ������ ����� ���ϸ� ..324..�� ���� ���� ����� ���´�*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int input;
vector<int> intent;
vector<int> want;
int divide(int st, int ed) {
	int res = 0;
	int idx = st;
	if (st == ed) {
		if (intent[st] == want[st]) {
			return 0;
		}
		else if (intent[st] > want[st]) {
			return intent[st] - want[st];
		}
		else {
			return want[st] - intent[st];
		}
	}
	while (1) {
		if (idx > ed) {
			break;
		}
		if (intent[idx] == want[idx]) {//���� ��� �۾� �ʿ� ����
			idx++;
		}
		else if (intent[idx] > want[idx]) {//�ٿ��� �ϴ� ���
			int gap = intent[idx] - want[idx];
			int start = idx;
			int min_idx = idx;
			int end = idx;
			idx++;
			while (1) {
				if (idx > ed) {
					end = ed;
					break;
				}
				if (intent[idx] <= want[idx]) {
					end = idx - 1;
					break;
				}
				if (intent[idx] - want[idx] < gap) {//�ٿ��� �ϴ� ������ ���� ���� ���� �߽����� �������� divide�� ����
					gap = intent[idx] - want[idx];
					min_idx = idx;
				}
				idx++;
			}
			if (start == end) {
				intent[start] -= gap;
				res += gap;
			}
			else {
				for (int i = start; i <= end; i++) {
					intent[i] -= gap;
				}
				res += gap;
				res += divide(start, min_idx - 1);//�ٿ��� �ϴ� ������ ���� ������ �� �߽����� ����
				res += divide(min_idx + 1, end);//�ٿ��� �ϴ� ������ ���� ������ �� �߽����� ������
				//�� �� �κ��� divide and conquer
			}
		}
		else if (intent[idx] < want[idx]) {//�÷��� �ϴ� ���
			int gap = want[idx] - intent[idx];
			int start = idx;
			int min_idx = idx;
			int end = idx;
			idx++;
			while (1) {
				if (idx > ed) {
					end = ed;
					break;
				}
				if (intent[idx] >= want[idx]) {
					end = idx - 1;
					break;
				}
				if (want[idx] - intent[idx] < gap) {//�÷��� �ϴ� ������ ���� ���� ���� �߽����� �������� divide�� ����
					gap = want[idx] - intent[idx];
					min_idx = idx;
				}
				idx++;
			}
			if (start == end) {
				intent[start] += gap;
				res += gap;
			}
			else {
				for (int i = start; i <= end; i++) {
					intent[i] += gap;
				}
				res += gap;
				res += divide(start, min_idx - 1);//�÷��� �ϴ� ������ ���� ���� ���� ����
				res += divide(min_idx + 1, end);//�÷��� �ϴ� ������ ���� ���� ���� ������
				//��, �̰��� divide and conquer
			}
		}
	}
	return res;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		intent.push_back(input);
	}
	for (int i = 0; i < N; i++) {
		cin >> input;
		want.push_back(input);
	}
	cout << divide(0, N - 1);
	return 0;
}