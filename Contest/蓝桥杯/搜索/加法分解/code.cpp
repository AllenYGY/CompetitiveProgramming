#include<iostream>
#include<vector>

using namespace std;

int SUM;
vector<int> path;

void printAns(vector<int> path){
    cout<<SUM<<"=";
    for(int i=0;i<path.size()-1;i++){
        cout<<path[i]<<"+";
    }
    cout<<path[path.size()-1]<<endl;
}


void dfs_1(int i){
    if(i==SUM){
        printAns(path);
        return ;
    }
    if(i>=SUM){
        return ;
    }
    for(int j = 1;j<=SUM;j++){
        path.push_back(j);
        dfs_1(i+j);
        path.pop_back();
    }
}

void dfs_2(int i,int start){
    if(i==SUM){
        printAns(path);
        return ;
    }
    if(i>=SUM){
        return ;
    }
    for(int j = start;j<=SUM;j++){
        path.push_back(j);
        dfs_2(i+j,j);
        path.pop_back();
    }
}

int main(){
    int mode=0;
    cin>>SUM>>mode;
    if(mode==1)
        dfs_1(0);
    if(mode==2)
        dfs_2(0,1);
    return 0;
}