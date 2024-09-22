// #include<bits/stdc++.h>
// #include<iostream>
// #define int long long
// #define endl '\n'
// using namespace std;
 
// int read(){
//     int x = 0, f = 1;
//     char ch = getchar();
//     while (ch < '0' || ch > '9'){
//         if (ch == '-')
//             f = -1;
//         ch = getchar();
//     }
//     while (ch >= '0' && ch <= '9')
//         x = x * 10 + ch - '0', ch = getchar();
//     return x * f;
// }
 
// void write(int x){
//     if (x < 0)
//         putchar('-'), x = -x;
//     if (x > 9)
//         write(x / 10);
//     putchar(x % 10 + '0');
// }
 
// void solve(){
       
// }
 
// signed main() {
//     int N=read();
//     int Q=read();
//     string s;
//     cin>>s;
//     int cnt=0;
//     for(int i=2;i<N;i++){
//         if(s[i-2]=='A'&&s[i-1]=='B'&&s[i]=='C'){
//             cnt++;
//         }
//     }
//     while(Q--){
//         int idx=read();
//         char c;
//         cin>>c;
//         if(idx+1<N and idx-1>=0 and s[idx]=='B' and s[idx+1]=='C'){
//             if (s[idx-1]=='A'){
//                 if(c!='A'){
//                     cnt--;
//                 }
//             }
//             else if(c=='A'){
//                 s[idx-1]=c;
//                 cnt++;
//             }
//         }
//         if(idx<N and idx-2>=0 and s[idx-2]=='A' and s[idx]=='C'){
//             if(s[idx-1]=='B'){
//                 if(c!='B'){
//                     cnt--;
//                 }
//             }else if(c=='B'){
//                 cnt++;
//             }
//         }
//         if(idx-1<N and idx-3>=0 and s[idx-3]=='A' and s[idx-2]=='B'){
//             if(s[idx-1]=='C'){ 
//                 if(c!='C'){
//                     cnt--;
//                 }
//             }else if(c=='C'){
//                 cnt++;
//             }
//         }
//         s[idx-1]=c;
//         cout<<cnt<<endl;
//         // cout<<s<<endl;
        
//     }

//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long

// Function to count occurrences of "ABC" in the given string
int countABC(string &s, int N) {
    int cnt = 0;
    for (int i = 2; i < N; i++) {
        if (s[i-2] == 'A' && s[i-1] == 'B' && s[i] == 'C') {
            cnt++;
        }
    }
    return cnt;
}

// Function to check if "ABC" appears at position i in string s
bool isABC(string &s, int i) {
    return (i >= 2 && s[i-2] == 'A' && s[i-1] == 'B' && s[i] == 'C');
}

signed main() {
    int N, Q;
    cin >> N >> Q;
    string s;
    cin >> s;
    
    // Count initial occurrences of "ABC"
    int cnt = countABC(s, N);

    while (Q--) {
        int idx;
        char c;
        cin >> idx >> c;
        idx--; // Adjust to 0-based indexing

        // Check affected regions (idx-2 to idx, idx-1 to idx+1, idx to idx+2)
        for (int i = max(2LL, idx-2); i <= min(N-1, idx+2); i++) {
            if (isABC(s, i)) cnt--;
        }

        // Update the string
        s[idx] = c;

        // Re-check affected regions (idx-2 to idx, idx-1 to idx+1, idx to idx+2)
        for (int i = max(2LL, idx-2); i <= min(N-1, idx+2); i++) {
            if (isABC(s, i)) cnt++;
        }

        // Output the current count of "ABC"
        cout << cnt << endl;
    }

    return 0;
}