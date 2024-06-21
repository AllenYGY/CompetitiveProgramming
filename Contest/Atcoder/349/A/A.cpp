#include<bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin>>N;
    N-=1;
    int ans=0;
    while(N--){
        int tmp;
        cin>>tmp;
        ans+=tmp;
    }
    cout<<-ans;
    return 0;
}