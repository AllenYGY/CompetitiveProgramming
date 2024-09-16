#include<bits/stdc++.h>

using namespace std;

// 5
// 4.00 8.50 3.20 12.00 14.10
// 3 5
// 5 2
// 1 1
// 2 3
// 2 2
// 1 9
// 0 0

int main(){
    int num=0;
    cin>>num;
    vector<double> vec;
    vec.push_back(0.0);
    for(int i=1;i<=num;i++){
        double tmp;
        cin>>tmp;
        vec.push_back(tmp);
    }
    vector<int> res(num+1,0);
    double m=0.0;
    int code=-1;
    int size=-1;
    while(code!=0&&size!=0){
        cin>>code>>size;
        res[code]+=size;
        m+=vec[code]*size;
    }
    for(int i=1;i<=num;i++){
        cout<<res[i]<<endl;
    }
    printf("%.2lf",m);
    return 0;
}
