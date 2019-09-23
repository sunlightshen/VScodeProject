#include<iostream>
#include<algorithm>
#include<vector>
using namespace std; 


class Solution {
private:
	void generatecombine(int n,int k,int start,vector<int> &p,vector<vector<int> > &res)
	{
		if(p.size()==k)
		{
			res.push_back(p);
			return;
		}
		else
		{
			for(int i=start;i<n;i++)
			{
				p.push_back(i);
				generatecombine(n,k,i+1,p,res);
				p.pop_back();
			}
		}

	}
public:
    vector<vector<int> > combine(int n, int k) {
    	vector<vector<int> > res;
    	vector<int> p;
    	generatecombine(n,k,1,p,res);
    	return res;
    }
};
int main()
{
    vector<vector<int> > res;
    int n=10;
    int k=3;
    res = Solution().combine(n,k);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
	
}
