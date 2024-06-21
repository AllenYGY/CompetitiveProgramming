#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;

// 改进版替罪羊树，在另外一些细节上也进行了一些更改，具体看注释
#define ls(x) tree[x].ls
#define rs(x) tree[x].rs
#define num(x) tree[x].num
#define val(x) tree[x].val
#define sz(x) tree[x].sz
#define exist(x) !(num(x) == 0 && ls(x) == 0 && rs(x) == 0)
const double ALPHA = 0.7;
struct Node
{
    int ls, rs, num, val, sz;
} tree[MAXN];           // 改用结构体进行存储
vector<int> FP, FN, FV; // 存储拉平后的节点编号、数目、值
int cnt = 1;
int flatten(int pos) // 一趟中序遍历，把当前子树拉平并存到vector里，返回当前节点的索引
{
    if (exist(ls(pos))) // 递归地拉平左子树
        flatten(ls(pos));
    int id = FP.size(); // 记下当前节点的索引
    if (num(pos) != 0)  // 如果该节点是已被删除的节点，就略过，否则把相应信息存入vector
    {
        FP.push_back(pos);
        FV.push_back(val(pos));
        FN.push_back(num(pos));
    }
    if (exist(rs(pos))) // 递归地拉平右子树
        flatten(rs(pos));
    return id;
}
void rebuild(int pos, int l = 0, int r = FP.size() - 1) // 以pos为根节点，以[l,r]内的信息重建一棵平衡的树
{
    int mid = (l + r) / 2, sz1 = 0, sz2 = 0;
    if (l < mid)
    {
        ls(pos) = FP[(l + mid - 1) / 2]; // 重用节点编号
        rebuild(ls(pos), l, mid - 1);    // 递归地重建
        sz1 = sz(ls(pos));
    }
    else
        ls(pos) = 0;
    if (mid < r)
    {
        rs(pos) = FP[(mid + 1 + r) / 2];
        rebuild(rs(pos), mid + 1, r);
        sz2 = sz(rs(pos));
    }
    else
        rs(pos) = 0;
    num(pos) = FN[mid]; // 把存于vector中的信息复制过来
    val(pos) = FV[mid];
    sz(pos) = sz1 + sz2 + num(pos); // 递归确定重建后树的大小
}
void try_restructure(int pos) // 尝试重构当前子树
{
    double k = max(sz(ls(pos)), sz(rs(pos))) / double(sz(pos));
    if (k > ALPHA)
    {
        FP.clear(), FV.clear(), FN.clear(); // 清空vector
        int id = flatten(pos);
        swap(FP[id], FP[(FP.size() - 1) / 2]); // 这里是确保当前节点的编号在重构后不会改变，因为它可能
        rebuild(pos);
    }
}
// 接下来是普通的二叉查找树
void insert(int v, int pos = 1)
{
    if (!exist(pos))
    {
        val(pos) = v;
        num(pos) = 1;
    }
    else if (v < val(pos))
    {
        if (!exist(ls(pos)))
            ls(pos) = ++cnt;
        insert(v, ls(pos));
    }
    else if (v > val(pos))
    {
        if (!exist(rs(pos)))
            rs(pos) = ++cnt;
        insert(v, rs(pos));
    }
    else
        num(pos)++;
    sz(pos)++;
    try_restructure(pos);
}
void remove(int v, int pos = 1)
{
    sz(pos)--;
    if (v < val(pos))
        remove(v, ls(pos));
    else if (v > val(pos))
        remove(v, rs(pos));
    else
        num(pos)--;
    try_restructure(pos);
}
int countl(int v, int pos = 1)
{
    if (v < val(pos))
        return exist(ls(pos)) ? countl(v, ls(pos)) : 0;
    else if (v > val(pos))
        return sz(ls(pos)) + num(pos) + (exist(rs(pos)) ? countl(v, rs(pos)) : 0);
    else
        return sz(ls(pos));
}
int countg(int v, int pos = 1)
{
    if (v > val(pos))
        return exist(rs(pos)) ? countg(v, rs(pos)) : 0;
    else if (v < val(pos))
        return sz(rs(pos)) + num(pos) + (exist(ls(pos)) ? countg(v, ls(pos)) : 0);
    else
        return sz(rs(pos));
}
int rank(int v)
{
    return countl(v) + 1;
}
int kth(int k, int pos = 1)
{
    if (sz(ls(pos)) + 1 > k)
        return kth(k, ls(pos));
    else if (sz(ls(pos)) + num(pos) < k)
        return kth(k - sz(ls(pos)) - num(pos), rs(pos));
    else
        return val(pos);
}
int pre(int v)
{
    int r = countl(v);
    return kth(r);
}
int suc(int v)
{
    int r = sz(1) - countg(v) + 1;
    return kth(r);
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define For(w, a, n) for (int w = (a); w < (n); ++w)
#define _For(a, b, c) for (int a = (b); a > (c); a--)
#define all(x) (x).begin(), x.end()
#define inf 0x3f3f3f3f
#define endl '\n'
// 对拍
#define fo1                         \
    freopen("data.in", "r", stdin); \
    freopen("res.out", "w", stdout);
#define fo2                         \
    freopen("data.in", "r", stdin); \
    freopen("ans.out", "w", stdout);
// 输出
#define printA(a, b, c)            \
    cout << '\n'                   \
         << "debug start" << '\n'; \
    for (int i = a; i <= b; i++)   \
    {                              \
        cout << c[i] << ' ';       \
    }                              \
    cout << "\n\ndebug over\n\n";
template <typename T>
void print(const T &t) { cout << t << endl; }
template <typename T, typename... Args>
void print(const T &t, const Args... args)
{
    cout << t << ' ';
    print(args...);
}
template <typename T>
void println(const T &t) { cout << t << endl; }
template <typename T, typename... Args>
void println(const T &t, const Args... args)
{
    cout << t << endl;
    println(args...);
}

typedef unsigned long long ull;
typedef pair<int, int> pii;
int read();
void write(int);

const int N = 5e5 + 5;
const int MOD = 1e9 + 7;
int T = 1;

void hhhh()
{
}

signed main()
{
    // 单个时关闭cin即可
    cin >> T;
    while (T--)
    {
        hhhh();
    }
    return 0;
}

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
inline void write(int x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}