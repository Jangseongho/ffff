// pro05.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <math.h>
#include <stdio.h>
#pragma warning(disable:4996)
#define MAX 100

//1번 먼저 입력될 정수의 개수 n <= 100을 입력받고, 이어서 n개의 정수를 입력받아 순서대로 배열에 저장한다. 
// 추가로 하나의 정수 K를 입력받은 후 N개의 정수들 중에 K보다 작거나 같으면서 가장 큰 정수를 찾아 
// 그 정수의 배열 인덱스, 찾은 정수의 값, 그리고 K와의 차이의 절대값을 출력하는 프로그램을 작성하라. 
// 답이 여럿일 때는 그 중 가장 먼저 나온 값을 찾고, 답이 존재하지 않을 때는 -1을 출력하라.

void p01(){
	int array[MAX];
	int n, k;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &array[i]);
	}
	scanf_s("%d", &k);
	int index = -1, min =-9999999;
	for (int i = 0; i < n; i++) {
		if (array[i] > min && array[i] <= k) {
			min = array[i];
			index = i;
		}
	}
	if (index == -1)
		printf("-1");
	else
		printf("%d %d %d", index, min, k - min);
}


// 3번 먼저 입력될 정수의 개수 n<=100을 입력받고, 이어서 n개의 정수를 받아 
// 평균과 표준편차를 계산하여 출력하는 프로그램을 작성하라.
// sqrt함수를 사용하라 

void p03() {
	int array[MAX];
	int n;
	double temp,sum = 0;
	scanf_s("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &array[i]);
		sum += array[i];
	}
	double av = sum / n;
	
	sum = 0;
	for (int i = 0; i < n; i++) {
		temp = (array[i] - av);
		sum += temp * temp;
	}
	double sd = sqrt(sum/n);
	
	printf("%lf %lf", av, sd);
}


//4번 하나의 양의 정수 N을 입력 받은 후 정수 N에 0에서 9까지의 digit가 각각 몇 번씩 등장하는지 카운트하여
// 순서대로 출력하는 프로그램을 작성하라. 예를 들어 N = 120341279라면 1, 2, 2, 1, 1, 0, 0, 1, 0, 1이라고 출력한다. 
// 즉, 0은 1번, 1은 2번, 2는 2번, 3과 4는 1번, 그리고 7과 9가 1번씩 등장했고, 5, 6, 8은 한 번도 등장 하지 않았다는 의미이다. 

void p04() {
	int array[10] = { 0 };
	int N;
	scanf_s("%d", &N);
	
	while (N > 0) {
		array[N % 10]++;
		N /= 10;
	}
	
	for (int i = 0; i < 10; i++)
		printf("%d, ", array[i]);
}


// 9번 우선 input9.txt파일로 부터 정수들을 읽는다. 
// 정수의 개수는 따로 주어지지 않으며 파일의 끝까지 읽어야 한다. 정수의 개수는 100개 이하이다. 
// 정수들 중에서 자신보다 먼저 나온 모든 정수들 보다 크거나 같은 정수를 리더(leader)라고 부른다. 
// 그리고 첫 번째 정수는 무조건 리더이다. 리더가 아닌 모든 정수들은 무시하고 리더들만 입력된 순서대로
// 배열에 저장하는 프로그램을 작성하라. 리더들은 배열의 맨 앞에서 부터 빈 칸 없이 저장되어야 한다. 
// 먼저 리더들의 개수를 출력하고 이어서 리더들을 순서대로 화면으로 출력하라.
// input9.txt:12 0 28 1 9 37 46 -92 -8 37 0 0 12 124 	output 5: 12 28 37 46 124

void p09() {
	int data[MAX] = { 0 };
	int n = 0,leader;

	FILE *fp = fopen("input9.txt", "r");
	fscanf_s(fp, "%d", &leader);
	data[n++] = leader;
	while (fscanf_s(fp, "%d", &data[n]) !=EOF) {
		if (data[n] >= leader)
			leader = data[n++];
	}
	fclose(fp);
	printf("%d: ", n);
	for (int i = 0; i < n; i++)
		printf("%d ", data[i]);
}


// 10번 input10.txt 파일에 매일 매일의 주식 가격을 표현하는 개의 양의 정수가 주어진다. 
// 정수의 개수 은 따로 주어지지 않으며 파일의 끝까지 읽어야 한다. 
// 주식 거래로 얻을 수 있는 최대 이익을 계산하는 프로그램을 작성하라. 
// 예를 들어 입력 정수들이 [100, 180, 260, 310, 40, 535, 695]라고 하자. 
// 이것은 첫째 날의 주식 가격은 100원, 둘째날은 180원, 셋째날은 260원, 그리고 마지막 날은 695원임을 의미한다. 
// 최대의 이익을 얻기 위해서는 첫째 날에 주식을 사고 넷째 날에 팔고, 그리고 다시 5번째 날에 사서 7번째 날에 팔면 
// 총 (310-100) + (695-40) = 865원의 이익을 얻을 수 있다
// input 100 180 260 310 40 535 695		output 865

void p10() {
	int data[MAX] = { 0 };
	int n = 0, sum = 0;
	FILE *fp = fopen("input10.txt", "r");
	fscanf_s(fp, "%d", &data[n++]);
	while (fscanf_s(fp, "%d", &data[n]) != EOF) {
		if (data[n - 1] < data[n])
			sum += data[n] - data[n - 1];
		n++;
	}
	fclose(fp);
	printf("%d", sum);
}

int main()
{
	//while (true)
		p10();
		getchar();
		getchar();
    return 0;
}

