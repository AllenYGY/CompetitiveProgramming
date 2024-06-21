#include"Number.h"

// * 欧几里得算法
// * 辗转相除法
// * 最大公因数
int gcd(int a, int b)
{
    int c = a % b;
    a = b;
    b = c;
    if (b == 0)
        return a;
    else
        return gcd(a, b);
}
//* gcd(a,b)=1     a,b 互质

int gcd(int a, int b)
{
    return b == 0 ? gcd(b, a % b) : a;
}

//* 最小公倍数
int lcm(int a, int b)
{
    return a * b / (gcd(a, b));
}

// * 拓展欧几里得

int exgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a % b, x, y), x0 = x, y0 = y;
    x = y0;
    y = x0 - (a / b) * y0;
    return d;
}

//! mod 运算
// *  (a + b) % p = (a % p + b % p) % p
// *  (a - b) % p = (a % p - b % p ) % p
// *  (a * b) % p = (a % p * b % p) % p

// * 快速幂
long long normalPower(long long base, long long power)
{
    long long result = 1;
    for (int i = 1; i <= power; i++)
    {
        result = result * base;
        result = result % 1000;
    }
    return result % 1000;
}
// * 如何求解
// * 把数字转换成二进制数
// * 通过二进制数求解

typedef long long ll;

ll ksm(ll a, ll b, ll c) //*   a：权重 初始值 2    b： 二进制数  eg: 1101 -> 取每一位是1 作为贡献   c： 模数
{
    ll ans = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            ans = ans * a % c;
        }
        a = a * a % c;
        b /= 2;
    }
    return ans;
}

// * 判断素数
bool is_prime(int val)
{
    //     1-3的值需要特判，因为我们循环判断只判断到sqrt(val)，1-3是判断不了的
    if (val == 1)
        return 0;
    if (val == 2 || val == 3)
        return 1;
    //     为什么只要判断到sqrt(val)？
    //     例如一个数8，它的因数有1、2、4、8，可以发现1<2<sqrt(8)<4<8
    //     所以我们只要判断小于sqrt(8)的数就可以了,因为因数都是成对出现的
    for (int i = 2; i <= sqrt(val); i++)
    {
        //         如果被整除了,那么该数一定不是素数,返回0
        if (val % i == 0)
            return 0;
    }
    //     如果是素数就返回1
    return true;
}

// * 质数筛

const int N = 1e5 + 10;
bool vis[N];
int prime[N];

// * 埃氏筛
void sieve()
{
    for (int i = 0; i < N; i++)
    {
        vis[N] = true;
    }
    vis[0] = vis[1] = false;
    for (int i = 2; i < N; i++)
    {
        if (vis[N])
        {
            for (int j = 2; j * i < N; j++)
            {
                vis[j * i] = false;
            }
        }
    }
}

// * 欧拉筛
bool isnp[N];
vector<int> primes; // 质数表
void init(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!isnp[i])
            primes.push_back(i);
        for (int p : primes)
        {
            if (p * i > n)
                break;
            isnp[p * i] = 1;
            if (i % p == 0)
                break;
        }
    }
}

void solve()
{
    printf("%d \n", gcd(16, 6));
    printf("%d \n", lcm(16, 6));
    printf("%lld \n", normalPower(2, 100)); //*取前三位
    printf("%lld \n", ksm(2, 1101, 13));
}

int main()
{
    solve();
    return 0;
}
