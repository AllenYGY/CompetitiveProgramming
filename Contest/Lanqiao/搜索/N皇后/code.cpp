// #include<iostream>
// #include<vector>

// using namespace std;

// int N;
// int SUM;
// vector<int> path;
// int status[1000];

// bool check(){
//     for(int i=0;i<N;i++){
//         if(path[i]+i==)
//     }
// }


// void printAns(vector<int> path){
//     for(int i=0;i<path.size();i++){
//         for(int j=0;j<path[i];j++){
//             cout<<".";
//         }
//         cout<<"N";
//         for(int j=path[i];j<N;j++){
//             cout<<".";
//         }        
//         cout<<endl;
//     }
// }

// int flag=0;

// void dfs(int u){
//     if(u==N){
//         if(check()){
//             printAns(path);
//             flag=1;
//         }
//         return ;
//     }
//     if(flag==1){
//         return;
//     }
//     for(int i=1;i<N+1;i++){
//         if(status[i]==1)
//             continue;
//         path.push_back(i);
//         status[i]=1;
//         dfs(u+1);
//         status[i]=0;
//         path.pop_back();
//     }

// }

// int main(){
//     cin>>N;
//     dfs(0);
//     return 0;
// }


