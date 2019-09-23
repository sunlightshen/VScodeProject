#include<iostream> 
#include<algorithm>
#include<vector>

using namespace std;


class Solution {

public:
    void DFS(vector<int> &candidates,int start,int k,vector<int> &path,vector<vector<int> > &res) {
        if (path.size()==k ){
            res.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            path.push_back(candidates[i]);
            DFS(candidates,i + 1,k,path,res);
            path.pop_back();
        }
    }

    vector<vector<int> > subsetsWithDup(vector<int> &nums) {
        vector<int> path;
        vector<vector<int> > res;
        vector<vector<int> > result;
        sort(nums.begin(), nums.end());
        for(int k=0;k<=nums.size();k++)
        {
        	res.clear();
        	DFS(nums,0,k,path,res);
        	result.insert(result.end(),res.begin(),res.end());
		}

        return result;
    }
};

int main()
{
	int nums[]={1,2,2};
	vector<int> num(nums,nums+sizeof(nums)/sizeof(int));
	vector<vector<int> > res =Solution().subsetsWithDup(num);
	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++)
		{
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
	
}
