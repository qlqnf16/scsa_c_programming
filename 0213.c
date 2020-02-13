// F2 100만들기
#if 0
#include <stdio.h>

int nums[10];

void sort(void) {
    int temp;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (nums[i] < nums[j]) {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
}

void findNumsToRemove(int diff) {
    for (int i = 8; i >= 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            if (nums[i] + nums[j] == diff) {
                nums[i] = 0;
                nums[j] = 0;
                return;
            }
        }
    }
}

int main(void)
{
    int sum = 0, diff;
    for (int i = 0; i < 9; i++) {
        scanf("%d", &nums[i]);
        sum += nums[i];
    }
    diff = sum - 100;

    sort();
    findNumsToRemove(diff);

    for (int i = 0; i < 9; i++) {
        if (nums[i]) printf("%d\n", nums[i]);
    }

    return 0;
}

#endif

// F3 잃어버린 페이지
#if 0
#include <stdio.h>

int pages[260][4];
int n;

void printPage(int p) {
    for (int i = 0; i < n / 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (pages[i][j] == p) {
                for (int k = 0; k < 4; k++) {
                    if (k != j) printf("%d ", pages[i][k]);
                }
                return;
            }
        }
    }
}

int main(void)
{
    int p, ps, pe, idx;
    scanf("%d %d", &n, &p); 
    ps = 1;
    pe = n;
    idx = 0;
    while (ps < pe) {
        pages[idx][0] = ps++;
        pages[idx][1] = ps++;
        pages[idx][3] = pe--;
        pages[idx][2] = pe--;
        idx++;
    }

    printPage(p);


    return 0;
}

#endif

// F4 폭탄돌리기
#if 0
#include <stdio.h>

int players[9];
int player;
int n;

int main(void)
{
    int timeinput, acctime = 0;
    char result;

    scanf("%d\n%d", &player, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %c", &timeinput, &result);

        if (result == 'T') {
            player++;
            if (player == 9) player = 1;
        }
        acctime += timeinput;
        players[player] += acctime;

        if (acctime >= 210) {
            printf("%d", result == 'T' ? player - 1 : player);
            return 0;
        }
    }
    printf("%d", player);

    return 0;
}

#endif

// F5 색종이
#if 0
#include <stdio.h>

int paper[110][110];
int n;

void colorPaper(int r, int c) {
    for (int i = r; i < r + 10; i++) {
        for (int j = c; j < c + 10; j++) {
            if (!paper[i][j]) paper[i][j] = 1;
        }
    }
}

int main(void)
{
    int xin, yin, r, c, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &xin, &yin);
        c = xin;
        r = 99 - (yin + 9);
        colorPaper(r, c);
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            printf("%d ", paper[i][j]);
            if (paper[i][j]) cnt++;
        }
        printf("\n");
    }

    printf("%d", cnt);

    return 0;
}

#endif

// F6 두 수의 최소합
#if 0
#include <stdio.h>

int n;
int nums[15];
int zeros[2];

int zerocnt;
int big;
int small;

