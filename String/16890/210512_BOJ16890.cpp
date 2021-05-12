/*BOJ 16890*/
/*string*/
/*string ����� front=front+new �̷��� �ϸ� �ð��ʰ� �߻�*/
/*string ����� front+=new �̷��� �ؾ� �ð��ʰ� �߻����� ����*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string koo, cube;
int N;
string front, back;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> koo >> cube;
	sort(koo.begin(), koo.end());//������� ������ ���� ���� ���ϹǷ� ��������
	sort(cube.begin(), cube.end(), greater<>());//ť�귯���� ������ ���� ���� ���ϹǷ� ��������
	int N = koo.size();
	front = "";
	back = "";
	int koo_fidx, cube_fidx, koo_bidx, cube_bidx;
	koo_fidx = cube_fidx  = 0;
	koo_bidx = (N + 1) / 2 - 1;//����� ���� ���� ������ �������� ��� �տ������� (N+1)/2�� ��ŭ ���
	cube_bidx = N / 2 - 1;//ť�귯���� �������� ��� �տ������� N/2����ŭ ���
	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {//�����
			if (koo.at(koo_fidx) < cube.at(cube_fidx)) {//������� ���� ���� ���ڰ� ť�귯���� ���� ū ���ں��� ������ �ִ��� ������
				front += koo.at(koo_fidx); koo_fidx++;
			}
			else {//������� ���� ���� ���ڰ� ť�귯���� ���� ū ���ں��� ũ�ų� ������ �ִ��� �ڷ�
				back = koo.at(koo_bidx) + back; koo_bidx--;
			}
		}
		else {//ť�귯��
			if (cube.at(cube_fidx) > koo.at(koo_fidx)) {//ť�귯���� ���� ū ���ڰ� ������� ���� ���� ���ں��� ũ�� �ִ��� ������
				front += cube.at(cube_fidx); cube_fidx++;
			}
			else {//ť�귯���� ���� ū ���ڰ� ������� ���� ���� ���ں��� �۰ų� ������ �ִ��� �ڷ�
				back = cube.at(cube_bidx) + back; cube_bidx--;
			}
		}
	}
	cout << front << back;
	return 0;
}