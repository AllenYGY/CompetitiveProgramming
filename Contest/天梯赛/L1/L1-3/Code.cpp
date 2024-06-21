#include<bits/stdc++.h>

using namespace std;

// 输入格式：
// 输入在一行中给出两个数字 A 和 B，其间以空格分隔。其中 A 是当前交通灯的颜色，
// 取值为 0 表示红灯、1 表示绿灯、2 表示黄灯；B 是前方行人的状态，取值为 0 表示前方两米内没有同向行走的人、1 表示有。

// 输出格式：
// 根据输入的状态在第一行中输出提示音：dudu 表示前方为绿灯，可以继续前进；biii 表示前方为红灯，应该止步；
// - 表示不做提示。在第二行输出患者应该执行的动作：move 表示继续前进、stop 表示止步。

int main(){
    int light;
    int status;
    cin>>light>>status;
    
    if(status!=1){
        if(light==1){
            cout<<"dudu"<<endl;
            cout<<"move";
        }else if(light==0){
            cout<<"biii"<<endl;
            cout<<"stop";
        }else if(light==2){
            cout<<"-"<<endl;
            cout<<"stop";
        }
    }
    else{
        cout<<"-"<<endl;
        if(light==1){
            cout<<"move";
        }else if(light==0){
            cout<<"stop";
        }else if(light==2){
            cout<<"stop";
        }
    }

    return 0;
}