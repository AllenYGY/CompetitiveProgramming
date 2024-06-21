#include<bits/stdc++.h>

using namespace std;

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int find(int num){
    int max=-1;
    int ans=1;
    for(int i=1;i<num;i++){
        int tmp=gcd(num,i)+i;
        if(tmp>=max){
            max=tmp;
            ans=i;
        }
    }
    return ans;
}

int main(){
    int N;
    cin>>N;
    while(N--){
        int num=0;
        cin>>num;
        cout<<find(num)<<endl;
    }
    return 0;
}