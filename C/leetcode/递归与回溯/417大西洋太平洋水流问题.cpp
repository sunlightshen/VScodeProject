#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > pacificAtlantic(vector<vector<int> >& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        vector<vector<int> > res;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool> > pacific(m, vector<bool>(n, false));
        vector<vector<bool> > atlantic(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            dfs(matrix, pacific, INT_MIN, i, 0);
            dfs(matrix, atlantic, INT_MIN, i, n - 1);
        }
        for (int i = 0; i < n; ++i) {
            dfs(matrix, pacific, INT_MIN, 0, i);
            dfs(matrix, atlantic, INT_MIN, m - 1, i);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    res.push_back(vector<int>({i,j}));
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<int> >& matrix, vector<vector<bool> >& visited, int pre, int i, int j) {
        int m = matrix.size(), n = matrix[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || matrix[i][j] < pre) return;
        visited[i][j] = true;
        dfs(matrix, visited, matrix[i][j], i + 1, j);
        dfs(matrix, visited, matrix[i][j], i - 1, j);
        dfs(matrix, visited, matrix[i][j], i, j + 1);
        dfs(matrix, visited, matrix[i][j], i, j - 1);
    }
};
int main()
{
	char g1[5][5] = {
        {1,2,2,3,5},
        {3,2,3,4,4},
        {2,4,5,3,1},
        {6,7,1,4,5},
        {5,1,1,2,4}};
    vector<vector<int> > grid1;
    for(int i = 0 ; i < 5 ; i ++ )
        grid1.push_back( vector<int>( g1[i] , g1[i] + sizeof( g1[i])/sizeof(int) ) );
    vector<vector<int> > result =Solution().pacificAtlantic(grid1);
    for(int i=0;i<result.size();i++)
    {
    	for(int j=0;j<result[i].size();j++)
    	{
    		cout<<grid1[i][j]<<" ";
		}
		cout<<endl;
	}
}
