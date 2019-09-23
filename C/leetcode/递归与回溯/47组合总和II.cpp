#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<numeric>
using namespace std;

class Solution {

public:
    void DFS(vector<int> &candidates,int start, int target,vector<int> &path,vector<vector<int> > &res) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size() && target - candidates[i] >= 0; i++) {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            path.push_back(candidates[i]);
            DFS(candidates,i + 1, target - candidates[i],path,res);
            path.pop_back();
        }
    }

    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        vector<int> path;
        vector<vector<int> > res;
        //对排序数据数组处理函数
        sort(candidates.begin(), candidates.end());
        DFS(candidates,0, target,path,res);
        return res;
    }
};


int main()
{
    int nums[]={10,1,2,7,6,1,5};
    int target = 8;
    vector<int> vec(nums,nums+sizeof(nums)/sizeof(int));
    vector<vector<int> > res = Solution().combinationSum2(vec,target);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }

}