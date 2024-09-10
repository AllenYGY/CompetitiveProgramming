#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main()
{
    long long int N, D, P;
    cin >> N >> D >> P;
    vector<long long int> v(N, 0);
    long long int i = 0;
    int size = N;
    while (N--)
    {
        cin >> v[i++];
    }
    std::sort(v.begin(), v.end(), std::greater<int>());
    
    int DP = P / D;
    int count=0;
    for (int i = 0; i < size; i++)
    {
        if(v[i]>DP){
            count++;
        }
    }
    long long int sum=0;
    if(count==0){
        sum = std::accumulate(v.begin(), v.end(), 0);
        cout<< sum<<endl;
    }
    else{
        if(count%D==0){
            sum = std::accumulate(v.begin()+count, v.end(), 0);
            sum=sum+count/D*P;
            cout<<sum<<endl;
        }
        else{
            long long int num=count/D;
            long long int coupon=num*D;
            sum = std::accumulate(v.begin()+coupon, v.end(), 0);
            if(size-coupon<D)
                if(sum>P) sum=P;
            sum=sum+num*P;
            cout<<sum<<endl;
        }
    }
    return 0;
}