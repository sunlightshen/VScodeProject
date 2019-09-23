#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

class Solution {
private:
        void generate(vector<int>&nums,vector<vector<int> > &res,vector<int> &p,int index,vector<bool> &used,set<vector<int> > &newset)
        {
        	if(index==nums.size())
        	{
                if(newset.find(p)==newset.end())
                {
                    res.push_back(p);
                    newset.insert(p);
                    return;
                }
                else
                {
                    return;
                }
                
        	}
        	else{
        		for(int i=0;i<nums.size();i++)
        		{
        			if(!used[i])
        			{
        				used[i]=true;
        				p.push_back(nums[i]);
        				generate(nums,res,p,index+1,used,newset);
        				p.pop_back();
                        used[i]=false;
        			}
        		}
                
                return;
        	}           
        }
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
    	vector<bool> used(nums.size(),false);
    	vector<vector<int> > result;
        set<vector<int> > newset;
        vector<int> p;
    	generate(nums,result,p,0,used,newset);
    	return result;
    }
};


int main()
{
	Solution solution;
	int nums[] ={1,1,2};
	vector<int> vec(nums,nums+sizeof(nums)/sizeof(int));
	vector<vector<int> > result =solution.permuteUnique(vec);
	for(int i=0;i<result.size();i++)
	{
		for(int j=0;j<result[i].size();j++)
		{
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}

}