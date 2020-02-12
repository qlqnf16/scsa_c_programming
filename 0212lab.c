// d8 문자사각형 
#if 0
#include <stdio.h>

char map[110][110];

int main(void) {
	int n, plus = 0;
	scanf("%d", &n);

	for (int j = n - 1; j >= 0; j--) {
		for (int i = n - 1; i >= 0; i--) {
			if (plus >= 26) plus = 0;
			map[i][j] = 'A' + plus++;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%c ", map[i][j]);
		}
		printf("\n");

	}

	return 0;
}
#endif

// D9 달팽이 사각형
#if 0
#include <stdio.h>

int map[110][110];
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int main(void) {
	int n, sqr, num = 1, i = 0, j = 0, di = 0; 
	int end0, end1, end2, end3;
	scanf("%d", &n);
	sqr = n * n;
	end0 = end1 = n - 1;
	end2 = 0;
	end3 = 1;

	while (num <= sqr) {
		map[i][j] = num++;
		if (di == 0 && j == end0) di++, end0--;
		else if (di == 1 && i == end1) di++, end1--;
		else if (di == 2 && j == end2) di++, end2++;
		else if (di == 3 && i == end3) di = 0, end3++;

		i += dir[di][0];
		j += dir[di][1];
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}

	return 0;
}
#endif

// E0 마방진
#if 0
#include <stdio.h>

int map[110][110];
int n;

void printMap(void) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void fillMap(int sj, int target) {
	int i = 0, j = sj, num = 1;
	while (num <= target) {
		map[i][j] = num;
		if (num % n) {
			i -= 1; j -= 1;
			if (i < 0) i = n - 1;
			if (j < 0) j = n - 1;
		}
		else i += 1;
		num++;
	}
}


int main(void) {
	scanf("%d", &n);
	fillMap(n / 2, n * n);
	printMap();

	return 0;
}
#endif

// E1 대각선 지그재그
#if 0
#include <stdio.h>

int map[110][110];
int n;

void printMap(void) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}

int main(void) {
	int dir = 0, num = 1, sqr, i, j;
	scanf("%d", &n);
	sqr = n * n;

	i = 0; j = 0;
	while (num <= sqr) {
		map[i][j] = num++;
		if (dir) {
			i--; j++;
			if (i < 0 || j >= n) {
				if (j >= n) i += 2, j--;
				else i++;
				dir = !dir;
			}
		}
		else {
			i++; j--;
			if (j < 0 || i >= n) {
				if (i >= n) j += 2, i--;
				else j++;
				dir = !dir;
			}
		}
	}

	printMap();

	return 0;
}
#endif

// E2 창고다각형
#if 0
#include <stdio.h>

#define MAX 1010

int pillars[MAX];
int n;
int s = -1, e;
int max, maxs, maxe;
int sum, fin;

void findSize(void) {
	for (int i = 0; i < MAX; i++) {
		if (pillars[i] && s == -1) s = i;
		if (pillars[i] && i >= e) e = i;
	}
}

void findMax(void) {
	for (int i = 0; i <= e; i++) {
		if (pillars[i] > max) {
			max = pillars[i];
			maxs = i;
			maxe = i;
		}
		else if (pillars[i] == max) maxe = i;
	}
	fin = (maxe - maxs + 1) * max;
}

int makeRoof(void) {
	int current = pillars[s], width = 0;
	for (int i = s+1; i <= maxs; i++) {
		width++;
		if (current < pillars[i]) {
			sum += width * current;
			current = pillars[i];
			width = 0;
		}
	}
	width = 0;
	current = pillars[e];
	for (int i = e-1; i >= maxe; i--) {
		width++;
		if (current < pillars[i]) {
			sum += width * current;
			current = pillars[i];
			width = 0;
		}
	}
}

int main(void) {
	int indx, temp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &indx, &temp);
		pillars[indx] = temp;
	}
	findSize();
	findMax();
	makeRoof();
	printf("%d", sum + fin);

	return 0;
}
#endif

// E3 그림 확대하기
#if 0
#include <stdio.h>

char paper[1000][1000];
int r, c;
int zr, zc;

int main(void) {
	scanf("%d %d %d %d", &r, &c, &zr, &zc);

	for (int i = 0; i < r; i++) {
		scanf("%s", paper[i]);
	}

	for (int i = 0; i < r; i++) {
		for (int k = 0; k < zr; k++) {
			for (int j = 0; j < c; j++) {
				for (int m = 0; m < zc; m++) {
					printf("%c", paper[i][j]);
				}
			}
			printf("\n");
		}
	}

	return 0;
}
#endif


// E4 종이접기
#if 0
#include <stdio.h>
#include <string.h>
#define MAX 10000000

int n;
char fold[MAX] = "^VV";
char next[MAX];


int main(void) {
	int idx, len;
	scanf("%d", &n);

	if (n == 1) printf("V");
	else if (n == 2) printf("%s", fold);
	else
	{
		for (int i = 3; i <= n; i++) {
			idx = 0; len = strlen(fold);
			for (int j = len - 1; j >= 0; j--) {
				next[idx++] = fold[j] == '^' ? 'V' : '^';
			}
			next[idx++] = 'V';
			for (int j = 0; j < len; j++) {
				next[idx++] = fold[j];
			}
			strcpy(fold, next);
		}

		printf("%s", fold);
	}
		
	return 0;
}
#endif

// E5 문자열뒤집기
#if 0
#include <stdio.h>
#include <string.h>

char str[52][52];
char input[52];

