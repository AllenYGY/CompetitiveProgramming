#include <bits/stdc++.h>
#include <iostream>
using namespace std;

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

// int main() {
//     string numberString = "09792949";
//     // vector<string> validDates = findValidDates(numberString);

//     cout << "存在的合法日期包括: ";
//     for (const string& date : validDates) {
//         cout << date << " ";
//     }
//     cout << endl;

//     return 0;
// }