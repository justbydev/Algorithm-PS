/*BOJ 2779*/
/*DP*/
/*compare string*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int T, N;
string sentence, input;
vector<string> letter;
int dp[50];
int alpha_letter[26];
int alpha_sub[26];
int cal_cost(string letter, string sub) {
	int cnt = 0;
	for (int i = 0; i < 26; i++) {
		alpha_letter[i] = 0;
		alpha_sub[i] = 0;
	}
	for (int i = 0; i < letter.length(); i++) {
		if (letter[i] != sub[i]) {
			cnt++;
		}
		alpha_letter[letter[i] - 'a']++;
		alpha_sub[sub[i] - 'a']++;//�Ǽ�2-�� string�� ����ִ� ���ĺ� ������ ��� ������ ���ؾ� �ϴµ� �׳� ���ĺ� ���� ���ηθ� ����
	}
	for (int i = 0; i < 26; i++) {
		if (alpha_letter[i] != alpha_sub[i]) {
			return -1;
		}
	}
	return cnt;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> sentence;
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> input;
			letter.push_back(input);
		}
		for (int j = 0; j < sentence.length(); j++) {
			dp[j] = 100;
		}
		for (int j = 0; j < sentence.length(); j++) {
			int sent_end_idx = j;
			for (int k = 0; k < letter.size(); k++) {
				int length = letter[k].length();
				int sent_st_idx = sent_end_idx - length + 1;
				if (sent_st_idx < 0) {
					continue;
				}
				if (sent_st_idx != 0 && dp[sent_st_idx - 1] >= 100) {//�� �ܾ ������ �߰����� ���ϰ� �Ǵµ� �� �������� ���� ���
					continue;//ex) ����=abcde �̰� ���� �ܾ dc�ε� abcde�� cd�� ���ϴ� ��� �� �� ab�� ���� �� �ִ� ��찡 �־�� �ϴµ� ���� ���
				}
				string sub = sentence.substr(sent_st_idx, length);
				int cost = cal_cost(letter[k], sub);
				if (cost != -1) {
					if (sent_st_idx == 0) {//�� �ܾ ������ ó������ ���ϴ� ���
						dp[j] = min(dp[j], cost);//�̷� �ܾ���� ���� �� ���� �� ����->�Ǽ�1
					}
					else {
						dp[j] = min(dp[j], cost + dp[sent_st_idx - 1]);
					}
				}
			}
		}
		if (dp[sentence.length()-1] >= 100) {
			cout << -1 << "\n";
		}
		else {
			cout << dp[sentence.length()-1] << "\n";
		}
		letter.clear();
	}
	return 0;
}