// pro08.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAX 101
#pragma warning(disable:4996)

// 1번 [Puppy's Escape] 강아지가 N x N 크기의 2차원 배열의 가운데 위치에서 출발한다.
// N은 홀수 이다. 상, 하, 좌, 우 4방향으로 인접한 셀(cell)들 중에서 방문한 적이 없는
// 한 셀을 동일한 확률로 랜덤하게 선택하여 한 칸 이동한다.
// 배열의 가장자리 셀에 도착하면 탈출에 성공한 것이다. 
// 하지만 아무 곳으로도 이동할 수 없는 상태에 처하면 탈출에 실패한 것이다.
// 입력으로 하나의 홀수 N <= 100을 받아서 강아지가 탈출에 성공할 확률을 
// 시뮬레이션으로 계산하는 프로그램을 작성하라. 실험 횟수는 10,000번으로 하라.

void p01() {
	srand((unsigned int)time(NULL));
	int N,x,y,dir;
	int maze[MAX][MAX] = { 0 };
	scanf_s("%d", &N);
	int count = 0;
	for (int i = 0; i < 10000; i++) {
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				maze[j][k] = 0;
		x = y = N / 2;
		while (x != 0 && y != 0 && x != N - 1 && y != N - 1) {
			maze[x][y] = 1;
			dir = rand() % 4;
			if (dir == 0 && maze[x][y + 1] == 0)
				y++;
			else if (dir == 1 && maze[x + 1][y] == 0)
				x++;
			else if (dir == 2 && maze[x][y - 1] == 0)
				y--;
			else if (dir == 3 && maze[x - 1][y] == 0)
				x--;
			else if (maze[x][y + 1] == 1 && maze[x + 1][y] == 1 && maze[x][y - 1] == 1 && maze[x - 1][y] == 1) {
				count++;
				break;
			}
		}
	}
	printf("%lf", 1-((double)count / 10000));
}


// 3번 이항계수 (binomail coefficient) nCk n개 중에서 k개를 선택하는 경우의 수를 구하여라.
// 입력으로 두 양의 정수 n,k,(k<=n<=100)를 받아서 nCk를 계산하여 출력하라.

void p03() {
	int C[MAX][MAX];
	int n, k;
	scanf_s("%d %d", &n, &k);
	for (int i = 0; i <= n; i++) {
		C[i][i] = 1;
		C[i][0] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}
	printf("%d", C[n][k]);
}


// 4번 데이터 파일 input4.txt에는 하나의  행렬이 저장되어 있다. 
// 파일의 첫 줄에는 행렬의 크기 이 저장되어 있고, 이어진 줄에는 각 줄마다 개의 정수가 저장되어 있다. 
// 이 파일을 읽어서 각 행의 평균과 표준편차, 각 열의 평균과 표준편차를 구해서 출력하는 프로그램을 작성하라. 

void p04() {
	int array[MAX][MAX];
	int n;
	double av,sd,temp, sum = 0;
	FILE *fp = fopen("input4.txt", "r");
	fscanf_s(fp,"%d", &n);
	//입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			fscanf_s(fp,"%d", &array[i][j]);
	}
	fclose(fp);
	//가로
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j < n; j++) {
			printf("%d ", array[i][j]);
			sum += array[i][j];
		}
		av = sum / n;
		sum = 0;
		for (int j = 0; j < n; j++) {
			temp = (array[i][j] - av);
			sum += temp * temp;
		}
		sd = sqrt(sum / n);
		printf("%lf %lf\n", av, sd);
	}
	//세로
	double result[MAX];
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j < n; j++) 
			sum += array[j][i];
		av = sum / n;
		sum = 0;
		for (int j = 0; j < n; j++) {
			temp = (array[j][i] - av);
			sum += temp * temp;
		}
		sd = sqrt(sum / n);
		result[i] = sd;
		printf("%lf ", av);
	}printf("\n");
	for (int i = 0; i < n; i++) 
		printf("%lf ", result[i]);
}


// 6번 배열을 0,0에서 시계방향으로 달팽이모양으로 출력
void p06() {
	int array[MAX][MAX];
	int n;
	FILE *fp = fopen("input6.txt", "r");
	fscanf_s(fp, "%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			fscanf_s(fp, "%d", &array[i][j]);
	}
	fclose(fp);
	//출력
	int dir = 1,i=0,j=-1;
	while (n > 0) {
		for (int k = 0; k < n; k++) {
			j += dir;
			printf("%d ", array[i][j]);
		}
		n--;
		for (int k = 0; k < n; k++) {
			i += dir;
			printf("%d ", array[i][j]);
		}
		dir *= -1;
	}
}

// 7번 N <= 1000000개의 음이 아닌 정수가 입력으로 주어진다. 각 정수는 벽돌의 개수를 나타낸다. 
// 가령 입력 정수가 3, 0, 0, 2, 0, 4라면 왼쪽에서 오른쪽 순서로 해당하는 개수 만큼의 벽돌이 쌓여 있다는 의미이다. 
// 모든 벽돌의 높이와 너비는 1로 동일하다. 비가 내렸을 때 이 벽돌들에 의해서 
// 고이는 물의 총량을 계산하는 프로그램을 작성하라. 예에서 고이는 물의 총량은 10이다. 
// 또 다른 예로 입력이 {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}라면 고이는 물의 총량은 6이다 
// (1과 2 사이에 1, 첫 번째 2와 3사이에 4, 그리고 끝에서 2번째 1과 마지막 2 사이에 1). 
// 입력은 키보드로 부터 받는다. 먼저 정수의 개수 이 주어지고 이어서 개의 음이 아닌 정수가 주어진다. 재밌다.

void p07() {
	int Bars[MAX];
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &Bars[i]);
	int i = 0, j = n - 1, max, Lmax = 0, Rmax = 0,water=0;
	while (i!=j)
	{
		if (Lmax < Bars[i])
			Lmax = Bars[i];
		if (Rmax < Bars[j])
			Rmax = Bars[j];
		Lmax > Rmax ? max = Rmax : max = Lmax;
		Bars[j] > Bars[i] ? water += max - Bars[i++] : water += max - Bars[j--];
	}
	printf("%d",water);
}

int main()
{
	while(true)
		p07();
    return 0;
}

