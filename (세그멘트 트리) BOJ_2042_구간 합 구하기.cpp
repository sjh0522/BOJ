#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#define MAX_N 1000001
#define ll long long
using namespace std;

int arry[MAX_N];
ll tree[MAX_N * 4];

void update(int treeIndex, int arryStart, int arryEnd, int arryIndex, ll updateVal) {
	// 1. 종료조건
	if (arryIndex < arryStart || arryEnd < arryIndex) {
		return;
	}
	if (arryStart == arryEnd) {
		tree[treeIndex] = updateVal;
		return;
	}

	// 2. segment tree update 재귀호출 반복
	int arryMid= (arryStart + arryEnd) / 2;
	update(treeIndex * 2, arryStart, arryMid, arryIndex, updateVal);
	update(treeIndex * 2+1, arryMid +1, arryEnd, arryIndex, updateVal);

	// 3. tree 값 갱신
	tree[treeIndex] = tree[treeIndex*2] + tree[treeIndex*2 + 1];
}

ll sum(int treeIndex, int arryStart, int arryEnd, int left, int right) {
	// 1. 종료조건
	if (right < arryStart || arryEnd < left) return 0;
	else if(left <= arryStart && arryEnd <= right) {
		return tree[treeIndex];
	}

	// 2. segment tree sum 재귀호출 반복
	int arryMid = (arryStart + arryEnd) / 2;
	return sum(treeIndex * 2, arryStart, arryMid, left, right) + sum(treeIndex * 2 + 1, arryMid + 1,arryEnd, left, right);
}

int main(void) {
	freopen("input.txt", "r", stdin);
	int N, M, K; //N: 숫자수, M:변경이 일어나는 횟수, K:구간의 합을 구하는 횟수
	scanf("%d %d %d", &N, &M, &K);
	
	// 입력
	fill(arry, arry + N + 1, 0);
	fill(tree, tree + N * 4 + 1, 0);
	for (int n = 0; n < N; n++) {
		scanf("%d", &arry[n]);
		update(1, 0, N - 1, n, arry[n]);
	}

	// 질문(M+K)
	int question, a, b;
	ll sol;
	for (int i = 1; i <= M + K; i++) {
		scanf("%d %d %d", &question, &a, &b);
		if (question == 1) {
			update(1, 0, N - 1, a-1, b);
		}
		else if (question == 2) {
			sol=sum(1, 0, N - 1, a-1, b-1);
			printf("%lld\n", sol);
		}
	}
}
