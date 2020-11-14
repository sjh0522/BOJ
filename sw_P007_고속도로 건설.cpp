#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int parent[50001];

int getParent(int a) {
	if (parent[a] == a) return a;
	else return parent[a] = getParent(parent[a]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main() {
	freopen("input.txt", "r", stdin);
	int test_case;
	scanf("%d", &test_case);
	for(int i=1; i<=test_case; i++){
	
	int N, M;
	scanf("%d %d", &N, &M);
	//N: 5 M: 8
	//printf("N: %d M: %d\n", N, M);

	vector<pair<int, pair<int, int> > > edges;
	for (int i = 0; i < M; i++) {
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		//printf("%d %d %d\n", a, b, w);
		edges.push_back({ w, {a,b} });
	}

	/*for (int i = 0; i < edges.size(); i++) {
		printf("edge[%d] : (%d, (%d, %d))\n", i, edges[i].first, edges[i].second.first, edges[i].second.second);
	}*/
	

	// kruskal 시작 //

	// 1. parent 초기화
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	// 2. edges 오름차순 정력
	sort(edges.begin(), edges.end());

	// 3. 간선 하나씩 확인
	int res = 0;
	for (int i = 0; i < edges.size(); i++) {
		int w = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;

		// cycle이 없을때만
		if (getParent(a) != getParent(b)) {
			//if (!findParent(a, b)) {
			unionParent(a, b);
			res += w;
		}
	}
	
	// 4. 결과
	printf("#%d %d", test_case, res);
	}
}