#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std; 

class Solution {
private:
	void generatecombine(vector<int> &nums,int k,int start,vector<int> &p,vector<vector<int> > &res,int target)
	{
		if(p.size()==k )
		{
			if(accumulate(p.begin() , p.end(),0)==target)
				res.push_back(p);
			return;
		}
		else
		{
			for(int i=start;i<nums.size();i++)
			{
				p.push_back(nums[i]);
				generatecombine(nums,k,i,p,res,target);
				p.pop_back();
			}
		}
	}
	vector<vector<int> > generateset(vector<int> &nums,int k,int target)
	{
		vector<vector<int> > res;
		vector<int> p;
		vector<int> index;
        if(k==0)
            return res;
        else
        {
            generatecombine(nums,k,0,p,res,target);
            return res;
        }
	}
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
    	vector<int> p;
    	vector<vector<int> > res;
    	vector<vector<int> > tmp;
    	vector<int> tp(candidates.begin(),candidates.end());
    	sort(tp.begin(),tp.end());
    	for(int i=1;i<=target/tp[0];i++)
    	{
    		tmp.clear();
    		tmp=generateset(candidates,i,target);
    		res.insert(res.end(),tmp.begin(),tmp.end());
    	}
    	return res;
    }
};
int main()
{
    int candidates[] = {2,3,5};
    vector<int> vec(candidates,candidates+sizeof(candidates)/sizeof(int));
    int target = 8; 
    vector<vector<int> > result =Solution().combinationSum(vec,target);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
	
}