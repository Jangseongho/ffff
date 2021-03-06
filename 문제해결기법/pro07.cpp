// pro07.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#define MAX 100

// 2번
// 수열 a1,a2,a3,...,an에서 어떤 3개의 값 (ai,aj,ak)가 i < j < k이면서 ai > aj > ak일 때 이를 역전된 3중쌍이라고 부른다. 
// 역전된 3중쌍의 개수를 구하는 프로그램을 작성하라. 
// 먼저 수열의 길이 N이 주어지고 이어서 N개의 정수가 입력으로 주어진다
// input 8 8 7 6 5 4 3 2 1 		output 56

void p02() {
	int array[MAX];
	int N, count = 0;
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) 
		scanf_s("%d", &array[i]);
	for (int i = 0; i < N-2; i++) {
		for (int j = i + 1; j < N-1; j++) {
			for (int k = j + 1; k < N; k++) {
				if (array[i] > array[j] && array[i] > array[k] && array[j] > array[k])
					count++;
			}
		}
	}
	printf("%d ", count);
}


// 입력으로 하나의 수열이 주어진다. 이 중 오름차순으로 정렬되어 있는 가장 긴 구간을 찾아서 
// 그 구간의 길이를 출력하는 프로그램을 작성하라. 
// 예를 들어 수열이 2, 3, (-2, -2, -2, 7, 7, 9, 10, 10), 9, -3라면 괄호 친 구간이 가장 긴 구간이고 그 길이는 8이다.
// 입력은 키보드로부터 받으며 먼저 수열의 길이 N이 주어지고 이어서 N개의 정수들이 주어진다.

void p04() {
	int array[MAX];
	int N, count = 1,maxlength = 0;
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++)
		scanf_s("%d", &array[i]);
	for (int i = 1; i < N; i++) {
		if (array[i] >= array[i - 1])
			count++;
		else
			count = 1;
		if (count > maxlength)
			maxlength = count;
	}
	printf("%d ", maxlength);
}


// 7번
// 입력으로 개의 폐구간(closed interval)이 주어진다. 
// 이중 겹치는 길이가 가장 긴 두 구간을 찾아서 출력하는 프로그램을 작성하라. 
// 예를 들어  N=4이고 입력된 구간들이 [0, 3], [3, 6], [2, 7], [4, 5]라면 구간 [3, 6]과 [2, 7]이 겹치는 길이는 3이고 가장 길다. 
// 입력은 input6.txt 파일로부터 받는다. 파일의 각 줄마다 하나의 구간의 시작점과 끝점이 주어진다. 
// 각 구간의 끝점은 항상 시작점보다 크거나 같다

void p07() {
	int start[MAX];
	int end[MAX];
	int N = 0;
	FILE *data;
	fopen_s(&data, "input7.txt", "r");
	while (fscanf_s(data, "%d", &start[N]) != EOF) {
		fscanf_s(data, "%d", &end[N]);
		N++;
	}

	int max, temp;
	for (int i = N-1; i > 1; i--) {
		max = 0;
		for (int j = 1; j <= i; j++) {
			if (start[max] < start[j])
				max = j;
		}
		temp = start[max];
		start[max] = start[i];
		start[i] = temp;
		temp = end[max];
		end[max] = end[i];
		end[i] = temp;
	}

	int maxinterval = 0,sindex,eindex;
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (end[i] - start[j]> maxinterval) {
				maxinterval = end[i] - start[j];
				sindex = i;
				eindex = j;
			}
		}
	}
	printf("[%d, %d], [%d, %d]", start[sindex], end[sindex], start[eindex], end[eindex]);
}


// 10번 N미만의 음이 아닌 N개의 정수들이 저장된 배열 A가 있다. 임의의 정수 i ,0<=i<N,에 대해서 다음과 같이 정의한다. 
// A^k[i]=	{ i	if k = 0
//		{ A[A^k-1[i]] if k > 0
// 어떤 정수 k >=0 에 대해서 만약 A^k[i] = A^k-1[i]이면 k 이상인 모든 정수 j에 대해서도 A^j[i] = A^k[i]가 된다.
// 이때 A^k[i]를 i의 루트(root)라고 부르고 R[i]로 나타낸다. 예를들어 A = [2,1,1,2,3,6,5]이라고 하자. 그러면
// A1[4]= A[A0[4]] = A[4] =3
// A2[4] = A[A1[4]] = A[3] = 2
// A3[4] = A[A2[4]] = A[2] = 1
// A4[4] = A[A3[4]] = A[1] = 1
// 이므로 4의 루트 R[4] = 1 이다. 항상 루트가 존재하는 것은 아니다. 위의 예에서 R[5]와 R[6]는 존재하지 않는다.
// 입력으로 정수 N을 받고 이어서 N 개의 N 미만인 음이 아닌 정수를 받는다 .
// R[0],... R[N-1]을 모두 구해서 순서대로 출력하는 프로그램을 작성하라 
// 단, 루트가 존재하지 않는 경우에는 -1을 출력하라.

void p10() {
	int array[MAX];
	int result[MAX];
	int N;
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++)
		scanf_s("%d", &array[i]);

	for (int i = 0; i < N; i++) {
		if (array[i] == i)
			result[i] = i;
		else
			result[i] = -1;
	}
	int level, x;
	for (int i = 0; i < N; i++) {
		if (result[i] == -1) {
			for (x = i, level = 1; level <= N; level++) {
				x = array[x];
				if (result[x] != -1 || x < i) {
					result[i] = result[x];
					break;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) 
		printf("%d ", result[i]);
}


// 11번 0 혹은 1로 이루어진 길이가 N인 수열이 주어진다. 
// 이 중 최대 하나의 0을 1로 교체해서 만들 수 있는 가장 긴 연속된 1의 개수를 구하는 프로그램을 작성하라.
// 예를 들어 N=13이고, 입력된 수열이 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1 라고 하자. 
// 그러면 10번째 0을 1로 교체하면 연속된 1의 개수는 7개가 된다. 
// 입력으로 먼저 N의 값이 주어지고 이어서 N개의 0 혹은 1이 주어진다

void p11() {
	//입력
	int array[MAX];
	int N;
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++)
		scanf_s("%d", &array[i]);
	//탐색
	int maxlength = 0, count = 0;
	for (int i = 0; i < N; i++) {
		if (array[i] == 0) {
			array[i] = 1;
			for (int j = 0; j < N; j++) {
				if (array[j] == 1)
					count++;
				else
					count = 0;
				if (count > maxlength)
					maxlength = count;
			}
			array[i] = 0;
		}
	}
	//길이가 0이면 0이 없다.
	if (maxlength == 0)
		maxlength = N;
	printf("%d", maxlength);
}


int main()
{
	while (true) 
		p10();  
	getchar(); getchar();
	return 0;
}

