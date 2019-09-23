#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std; 


class Solution {
private:
	void generatecombine(int n,int k,int start,vector<int> &p,vector<vector<int> > &res)
	{
		if(p.size()==k)
		{
			if(accumulate(p.begin() , p.end(),0)==n)
				res.push_back(p);
			return;
		}
		else
		{
			for(int i=start;i<=9;i++)
			{
				p.push_back(i);
				generatecombine(n,k,i+1,p,res);
				p.pop_back();
			}
		}

	}
public:
    vector<vector<int> > combinationSum3(int k, int n){
    	vector<vector<int> > res;
    	vector<int> p;
    	if(k>9)
    		return res;
    	if(n>45)
    		return res;
    	generatecombine(n,k,1,p,res);
    	return res;
        
    }
};


int main()
{
    int n=7;
    int k=3;
    vector<vector<int> > result =Solution().combinationSum3(k,n);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
	
}
