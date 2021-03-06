
#include "stdafx.h"

void p04();
void p06();
void p08();
void p10();
void p11();
int way(int x1, int y1, int x2, int y2, int x3, int y3);
int direction(int x1, int y1, int x2, int y2);
void p12();

int main()
{
	//모든 문제에 대해서 배열을 사용해서는 안된다. 또한 stdio.h 이외의 다른 라이브러리를 사용해서도 안된다.
	while(1)
		p12();
	return 0;
}


//4번 10개의 정수를 키보드로 부터 입력받는다. 입력된 정수들 중에서 음이 아닌 정수들 중에서 최소값을 찾아서 출력하는 프로그램을 작성하라. 
//input 1 4 8 11 -4 2 9 13 3 20 ouput 1
void p04() {
	int n, min;
	scanf_s("%d", &min);

	for (int i = 1; i < 10; i++) {
		scanf_s("%d", &n);
		if (n < min&&n >= 0)
			min = n;
	}
	printf("%d", min);
}


//6번 두 개의 날짜를 입력받은 후 그 중 첫 번째 날짜가 더 이르면 -1, 두 번째 날짜가 더 이르면 1, 두 날짜가 동일하면 0을 출력하는 프로그램을 작성하라. 
//각각의 날짜는 년, 월, 일을 나타내는 3개의 정수로 주어진다. 날짜의 유효성을 체크할 필요는 없다. 
//input 2017 1 3 2016 12 9 output 1
void p06() {
	int y1, m1, d1, y2, m2, d2,out;
	scanf_s("%d %d %d %d %d %d", &y1, &m1, &d1, &y2, &m2, &d2);
	if (y1 == y2) {
		if (m1 == m2) {
			if (d1 == d2)
				out = 0;
			else if (d1 < d2)
				out = -1;
			else
				out = 1;
		}
		else if (m1 < m2)
			out = -1;
		else
			out = 1;
	}
	else if (y1 < y2)
		out = -1;
	else
		out = 1;
	printf("%d", out);
}


//8번 두 개의 폐구간 [a, b]와 [c, d]를 입력받는다. 
//a≦b이고 c≦d이다. 두 구간이 겹치는지 판단하여 yes 혹은 no로 출력하는 프로그램을 작성하라. 
//두 구간이 겹친다는 것은 교집합이 공집합이 아니라는 의미이다
//input 4 7 2 12 output yes
//input 1 8 7 6 output Input error

void p08() {
	int a, b, c, d;
	scanf_s("%d %d %d %d", &a, &b, &c, &d);
	if (a > b || c > d)
		printf("Input error");
	else if (d >= a && b >= c)
		printf("YES");
	else
		printf("NO");
}


//10번 평면 상의 개의 점의 좌표가 순서대로 주어진다. 단, 임의의 연속된 두 점은 동일한 좌표를 갖거나 혹은 동일한 좌표를 가진다. 
//만약 그렇지 않으면 Input error라고 출력하고 종료한다. 
//입력된 점을 순서대로 연결하여 만들어지는 polyline의 길이를 구하여 출력하는 프로그램을 작성하라. 
//입력은 먼저 점의 개수 n이 주어지고, 이어서 개의 점의 x 좌표와 y 좌표의 쌍이 순서대로 주어진다.
// 가령 아래의 첫 번째 예에서는 n=4이고, 점의 좌표는 (10, 10), (30, 10), (30, 40), (50, 40) 이다.
// input 4 10 10 30 10 30 40 50 40	output 70

void p10() {
	int n, x1, x2, y1, y2, polyline = 0;
	scanf_s("%d %d %d", &n, &x1, &y1);
	for (int i = 1; i < n; i++) {
		scanf_s("%d %d", &x2, &y2);
		if (x1 == x2) 
			if(y2 > y1)
				polyline += y2 - y1;
			else 
				polyline += y1 - y2;
		else if (y1 == y2) 
			if(x2 > x1)
				polyline += x2 - x1;
			else
				polyline += x1 - x2;
		else {
			printf("Input error");
			return;
		}
		x1 = x2;
		y1 = y2;
	}
	printf("%d", polyline);
}


//11번 평면 상의 3개의 점의 좌표가 순서대로 주어진다. 
//단, 임의의 연속된 두 점은 동일한 좌표를 갖거나 혹은 동일한 좌표를 가진다. 
//만약 그렇지 않으면 Input error라고 출력하고 종료한다. 
//입력된 점을 순서대로 방문할 때 2번째 점에서 3번째 점으로 이동하는 것이 직진인지, 좌회전인지, 우회전인지, 
//혹은 U-턴인지 판단하여 Straight, Left, Right, 혹은 U-turn이라고 출력하는 프로그램을 작성하라
//input 0 0 2 0 2 2		output Left

void p11() {
	int x1, y1, x2, y2, x3, y3,out;
	scanf_s("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
	out = way(x1, y1, x2, y2, x3, y3);
	switch (out)
	{
		case -1:
		case 3:printf("Left"); break;
		case 0:printf("Stright"); break;
		case 1:
		case -3:printf("Right"); break;
		case 2:
		case -2:printf("U-turn"); break;
		default:printf("Input error"); break;
	}
}
int way(int x1, int y1, int x2, int y2, int x3, int y3) {
	if ((x1 == x2 || y1 == y2) && (x2 == x3 || y2 == y3)) 
		return direction(x1, y1, x2, y2) - direction(x2, y2, x3, y3);
	else
		return 4;
}
int direction(int x1, int y1, int x2, int y2) {
	x1 -= x2;
	y1 -= y2;
	if (x1 == 0) {
		if (y1 > 0)
			return 2;//왼
		else
			return 0;//오
	}
	else {
		if (x1 > 0)
			return 1;//위
		else
			return 3;//아래
	}
}


//12번 평면 상의 n개의 점의 좌표가 순서대로 주어진다. 
//단, 임의의 연속된 두 점은 동일한 x좌표를 갖거나 혹은 동일한 y좌표를 가진다. 
//만약 그렇지 않으면 Input error라고 출력하고 종료한다.
//입력된 점들을 순서대로 방문할 때 좌회전, 직진, 우회전, 그리고 U-턴의 횟수를 카운트하여 순서대로 출력하는 프로그램을 작성하라. 
//입력은 먼저 n의 값이 주어지고, 이어서 n개의 점의 x좌표와 y좌표가 순서대로 주어진다. 
//가령 아래의 첫 번째 n = 3예는 이고, 점의 좌표는 (0, 0), (2, 0), (2, 2)이며, 
//출력 1 0 0 0 은 좌회전은 1번이고 직진, 우회전, U-turn의 횟수는 0번임을 의미한다. 
//출력되는 횟수의 총합은 항상 n-2가 될 것이다
// input 3 0 0 2 0 2 2  	output 1 0 0 0

void p12() {
	int x1, y1, x2, y2, x3, y3, n, L, S, R, U;
	L = S = R = U = 0;
	scanf_s("%d %d %d %d %d", &n, &x1, &y1, &x2, &y2);
	for (int i = 2; i < n; i++) {
		scanf_s("%d %d", &x3, &y3);
		switch (way(x1, y1, x2, y2, x3, y3))
		{
			case -1:
			case 3:L++; break;
			case 0:S++; break;
			case 1:
			case -3:R++; break;
			case 2:
			case -2:U++; break;
			default:printf("Input error"); return;
		}
		x1 = x2;
		y1 = y2;
		x2 = x3;
		y2 = y3;
	}
	printf("%d %d %d %d", L, S, R, U);
}