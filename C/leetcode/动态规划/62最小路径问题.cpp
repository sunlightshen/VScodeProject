#include<iostream>
#include<algorithm>

using namespace std;
//将地柜转化为记忆化搜索
class Solution {
public:
    int uniquePaths(int m, int n) {
    	//动态记忆化数据
    	int dp[m][n]={0};
    	//初始化边界条件
    	for(int i=0;i<m;i++)
    	{
    		dp[i][0]=1;
    	}
    	for(int j=1;j<n;j++)
    	{
    		dp[0][j]=1;
    	}
    	for(int i=1;i<m;i++)
    	{
    		for (int j = 1; j < n; j++)
    		{
    			dp[i][j]=dp[i-1][j]+dp[i][j-1];
    		}
    	}
    	return dp[m-1][n-1];
        
    }
};

int main()
{
	int m=5,n=4;
	cout<<"The total number is :"<<Solution().uniquePaths(m,n)<<endl;
}