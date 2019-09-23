#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        vector<int> memo(n+1,-1);
        memo[0]=1;
        memo[1]=1;
        for(int i=2;i<=n;i++)
        {
            memo[i]=memo[i-1]+memo[i-2];
        }
        return memo[n];
        
    }
};

int  main()
{
        cout<<"the tatal number is :"<<Solution().climbStairs(10)<<endl;

}