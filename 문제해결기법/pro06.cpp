
#include "stdafx.h"
#include <stdio.h>
#define MAX 100
#pragma warning(disable:4996)


// 1번 키보드로 부터 연속해서 정수들을 입력받는다. 
// 정수가 하나 씩 입력될 때 마다 현재까지 입력된 정수들을 오름차순으로 정렬하여 화면에 출력한다.
// 단, 새로 입력된 정수가 이미 배열에 저장되어 있다면 추가하는 대신 “duplicate entry”라고 출력한다. 
// 사용자가 -1을 입력하면 프로그램을 종료한다.

void p01() {
	int data[MAX];
	int n = 0, tmp;
	while (1) {
		scanf("%d", &tmp);
		if (tmp == -1)
			break;
		int i = n - 1;
		while (i >= 0 && data[i] > tmp) {
			data[i + 1] = data[i];
			i--;
		}
		data[i+1] = tmp;
		n++;
		if (data[i] == tmp) {
			printf("duplicate entry\n");
			while (++i < n - 1)
				data[i] = data[i + 1];
			n--;
		}		
		for(int j = 0 ; j < n ; j++)
		printf("%d  ", data[j]);
	}
}


// 3번 선택정렬
void p03() {
	int data[MAX];
	FILE *fp = fopen("input3.txt", "r");
	int n = 0;
	while (fscanf_s(fp, "%d", &data[n]) != EOF)
		n++;
	int max,temp;
	for (int i = n -1; i > 0; i--) {
		max = 0;
		for (int j = 1; j <= i; j++) {
			if (data[j] > data[max])
				max = j;
		}
		temp = data[i];
		data[i] = data[max];
		data[max] = temp;
	}

	for (int i = 0; i < n; i++)
		printf("%d ", data[i]);
}


// 5번 입력으로 n개의 구간(interval)이 주어진다.
// 각 구간은 구간의 시작점과 끝점으로 표현된다.
// 시작점이 빠른 순서대로 정렬하여 출력하라.
// 시작점이 같은경우 끝점이 빠른 것을 먼저 출력한다.
// 입력 형식은 먼저 n의 값이 주어지고, 이어서 각 구간의 시작점과 끝점이 차례대로 주어진다.
// 각 구간의 시작점과 끝점은 정수이고, 끝점은 항상 시작점보다 크거나 같다

void p05() {
	int start[MAX];
	int end[MAX];
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) 
		scanf_s("%d %d", &start[i], &end[i]);
	int temp, max;
	for (int i = n - 1; i > 0; i--) {
		max = 0;
		for (int j = 1; j <= i; j++) {
			if (start[j] > start[max])
				max = j;
			else if (start[j] == start[max] && end[j] > end[max])
				max = j;
		}
		temp = start[max];
		start[max] = start[i];
		start[i] = temp;
		temp = end[max];
		end[max] = end[i];
		end[i] = temp;
	}
	for (int i = 0; i < n; i++)
		printf("%d %d\n", start[i], end[i]);
}


// 6번 임의의 순열(permutation)에서 사이클의 개수를 찾아 출려하라.
// 입력형식은  정수 N과 이어서 {0,1,2,...,N-1}의 임의의 순열이 주어진다.
// input 8 3 5 4 1 2 7 6 0 		output 3
void p06() {
	int N;
	scanf_s("%d", &N);
	int flag = (1 << N) - 1;
	int A[60];
	int count = 0, tmp = 1;
	for (int i = 0; i < N; i++)
		scanf_s("%d", &A[i]);
	for (int i = 0; i < N; i++,tmp *= 2) {
		if ((flag & tmp) > 0) {
			flag -= tmp;
			if (A[i] == i)
				count++;
			else{
				int x = i, y;
				while (A[x] >= 0 && A[x] < N) {
					y = A[x];
					if (i == y) {
						count++;
						break;
					}
					int check = 1 << y;
					if ((flag & check) > 0) {
						flag -= check;
						x = y;
					}
					else
						break;
				}
			}
		}
	}
	printf("%d", count);
}


// 입력으로 두 개의 양의 정수를 받는다. 그런 다음 두 정수를 사전식 순서(lexicographic order)로 출력하는 프로그램을 작성하라.
// 예를 들어 두 정수가 75와 111이라면  75는 7로 시작하므로 사전식 순서에서는 1로 시작하는 111보다 나중에 나와야 한다. 
// 즉 111, 75의 순서로 출력해야 한다.

void p07() {
	int x, y;
	scanf_s("%d %d", &x, &y);
	int max, count = 1, mx = x,my= y;
	if (x > y) max = x; else  max = y;
	while (max < 10) {
		max /= 10;
		count *= 10;
	}
	while (mx > count)
		mx *= 10;
	while (my > count)
		my *= 10;
	if (mx < my)
		printf("%d %d", x, y);
	else
		printf("%d %d", y, x);
}

int main()
{
	while(true)
	p06();
	getchar(); getchar();
	return 0;
}

