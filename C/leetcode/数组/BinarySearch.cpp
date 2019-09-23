#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    /*删除的元素放在最后*/
    int binarySearch(vector<int>& nums, int l,int r,int val) {
        while (l<r)
        {
        	int mid = l+(r-l)/2;//放置内存泄漏
            if(nums[mid]==val)
                return mid;
            else if(nums[mid]>val)
            {
                r=mid;
            }
            else
            {
                l = mid;
            }
        }
        return -1;
    }
};
 int main()
 {
     int a[] = {1,2,3,4,5,6,7,8,9};
     vector<int> vec(a,a+sizeof(a)/sizeof(int));
     Solution solution;
     int idx = solution.binarySearch(vec,0,vec.size(),9);
     cout<<"位置："<<idx<<endl;
 }