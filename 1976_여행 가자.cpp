#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int parent[201];

int getParent(int a){
	if (parent[a] == a) return a;
	else return parent[a] = getParent(parent[a]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return 1;
	else return 0;
}

int main() {
	freopen("input.txt", "r", stdin);
	int N, M;
	scanf("%d %d", &N, &M);

	//parent ÃÊ±âÈ­
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int adj;
			scanf("%d", &adj);
			if (adj) {
				unionParent(i, j);
			}
		}
	}

	int src; bool traveling = true;
	scanf("%d", &src);
	for (int i = 1; i <= M; i++) {
		int dst;
		scanf("%d", &dst);
		if (parent[src] != parent[dst]) {
			traveling = false; break;
		}
	}

	puts(traveling ? "YES" : "NO");
}