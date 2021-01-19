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
		alpha_sub[sub[i] - 'a']++;//실수2-각 string에 들어있는 알파벳 각각의 모든 개수로 비교해야 하는데 그냥 알파벳 존재 여부로만 비교함
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
				if (sent_st_idx != 0 && dp[sent_st_idx - 1] >= 100) {//그 단어가 문장의 중간부터 비교하게 되는데 그 이전값이 없는 경우
					continue;//ex) 문장=abcde 이고 현재 단어가 dc인데 abcde의 cd와 비교하는 경우 그 앞 ab를 만들 수 있는 경우가 있어야 하는데 없는 경우
				}
				string sub = sentence.substr(sent_st_idx, length);
				int cost = cal_cost(letter[k], sub);
				if (cost != -1) {
					if (sent_st_idx == 0) {//그 단어가 문장의 처음부터 비교하는 경우
						dp[j] = min(dp[j], cost);//이런 단어들이 여러 개 있을 수 있음->실수1
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