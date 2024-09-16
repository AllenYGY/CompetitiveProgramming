#include<iostream>
#include<vector>

using namespace std;

int N;
int SUM;
vector<int> path;
int status[1000];

bool check(){
    vector<int> q;
    for(int i=0; i < N;i++){
        q.push_back(path[i]);
    }
    while(q.size()!=0){
        for(int i=0;i<q.size()-1;i++){
            q[i]=q[i]+q[i+1];
        }
        q.pop_back();
    }
    return q[0]==SUM;
}


void printAns(vector<int> path){
    for(int i=0;i<path.size();i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
}

int flag=0;

void dfs(int u){
    if(u==N){
        if(check()){
            printAns(path);
            flag=1;
        }
        return ;
    }
    if(flag==1){
        return;
    }
    for(int i=1;i<N+1;i++){
        if(status[i]==1)
            continue;
        path.push_back(i);
        status[i]=1;
        dfs(u+1);
        status[i]=0;
        path.pop_back();
    }

}

int main(){
    cin>>N>>SUM;
    dfs(0);
    return 0;
}


