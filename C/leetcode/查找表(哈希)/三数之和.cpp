#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;


class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ret;
        
        set<vector<int>> tmpret;
        map<int, int> m_map;
        vector<int> _nums;

        for(const auto & num : nums){
            ++m_map[num];
        }
        for(const auto &num : m_map){
            _nums.insert(_nums.end(), (num.second > 3? 3 : num.second), num.first);
        }
        int i =0 , j = 0, k = 0;
        for(i = 0; i < _nums.size(); ++i){
            j = i+1;
            k = _nums.size()-1;
            while(j < k){
                if((_nums[j] + _nums[k]) == -_nums[i]){
                    tmpret.insert({_nums[i], _nums[j], _nums[k]});
                    ++j;
                    --k;
                }else if((_nums[j] + _nums[k]) > -_nums[i]) 
                    --k;
                else ++j; 
            }
        }
        for(const auto &vec : tmpret)
            ret.push_back(vec);
        return ret;
    }
};
int main()
{
    int a[] = {-1, 0, 1, 2, -1, -4};
    vector<int> vec(a,a+sizeof(a)/sizeof(int));
    Solution solution;
    vector<vector<int> > result = solution.threeSum(vec);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
        cout<<"*****"<<endl;
    }
}