#include<iostream>
// #include<bits/stdc++.h>
using namespace std;

int main(){
    int T=0;
    cin >> T;
    int i=1,ans=1;
    T-=1;
    int max=0;
    cin >> max;
    while (T--)
    {
        int tmp;
        cin >> tmp;
        i++;
        if(tmp>max){
            max=tmp;
            ans=i;
            break;
        }
    }
    if(ans==1) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}