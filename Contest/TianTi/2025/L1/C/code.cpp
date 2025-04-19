#include<bits/stdc++.h>

// #define int long long 
#define endl '\n'

using namespace std;

// 根据输入情况，如果可以获得高温补贴，
// 则在一行中输出 Bu Tie（补贴），第二行输出 T 的值；否则输出不补贴的原因：
// 如果室内外温度都超标，仅仅是因为室内工作就不补贴，则输出 Shi Nei（室内），第二行输出 T 的值；
// 如果在室外工作但天气不热、或工作场所温度不高，则输出 Bu Re（不热），第二行输出 t 的值；
// 如果天气不热、或工作场所温度不高，且在室内工作，则输出 Shu Shi（舒适），第二行输出 t 的值。

void solve(){

}

int main(){
    int T,S,t; cin>>T;cin>>S;cin>>t;
    if(S==1 and T>35 and t>=33){
        cout<<"Bu Tie"<<endl;
        cout<<T<<endl;
    }
    else if (S==0 and T>35 and t>=33){
        cout<<"Shi Nei"<<endl;
        cout<<T<<endl;
    }
    else if(S==1 and (T<=35 or t<33)){
        cout<<"Bu Re"<<endl;
        cout<<t<<endl;
    }
    else if(S==0 and(T<=35 or t<33)){
        cout<<"Shu Shi"<<endl;
        cout<<t<<endl;
    }
    return 0;
}