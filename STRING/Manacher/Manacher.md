---
Create Time: 22nd June 2024
Title: Manacher
status: DONE
dg-publish: false
Author:
  - AllenYGY
tags:
  - Manacher
  - String
  - NOTE
  - Algorithm
created: 2024-06-22T00:52
updated: 2024-06-22T00:53
---

# [Manacher]

1. 暴力方法如何寻找最长回文子串
   - 中心扩展 $O(n^2)$
2. Manacher扩展串
   - 可以方便的寻找奇长度、偶长度的回文，扩展字符可以随意设置，不会影响计算
3. 回文半径和真实回文长度的对应
   - 真实长度 $len = p[i] - 1$
4. 扩展回文串结尾下标和真实回文串终止位置的对应
   - 真实回文串终止位置 = 扩展回文串结尾下标 / 2
5. 回文半径数组*p*、回文覆盖最右边界*r*、回文中心*c*
6. *Manacher*算法的加速过程，当来到的中心点*i*，利用*p*、*r*、*c*来进行回文扩展
   a. $i>r$，那么以*i*为中心直接扩展
   b. $i \leq r$，对称点 $2*c-i$ 的回文半径，在大回文区域以内，直接确定$p[i] = p[2*c-i]$
   c. $i \leq r$，对称点 $2*c-i$ 的回文半径，在大回文区域以外，直接确定$p[i] = r - i$
   d. $i \leq r$，对称点 $2*c-i$ 的回文半径，撞线大回文区域的边界，从*r*之外的位置进行扩展

## CODE

```cpp
string Preprocess(string s) { // 字符串预处理
	string res = "#";
	for (int i = 0; i < s.size(); i++) {
		res += s[i];
		res += "#";	
	}
	return res;
}

string Postprocessing(string s) { // 字符串还原
	string res = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != '#') {
			res += s[i];
		}
	}
	return res;
}

string Manacher(string s) {
	string t = Preprocess(s);
	string ans = "";
	vector<int> p(t.size(), 0);
	int mx = 0;
	for(int i = 0, c = 0, r = 0, len; i < t.size(); i++) {
		len = i < r ? min(r - i, p[2 * c - i]) : 1;
		while (i + len < t.size() && i - len >= 0 && t[i + len] == t[i - len]){	
			len++;
		}
		if (i + len > r){
			r = i + len;
			c = i;
		}
		if(len > mx){
			mx = len;
			// 2 * len - 1 是原字符串的长度	
			ans = t.substr(i - len + 1, 2 * len - 1); 
		}
		p[i] = len;
	}
	ans = Postprocess(ans);
	return ans;
}
```
