#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int binarySearch(vector<int>& nums, int l,int r,int val) {
        while (l<=r)
        {
        	int mid = l+(r-l)/2;//放置内存泄漏
            if(nums[mid]==val)
                return mid;
            else if(nums[mid]>val)
            {
                r=mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        return -1;
    }
    /*二分查找的时间复杂度较高*/ 
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> t;
        for(int i=0;i<numbers.size()-1;i++)
        {
            int key = target-numbers[i];
            int left =i+1;
            int right = numbers.size()-1;
            int idx = binarySearch(numbers,left,right,key);
            cout<<"---"<<idx<<endl;
 			if(idx>-1)
            {
                t.push_back(i+1);
                t.push_back(idx+1);
            }
            
        }
        return t;
        
    }
    /*双指针求解*/ 
    vector<int> twoSum1(vector<int>& numbers, int target) {
    	int i=0;
		int j=numbers.size()-1;
		vector<int> vec;
		vec.clear();
		while(i<j)
		{
			if(numbers[i]+numbers[j]==target)
			{
				vec.push_back(i+1);
				vec.push_back(j+1);
				break; 
			}
			else if(numbers[i]+numbers[j]>target)
				j--;
			else
				i++;
		 } 
		 return vec;
    	
  
    }
		 
};

int main()
{
    int a[]={2,7,11,15};
    vector<int> vec(a,a+sizeof(a)/sizeof(int));
    Solution solution;
    vector<int> t=solution.twoSum1(vec,9);
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<" ";
    }
    cout<<"xidx:"<<t[0]<<" "<<t[1];
}