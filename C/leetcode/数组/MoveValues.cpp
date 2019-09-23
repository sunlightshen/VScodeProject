#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    /*删除的元素放在最后*/
    int removeElement(vector<int>& nums, int val) {
        vector<int> tmp;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=val)
            {
                tmp.push_back(nums[i]);
            }
            else
            {
                count++;
            }
        }
        int size =tmp.size();
        for(int i=0;i<count;i++)
        {
            tmp.push_back(val);
        }
        nums = tmp;
        return size;
        
    }
};
int main()
{
    /*删除的元素是放在数组的后面，而不是完成删除*/
    int a[]={1,2,4,5,6,7,0,0,1};
    vector<int> vec(a,a+sizeof(a)/sizeof(int));
    Solution solution;
    int b = solution.removeElement(vec,1);
    cout<<b<<endl;

}