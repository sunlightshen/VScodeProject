#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l =0;
        int r =0;
        vector<int> num;
        num.clear();
        while (l<m && r<n)
        {
            if(nums1[l]<=nums2[r])
                num.push_back(nums1[l++]);
            else
                num.push_back(nums2[r++]);
        }
        if(l<m)
        {
            for(int i=0;i<m-l;i++)
                num.push_back(nums1[l+i]);
        }
        if(r<n)
        {
            for(int i=0;i<n-r;i++)
                num.push_back(nums2[r+i]);
        }
        nums1 = num;
        
        
    }
};
int main()
{
    int v1[] ={1,5,7,0,0};
    int v2[] ={4,5,8,9};
    vector<int> vec1(v1,v1+sizeof(v1)/sizeof(int));
    vector<int> vec2(v2,v2+sizeof(v2)/sizeof(int));
    Solution solution;
    solution.merge(vec1,3,vec2,4);
    for(int i=0;i<7;i++)
    {
        cout<<vec1[i]<<" ";
    }
}