/*BOJ 8972*/
/*simulation*/
/*정상 움직임->미친 것 다음 움직인 저장->map 좌표 다시 찍으면서 2번이상 찍는 것 bump에 저장*/
/*->bump에 저장된 것 map 좌표 다시 '.'으로 바꿈*/
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
int R, C;
char map[100][100];
int myx, myy;
int dx[9] = { 1, 1, 1, 0, 0, 0, -1, -1, -1 };
int dy[9] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };
typedef struct _info {
	int x;
	int y;
}info;
vector<info> crazy;
vector<info> crazy_nxt;
vector<info> bump;
string MV;
int move(void) {
	for (int i = 0; i < MV.length(); i++) {
		int now = (MV[i] - '0') - 1;
		int beforex = myx;
		int beforey = myy;
		myx += dx[now]; myy += dy[now];
		map[beforex][beforey] = '.';
		for (int j = 0; j< crazy.size(); j++) {
			int nowx = crazy[j].x, nowy = crazy[j].y;
			if (map[nowx][nowy]=='R') {
				if (myx == nowx && myy == nowy) {
					return i + 1;
				}
				int nx = nowx + dx[0], ny = nowy + dy[0];
				int dist = abs(myx - nx) + abs(myy - ny);
				for (int k = 1; k <= 8; k++) {
					if (k == 4) {
						continue;
					}
					int tmpx = nowx + dx[k], tmpy = nowy + dy[k];
					int tmp = abs(tmpx - myx) + abs(tmpy - myy);
					if (tmp < dist) {
						dist = tmp;
						nx = tmpx; ny = tmpy;
					}
				}
				if (myx == nx && myy == ny) {
					return i + 1;
				}
				map[nowx][nowy] = '.';
				crazy_nxt.push_back({ nx, ny });
				crazy[j].x = nx; crazy[j].y = ny;
			}
		}
		map[myx][myy] = 'I';
		for (int j = 0; j < crazy_nxt.size(); j++) {
			if (map[crazy_nxt[j].x][crazy_nxt[j].y] == 'R') {
				bump.push_back({ crazy_nxt[j].x, crazy_nxt[j].y });
			}
			else {
				map[crazy_nxt[j].x][crazy_nxt[j].y] = 'R';
			}
		}
		for (int j = 0; j < bump.size(); j++) {
			map[bump[j].x][bump[j].y] = '.';
		}
		crazy_nxt.clear();
		bump.clear();
	}
	return -1;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'I') {
				myx = i; myy = j;
			}
			else if (map[i][j] == 'R') {
				crazy.push_back({ i, j});
			}
		}
	}
	cin >> MV;
	int cnt = move();
	if (cnt == -1) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cout << map[i][j];
			}
			cout << "\n";
		}
	}
	else {
		cout << "kraj " << cnt << "\n";
	}
	return 0;
}