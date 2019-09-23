#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
private:
	void generatecombine(vector<int> &nums,int k,int start,vector<int> &p,vector<vector<int> > &res)
	{
		if(p.size()==k)
		{
			res.push_back(p);
			return;
		}
		else
		{
			for(int i=start;i<nums.size();i++)
			{
				p.push_back(nums[i]);
				generatecombine(nums,k,i+1,p,res);
				p.pop_back();
			}
		}
	}
	vector<vector<int> > generateset(vector<int> &nums,int k)
	{
		vector<vector<int> > res;
		vector<int> p;
        if(k==0)
            return res;
        else
        {
            generatecombine(nums,k,0,p,res);
            return res;
        }
	}
public:
    vector<vector<int> > subsets(vector<int>& nums) {
    	vector<int> p;
    	vector<vector<int> > res;
    	vector<vector<int> > tmp;
    	for(int i=0;i<=nums.size();i++)
    	{
    		tmp.clear();
    		tmp=generateset(nums,i);
    		res.insert(res.end(),tmp.begin(),tmp.end());
    	}
        vector<int> init;
        init.clear();
        res.insert(res.begin(),init);
    	return res;
    }
};

int main()
{
    int nums[]={1,2,3};
    vector<int> vec(nums,nums+sizeof(nums)/sizeof(int));
    vector<vector<int> > res;
    res = Solution().subsets(vec);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}