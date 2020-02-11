//B6 가장 가까운 짝수인 7의 배수
#if 0
#include <stdio.h>

int main(void)
{
    int n, max = 14, min;
    scanf("%d", &n);

    while (max < n)
    {
        max += 14;
    }
    min = max - 14;
    if (!min) printf("%d", 14);
    else {
        if (n - min > max - n) printf("%d", max);
        else printf("%d", min);
    }

    return 0;
}

#endif

//B7 공배수의 개수
#if 0
#include <stdio.h>

int a[10] = { 12, 18, 21, 36, 15, 19, 22, 24, 31, 55 };

int main(void)
{
    int n1, n2, cnt = 0;
    scanf("%d %d", &n1, &n2);
    for (int i = 0; i < 10; i++) {
        if (a[i] % n1 == 0 && a[i] % n2 == 0) cnt++;
    }
    printf("%d", cnt);

    return 0;
}
#endif

//B8 가까운 실수, 먼 실수
#if 0
#include <stdio.h>
#define base 3.5f

int main(void)
{
    float disMax = 0, disMin = 999999.0f, maxNum, minNum, num, dis;
    for (int i = 0; i < 5; i++) {
        scanf("%f", &num);
        dis = num - base;
        if (dis < 0) dis *= -1;
        if (dis > disMax) { disMax = dis; maxNum = num; }
        if (dis < disMin) { disMin = dis; minNum = num; }
    }

    printf("%f %f", minNum, maxNum);

    return 0;
}
#endif

// B9 16진수 구구단
#if 0
#include <stdio.h>

int hexToDec(char hex) {
    return hex - 'A' + 10;
}

void printHex(int dec) {
    char one, two;
    if (dec / 16 >= 10) one = 'A' + (dec / 16) - 10;
    else one = '0' + (dec / 16);
    if (dec % 16 >= 10) two = 'A' + (dec % 16) - 10;
    else two = '0' + (dec % 16);
    if (one > '0') printf("%c%c", one, two);
    else printf("%c", two);
}

int main(void)
{
    char hex; int dec;
    scanf("%c", &hex);
    dec = hexToDec(hex);

    for (int i = 1; i < 16; i++) {
        printHex(dec);
        printf("*");
        printHex(i);
        printf("=");
        printHex(dec * i);
        printf("\n");
    }

    return 0;
}

#endif

// C0 숫자의 종류
#if 0
#include <stdio.h>

int nums[1001];

int checkExist(int n, int size) {
    for (int i = 0; i < size; i++) {
        if (nums[i] == n) return 1;
    }
    return 0;
}

int main(void)
{
    int n, input, indx = 0, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &input);
        if (!checkExist(input, indx)) {
            nums[indx++] = input;
            cnt++;
        }
    }

    printf("%d", cnt);

    return 0;
}
#endif

// C1 합의 회문
#if 0
#include <stdio.h>

int number[7];
int revNum[7];
int sumArr[7];

int pow10(int top) {
    int num = 1;
    while (top--) num *= 10;
    return num;
}

int sumOfRev(int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        revNum[i] = number[size - 1 - i];
    }
    for (int i = 0; i < size; i++) {
        sum += (number[i] + revNum[i]) * pow10(i);
    }
    return sum;
}

int solution(void) {
    int n, i = 0, sum;
    scanf("%d", &n);
    while (n / pow10(i)) {
        number[i] = n / pow10(i) % 10;
        i ++;
    }


    sum = sumOfRev(i);
    i = 0;
    while (sum / pow10(i)) {
        sumArr[i] = sum / pow10(i) % 10;
        i++;
    }
    i--;

    for (int j = 0; j < (i+1) / 2; j++) {
        if (sumArr[j] != sumArr[i-j]) return 0;
    }
    return 1;
}

int main(void)
{
    int n, sol;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        sol = solution();
        printf("%s\n", sol ? "YES" : "NO");
    }

    return 0;
}
#endif

// C1 정수론 몫과 나머지
#if 0
#include <stdio.h>

int a, b, c;
int nums[3];

int findmin(int a, int b, int c) {
    if (a < b) {
        if (c < a) return c;
        else return a;
    }
    else {
        if (c < b) return c;
        else return b;
    }
}

int findmax(int min) {
    int n, no;
    n = min;

    while (1) {
        no = 0;
        for (int i = 0; i < 2; i ++) {
            if (nums[i] % n != nums[i + 1] % n) {
                no = 1;  break;
            }
        }
        if (!no) return n;
        n--;
    }
}

