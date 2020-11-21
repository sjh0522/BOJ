#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <vector>
#define MAX 1001
using namespace std;

int N, M, K;
vector<pair<int, int>> adj[MAX];
priority_queue<int> dist[MAX];

int main(void) {
	freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &N, &M, &K);
	
	// 0. �Է�
	for (int i = 1; i <= M; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back(make_pair(v, w));
	}
	
	// ���ͽ�Ʈ�� //
	// 1. �ʱ�ȭ
	// 1-1. ������ pq�� ����
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, 1));
	dist[1].push(0);

	// 2. queue �� ������
	while (!pq.empty()) {
		// 2-1. curr ��� pq���� ����
		int currnode = pq.top().second;
		int distToCurrnode = -pq.top().first;
		pq.pop();

		// 2-2. skip ����
		if (dist[currnode].top() < distToCurrnode) continue;

		// 2-3. adj Ž��
		for (int j = 0; j <= adj[currnode].size(); j++) {
			int nextnode = adj[currnode][j].first;
			int distFromCurrToNext = adj[currnode][j].second;
			int distToNextnode = distToCurrnode + distFromCurrToNext;

			if (dist[nextnode].size() < K) {
				dist[nextnode].push(distToNextnode);
				pq.push(make_pair(-distToNextnode, nextnode));
				continue;				
			}
			if (dist[nextnode].top() > distToNextnode) {
				dist[nextnode].push(distToNextnode);
				dist[nextnode].pop();
				pq.push(make_pair(-distToNextnode, nextnode));
			}
		}




	}


	// 3. ���
	for (int i = 1; i <= N; i++) {
		if (dist[i].size() < K)printf("-1\n");
		else printf("%d\n", dist[i].top());
	}
}