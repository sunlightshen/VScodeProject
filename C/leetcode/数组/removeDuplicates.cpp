#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    /*在原数组上进行操作*/
    int removeDuplicates(vector<int>& nums) {
        vector<int> tmp;
        for(int i=0;i<nums.size();i++)
        {  
            if(i==0)
            {
                tmp.push_back(nums[i]);
            }
            else if(nums[i]==nums[i-1] && i!=0)
            {
                continue;
            }
            else
            {
                tmp.push_back(nums[i]);
            }
            
        }
        nums = tmp; 
        return tmp.size();
 
    }
};
int main()
{
    int a[] ={1,1,2,2,5,5,6,7,8,9};
    vector<int> vec(a,a+sizeof(a)/sizeof(int));
    Solution solution;
    int len = solution.removeDuplicates(vec);
    cout<<"lenght:"<<len<<endl;
    cout<<"------"<<endl;
    for(int i=0;i<len;i++)
    {
        cout<<vec[i]<<" ";
    }
}