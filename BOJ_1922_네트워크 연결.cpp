#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;

vector<pair<int, pair<int, int>>> edges;
int parent[MAX];

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

int main(void) {
	freopen("input.txt", "r", stdin);
	int n, m;
	scanf("%d %d", &n, &m);

	// 0. 입력
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		edges.push_back(make_pair(w, make_pair(u, v)));
	}

	// kruskal //
	// 1. parent 초기화
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	// 2. edges 오름차순 정렬
	sort(edges.begin(), edges.end());

	// 3. edges 하나씩 탐색
	int res = 0;
	for (int i = 0; i < edges.size(); i++) {
		int w = edges[i].first;
		int u = edges[i].second.first;
		int v = edges[i].second.second;

		// parent가 다를때만
		if (getParent(u) != getParent(v)) {
			unionParent(u, v);
			res += w;
		}
	}
	printf("%d", res);
}
