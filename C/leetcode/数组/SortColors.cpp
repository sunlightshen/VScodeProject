#include<algorithm>
#include<iostream>
#include<vector>
#include<cassert>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> zero;
        vector<int> one;
        vector<int> two;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                zero.push_back(nums[i]);
            if(nums[i]==1)
                one.push_back(nums[i]);
            if(nums[i]==2)
                two.push_back(nums[i]);
        }
        int  index =0;
        while ((index<nums.size()))
        {
            for(int i=0;i<zero.size();i++)
                nums[index++] = zero[i];
            for(int i=0;i<one.size();i++)
                nums[index++] = one[i];
            for(int i=0;i<two.size();i++)
                nums[index++] = two[i];
        }
        
        
    }
    /*三路快排*/
    void sortColors1(vector<int> &nums) {
        int zero = -1;          
        int two = nums.size();  
        //循环终止条件（注意边界问题的解决）
        for( int i = 0 ; i < two ; ){
            if( nums[i] == 1 )
                i ++;
            else if ( nums[i] == 2 )
                swap( nums[i] , nums[--two]);
            else{
                swap( nums[++zero] , nums[i++] );
            }
        }
    }
};
int main()
{
    int a[]={0,1,1,2,2,0,0,2,2,1,1};
    vector<int> vec(a,a+sizeof(a)/sizeof(int));
    Solution solution;
    solution.sortColors1(vec);
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<" ";
    }
}