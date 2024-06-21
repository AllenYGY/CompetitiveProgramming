#include<iostream>

#define int long long 
using namespace std;

const int MAXN = 1000000;

int fa[MAXN];

void init(int n){
	for (int i = 1; i <= n; ++i)
		fa[i] = i;
}

int find(int x){
	return x == fa[x] ? x : (fa[x] = find(fa[x]));
}

void merge(int i, int j){
	fa[find(i)] = find(j);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        init(n+1);
        int i,j,e;
        bool flag=true;
        while(n--){
            cin>>i>>j>>e;
            if(e==1){
                merge(i,j);
            }else if(e==0){
                if(find(i)==find(j)){
                    cout<<"NO"<<endl;
                    flag=false;
                    break;
                }
            }
        }
        if(flag)    
            cout<<"YES"<<endl;
    }
    return 0;
}