// pro09.cpp.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <math.h>
#include <stdlib.h>
#define MAX 100
int compareLexicographic(int x, int y);
int lenOfOverlap(int sa, int ta, int sb, int tb);
int calpoly(int c, int o, int x);


// 6번 사용자로부터 하나의 다항식을 입력받고 이어서 변수 의 값을 입력받아 
// 다항식의 값을 계산하여 출력하는 프로그램을 작성하라. 예를 들어 다항식이
// 3x^5 + 2x^4 - x^2 + 7x - 6
// 이라고 가정하면 입력은 먼저 항의 개수 5가 주어지고 이어서 다음과 같이 각 항의 계수와 차수가 순서대로 주어진다
// 3  5  2  4  -1  2  7  1  -6  0
// 마지막으로 변수 의 값이 주어진다. 계수, 차수, 변수 의 값은 모두 정수라고 가정한다.
// input 4 2 10 -5 2 1 1 1 0  	output 2031

void improv06() {
	int n, x;
	int Coef[MAX] = { 0 };
	int Order[MAX];
	int temp,index;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) 
		scanf_s("%d %d", &Coef[i], &Order[i]);
	scanf_s("%d", &x);
	int sum = 0;
	for (int i = 0; i < MAX; i++)
		sum += calpoly(Coef[i], Order[i], x);
	printf("%d", sum);
}

void p06() {
	int n, x;
	int Coef[MAX];
	int Order[MAX];
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d %d", &Coef[i], &Order[i]);
	}
	scanf_s("%d", &x);
	int xorder = 0,sum = 0,mx=1;
	for (int i = n - 1; i >= 0; i--) {
			while (xorder < Order[i]) {
				mx *= x;
				xorder++;
			}
			sum += Coef[i] * mx;			
	}
	printf("%d", sum);
}

int calpoly(int c, int o,int x) {
	if (c == 0)
		return 0;
	if (o == 0)
		return c;
	double temp = 1;
	for (int i = 0; i < o; i++)
		temp *= x;
	return c * temp;
}


// 5번 입력으로 양의 정수들이 주어진다. 각 정수들은 8자리 이내의 정수들이다. 
// 이 정수들을 사전식 순서(lexicographic order)로 정렬하여 출력하는 프로그램을 작성하라. 
// 예를 들어 입력 정수들이 75, 111, 120, 3456, 9, 12, 67, 91이라면 111, 12, 120, 3456, 67, 75, 9, 91의 순서이다. 
// 입력은 input5.txt 파일에서 읽는다. 정수의 개수는 따로 주어지지 않고 파일의 끝까지 읽어야 한다. 
// 이 문제를 해결하기 위해서 두 정수를 매개변수로 받아서 사전식 순서를 비교하는 함수
// int compareLexicographic(int x, int y) 를 작성하라.
// 이 함수는 정수 a와 b를 비교하여 a가 사전식 순서로 앞설 경우에는 -1,
// b가 앞설 경우에는 1, 그리고 두 정수가 동일할 경우에는 0을 반환한다.

void p05() {
	FILE *fp;
	int data[MAX];
	int n = 0,i;
	fopen_s(&fp,"input5.txt", "r");
	fscanf_s(fp, "%d", &data[n++]);
	while (fscanf_s(fp, "%d", &data[n]) != EOF)
		n++;
	int temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (compareLexicographic(data[j], data[j + 1]) < 0) {
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < n; i++)
		printf("%d\t", data[i]);
}

int compareLexicographic(int x, int y) {
	int max, count = 1, mx = x, my = y;
	if (x == y) {
		return 0;
	}
	x > y ? max = x : max = y;
	while (max > 10) {
		max /= 10;
		count *= 10;
	}
	while (mx < count)
		mx *= 10;
	while (my < count)
		my *= 10;
	if (mx == my) 
		return x > y ? -1 : 1;
	return mx > my ? -1 : 1;
}


// 3번 평면상에서 좌표축에 평행한 2개의 직사각형이 입력으로 주어진다. 
// 두 사각형이 교차하는 영역, 즉 두 사각형에 공통으로 포함되는 영역의 면적을 구하는 프로그램을 작성하라. 
// 각각의 사각형은 대각 방향의 두 꼭지점의 좌표로 주어진다.
// 이 문제를 해결하기 위해서 임의의 두 구간에 대해서 두 구간이 겹치는 영역의 길이를 구하는 함수
// int lenOfOverlap( int sa, int ta, int sb, int tb) 를 작성하여 이용하라
// 이 함수는 [sa, ta]와 [sb, tb]의 겹치는 영역의 길이를 계산하여 반환한다.

void p03() {
	int data[8];
	for (int i = 0; i < 8; i++)
		scanf_s("%d", &data[i]);
	printf("%d", lenOfOverlap(data[0], data[2], data[4], data[6])*lenOfOverlap(data[1], data[3], data[5], data[7]));
}
double func(double x, double y, double z) {
	return x <= y ? (y <= z ? y : (x <= z ? z : x)) : (z <= y ? y : (x <= z ? x : z));
}


int lenOfOverlap(int sa, int ta, int sb, int tb) {
	if (sa > ta) {
		int temp = sa;
		sa = ta;
		ta = temp;
	}
	if (sb > tb) {
		int temp = sb;
		sb = tb;
		tb = temp;
	}
	if (sa <= sb) {
		if (ta < tb) {
			if (ta > sb)
				return abs(sb - ta);
			else
				return 0;
		}
		else
			return abs(tb - sb);
	}
	else {
		if (ta > tb) {
			if (tb > sa)
				return abs(sa - tb);
			else
				return 0;
		}
		else
			return abs(ta - sa);
	}
}

int main()
{	
	improv06();
	getchar(); getchar();
    return 0;
}

