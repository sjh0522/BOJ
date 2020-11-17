#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <vector>
#define MAX 32001
using namespace std;

vector<int> adj[MAX];
int inDegree[MAX];

int main(void) {
	freopen("input.txt", "r", stdin);
	int N, M;
	scanf("%d %d", &N, &M);

	// 0. �Է�
	for (int i = 1; i <= M; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		adj[s].push_back(e);
		// 0-1. ���� ���� ����
		inDegree[e]++;
	}

	// topology sort //
	// 1. ���� ���� 0 �� ��� queue�� ����
	vector<int> result;
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) q.push(i);
	}

	// 2. N��� ��� Ž��
	for (int i = 1; i <= N; i++) {
		// 2-1. queue�� ��� cycle�߻��Ͽ� ����
		if (q.empty()) break;

		// 2-2. queue���� ���� ���� ���� �� result�� ����
		int currnode = q.front(); q.pop();
		result.push_back(currnode);

		// 2-3. adj ��� Ž��
		for (int j = 0; j < adj[currnode].size(); j++) {
			int nextnode = adj[currnode][j];
			if (--inDegree[nextnode] == 0) q.push(nextnode);
		}
	}

	// 3. ���
	for (int i = 0; i < result.size(); i++) {
		printf("%d ", result[i]);
	}

}