#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string ip="";
        backtrack(s, 0, 0, ip, result); 
        return result;
    }
    void backtrack(string s, int start, int step, string ip ,vector<string>& result){
        //终止条件
        if(start==s.size() && step==4){
            ip.erase(ip.end()-1); 
            result.push_back(ip);
            return;
        }
        if(s.size()-start > (4-step)*3) return; 
        if(s.size()-start < (4-step)) return; 
        int num = 0;
        for(int i = start; i<start+3; i++){
            num = num*10+(s[i]-'0');
            if(num <= 255){
                ip += s[i];
                backtrack(s, i+1, step+1, ip+'.', result);
            }
            //首字母不能为0
            if(num==0) break;
        }
    }
};

int main()
{
    string s="25525511135";
    vector<string> res;
    Solution solution;
    res =solution.restoreIpAddresses(s);
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<endl;
    }

}