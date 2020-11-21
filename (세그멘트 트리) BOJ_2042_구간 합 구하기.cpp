#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#define MAX 1000000
typedef long long ll;

int N, M, K;
ll tree[MAX * 4];

void update(int treeIndex, int start, int end, int index, ll val) {
	// 1. 종료조건
	if (index < start || end < index) return;
	if (start == end) {
		tree[treeIndex] = val; return;
	}
	
	// 2. segment tree update 재귀호출 반복
	int mid = (start + end) / 2;
	update(treeIndex * 2, start, mid, index, val);
	update(treeIndex * 2 + 1, mid + 1, end, index, val);

	// 3. leaf 노드부터 update
	tree[treeIndex] = tree[treeIndex * 2] + tree[treeIndex * 2 + 1];
	return;
}

ll sum(int treeIndex, int start, int end, int left, int right) {
	// 1. 종료조건
	if (right < start || end < left) return 0;
	else if (left <= start && end <= right) return tree[treeIndex];

	// 2. segment tree sum 재귀호출 반복
	int mid = (start + end) / 2;
	return sum(treeIndex * 2, start, mid, left, right) + 
		   sum(treeIndex * 2 + 1, mid + 1, end, left, right);
}

int main(void) {
	freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &N, &M, &K);

	// 0. 입력
	for (int i = 0; i < N; i++) {
		ll val;
		scanf("%lld", &val);
		update(1, 0, N - 1, i, val);
	}

	// 1. 결과
	for (int i = 0; i < M + K; i++) {
		int question, b, c;
		scanf("%d %d %d", &question, &b, &c);		
		if (question==1) update(1, 0, N - 1, b - 1, c);
		else if (question==2) printf("%lld\n", sum(1, 0, N - 1, b - 1, c - 1));
	}
}
