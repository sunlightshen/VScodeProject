#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> demo1;
        set<int> demo2;
        for(int i=0;i<nums1.size();i++)
            demo1.insert(nums1[i]);
        for(int i=0;i<nums2.size();i++)
        {
            if(demo1.find(nums2[i])!=demo1.end())
                demo2.insert(nums2[i]);
        }
        vector<int> result(demo2.begin(),demo2.end());
        return result;
    }
};



int main()
{
    int n1[]={1,2,2,1};
    int n2[]={2,2};
    vector<int> num1(n1,n1+sizeof(n1)/sizeof(int));
    vector<int> num2(n2,n2+sizeof(n2)/sizeof(int));
    Solution solution;
    vector<int> result = solution.intersection(num1,num2);
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" "<<endl;
    }    

}