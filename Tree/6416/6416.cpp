/*BOJ 6416*/
/*tree*/
/*1. �� ���� tree*/
/*2. root�� �ݵ�� �Ѱ��� ����*/
/*3. cycle �������� ����*/
/*4. �� ��忡�� �ٸ� ������ ���� ���� �ݵ�� �Ѱ��� ����*/
/*map ����*/
/*map.find(key)==map.end()�̸� key���� ���� ��*/
/*for(auto it=map.begin(); it!=map.end(); it++)�� ���� map iterate*/
#include<iostream>
#include<map>
using namespace std;
int k=1, u, v;
typedef struct _info {
	int indegree;
	int outdegree;
}info;
map<int, info> tree;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int flag = 0;
	int not_tree = 0;
	int node_cnt = 0;
	while (1) {
		while (1) {
			cin >> u >> v;
			if (u < 0 && v < 0) {
				flag = 1;
				break;
			}
			if (u == 0 && v == 0) {
				int root = 0;
				for (auto it = tree.begin(); it != tree.end(); it++) {
					if (it->second.indegree == 0) {
						root++;
					}
				}
				if (root > 1) {//root�� 2�� �̻�->tree X
					not_tree = 1;
				}
				if (node_cnt != 0 && root == 0) {//root�� ���� ���->tree X
					not_tree = 1;
				}
				if (not_tree == 1) {
					cout << "Case " << k << " is not a tree." << "\n";
				}
				else {
					cout << "Case " << k << " is a tree." << "\n";
				}
				tree.clear();
				node_cnt = 0;
				not_tree = 0;
				k++;
			}
			else {
				node_cnt++;
				if (tree.find(u) == tree.end()) {
					tree[u] = { 0, 1 };
				}
				else {
					tree[u].outdegree++;
				}
				if (tree.find(v) == tree.end()) {
					tree[v] = { 1, 0 };
				}
				else {
					if (tree[v].indegree == 0) {
						tree[v].indegree = 1;
					}
					else {//������ ������ 2�� �̻�->cycle �����ϹǷ� tree X
						not_tree = 1;
						tree[v].indegree++;
					}
				}
			}
		}
		if (flag == 1) {
			break;
		}
	}
	return 0;
}