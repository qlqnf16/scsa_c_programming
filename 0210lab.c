#if 0
#include <stdio.h>

#define DAYS 5

int main(void)
{
    double s, e, hr, total = 0;
    double pay;
    for (int i = 0; i < DAYS; i++) {
        scanf("%lf %lf", &s, &e);
        hr = e-s;
        if (hr > 1) {
            if (hr > 5) total += 4;
            else total += hr - 1;
        }
        printf("current: %.1f\n", total);
        hr = 0;
    }

    pay = total * 10000;

    if (total >= 15) pay *= 0.95;
    else if (total <= 5) pay *= 1.05;

    printf("%.f", pay);

    return 0;
}
#endif

// 케이크 자르기
#if 0
#include <stdio.h>

int main(void)
{
    // 여기서부터 작성
    int s1, e1, s2, e2,tmp, result = 0;
    scanf("%d %d\n%d %d", &s1, &e1, &s2, &e2);
    if (s1 > e1) { tmp = s1; s1 = e1; e1 = tmp; }
    if (s2 > e2) { tmp = s2; s2 = e2; e2 = tmp; }

    if (s1 < s2) {
        if (e1 > e2 || e1 < s2) result = 1;
    } else if (s1 > s2) {
        if (e1 < e2 || e2 < s1) result = 1;
    }

    printf("%scross", result ? "not " : "");
    return 0;
}
#endif

// 금메달은 누구?
#if 0
#include <stdio.h>
struct st {
    int id;
    int total;
} records[11], temp;


int totals[11];
int indx[11];
int medals[3];
char* medal[3] = { "GOLD", "SILVER", "BRONZE" };

int main(void)
{
    // 여기서부터 작성
    int N, idx, score, total, max, maxi, count;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &records[i].id);
        total = 0;
        for (int i = 0; i < 4; i++) {
            scanf("%d", &score);
            total += score;
        }
        records[i].total = total;
    }

    // 정렬
    for (int i = 0; i < 11; i++) {
        for (int j = i; j < 11; j++) {
            if (records[i].total < records[j].total) {
                temp = records[i];
                records[i] = records[j];
                records[j] = temp;
            }
        }
    }
 
    for (int i = 0; i < 11; i++) {
        for (int j = i; j < 11; j++) {
            if (records[i].total == records[j].total && records[i].id > records[j].id) {
                temp = records[i];
                records[i] = records[j];
                records[j] = temp;
            }
        }
    }

    max = records[0].total;  maxi = 0; count = 1;
    for (int i = 0; i < 11; i++) {
        if (records[i].total >= max) medals[maxi] = count++;
        else {
            maxi++;
            count = 1;
            max = records[i].total;
            medals[maxi] = count++;
        }

        if (maxi >= 3) break;
    }


    maxi = 0;
    for (int i = 0; i < 3; i++) {
        printf("%s : ", medal[i]);
        for (int j = 0; j < medals[i]; j++) {
            printf("%d ", records[maxi++].id);
        }
        printf("\n");
    }

    return 0;
}
#endif

// 최소공약수 최소공배수
#if 0
#include <stdio.h>

int gcd(int b, int l) {
    if (l == 0) return b;
    else return gcd(l, b % l);
}

int main(void)
{
    int a, b, temp, r, s;
    scanf("%d %d", &a, &b);
    
    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }
    
    r = gcd(a, b);
    s = (a / r) * (b / r) * r;
    printf("%d\n%d", r, s);


    return 0;
}
#endif

// 같은 모양 찾기
#if 0
#include <stdio.h>
#include <stdlib.h>

int** map, ** pattern;

int comparePattern(int a, int b, int P) {
    int i, j, pi, pj;
    pi = 0;
    for (i = a; i < a + P; i++) {
        pj = 0;
        for (j = b; j < b + P; j++) {
            printf("[%d][%d] map: %d, pattern[%d][%d]: %d\n",i, j ,map[i][j], pi, pj, pattern[pi][pj]);
            if (map[i][j] != pattern[pi][pj]) return 0;
            pj++;
        }
        pi++;
    }
    return 1;
}