int main(void) {
	int idx = 0, idx2 = 0;
	for (;;) {
		scanf("%c", &input);
		if (input == 10) break;
		else if (input == ' ' || input == '.' || input == '!') {
			idx++;
			idx2 = 0;
			str[idx][idx2] = input;
			idx++;
		}
		else str[idx][idx2++] = input;
	}

	for (int j = 0; j <= idx; j++) {
		if (strlen(str[j])) {
			for (int i = strlen(str[j]) - 1; i >= 0; i--) {
				if (str[j][i] >= 'a' && str[j][i] <= 'z') printf("%c", str[j][i] - 32);
				else printf("%c", str[j][i]);
			}
		}
	}

	return 0;
}
#endif

// E6 문자열 찾기
#if 0
#include <stdio.h>
#define MAX 10010
char compare[3] = "OI";
char input[MAX];

int main(void) {
	int ci, koi, ioi, koiCnt=0, ioiCnt=0;
	scanf("%s", input);

	for (int i = 0; i < strlen(input); i++) {
		if (input[i] == 'K' || input[i] == 'I') {
			if (input[i] == 'K') koi = 1, ioi = 0;
			else koi = 0, ioi = 1;

			ci = 0;
			for (int j = i + 1; j < i + 3; j++) {
				if (input[j] == compare[ci]) ci++;
				else break;
			}
			if (ci >= 2) {
				if (koi) koiCnt++;
				else ioiCnt++;
			}
		}
	}

	printf("%d\n%d", koiCnt, ioiCnt);

	return 0;
}
#endif

// E7 문자열 변환
#if 0
#include <stdio.h>

#define MAX 100010

char chTochange[130];
char str[MAX];
int n, m;

int main(void) {
	int i;
	char idx, temp, input;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf(" %c %c", &idx, &temp);
		chTochange[idx] = temp;
	}

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf(" %c", &temp);
		if (chTochange[temp]) str[i] = chTochange[temp];
		else str[i] = temp;
	}

	printf("%s", str);

	return 0;
}
#endif

// E8 체스판
#if 0
#include <stdio.h>

int r, c, a, b;

int main(void) {
	int red, redi;
	scanf("%d %d", &r, &c);
	scanf("%d %d", &a, &b);
	redi = 1;


	for (int i = 0; i < r * a; i++) {
		if (i > 0 && i % a == 0) redi = !redi;
		red = redi;
		for (int j = 0; j < c * b; j++) {
			if (j > 0 && j % b == 0) red = !red;
			printf("%c", red ? 'X' : '.');
		}
		printf("\n");
	}


	return 0;
}
#endif

// E9 미로탈출 로봇
#if 01
#include <stdio.h>
#define VALIDLOC (map[x][y] != 1 && (x >= 0 && x < n && y >= 0 && y < n))

int map[10][10];
int visit[10][10];

int dir[4][2] = { {1, 0}, {0, -1}, {-1, 0}, {0, 1} };
int dirOrd[4];
int n;
int dis;

void startMove(void) {
	int prevx, prevy, x, y, di = 0, re;

	visit[0][0] = 1;
	prevx = 0, prevy = 0;

	while (1)
	{
		x = prevx + dir[dirOrd[di]][0];
		y = prevy + dir[dirOrd[di]][1];
		if (VALIDLOC && visit[x][y]) return;
		if (!VALIDLOC) {
			re = di;
			while (!VALIDLOC)
			{
				di++;
				if (di == 4) di = 0;
				if (di == re) return;
				x = prevx + dir[dirOrd[di]][0];
				y = prevy + dir[dirOrd[di]][1];
				if (visit[x][y]) return;
			}
		}

		visit[x][y] = 1;
		prevx = x;
		prevy = y;
		dis++;

		if (dis >= n * n -1) break;
	}
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	for (int i = 0; i < 4; i++) {
		scanf("%d", &dirOrd[i]);
		dirOrd[i]--;
	}

	startMove();

	printf("%d", dis);


	return 0;
}
#endif

// F0 큰숫자연산
#if 0
#include <stdio.h>
#include <string.h>

char num1[101];
char num2[101];
char cal[2];

int main(void) {
	int len, smallLen, len1, len2;

	gets(num1);
	gets(cal);
	gets(num2);

	if (cal[0] == '*') {
		len = strlen(num1) + strlen(num2) - 2;
		printf("%d", 1);
		for (int i = 0; i < len; i++) printf("%d", 0);
	}
	else {
		len1 = strlen(num1) - 1;
		len2 = strlen(num2) - 1;
		len = len1 > len2 ? len1 : len2;

		if (len1 == len2) printf("%d", 2);
		else {
			smallLen = len1 > len2 ? len2 : len1;
			printf("%d", 1);
		
		}

		for (int i = 0; i < len; i++) {
			if (len1 != len2 && i == len - smallLen - 1) {
				printf("%d", 1);
			}
			else printf("%d", 0);
		}
	}
	return 0;
}
#endif

// F1 해킹
#if 0
#include <stdio.h>
#include <string.h>

char clues[101][15];
char reverse[15];
int n;

int main(void) {
	int len;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", clues[i]);
	}

	for (int i = 0; i < n; i++) {
		len = strlen(clues[i]);
		for (int j = 0; j < len; j++) {
			reverse[j] = clues[i][len - 1 - j];
		}
		for (int j = i + 1; j < n; j++) {
			if (!strcmp(clues[j], reverse)) {
				printf("%d %c", len, reverse[len / 2]);
				return 0;
			}
		}
	}

	return 0;
}
#endif