#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
private:
        void generate(vector<int>&nums,vector<vector<int> > &res,vector<int> &p,int index,vector<bool> &used)
        {
        	if(index==nums.size())
        	{
        		res.push_back(p);
        		return;
        	}
        	else{
        		for(int i=0;i<nums.size();i++)
        		{
        			if(!used[i])
        			{
        				used[i]=true;
        				p.push_back(nums[i]);
        				generate(nums,res,p,index+1,used);
        				p.pop_back();
                        used[i]=false;
        			}
        		}
                return;
        	}           
        }
public:
    vector<vector<int> > permute(vector<int>& nums) {
    	vector<bool> used(nums.size(),false);
    	vector<vector<int> > result;
        vector<int> p;
    	generate(nums,result,p,0,used);
    	return result;
    }
};


int main()
{
	Solution solution;
	int nums[] ={1,2,3};
	vector<int> vec(nums,nums+sizeof(nums)/sizeof(int));
	vector<vector<int> > result =solution.permute(vec);
	for(int i=0;i<result.size();i++)
	{
		for(int j=0;j<result[i].size();j++)
		{
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}

}