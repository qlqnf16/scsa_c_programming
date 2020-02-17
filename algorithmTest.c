// 1
#if 0
#include <stdio.h>

int a, b, c;
int time[101];
int sum;

void fillTime(int s, int e) {
	for (int i = s+1; i <= e; i++) {
		time[i] += 1;
	}
}

int main(void) {
	int min = 987, max = 0, start, end;

	scanf("%d %d %d", &a, &b, &c);
	for (int i = 0; i < 3; i++) {
		scanf("%d %d", &start, &end);
		fillTime(start, end);
		if (start < min) min = start;
		if (end > max) max = end;
	}

	for (int i = min; i <= max; i ++) {
		if (time[i] == 1) sum += a;
		else if (time[i] == 2) sum += b * 2;
		else if (time[i] == 3) sum += c * 3;
	}

	printf("%d", sum);

	return 0;
}

#endif

// 2
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char sentence[1010];
int checkAlphabet[26];
int sum;

int main(void) {
	int len, idx;

	gets(sentence);
	for (int i = 0; i < strlen(sentence); i++) {
		if (sentence[i] >= 'a' && sentence[i] <= 'z') sentence[i] -= 32;
		if (sentence[i] >= 'A' && sentence[i] <= 'Z') {
			idx = sentence[i] - 'A';
			if (!checkAlphabet[idx]) {
				checkAlphabet[idx] = 1;
				sum += 1;
			}
		}
	}

	printf("%s", sum == 26 ? "pangram" : "not pangram");

	return 0;
}

#endif

// 3
#if 0
#include <stdio.h>
#define MAX 1010

int lens[MAX];
int n, sum;
int min = 2000;

int main(void) {
	int temp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &lens[i]);
		if (lens[i] < min) min = lens[i];
	}

	sum = n;
	while (sum) {
		printf("%d\n", sum);
		temp = 2000;
		//printf("min: %d", min);
		for (int i = 0; i < n; i++) {
			if (lens[i]) {
				lens[i] -= min;
				if (lens[i] <= 0) sum--;
				if (lens[i] && lens[i] < temp) temp = lens[i];
			}
		}
		min = temp;
	}

	return 0;
}

#endif

// 4 refactoring needed
#if 0
#include <stdio.h>

int clockNum[4];
int inputNum[4];
int allNum[10000][4];
int allClockNum[10000];
int visit[10000];
int cnt, idx;

int pow(int top) {
	int base = 1;
	while (top--) base *= 10;
	return base;
} 

int findClockNum(void) {
	int temp, min = 10000;
	for (int i = 0; i < 4; i++) {
		temp = inputNum[i % 4] * 1000 + inputNum[(i + 1) % 4] * 100 + inputNum[(i + 2) % 4] * 10 + inputNum[(i + 3) % 4];
		if (temp < min) min = temp;
	}

	for (int i = 0; i< 4; i++) {
		clockNum[3 - i] = min / pow(i) % 10;
	}
	//printf("min: %d\n", min);
	return min;
}


void fillClockNums(void) {
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			for (int k = 1; k < 10; k++) {
				for (int m = 1; m < 10; m++) {
					allNum[idx][0] = i;
					allNum[idx][1] = j;
					allNum[idx][2] = k;
					allNum[idx][3] = m;
					idx++;
				}
			}
		}
	}
}

void getRealClockNums(void) {
	int ix = 0, temp, min = 10000;

	for (int k = 0; k < idx; k++) {
		min = 10000;
		for (int i = 0; i < 4; i++) {
			temp = allNum[k][i % 4] * 1000 + allNum[k][(i + 1) % 4] * 100 + allNum[k][(i + 2) % 4] * 10 + allNum[k][(i + 3) % 4];
			if (temp < min) min = temp;
		}

		if (!visit[min]) {
			allClockNum[ix++] = min;
			visit[min] = 1;
			cnt++;
		}
	}
}

/*
void swapArr(int i, int j) {
	int temp[4];
	for (int k = 0; k < 4; k++) { temp[k] = allClockNum[i][k]; };
	for (int k = 0; k < 4; k++) { allClockNum[i][k] = allClockNum[j][k]; };
	for (int k = 0; k < 4; k++) { allClockNum[j][k] = temp[k]; };
}
*/

void sort(void) {
	int temp;
	for (int i = 0; i < cnt; i++) {
		for (int j = i + 1; j < cnt; j++) {
			if (allClockNum[i] > allClockNum[j]) {
				temp = allClockNum[i];
				allClockNum[i] = allClockNum[j];
				allClockNum[j] = temp;
			}
		}
	}
}

