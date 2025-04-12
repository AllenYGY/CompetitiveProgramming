#include<bits/stdc++.h>
#include<iostream>
// #define int long long
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

int GCD(int a,int b){
    if (b==0) return a;
    return GCD(b,a%b);
}

int lcm(int a, int b) {
    return (a * b) / GCD(a, b);
}


string FJ_string(int n){
    if (n==1) return "A";
    else return FJ_string(n-1)+char(int('A') +(n-1))+ FJ_string(n-1);
}

void expEnumeration(int index, int n, vector<int>current ){
     if (index > n){
        for(int i =0 ;i<current.size();i++){
            cout<<current[i]<<" ";
        }
        cout<<endl;
        return ;
     }
     expEnumeration(index+1,n,current);
     current.push_back(index);
     expEnumeration(index+1,n,current);


}

vector<vector<int>> matrixMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int colsB = B[0].size();
    vector<vector<int>> C(rowsA, vector<int>(colsB, 0));
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            for (int k = 0; k < colsA; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

vector<vector<int>> matrixPow(vector<vector<int>>& M, int n ){
    int matrixSize = M.size();
    vector<vector<int>> ans(matrixSize, vector<int>(matrixSize, 0));
    for(int i=0;i<matrixSize;i++){
        ans[i][i]=1;
    }
    for(;n!=0;n>>=1){
        if(n&1) ans = matrixMultiply(ans,M);
        M = matrixMultiply(M,M);
    }
    return ans;
}

void perEnumeration(int u,int n,vector<int>& current,vector<bool>& pos){
    if(u==n){
        for(int i=0;i<current.size();i++){
            cout<<current[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        if(!pos[i]){
            current.push_back(i);
            pos[i]=true;
            perEnumeration(u+1,n,current,pos);
            pos[i]=false;
            current.pop_back();
        }
    }
}

void solve(){
    cout<<GCD(3,3)<<endl;
    cout<<FJ_string(4)<<endl;
    vector<int> current;
    int n = 3;
    vector<bool> pos(n, false);
    expEnumeration(0,3,current);
    perEnumeration(0,3,current,pos);
}
 
int main() {
    solve();

    return 0;
}