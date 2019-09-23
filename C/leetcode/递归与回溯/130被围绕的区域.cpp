#include<iostream> 
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char> >& board) {
        if(board.size()==0){
            return;
        }
        int rows=board.size(),cols=board[0].size();
        for(int i=0;i<rows;i++){
            dfs(board,i,0);
            dfs(board,i,cols-1);
        }
        for(int j=1;j<cols-1;j++){
            dfs(board,0,j);
            dfs(board,rows-1,j);
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]=='1'){
                    board[i][j]='O';
                }
                else{
                    board[i][j]='X';
                }
            }
        }
    }
private:
    void dfs(vector<vector<char> >& board,int i,int j){
        if(i>=0&&i<board.size()&&j>=0&&j<board[0].size()&&board[i][j]=='O'){
            board[i][j]='1';
            dfs(board,i-1,j);
            dfs(board,i+1,j);
            dfs(board,i,j-1);
            dfs(board,i,j+1);
        }
    }
};


int main()
{
	char g1[4][4] = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}};
    vector<vector<char> > grid1;
    for(int i = 0 ; i < 4 ; i ++ )
        grid1.push_back( vector<char>( g1[i] , g1[i] + sizeof( g1[i])/sizeof(char) ) );
    Solution().solve(grid1);
    for(int i=0;i<grid1.size();i++)
    {
    	for(int j=0;j<grid1[i].size();j++)
    	{
    		cout<<grid1[i][j]<<" ";
		}
		cout<<endl;
	}
}
