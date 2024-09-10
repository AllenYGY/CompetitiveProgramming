#include <iostream>
using namespace std;

int peaches_2(int day) {
    if (day == 10) {
        return 1; 
    } else {
        return (peaches_2(day + 1) + 1) * 2;
    }
}

int peaches_1(int day) {
    int total_peaches = 1;
    for (int i = 10; i > 1 ; --i) {
        total_peaches = (total_peaches + 1) * 2;
    }
    return total_peaches;
}

int main() {
    int day = 1; 
    int total_peaches = peaches_1(day);
    cout << total_peaches << endl;
    return 0;
}