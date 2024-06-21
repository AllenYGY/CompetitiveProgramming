# 树状数组

最简单的树状数组支持两种操作，时间复杂度均为$O(logn)$
巧妙地利用了二进制（实际上，树状数组的英文名BIT，直译过来就是二进制下标树）

- 单点修改：更改数组中一个元素的值
- 区间查询：查询一个区间内所有元素的和

## 定义

1. $lowbit(x)$ 二进制数最右边的一个1，连带着它之后的0
2. $C_i$ 维护 $\(A_i-lowbit(x),A_i\]$ 区间

## lowbit

- $lowbit(x) = (x) & (-x)$

## CODE

- 单点修改

```cpp
int tree[MAXN];
inline void update(int i, int x) // 对 i 位置 ➕ x
{
    for (int pos = i; pos < MAXN; pos += lowbit(pos))
        tree[pos] += x;
}
```

- 求前n项和

```cpp
inline int query(int n)
{
    int ans = 0;
    for (int pos = n; pos; pos -= lowbit(pos))
        ans += tree[pos];
    return ans;
}
```

- 区间求和

```cpp
inline int query(int a, int b)
{
    return query(b) - query(a - 1);
}
```
