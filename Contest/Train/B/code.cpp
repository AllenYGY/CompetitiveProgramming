#include<iostream>
// #include<bits/stdc++.h>
using namespace std;

int main(){
    int N=0,K=0;
    cin >> N >> K;
    int A[N];
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    int count=0;
    for(int i=0;i<N;){
        int size=K;
        while(i<N && A[i]<=size){
            size-=A[i];
            i++;
        }
        count++;
        // cout<<i<<" "<<endl;
    }
    cout << count << endl;
    return 0;
}
// 2 5 1 4 1 2 3
// 1 2 2 3 3 4 4