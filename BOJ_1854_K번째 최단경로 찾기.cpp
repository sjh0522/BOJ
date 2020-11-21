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
	
	// 0. 입력
	for (int i = 1; i <= M; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back(make_pair(v, w));
	}
	
	// 다익스트라 //
	// 1. 초기화
	// 1-1. 시작점 pq에 삽입
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, 1));
	dist[1].push(0);

	// 2. queue 빌 때까지
	while (!pq.empty()) {
		// 2-1. curr 노드 pq에서 꺼냄
		int currnode = pq.top().second;
		int distToCurrnode = -pq.top().first;
		pq.pop();

		// 2-2. skip 조건
		if (dist[currnode].top() < distToCurrnode) continue;

		// 2-3. adj 탐색
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


	// 3. 출력
	for (int i = 1; i <= N; i++) {
		if (dist[i].size() < K)printf("-1\n");
		else printf("%d\n", dist[i].top());
	}
}