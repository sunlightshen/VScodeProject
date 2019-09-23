#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
//动态规划套路解法(记忆化搜索)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
            //关键判断走的方向的问题
        	int dp[grid.size()][grid[0].size()];
		for(int i = 0 ;i< grid.size();i++){
			for(int j = 0 ; j<grid[0].size();j++){
				if(i==0&&j==0) dp[i][j]=grid[i][j];
				else if(i==0||j==0){
                                        //只能是一个方向的
					if(i==0) dp[i][j] = dp[i][j-1]+grid[i][j];
					if(j==0) dp[i][j] = dp[i-1][j]+grid[i][j];
				}else {
                                        //从左侧和上册选取一个最下的值作为该问题的最佳的解
					dp[i][j]=min(dp[i][j-1],dp[i-1][j])+grid[i][j];
				}
			}
		}
		return dp[grid.size()-1][grid[0].size()-1];
    }
};
int main()
{
        
  int g1[3][3] ={{1,3,1},{1,5,1},{4,2,1}};
    vector<vector<int> > grid1;
    for(int i = 0 ; i < 3 ; i ++ )
        grid1.push_back( vector<int>( g1[i] , g1[i] + sizeof( g1[i])/sizeof(int) ) );
        cout<<"最小路径和为："<<Solution().minPathSum(grid1)<<endl;

}