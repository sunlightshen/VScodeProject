#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
    }
};

int main()
{
    string s ="cbaebabacd";
    string p="abc";
    Solution solution;
    vector<int> result = solution.findAnagrams(s,p);
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;
}
