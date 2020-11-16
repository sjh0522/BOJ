#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#define MAX 20001
#define INF 1000000000
using namespace std;

vector<pair<int, int>> adj[MAX];
int dist[MAX];

void dijkstra(int start) {
	// 2-1. pq ����, start ��� pq�� ����
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	dist[start] = 0;

	// dijkstra Ž�� ����
	while (!pq.empty()) {
		// 2-2. curr ������ ����
		int currNode = pq.top().second;
		int distAtCurrNode = -pq.top().first;
		pq.pop();

		// 2-3. curr ������ dist�� ���ݱ��� ã�� curr �� dist���� ũ�� skip
		if (dist[currNode] < distAtCurrNode) continue;

		// 2.4 curr�� adj ��� Ž��
		for (int j = 0; j < adj[currNode].size(); j++) {
			int nextNode = adj[currNode][j].first;
			int currToNextDist = adj[currNode][j].second;

			// 2-5. curr -> nextNode ��ΰ� �� ª�� ���
			if (dist[nextNode] > dist[currNode] + currToNextDist) {
				dist[nextNode] = dist[currNode] + currToNextDist;
				pq.push(make_pair(-dist[nextNode], nextNode));
			}
		}
	}
}

int main(void) {
	freopen("input.txt", "r", stdin);
	int V, E, K;
	scanf("%d %d %d", &V, &E, &K);
	//printf("%d %d %d\n", V, E, K);
	
	for (int i = 1; i <= E; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		//printf("%d %d %d\n", u, v, w);
		adj[u].push_back(make_pair(v, w));
	}
	
	// dijkstra ���� //
	// 1. ��� ���� �迭 �ʱ�ȭ
	fill(dist, dist + V + 1, INF);

	// 2. dijkstra
	dijkstra(K);

	// 3. ���
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) printf("INF\n");
		else printf("%d\n", dist[i]);
	}
}