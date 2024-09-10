#include <bits/stdc++.h>
#include <iostream>
#define int long long
#define endl '\n'
using namespace std;

int read()
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
        x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}

void write(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

string find_subsequence_and_remaining(const std::string &s, const std::string &p)
{
    int m = s.length(), n = p.length();
    int i = 0, j = 0;
    // 使用双指针找到模式串的位置
    while (i < m && j < n)
    {
        if (s[i] == p[j])
        {
            j++;
        }
        i++;
    }
    // 检查是否匹配成功
    if (j == n)
    {
        // 返回匹配位置之后的所有字符
        return s.substr(i);
    }
    else
    {
        return ""; // 返回空字符串表示没有匹配成功
    }
}

string removestrcharacter(string s)
{
    string result = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            result += s[i];
        }
    }
    return result;
}

bool isValidDate(const string& date) {
    if (date.length() != 4) {
        return false;
    }
    int month = stoi(date.substr(0, 2));
    int day = stoi(date.substr(2, 2));
    if (month < 1 || month > 12) {
        return false;
    }
    if (day < 1 || day > 31) {
        return false;
    }
    // 检查特定月份的天数
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return false;
    }
    if (month == 2) {
        if (day > 29) {
            return false;
        }
    }
    return true;
}

void findValidDatesHelper(const string& numberString, int index, string currentDate, unordered_set<string>& validDates) {if (currentDate.length() == 4) {
    if (isValidDate(currentDate)) {
            validDates.insert(currentDate);
        }
        return;
    }

    if (index >= numberString.length()) {
        return;
    }

    // 选择当前字符
    findValidDatesHelper(numberString, index + 1, currentDate + numberString[index], validDates);

    // 跳过当前字符
    findValidDatesHelper(numberString, index + 1, currentDate, validDates);
}

int findValidDates(const string& numberString) {
    // 用一个哈希表存储valiDates
    unordered_set<string> validDates;
    findValidDatesHelper(numberString, 0, "", validDates);
    return validDates.size();
}

int getVaildDateCount(string s){
    return findValidDates(s);
}

signed main()
{
    int T = read();
    while (T--)
    {
        int n = read(), m = read();
        string S;
        cin >> S;
        unordered_set<string> names;
        for (int i = 0; i < n; ++i)
        {
            string name;
            cin >> name;
            names.insert(name);
        }
        unordered_map<string, int> datecount;
        int ans=0;
        for (auto name : names)
        {
            string temp = find_subsequence_and_remaining(S, name);
            temp = removestrcharacter(temp);
            if (datecount.find(temp) == datecount.end())
                datecount[temp] = getVaildDateCount(temp);
            ans += datecount[temp];
        }
        cout << ans << endl;
        return 0;
    }
}