void sort(void) {
    int temp, min = 999;
    for (int i = 0; i < n-zerocnt; i++) {
        for (int j = i+1; j < n-zerocnt; j++) {
            if (nums[i] > nums[j]) {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
}

int pow(int top) {
    int base = 1;
    while (top--) base *= 10;
    return base;
}

int zeroExists(void) {
    int cnt = 0;
    for (int i = 0; i < 2; i++) {
        if (zeros[i]) cnt++;;
    }
    return cnt;
}

int main(void)
{
    int input, idx = 0, visit1 = 0, visit2 = 0, top1, top2;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &input);
        if (input) nums[idx++] = input;
        else zerocnt++;
    }

    sort();
    idx = 0;
    if (n % 2) {
        big += nums[idx++] * pow(n / 2);
    }

    for (int i = (n/2) - 1; i >= 0; i--) {
        if (i == n / 2 - 1) {
                small += nums[idx++] * pow(i);
            if (n % 2 == 0) { 
                big += nums[idx++] * pow(i); 
            }
            else {
            if (zerocnt) zerocnt--;
            else big += nums[idx++] * pow(i);
            
            }
            
           
        }
        else {
            if (zerocnt) zerocnt--;
            else big += nums[idx++] * pow(i);
            if (zerocnt) zerocnt--;
            else small += nums[idx++] * pow(i);
        }
    }

    printf("%d", big+small);

    return 0;
}

#endif

// F7 분수 정렬
#if 0
#include <stdio.h>

int n, cnt;
int bunmo[13000];
int bunja[13000];

int isALagerThanB(int a, int b) {
    int aja = bunja[a], amo = bunmo[a], bja = bunja[b], bmo = bunmo[b];

    if (aja == bja) return amo > bmo ? 0 : 1;
    else if (amo == bmo) return aja > bja ? 1 : 0;
    else {
        aja *= bmo;
        bja *= amo;
        return aja > bja ? 1 : 0;
    }
}

void swapBunsu(int i, int j) {
    int tempja, tempmo;

    tempja = bunja[i];
    bunja[i] = bunja[j];
    bunja[j] = tempja;

    tempmo = bunmo[i];
    bunmo[i] = bunmo[j];
    bunmo[j] = tempmo;
}

int isRelativelyPrime(int a, int b) {
    for (int i = 2; i <= b; i++) {
        if (a % i == 0 && b % i == 0) return 0;
    }
    return 1;
}

void sort(void) {
    for (int i = 0; i < cnt; i++) {
        for (int j = i+1; j < cnt; j++) {
            if (isALagerThanB(i, j)) swapBunsu(i, j);
        }
    }
}

int main(void)
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
       for (int j = n; j > 0; j--) {
           if (j > i && (isRelativelyPrime(i, j))) {
               bunja[cnt] = i;
               bunmo[cnt] = j;
               cnt++;
           }
       }
    }

    sort();
    printf("0/1\n");
    for (int i = 0; i < cnt; i++) {
        printf("%d/%d\n", bunja[i], bunmo[i]);
    }
    printf("1/1\n");

    return 0;
}

#endif

// F8 원 안의 사각형
#if 0
#include <stdio.h>


int main(void)
{
    int n, sqr, height, sum = 0;
    scanf("%d", &n);
    sqr = n * n;
    height = n;

    for (int i = 1; i < n; i++) {
        
        while (i * i + height * height > sqr) {  
            height--; 
        }
        sum += height;
    }

    printf("%d", sum * 4);

    return 0;
}

#endif

// F9 달팽이삼각형
#if 0
#include <stdio.h>

int dir[3][2] = { {1, 1}, {0, -1}, {-1, 0} };
int end[3];

int map[110][110];
int n, maxcnt;

void printMap(void);

void clearMap(void) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            map[i][j] = -1;
        }
    }
}

void fillMap(void) {
    int num = 1, x, y, nextX, nextY, di = 0;
    
    x = 0, y = 0;
    map[x][y] = 0;
    for (int i = 0; i < maxcnt-1; i++) {
        nextX = x + dir[di][0];
        nextY = y + dir[di][1];
        map[nextX][nextY] = num++;
        if (num >= 10) num = 0;

        if (di == 0 && nextX == end[0]) { end[0]--; di++; }
        else if (di == 1 && nextY == end[1] ) { end[1] ++; di++; }
        else if (di == 2 && nextX == end[2]) { end[2] +=2; di = 0; }

        x = nextX; y = nextY;
    }

}

void printMap(void) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] < 0) break;
           else printf("%d ", map[i][j]);
        }
        printf("\n");
     }
}

int main(void)
{
    scanf("%d", &n);
    maxcnt = (n * (n + 1)) / 2;

    end[0] = n-1;
    end[1] = 0;
    end[2] = 1;

    clearMap();
    fillMap();
    printMap();

    return 0;
}

#endif

// G0 숫자찾기
#if 0
#include <stdio.h>
#define MAX 1000010

char converted[MAX];
char original[MAX];

void printAnswer(int tc, int idx) {
    printf("%d. ", tc);
    if (original[idx - 1] == '0') {
        printf("IMPOSSIBLE\n");
        return;
    }
    for (int i = idx - 1; i >= 0; i--) {
        printf("%c", original[i]);
    }
    printf("\n");
}

