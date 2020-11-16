#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#define INF 1e18
#define MAX 501
using namespace std;

long long dist[MAX];
vector<pair<int, int>> adj[MAX];

int main(void) {
	freopen("input.txt", "r", stdin);
	int N, M;
	scanf("%d %d", &N, &M);
	
	for (int i = 1; i <= M; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back(make_pair(b, c));
	}

	// ����-���� ���� //
	// k��° ���������� ���������κ��� �� �������� k���� ������ ���ļ� ������ �� �ִ� �ִܰ�θ� �� ���� //
	// 1. �ڷ� ���� �ʱ�ȭ
	bool minusCycle = false;
	fill(dist, dist + N + 1, INF);
	dist[1] = 0;

	// 2. ������ �ִ� ��δ� �ִ� (N-1)�� ���� ����
	//    (N-1) ���� + minusCycle ���� ���� Ȯ��
	for (int k = 1; k <= N; k++) {
		// 2-1. (N-1) ������ ���� �� ������ k�� ������ ���Ŀ��� �ִܰ�� ����
		for (int currNode = 1; currNode <= N; currNode++) {
			for (int j = 0; j < adj[currNode].size(); j++) {
				int nextNode = adj[currNode][j].first;
				int currToNextNodeDist = adj[currNode][j].second;
				// 2-2. currNode �� INF �̸� �ǹ̰� ����
				if (dist[currNode] != INF && dist[nextNode] > dist[currNode] + currToNextNodeDist) {
					dist[nextNode] = dist[currNode] + currToNextNodeDist;
					// 2-2. N��° ������ ���� ���ŵǸ� minusCycle ����
					if (k == N) minusCycle = true;
				}
			}
		}
	}
	if (minusCycle) puts("-1");
	else {
		for (int i = 2; i <= N; i++)
			printf("%lld\n", dist[i] != INF ? dist[i] : -1);
	}
}