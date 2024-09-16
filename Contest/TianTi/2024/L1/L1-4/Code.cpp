#include<bits/stdc++.h>

using namespace std;

int main(){
    int A, B;
    cin>>A>>B;
    vector<int> vec;
    for(int i=0;i<B;i++){
        int tmp;
        cin>>tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(),vec.end());

    int ans=vec[1]- (A-vec[0]);

    for(int i=2;i<B;i++){
        ans=ans-(A-vec[i]);
    }
    if(ans>0)
        cout<<ans;
    else
        cout<<0;
    return 0;
}