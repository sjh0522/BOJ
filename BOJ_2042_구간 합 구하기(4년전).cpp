#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#define MAX 1000000
using namespace std;
typedef long long ll;

long long tree[MAX * 4];
int N, M, K;

void update(int treeIndex, int start, int end, int arrIndex, int val) {
	// 1. 종료조건
	if (arrIndex < start || end < arrIndex) return;	
	if (start == end) {
		tree[treeIndex] = val; return;		
	}

	// 2. 좌/우 나눠서 말단 값 구하러 update 호출
	int mid = (start + end) / 2;
	update(treeIndex * 2, start, mid, arrIndex, val);
	update(treeIndex * 2 + 1, mid + 1, end, arrIndex, val);

	// 3. tree값 update
	tree[treeIndex] = tree[treeIndex * 2] + tree[treeIndex * 2 + 1];
	return;
}

ll sum(int treeIndex, int start, int end, int left, int right) {
	// 1. 종료조건
	if (right < start || end < left) return 0;
	if (left <= start && end <= right) return tree[treeIndex];

	// 2. 좌/우 나눠서 sum 연산
	int mid = (start + end) / 2;
	return sum(treeIndex * 2, start, mid, left, right) + sum(treeIndex * 2 + 1, mid + 1, end, left, right);
}


int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &N, &M, &K);

	// 0. 입력
	for (int i = 0; i < N; i++) {
		int val;
		scanf("%d", &val);
		update(1, 0, N - 1, i, val);
	}

	// 1. 결과
	for (int i = 0; i < M + K; i++) {
		int question, b, c;
		scanf("%d %d %d", &question, &b, &c);
		if (question==1) update(1, 0, N - 1, b - 1, c);
		else if(question==2) printf("%lld\n",sum(1, 0, N - 1, b - 1, c - 1));
	}
}