int main(void)
{
    int M, P, count = 0;
    scanf("%d", &M);
    map = (int**)malloc(sizeof(int*) * M);
    for (int i = 0; i < M; i++) {
        map[i] = (int*)malloc(sizeof(int) * M);
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    scanf("%d", &P);
    pattern = (int**)malloc(sizeof(int*) * P);
    for (int i = 0; i < P; i++) {
        pattern[i] = (int*)malloc(sizeof(int) * P);
    }
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < P; j++) {
            scanf("%1d", &pattern[i][j]);
        }
    }

    for (int i = 0; i < M - P +1; i++) {
        for (int j = 0; j < M - P+1; j++) {
            if(comparePattern(i, j, P)) count ++;
        }
    }

    printf("%d", count);
    return 0;
}
#endif

// 배수의 합
#if 0
#include <stdio.h>
#define MAX 10000

int main(void)
{
    int N, n, sum = 0;
    scanf("%d", &N);
    n = N;

    while (1) {
        sum += n;
        n += N;
        if (sum >= MAX) break;
    }

    printf("%d", n - N - N);
    
    return 0;
}
#endif

// 숫자의 합
#if 0
#include <stdio.h>
#include <string.h>

int sums[3] = { 0 };

int pow(base, top) {
    int r = 1;
    while (top) {
        r *= base;
        top--;
    }
    return r;
}

int main(void)
{
    int N, temp, len, po; 
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &temp);
        if (temp >= 100) sums[2] += temp;
        else if (temp >= 10) sums[1] += temp;
        else len = sums[0] += temp;
    }

    for (int i = 2; i >= 0; i--) {      printf("%d ", sums[i]);
    }

    return 0;
}
#endif

// 배열 채우기
#if 0
#include <stdio.h>

int** map;

int main(void)
{
    int i, j, n, dir = 1, num = 1;
    scanf("%d", &n);
    /*
    map = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        map[i] = (int*)malloc(sizeof(int) * n);
    }
    */

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", num);
            if (j == n - 1) {
                dir = !dir;
                num += n;
            }
            else {
            if (dir) num++;
            else num--;
            }
        }
        printf("\n");
    }

    return 0;
}
#endif

// 배열 정리
#if 0
#include <stdio.h>
int** map;

int main(void)
{
    int x, y, count;
    scanf("%d %d", &x, &y);
    map = (int**)malloc(sizeof(int*) * x);
    for (int i = 0; i < x; i++) {
        map[i] = (int*)malloc(sizeof(int) * y);
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    for (int i = 0; i < x; i++) {
        count = 1;
        for (int j = 0; j < y; j++) {
            if (map[i][j] == 0) {
                printf("%d ", map[i][j]);
                count = 1;
            }
            else printf("%d ", count++);
        }
        printf("\n");
    }

    return 0;
}

#endif

// 피보나치
#if 0
#include <stdio.h>

int fibo[40];

int main(void)
{
    int n;
    scanf("%d", &n);

    fibo[0] = 1;
    fibo[1] = 1;
    for (int i = 2; i < n; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }

    printf("%d", fibo[n - 1]);
    return 0;
}
#endif

// 6174
#if 0
#include <stdio.h>

int number[4];

void sort(void) {
    int temp;
    for (int i = 0; i < 4; i++) {
        for (int j = i; j < 4; j++) {
            if (number[i] > number[j]) {
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }
    }
}

int pow(base, top) {
    int num = 1;
    while (top--) num *= base;
    return num;
}

int main(void)
{
    int i, big=0, little=0, diff=0, count = 0;
    for (i = 0; i < 4; i ++) scanf("%1d", &number[i]);

    while (diff != 6174) {
        big = 0; little = 0;
        sort();
        for (i = 0; i < 4; i++) big += number[i] * pow(10, i);
        for (i = 3; i >= 0; i--) little += number[i] * pow(10, 3 - i);
        diff = big - little;
        for (i = 0; i < 4; i++) number[i] = diff / pow(10, i) % 10;
        count++;
    }
    printf("%d", count);
}

#endif


// 카드게임
#if 0
#include <stdio.h>
#include <stdlib.h>

int** cards;
int* scores;
int main(void)
{
    int players, win;
    scanf("%d", &players);

    scores = calloc(sizeof(int), players);
    cards = (int**)malloc(sizeof(int*) * players);
    for (int i = 0; i < players; i++) {
        cards[i] = (int*)malloc(sizeof(int) * 3);
    }

    for (int i = 0; i < players; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &cards[i][j]);
        }
    }

    for (int t = 0; t < 3; t++) {
        for (int i = 0; i < players; i++) {
            win = 1;
            for (int j = 0; j < players; j++) {
                if (i != j && cards[i][t] == cards[j][t]) {
                    win = 0; break;
                }
            }
            if (win) {
                scores[i] += cards[i][t];
            }
        }
    }

    for (int i = 0; i < players; i++) {
        printf("%d\n", scores[i]);
    }

    return 0;
}
#endif

