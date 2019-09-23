#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    /*利用排序实现*/
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k]; 
    }
    /*分治思想*/
    int findkth(vector<int>&num,int l,int r,int k)
    {

        int middle = l;
        int count = 1;                     
        int i,j;
        for(i = l + 1;i<=r;i++)     
        {
            if(num[i]>num[l])  			 	 
            {
                count++;
                middle++; 
                swap(num[middle],num[i]);      
            }
        } 
        swap(num[middle],num[l]);   
        if(k<count){ 				 
            findkth(num,l,middle-1,k);
        }
        else if(k>count){	
            findkth(num,middle+1,r,k-count);
        }
        else
            return middle; 
    }
    int findKthLargest1(vector<int>& nums, int k) {
        int kth = findkth(nums,0,nums.size()-1,k);
        return nums[kth];
    }
};
int main()
{
    int a[]={3,2,1,5,6,4};
    vector<int> vec(a,a+sizeof(a)/sizeof(int));
    Solution solution;
    int m =solution.findKthLargest1(vec,2);
    cout<<"The kth number is :"<<m<<endl;
}

