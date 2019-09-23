#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int begin =0;
        int sum =0;
        int flag =0;
        int len = INT_MAX;
        int result;
        int i =0;
        while(i<nums.size())
        {
            sum=sum+nums[i];
            while (sum>=s)
            {
                len =min(len,(i-begin+1));
                sum = sum-nums[begin];
                begin++;
            }
            i++;  
        }
        return len==INT_MAX?0:len;
    }
};
int main()
{
    int a[]={1,100};
    int s =10;
    vector<int> vec(a,a+sizeof(a)/sizeof(int));
    Solution solution;
    int l =solution.minSubArrayLen(s,vec);
    cout<<"true:"<<2<<"-----"<<"l:"<<l<<endl;
}