// pro04.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>

//모든 문제에 대해서 배열을 사용해서는 안된다.


//3번 하나의 양의 정수 N을 입력받는다. 2차원 평면의 1사분면에서
// x-좌표와 y-좌표가 각각 0이상 이하의 정수인 모든 점들의 좌표를 
// 다음과 같은 순서로 한 줄에 하나씩 출력한다.
// y-좌표가 증가하는 순서로 출력한다. 
// y-좌표가 동일한 경우 y-좌표가 짝수이면 x-좌표가 증가하는 순서대로, 
// y-좌표가 홀수이면 x-좌표가 감소하는 순서대로 출력한다.

void p03() {
	int N,x,y=0;
	scanf_s("%d", &N);
	while (y <= N) {
		if (y % 2 == 0) {
			for (x = 0; x <= N; x++)
				printf("%d %d\n", x, y);
		}
		else {
			for (x = N; x >= 0; x--)
				printf("%d %d\n", x, y);
		}
		y++;
	}
}


//4번 하나의 양의 정수 K를 입력 받아서 평면 상에서  x-좌표와 y-좌표가 각각 음수가 아닌 정수이면서 
//그 합이  K이하인 모든 점들의 좌표를 한 줄에 하나씩 출력한다.
// 단, 점들은 x-좌표와 y-좌표의 합이 작은것 부터 큰 것 순서로 출력해야하며, 
//합이 동일한 경우에는  x-좌표가 작은것 부터 큰 것 순으로 출력해야 한다. 

void p04() {
	int K, x = 0, sum = 0;
	scanf_s("%d",&K);
	while (sum <= K) {
		while (x  <= sum) {
			printf("%d %d\n", x, sum-x);
			x++;
		}
		x = 0;
		sum++;
	}
}


//7번 원점 (0,0)에서 출발하여 매 스텝마다 동서남북 4방향 중 한 방향을 각각 1/4의 확률로 랜덤하게 선택하여 1만큼 움직인다.
// x-좌표나 y-좌표가 N이나 -N에 도달하면 종료한다. 
// 종료할 때까지 몇 스텝이 걸리는지 실험적으로 판단하는 프로그램을 작성하라. 
// 즉 동일한 실험을 T번 반복하여 가장자리에 도달하는데 걸린 스텝 수의 평균을 구하라. 
// N은 입력으로 주어지고 T는 1000으로 하라

void p07() {
	srand((unsigned int)time(NULL));
	int N, x = 0, y = 0, count = 0, dir;
	scanf_s("%d", &N);
	for (int i = 0; i < 1000; i++) {
		while (true) {
			if (x == N || x == -N || y == N || y == -N)
				break;
			dir = rand() % 4;
			if (dir == 0)
				x++;
			else if (dir == 1)
				x--;
			else if (dir == 2)
				y++;
			else
				y--;
			count++;
		}
		x = y = 0;
	}
	printf("%lf", count / 1000.0);
}


//8번 1693년에 Samuel Pepys는 뉴튼에게 다음 중 어느 쪽이 더 일어날 확률이 높은지 질문하였다:
// “주사위를 6번 던져서 적어도 한 번 1이 나오는 것과 주사위를 12번 던져서 적어도 두 번 1이 나오는 것”. 
// 이 질문에 대한 답을 시뮬레이션을 통해 알아내는 프로그램을 작성하라. 
// 즉 T=1,000,000번의 실험을 반복하여 두 사건이 일어난 경우의 수를 각각 카운트하는 프로그램을 작성하라. 
// 6번 던져서 적어도 1번 1이 나오는 사건의 확률은 1-(5/6)6 ≃  0.6651이고, 
// 12번 중 적어도 2번 1이 나오는 사건의 확률은 1-(5/6)12-2(5/6)11 ≃ 0.618667이다. 
// 대략 이 확률에 근접하는 실험 결과가 나오면 정답이다

