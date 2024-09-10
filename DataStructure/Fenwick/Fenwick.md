---
Create Time: 21st June 2024
Title: Fenwick
status: UNFINISHED
dg-publish: false
Author:
  - AllenYGY
tags:
  - NOTE
  - DataStructure
  - Fenwick
created: 2024-06-21T18:07
updated: 2024-06-22T01:36
---

# [Fenwick]

最简单的树状数组支持两种操作，时间复杂度均为$O(logn)$
巧妙地利用了二进制

- 单点修改：更改数组中一个元素的值
- 区间查询：查询一个区间内所有元素的和

## Definition

1. $lowbit(x)$ 二进制数最右边的一个1，连带着它之后的0
2. $C_i$  维护 $(A_i-lowbit(x),A_i)$ 区间

## Lowbit

- $lowbit(x) = (x) \& (-x)$

## CODE

- 单点修改
  
```cpp
void update(int i, int val) {
	for (; i < tree.size(); i += i & -i) {
		tree[i] += val;
	}
}
```
  
- 求前n项和
  
```cpp
// 返回下标在 [1,i] 的元素之和,
int pre(int i) {
	int res = 0;
	while (i > 0) {
		res += tree[i];
		i &= i - 1;
	}
	return res;
}
```

- 区间求和

```cpp
// 返回下标在 [l,r] 的元素之和
int query(int l, int r) {
	if (r < l) {
		return -1;
	}
	return pre(r) - pre(l - 1);
}
```

## Template

```cpp
class Fenwick {
	vector<int> tree;
public:
	Fenwick(int n) : tree(n) {}
	// 把下标为 i 的元素增加 1
	
	void add(int i) {
		while (i < tree.size()) {
			tree[i]++;
			i += i & -i; // i & -i 会得到 i 的最后一个 1 即 lowbit
		}
	}
	
	void update(int i, int val) {
		for (; i < tree.size(); i += i & -i) {
			tree[i] += val;
		}
	}
  
	// 返回下标在 [1,i] 的元素之和
	int pre(int i) {
		int res = 0;
		while (i > 0) {
			res += tree[i];
			i &= i - 1;
		}
		return res;
	}
	
	// 返回下标在 [l,r] 的元素之和
	int query(int l, int r) {
		if (r < l) {
			return -1;
		}
		return pre(r) - pre(l - 1);
	}

};
```

[3072. 将元素分配到两个数组中 II](https://leetcode.cn/problems/distribute-elements-into-two-arrays-ii/)