int main(void)
{
    int sum, min, res;
    scanf("%d %d %d", &nums[0], &nums[1], &nums[2]);
    sum = nums[0] + nums[1] + nums[2];
    min = findmin(nums[0], nums[1], nums[2]);
    printf("min: %d\n", min);
    /*
    while (min) {
        if (sum % min == 0) break;
        min--;
    */
    }

    // min = n + R
    res = findmax(min);

    printf("%d", res);


    return 0;
}
#endif

// C5 수학귀신
#if 0
#include <stdio.h>

int input[50][2];

int main(void)
{
    int k;
    scanf("%d", &k);

    input[0][0] = 1;
    input[0][1] = 0;
    input[1][0] = 0;
    input[1][1] = 1;
    for (int i = 2; i <= k; i++) {
        input[i][0] = input[i - 1][0] + input[i - 2][0];
        input[i][1] = input[i - 1][1] + input[i - 2][1];
    }

    printf("%d %d", input[k][0], input[k][1]);

    return 0;
}

#endif

// C6 우정수와 완전수
#if 0
#include <stdio.h>


int size;
int results[10000][2];


int isPerfectNumber(int num) {
    int sum = 1;
    if (num == 1) return 1;
    for (int i = 2; i < num; i++) {
        if (num % i == 0) sum += i;
    }
    if (sum == num) {
        results[size][0] = 1;
        results[size][1] = num;
        size++;  
        return 1;
    }
    else return 0;
}

void findAmicableNumber(int num) {
    int sum = 1, secondSum = 1;
    for (int i = 2; i < num; i++) {
        if (num % i == 0) sum += i;
    }
    for (int i = 2; i < sum; i++) {
        if (sum % i == 0) secondSum += i;
    }
    if (secondSum == num) {
        results[size][0] = num;
        results[size][1] = sum;
        size++;
    }
}

int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);

    for (int i = a; i <= b; i ++) {
        if (isPerfectNumber(i));
        else findAmicableNumber(i);
    }

    printf("%d\n", size);

    for (int i = 0; i < size; i++) {
        if (results[i][0] == 1) printf("%d\n", results[i][1]);
        else printf("%d %d\n", results[i][0], results[i][1]);
    }

    return 0;
}

#endif

// c7 주사위
#if 0
#include <stdio.h>

int cases[] = {0, 0, 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1};

int main(void)
{
    // 여기서부터 작성
    int n, r; 
    scanf("%d", &n);
    r = cases[n];

    printf("%.4f%", r / 36.0 * 100);
    

    return 0;
}
#endif

// c8 그릇
#if 0
#include <stdio.h>

char plate[50];

int main(void)
{
    // 여기서부터 작성
    int height = 10, i = 1;
    scanf("%s", plate);
    char prev = plate[0];
    while (plate[i]) {

        if (prev == plate[i]) height += 5;
        else height += 10;
        prev = plate[i];
        i++;
    }
    printf("%d", height);
    return 0;
}

#endif

// c9 분수의 합
#if 0
#include <stdio.h>

int bunja[101];
int bunmo[101];

long long gcd(long long b, long long l) {
    if (l == 0) return b;
    else return gcd(l, b % l);
}

int main(void)
{
    int n;
    long long int mul = 1, d, sum = 0, clr;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &bunja[i], &bunmo[i]);
        mul = (mul * bunmo[i]) / gcd(mul, bunmo[i]);
    }

    for (int i = 0; i < n; i++) {
        if (bunja[i]) sum += (mul / bunmo[i]) * bunja[i];
    }

    clr = gcd(sum, mul);
    mul /= clr;
    sum /= clr;
    
    if (sum != 0)printf("%lld/%lld", sum, mul);
    else printf("0");

    return 0;
}
#endif

// D0 꼭지점
#if 0
#include <stdio.h>

int main(void)
{
    int n, sum = 2, base = 1, dots = 0, num = 1, dir = 1;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        sum += base;
        base *= 2;
    }

    dots = sum* (sum - 1) + sum;
    printf("%d", dots);

    return 0;
}
#endif

// D1 연속부분 최대곱
#if 0
#include <stdio.h>


double nums[100001];
double dp[100001];

int main(void)
{
    int n;
    double max = -987987987.0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &nums[i]);
    }

    dp[0] = nums[0];
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] < 1 ? nums[i] : dp[i - 1] * nums[i];
        if (dp[i] > max) max = dp[i];
    }

    printf("%.3lf", max);

    return 0;
}
#endif