// 순환 수열
#if 0
#include <stdio.h>

int visitcheck[10000001];

int main(void)
{
    int n, p, num, cnt=0;
    scanf("%d %d", &n, &p);
    num = n;
    //visitcheck[num] = 1;

    while (1) {
        num = num * n % p;
        if (visitcheck[num]) break;
        else {
            visitcheck[num] = 1;
            cnt++;
        }
    }

    printf("%d", cnt);
    return 0;
}
#endif

// 찢어진 책
#if 0
#include <stdio.h>

int main(void)
{
    int N, sum, oriSum = 0, n = 1, d;
    scanf("%d %d", &N, &sum);

    for (int i = 0; i < N; i++) {
        oriSum += n;
        n ++;
    }

    d = oriSum - sum;
    if (d < 0 || d > N*2 || d%2 == 0 || d/2%2 == 0) printf("Error");
    else printf("%d %d", d / 2, d / 2 + 1);

    return 0;
}
#endif


// 같은 모양 찾기2
#if 0
#include <stdio.h>
#include <stdlib.h>
#define MAX 110

int M, P;
int map[MAX][MAX], pattern[MAX][MAX], newpattern[MAX][MAX];

int comparePattern(int a, int b) {
    int i, j, pi, pj;
    pi = 0;
    for (i = a; i < a + P; i++) {
        pj = 0;
        for (j = b; j < b + P; j++) {
            //printf("[%d][%d] map: %d, pattern[%d][%d]: %d\n", i, j, map[i][j], pi, pj, pattern[pi][pj]);
            if (map[i][j] != pattern[pi][pj]) return 0;
            pj++;
        }
        pi++;
    }
    return 1;
}

void rotatePattern(void) {
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < P; j++) {
            newpattern[i][j] = pattern[P - 1 - j][i];
        }
    }

    for (int i = 0; i < P; i++) {
        for (int j = 0; j < P; j++) {
            pattern[i][j] = newpattern[i][j];
        }
    }
}


int main(void)
{
    int count = 0;
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    scanf("%d", &P);
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < P; j++) {
            scanf("%1d", &pattern[i][j]);
        }
    }

    for (int t = 0; t < 4; t++) {
        for (int i = 0; i < M - P + 1; i++) {
            for (int j = 0; j < M - P + 1; j++) {
                if (comparePattern(i, j)) count++;
            }
        }
        rotatePattern();
    }

    printf("%d", count);
    return 0;
}
#endif

// 에라스토테네스의 체
#if 0
#include <stdio.h>
#define MAX 1001

int nums[MAX];
int n, k;

int erat(void) {
    int found, cnt = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (nums[i * j] == 0) {
                if (i * j > n) break;
                //printf("%d ", i * j);
                nums[i * j] = 1;
                cnt++;
                if (cnt == k) return i * j;
            }
        }
    }
}

int main(void)
{
    // 여기서부터작성
    int res;
    scanf("%d %d", &n, &k);
    
    res = erat();
    printf("%d", res);

    return 0;
}

#endif

// 기상청
#if 0
#include <stdio.h>
#define MAX 101

char sky[MAX][MAX];

int main(void)
{
    int H, W, lastCloud;
    scanf("%d %d", &H, &W);
    for (int i = 0; i < H; i++) {
        scanf("%s", sky[i]);
        fflush(stdin);
    }

    for (int i = 0; i < H; i++) {
        lastCloud = -1;
        for (int j = 0; j < W; j++) {
            if (sky[i][j] == 'c') {
                printf("%d ", 0);
                lastCloud = 0;
            }
            else {
                if (lastCloud >= 0) lastCloud++;
                printf("%d ", lastCloud);
            }
        }
        printf("\n");
    }

    return 0;
}
#endif