int main(void) {
	int found;
	for (int i = 0; i < 4; i++) {
		scanf("%d", &inputNum[i]);
	}

	fillClockNums();
	getRealClockNums();
	sort();
	found = findClockNum();

	/*
	for (int i = 0; i < cnt; i++) {
		printf("%d " , allClockNum[i]);
	}
	*/

	for (int i = 0; i < cnt; i++) {
		if (allClockNum[i] == found) {
			printf("%d", i+1);
			return 0;
		}
	}
	
	
	



	return 0;
}

#endif

// 5


#if 0
#include <stdio.h>

int n, kmin, kmax;
int scores[1001];
int snum[3];
int min;

void sortScore(void) {
	int temp;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (scores[i] > scores[j]) {
				temp = scores[i];
				scores[i] = scores[j];
				scores[j] = temp;
			}
		}
	}
}

int calcDiffBetweenStuents(void) {
	int min = 987987, max = -1;

	for (int i = 0; i < 3; i++) {
		if (snum[i] < min) min = snum[i];
		if (snum[i] > max) max = snum[i];
	}

	if (min < kmin) return 999;
	if (max > kmax) return 999;

	return max - min;
}

void initStuNums(void) {
	snum[0] = n / 3;
	snum[1] = n / 3;
	snum[2] = n - ((n / 3) * 2);
}

void findAnswer(void) {
	int t1, t2, duplesst1, dupt1, duplesst2, dupt2, temp;

	sortScore();
	t1 = n / 3 - 1;
	t2 = t1 + n / 3;
	min = 987;
	initStuNums();

	duplesst1 = dupt1 = duplesst2 = dupt2 = 0;
	
	// t1 미만반 t1 이상반 비교
	if (scores[t1] == scores[t1 + 1]) {
		// t1미만 개수 / t1 이상 개수 
		for (int i = t1; i >= 0; i--) {
			if (scores[i] == scores[t1]) duplesst1++;
		}
		for (int i = t1 + 1; i < n; i++) {
			if (scores[i] == scores[t1]) dupt1++;
		}
	}

	// t2 미만반 t2 이상반 비교
	if (scores[t2] == scores[t2 + 1]) {
		// t1미만 개수 / t1 이상 개수 
		for (int i = t2; i >= 0; i--) {
			if (scores[i] == scores[t2]) duplesst2++;
		}
		for (int i = t2 + 1; i < n; i++) {
			if (scores[i] == scores[t2]) dupt2++;
		}
	}

	if (scores[t1] == scores[t1 + 1] && scores[t2] != scores[t2 + 1]) {
		snum[0] -= duplesst1;
		snum[1] += duplesst1;
		temp = calcDiffBetweenStuents();
		if (temp < min) min = temp;
		initStuNums();

		snum[0] += dupt1;
		snum[1] -= dupt1;
		temp = calcDiffBetweenStuents();
		if (temp < min) min = temp;
		initStuNums();
		
		return  0;
	}

	if (scores[t1] == scores[t1 + 1] && scores[t2] != scores[t2 + 1]) {
		snum[1] -= duplesst2;
		snum[2] += duplesst2;
		temp = calcDiffBetweenStuents();
		if (temp < min) min = temp;
		initStuNums();

		snum[1] += dupt2;
		snum[2] -= dupt2;
		temp = calcDiffBetweenStuents();
		if (temp < min) min = temp;
		initStuNums();

		return  0;
	}

	// 최적의 옮기기 찾기
	//1 -> ->
	snum[0] -= duplesst1;
	snum[1] += duplesst1;
	snum[1] -= duplesst2;
	snum[2] += duplesst2;
	temp = calcDiffBetweenStuents();
	if (temp < min) min = temp;
	initStuNums();

	//2 <- <-
	snum[0] += dupt1;
	snum[1] -= dupt1;
	snum[1] += dupt2;
	snum[2] -= dupt2;
	temp = calcDiffBetweenStuents();
	if (temp < min) min = temp;
	initStuNums(); 

	//3 -> <
	snum[0] -= duplesst1;
	snum[1] += duplesst1;
	snum[1] += dupt2;
	snum[2] -= dupt2;
	temp = calcDiffBetweenStuents();
	if (temp < min) min = temp;
	initStuNums();

	//4 <- ->
	snum[0] += t1;
	snum[1] -= t1;
	snum[1] -= duplesst2;
	snum[2] += duplesst2;
	temp = calcDiffBetweenStuents();
	if (temp < min) min = temp;
	initStuNums();
}

int main(void) {
	int tc;
	scanf("%d", &tc);

	for (int i = 0; i < tc; i++) {
		scanf("%d %d %d", &n, &kmin, &kmax);
		for (int j = 0; j < n; j++) {
			scanf("%d", &scores[j]);
		}

		findAnswer();
		printf("%d\n", min == 987 ? -1 : min);
	}

	return 0;
}

