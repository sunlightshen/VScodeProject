#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
//自顶向下的解题思想符合动态规划的基本思路）
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = triangle.size() - 2; i >= 0; --i) {
            for (int j = triangle[i].size() - 1; j >= 0; --j) {
                    //状态转移函数
                triangle[i][j] += min (triangle[i + 1][j + 1], triangle[i + 1][j]);
            }
        }
        return triangle[0][0];
    }
int minimumTotal1(vector<vector<int>>& triangle) {
       return dfs(0, 0, triangle);
    }
    int dfs(int x, int y,vector<vector<int>>& triangle) {
        if (x == triangle.size() )
            return 0;
        return triangle[x][y] + min(dfs(x + 1, y, triangle),dfs(x + 1, y + 1, triangle));
    }
};
int main()
{
       int tmp1[]={2};
       int tmp2[]={3,4};
       int tmp3[]={6,5,7};
       int tmp4[]={4,1,8,3};
       vector<int> vec1(tmp1,tmp1+sizeof(tmp1)/sizeof(int));
       vector<int> vec2(tmp2,tmp2+sizeof(tmp2)/sizeof(int));
       vector<int> vec3(tmp3,tmp3+sizeof(tmp3)/sizeof(int));
       vector<int> vec4(tmp4,tmp4+sizeof(tmp4)/sizeof(int));
       vector<vector<int>> res;
       res.push_back(vec1);
       res.push_back(vec2);
       res.push_back(vec3);
       res.push_back(vec4);
       cout<<"The total number is:"<<Solution().minimumTotal(res)<<endl;



}