void findOriginal(int tc, int end) {
    int oriIdx = 0, up = 0;
    char compare;

    compare = converted[end-1];
    original[oriIdx++] = compare;
    
    for (int i = end - 2; i >= 0; i--) {
        if (up) compare++;
        if (compare <= converted[i]) {
            compare = converted[i] - compare + '0';
            up = 0;
        }
        else {
            compare = converted[i] + 10 - compare + '0';
            up = 1;
        }

        original[oriIdx++] = compare;
    }
    
    printAnswer(tc, oriIdx);
}

int main(void)
{
    char input[1000000];
    int len=0;

    for (int tc = 1;;tc++) {
        scanf("%s%n", &converted, &len);
        if (converted[0] =='0') return 0;

        if (tc > 1) len--;
        findOriginal(tc, len);
    }

    return 0;
}

#endif

// G1 주차요금
#if 0
#include <stdio.h>

int pay[101];
int time[101];
int n;
int sum;

void calcPay(void) {
    int cartime;
    for (int i = 0; i < n; i++) {
        cartime = time[i];
        if (cartime < 10) pay[i] = 0;
        else if (cartime <= 30) pay[i] = 500;
        else {
            if ((cartime - 30) % 10 == 0) {
                pay[i] = ((cartime - 30) / 10) * 300 + 500;
            }
            else {
                pay[i] = ((cartime - 30) / 10 + 1) * 300 + 500;
            }
            if (pay[i] > 50000) pay[i] = 50000;
        }
        sum += pay[i];
        printf("%d분 %d원\n", cartime, pay[i]);
    }
}

int main(void)
{
    scanf("%d", &n);
    for (int i = 0; i< n; i++) {
        scanf("%d", &time[i]);
    }

    calcPay();
    printf("%d", sum);
        
    return 0;
}

#endif

// G2 색종이
#if 0
#include <stdio.h>
#define MAX 102

int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int paper[MAX][MAX];
int n;
int found, sum;

void colorPaper(int r, int c) {
    for (int i = r; i < r + 10; i++) {
        for (int j = c; j < c + 10; j++) {
            if (!paper[i][j]) paper[i][j] = 1;
        }
    }
}

int searchNear(int prevr, int prevc) {
    int r, c, count = 0;
    for (int i = 0; i < 4; i++) {
        r = prevr + dir[i][0];
        c = prevc + dir[i][1];
       
        if ((r >= 0 && r < MAX && c >= 0 && c < MAX) && paper[r][c] == 1) {
            count++;
        }
    }

    return count;
}

void calcLen(void) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (paper[i][j] == 0) {
               sum+= searchNear(i, j);
            }
        }
    }
}

int main(void)
{
    int r, c;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &r);
        c = c;
        r = (99 - (r + 9))+1;
        colorPaper(r, c);
    }

    calcLen();
    printf("%d", sum);

    return 0;
}

#endif

// G3 회전초밥
#if 0
#include <stdio.h>
#include <stdlib.h>

#define MAX 3000001

int n, d, k, c;
int* plates;
int visit[3001];
int ecnt;

int findCombi(void) {
    int dup = 0, minDup = 987987987, num;

    for (int i = 0; i < k; i++) {
        num = plates[i];
        visit[num] ++;
        if (visit[num] > 1) dup += 1;
    }

    for (int i = 0; i < n; i++) {
        if (dup <= minDup) {
            if (dup < minDup || ecnt > visit[c]) ecnt = visit[c];
            minDup = dup;
        }

        num = plates[i];
        if (visit[num] > 1) dup -= 1;
        visit[num] --;

        if (i + k >= n) num = plates[i + k - n];
        else num = plates[i+k];
        visit[num] ++;
        if (visit[num] > 1) dup += 1;
    }

    return minDup;
}

int main(void)
{
    int isCoupon = 0, combi, answer;

    scanf("%d %d %d %d", &n, &d, &k, &c); // 접시, 초밥 종류, 연속접시, 쿠폰번호
    plates = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &plates[i]);
        if (!isCoupon && plates[i] == c) isCoupon = 1;
    }

    ecnt = k + 1;
    combi = findCombi();
    
    answer = k + 1 - combi;
    if (ecnt) answer -= 1;

    printf("%d", answer);

    return 0;
}

#endif
