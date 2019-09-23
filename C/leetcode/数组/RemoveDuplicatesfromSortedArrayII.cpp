#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int num = 0;
        int j = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[j]==nums[i]){
                num++;
                if(num<2){
                    nums[++j] = nums[i];
                }
            }else{
                nums[++j] = nums[i];
                num = 0;
            }
        }
        return j+1;
    }
};
int main()
{
    int a[] ={1,1,1,1,2,2,4,4,5,5,5};
    vector<int> vec(a,a+sizeof(a)/sizeof(int));
    Solution solution;
    int len = solution.removeDuplicates(vec);
    cout<<"lenght:"<<len<<endl;
    cout<<"------"<<endl;
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<" ";
    }
}