// D2 CD만들기
#if 0
#include <stdio.h>

int songs[220];
int n, t;

void sort(void) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            if (songs[i] > songs[j]) {
                temp = songs[i];
                songs[i] = songs[j];
                songs[j] = temp;
            }
        }
    }
}

int main(void)
{
    int sum = 0, i = 0, cnt =0;
    scanf("%d %d", &n, &t);
    for (int i = 0; i < n; i++) {
        scanf("%d", &songs[i]);
    }
    sort();
    while (sum <= t) {
        if (songs[i]) {
            sum += songs[i];
            cnt++;
        }
        i++;
    }

    printf("%d",cnt-1);

    return 0;
}

#endif

// D3 미친 수열
#if 0
#include <stdio.h>

int main(void)
{
    long long n, sum = 1, num = 1;
    scanf("%lld", &n);

    while (sum <= n)
    {
        sum += num;
        num++;
    }

    printf("%lld", num - 1);

    return 0;
}
#endif

// D4 숫자근
#if 0
#include <stdio.h>

int nums[1010];

int pow(int top);

int sumOfDigits(int num) {
    int sum = 0;
    for (int i = 0;;i++)
    {
        if (num / pow(i) <= 0) break;
        sum += num / pow(i) % 10;
    }
    return sum;
}

int getDigitRoot(int num) {
    int newNum = num;
    while (newNum >= 10) {
        newNum = sumOfDigits(newNum);
        //printf("%d: %d\n", num, newNum);
    }
    return newNum;
}

int main(void)
{
    int n, digitRoot, max = 0, indx;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    for (int i = 0; i < n; i++) {
        digitRoot = getDigitRoot(nums[i]);
        if (max < digitRoot) {
            max = digitRoot;
            indx = i;
        }
        else if (max == digitRoot) {
            if (nums[i] < nums[indx]) indx = i;
        }
    }

    printf("%d", nums[indx]);

    return 0;
}

int pow(int top) {
    int num = 1;
    while (top--) num *= 10;
    return num;
}
#endif

// D5 앞뒤 같은 제곱
#if 0
#include <stdio.h>

char convertedNum[20];
char convertedI[20];
char* cp = convertedNum;
char* ci = convertedI;

int checkPelindrome(int size) {
    if (size == 1) return 1;
    for (int i = 0; i < size / 2; i++) {
        if (convertedNum[i] != convertedNum[size - 1 - i]) return 0;
    }
    return 1;
}

int decToBase(int dec, int base, char * arr) {
    int i = 0, temp;
    while (dec >= base) {
        temp = dec % base;
        arr[i] = temp >= 10 ? 'A' + (temp - 10) : '0' + temp;
        dec /= base;
        i++;
    }
    arr[i] = dec >= 10 ? 'A' + (dec - 10) : '0' + dec;
    for (int j = ++i; j < 20; j++) {
        if (!arr[j]) break;
        arr[j] = 0;
    }
    return i;
}

int main(void)
{
    int base, sqr, size, iSize;
    scanf("%d", &base);

    for (int i = 1; i <= 300; i++) {
        sqr = i * i;
        size = decToBase(sqr, base, cp);
        if (checkPelindrome(size)) {
            iSize = decToBase(i, base, ci);
            for (int j = iSize - 1; j >= 0; j--) {
                printf("%c", convertedI[j]);
            }
            printf(" ");
            for (int j = size-1; j >= 0; j--) {
                printf("%c", convertedNum[j]);
            }
            printf("\n");
        }
    }

    return 0;
}
#endif

// D6 주사위
#if 0
#include <stdio.h>

int sides[3];
int countSum[100];

int main(void)
{
    int sum, max = 0, maxnum;

    for (int i = 0; i < 3; i++) {
        scanf("%d", &sides[i]);
    }

    for (int i = 1; i <= sides[0]; i++) {
        for (int j = 1; j <= sides[1]; j++) {
            for (int k = 1; k <= sides[2]; k++) {
                sum = i + j + k;
                countSum[sum] ++;
            }
        }
    }

    for (int i = 0; i < 100; i++) {
        if (countSum[i] > max) {
            max = countSum[i];
            maxnum = i;
        }
    }

    printf("%d", maxnum);

    return 0;
}
#endif

// D7 도미노
#if 01
#include <stdio.h>

int dp[10010];

int main(void)
{
    int n;
    scanf("%d", &n);

    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + i + 1;
    }

    printf("%d", dp[n]);

    return 0;
}
#endif