#endif

// 6

#if 0
#include <stdio.h>
#define MAX 110

struct st {
	int time;
	char direction;
}movement[MAX];

int map[MAX][MAX];
int n, k, l;
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int dirIdx;
int snaker, snakec;
int isGameover;
int totalTime;
int tailr, tailc;

void showMap(void);

void clearTail(void) {
	int r, c;

	printf("TAIL: %d %d\n", tailr, tailc);
	for (int i = 0; i < 4; i++) {
		r = tailr + dir[i][0];
		c = tailc + dir[i][1];
		
		if ((r >= 0 && r < n && c >= 0 && c < n) && map[r][c] == 2) {
			map[tailr][tailc] = 0;
			tailr = r;
			tailc = c;
		}
	}

}

void moveSnake(int sec, int turnRight) {
	int r, c;

	for (int i = 0; i < sec; i++) {
		r = snaker + dir[dirIdx][0];
		c = snakec + dir[dirIdx][1];
		totalTime++;

		if (!(r >= 0 && r < n && c >= 0 && c < n) || map[r][c] == 2) {
			isGameover = 1;
			return;
		}
		map[snaker][snakec] = 0;
		if (map[r][c] == 1) {
			map[snaker][snakec] = 2;
			map[r][c] = 0;
		}
		else if (map[r][c] == 0) clearTail();

		snaker = r;
		snakec = c;
		map[snaker][snakec] = 3;
		
		
		showMap();
		printf("\n");
		
	}

	if (turnRight) { 
		dirIdx++; 
		if (dirIdx >= 4) dirIdx = 0;
	}
	else {
		dirIdx--;
		if (dirIdx < 0) dirIdx = 3;
	}

}

int main(void) {
	int r, c, dir;

	scanf("%d\n%d", &n, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &r, &c);
		map[r-1][c-1] = 1;
	}

	scanf("%d", &l);
	for (int i = 0; i < l; i++) {
		scanf("%d %c", &movement[i].time, &movement[i].direction);
	}

	for (int i = 0; i < l; i++) {
		dir = (movement[i].direction == 'D') ? 1 : 0;
		moveSnake(movement[i].time, dir);
		if (isGameover) break;
	}
	
	printf("%d", totalTime);

	return 0;
}

void showMap(void) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}
 

#endif

// 6 다시
#if 1
#include <stdio.h>
#define MAX 10001

struct st {
	int time;
	char direction;
}movement[MAX];

int map[MAX][MAX];
int n, k, l;
int dir[4][2]= { {0,1},{1,0},{0,-1},{-1,0} };
int di;

int snakeQueue[MAX][2];
int head, tail;
int r, c;

int isGameover;
int totalTime;

void showMap(void);

void showQueue(void) {
	for (int i = tail; i <= head; i++) {
		printf("[%d,%d] ", snakeQueue[i][0], snakeQueue[i][1]);
	}
	printf("\n");
}

int moveSnake(int sec, int turnRight) {
	int nextr, nextc, tailr, tailc;

	for (int i = 0; i < sec; i++) {
		nextr = r + dir[di][0];
		nextc = c + dir[di][1];
		totalTime++;

		if (!(nextr >= 0 && nextr < n && nextc >= 0 && nextc < n) || map[nextr][nextc] == 2) {
			isGameover = 1;
			return;
		}

		head++;
		snakeQueue[head][0] = nextr;
		snakeQueue[head][1] = nextc;

		if (map[nextr][nextc] == 0) {
			tailr = snakeQueue[tail][0];
			tailc = snakeQueue[tail][1];
			map[tailr][tailc] = 0;

			tail++;
		}
		if (map[nextr][nextc] == 1) {
			map[r][c] = 2;
		}

		map[nextr][nextc] = 3;
		r = nextr;
		c = nextc;
		
		showQueue();
		showMap();
	}

	if (turnRight) {
		di++;
		if (di >= 4) di = 0;
	}
	else {
		di--;
		if (di < 0) di = 3;
	}
}


int main(void) {
	int r, c, dir;

	scanf("%d\n%d", &n, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &r, &c);
		map[r - 1][c - 1] = 1;
	}

	scanf("%d", &l);
	for (int i = 0; i < l; i++) {
		scanf("%d %c", &movement[i].time, &movement[i].direction);
	}

	for (int i = 0; i < l; i++) {
		dir = (movement[i].direction == 'D') ? 1 : 0;
		moveSnake(movement[i].time, dir);
		if (isGameover) break;
	}

	printf("%d", totalTime);

	return 0;
}


void showMap(void) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}

#endif