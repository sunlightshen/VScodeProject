#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        int j=s.length()-1;
        bool  flag =true;
        while(i<j)
        {
            if((s[i]>='0' && s[i]<='9')||(s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
            {
                if((s[j]>='0' && s[j]<='9')||(s[j]>='a'&&s[j]<='z')||(s[j]>='A'&&s[j]<='Z'))
                {
                    if(s[i]==s[j])
                    {
                        i++;
                        j--;
                    }
                    else if((s[i]>='a'&&s[i]<='z')&&(s[j]>='A'&&s[j]<='Z')&&(s[i]==s[j]+32))
                    {
                        i++;
                        j--;
                    }
                    else if((s[j]>='a'&&s[j]<='z')&&(s[i]>='A'&&s[i]<='Z')&&(s[j]==s[i]+32))
                    {
                        i++;
                        j--;
                    }
                    else
                    {
                        flag =false;
                        break;
                    }
                    
                }
                else
                    j--;
            }
            else
                i++; 
        }
        return flag;
        
    }
};

int main()
{
    string a ="aba:::ba";
    Solution solution;
    bool f =solution.isPalindrome(a);
    if(f)
        cout<<"TRUE"<<endl;
    else
        cout<<"FALASE"<<endl;
    
}