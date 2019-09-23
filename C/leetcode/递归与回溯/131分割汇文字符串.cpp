#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) 
    {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
    vector<vector<string> > partition(string s) {
        vector<vector<string> > result;
        vector<string> tmp;
        backtrack(s,0,tmp,result);
        return result;
    }
    void backtrack(string s, int start,vector<string> &tmp,vector<vector<string>  >& result){
        if(start ==s.size())
        {
            result.push_back(tmp);
            return;
        }
        string sub="";
        for(int i=start;i<s.size();i++)
        {
            sub+=s[i];
            if(isPalindrome(sub))
            {
                tmp.push_back(sub);
                backtrack(s,i+1,tmp,result);
                //弹出上一个
                tmp.pop_back();
            }
        }     
    }
};

int main()
{
    string s="abb";
    Solution solution;
    vector<vector<string> > result;
    result =solution.partition(s);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
        {
            cout<<result[i][j]<<" "<<endl;
        }
        cout<<endl;
    }
}