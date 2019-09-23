#include<algorithm>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<iostream>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int ,int> demo1;
        unordered_map<int ,int> demo2;
        for(int i=0;i<s.length();i++)
        {
            demo1[s[i]]++;
        }
        for(int i=0;i<t.length();i++)
        {
            demo1[t[i]]--;
        }
        for(unordered_map<int,int>::iterator iter=demo1.begin();iter!=demo1.end();++iter)
        {
            if(iter->second!=0)
                return false;
        }
        return true;
        
    }
};


int main()
{
    string s = "anagram";
    string t = "nagaram";
    Solution solution;
    bool flag = solution.isAnagram(s,t);
    if(flag)
        cout<<"True"<<endl;
    else
        cout<<"Flase"<<endl;
    
}