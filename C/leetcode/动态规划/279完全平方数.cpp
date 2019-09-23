#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

class Solution{
public:

//便利所有的子问题并实现最优解
    int numSquares(int n) {
        vector<int> dp(n+1,INT64_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++)
            for (int j=1;j<=sqrt(i);j++)
            {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        return dp[n];
    }
};

int main()
{
        cout<<"the samll square number is :"<<Solution().numSquares(13)<<endl;
}