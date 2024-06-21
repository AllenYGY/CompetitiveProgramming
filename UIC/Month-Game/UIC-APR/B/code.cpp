#include<bits/stdc++.h>

#define int long long

using namespace std;

// 小梦已经完全掌握了循环求和，小熊便扔给他一道求和题：累加  到  中每个数字的数位和。所谓数位和，就是一个数字所有数位上数字之和。举例说明：
//比如 ，则原本的数列为：1、2、3、4、5、6、7、8、9、10、11、12
//他们的数位和数列为：1、2、3、4、5、6、7、8、9、1、2、3。将这个数列求和，得到的总和为：51。
// So let's do it!
int sum(int n){
    int res = 0;
    while(n){
        res += n % 10;
        n /= 10;
    }
    return res;
}
// Maybe more effienct way to solve this problem is to use the formula of the sum of the first n numbers.
// int sum(int n){
//     return n * (n + 1) / 2;
// }

signed main(){
    int N;
    cin >> N;
    
    while(N--){
        int num;
        cin>>num;
        int ans=0;
        for(int i = 1; i <= num; i++){
            ans += sum(i);
        }
        cout << ans << endl;
    }
    
}