#include<iostream>
using namespace std;
int main(){
    int N,M,P;
    cin>>N>>M>>P;
    if((N-M)<0)
        cout<<0;
    else{
        int temp=N-M;
        int times=temp/P;
        cout<<times+1<<endl;
    }
    return 0;
}