void p08() {
	srand((unsigned int)time(NULL));
	int dice,count=0;
	bool flag = false;
	for (int i = 0; i < 1000000; i++) {
		for (int j = 0; j < 6; j++) {
			dice = rand() % 6;
			if (dice == 0) {
				count++;
				break;
			}
		}
	}
	printf("6번 던져서 적어도 한번 %lf\n", count / 1000000.0);
	count = 0;
	for (int i = 0; i < 1000000; i++) {
		for (int j = 0; j < 12; j++) {
			dice = rand() % 6;
			if (dice == 0) {
				if (flag) {
					count++;
					flag = false;
					break;
				}
				flag = true;
			}
		}
	}
	printf("12번 던져서 적어도 한번 %lf\n", count / 1000000.0);

}


//10번 평면상에서 좌표축에 평행한 2개의 직사각형이 입력으로 주어진다. 
// 두 사각형이 교차하는 영역, 즉 두 사각형에 공통으로 포함되는 영역의 면적을 구하는 프로그램을 작성하라.
// 각각의 사각형은 대각 방향의 두 꼭지점의 좌표로 주어진다. 
// 꼭지점의 좌표값은 -1,000,000 이상이고 1,000,000이하의 정수이다.
// input 1 1 4 4 1 1 2 3 		output 2
void p10() {
	int x1, x2, y1, y2, x3, x4, y3, y4,temp,cntx=0,cnty=0;
	scanf_s("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
	if (x1 > x2) {
		temp = x1;
		x1 = x2;
		x2 = temp;
	}
	if (y1 > y2) {
		temp = y1;
		y1 = y2;
		y2 = temp;
	}
	if (x3 > x4) {
		temp = x3;
		x3 = x4;
		x4 = temp;
	}
	if (y3 > y4) {
		temp = y3;
		y3 = y4;
		y4 = temp;
	}
	printf("%d %d %d %d %d %d %d %d\n", x1, x2, y1, y2, x3, x4, y3, y4);
	while (x3 < x4) {
		if (x3 >= x1&&x3 < x2)
			cntx++;
		x3++;
	}
	while (y3 < y4) {
		if (y3 >= y1&&y3 < y2)
			cnty++;
		y3++;
	}
	printf("%d\n", cntx*cnty);
}


// 11번 (x = 0 or 1) 이며, x~는 x가 한번 한번 이상 반복되는 모든 이진 수열을 말하고,
//  (xyz)~는 괄호 안에 있는 xyz가 한번 이상 반복되는 모든 이진 수열을 말한다.
// ex)  	1~ = { 1, 11 ,111, 1111, ....}
//	(01)~ = { 01, 0101, 010101, 01010101,... }
//	(1001)~ = {1001, 10011001, 100110011001,...}
//	10~11 = {1011, 10011, 100011, 1000011,...}
//	(10~1)~ = {101, 1001, 10001,...,1011001,..., 100110110001101,...} 
//우리가 식별하고자 하는 패턴은 다음과 같다.
//	(100~1~)~
// 여기에 속하는 예를 들어보면, 1001, 10000111, 1000111001, 1001100011100011 등이다. 
// 입력으로 개의 0 혹은 1이 주어질 때, 이것이 (100~1~)~ 패턴에 해당되는지 아닌지를 판별하는 프로그램을 작성하라.
// N은 5,000 이하이고 배열을 사용해서는 안된다.
// 입력 형식: 먼저 이진 수열의 길이 N이 주어지고 다음 줄에는 0 혹은 1이 한 칸씩 띄워져서 N개 주어진다
// input 22 1 0 0 1 1 1 0 0 0 1 1 1 1 1 0 0 1 1 0 0 1 1 	output YES

void p11() {
	int pre, prepre, able = 0;
	bool result = false;
	int N;
	scanf_s("%d", &N);
	scanf_s("%d %d", &prepre, &pre);
	if (prepre == 1 && pre == 0)
		result = true;
	for (int i = 0; i < N - 2; i++) {
		prepre = pre;
		scanf_s("%d", &pre);
		switch (prepre * 4 + pre * 2 + able) {
		case 0:able = 1; break;
		case 1:break;
		case 2:result = false; break;
		case 3:able = 0; break;
		case 4:result = false; break;
		case 5:able = 0; break;
		case 6:able = 1; break;
		case 7:break;
		}
	}
	if(result)
		printf("YES");
	else
		printf("NO");
}

void main() {
	while (true)
		p11();
}

