#include<iostream>
#include<algorithm>
#include<map>
#include <string>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> demo1;
        map<char,char> demo2;
        bool flag = true;
        if(s.length()!=t.length())
            return false;
        for(int i=0;i<s.length();i++)
        {
            //建立双向映射
            if(demo1[s[i]]||demo2[t[i]])
            {
                if(demo1[s[i]]!=t[i]||demo2[t[i]]!=s[i])
                    flag =false;
            }
            else
            {
                 demo1[s[i]]=t[i];
                 demo2[t[i]]=s[i];
            } 
        }
        return flag;
        
    }
};
int main()
{
    string s = "ab";
    string t = "aa";
    Solution solution;
    bool flag = solution.isIsomorphic(s,t);
    if(flag)
        cout<<"true"<<endl;
    else
    {
        cout<<"flase"<<endl;
    }
    map<char,char> d;
    d['i']='k';
    if(d.find('i')!=d.end())
        cout<<d['i']<<endl;
    else
    {
        cout<<"empty"<<endl;
    }
}