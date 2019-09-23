#include<iostream>
#include<algorithm>
#include<vector> 
#include<unordered_map>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> temp1;
        vector<int> result;
        for(int i=0;i<nums1.size();i++)
        {
            temp1[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++)
        {
            if(temp1[nums2[i]]>0)
            {
                temp1[nums2[i]]--;
                result.push_back(nums2[i]);
            }

        }
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
    vector<int> tmp ;
    tmp= solution.intersect(num1,num2);
    for(int i=0;i<tmp.size();i++)
    {
        cout<<tmp[i]<<" "<<endl;
    }   
}
