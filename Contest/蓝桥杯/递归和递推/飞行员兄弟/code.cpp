#include<iostream>
#include<vector>


using namespace std;

const int N=20;

int s[N][N];
int c[N][N];
bool used[N][N];
int ans=17;

vector<vector<int> > path;

void turn(int i,int j){
    s[i][j]^=1;
    for(int k=1;k<=4;k++){
        s[k][j]^=1;
    }
    for(int k=1;k<=4;k++){
        s[i][k]^=1;
    }
}

bool check(){
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            if(s[i][j]==1){
                return false;
            }
        }
    }
    return true;
}
//*每个元素点或者不点枚举次数
void dfs(int cnt){
    if(check()){
        if(cnt<ans){
            ans=cnt;
            path.clear();
            for(int i=1;i<=4;i++){
                for(int j=1;j<=4;j++){
                    if(used[i][j]){
                        vector<int> tmp;
                        tmp.push_back(i);
                        tmp.push_back(j);
                        path.push_back(tmp);
                    }
                }
            }
        }
        return ;
    }
    if(cnt>=ans){
        return ;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            if(used[i][j]){
                continue;
            }
            used[i][j]=true;
            turn(i,j);
            dfs(cnt+1);
            used[i][j]=false;
            turn(i,j);
        }
    }
}

int main(){
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            cin>>c[i][j];
            if(c[i][j]=='+'){
                s[i][j]=1;
            }
        }
    }
    dfs(0);
    cout<<ans<<endl;
    for(int i=0;i<path.size();i++){
        cout<<path[i][0]<<" "<<path[i][1]<<endl;
    }
    return 0;
}