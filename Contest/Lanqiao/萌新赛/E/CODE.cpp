#include<bits/stdc++.h>
#include<iostream>
#define int long long
#define endl '\n'

using namespace std;
 
int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9'){
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}
 
void write(int x){
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}
 
signed  main() {
    int number = read(); 
    bitset<32> num(number); 
    int n= num.count();
    // int ans=(1+n)*n/2;
    cout<<pow(2,n)-2<<endl;

    return 0;
}
