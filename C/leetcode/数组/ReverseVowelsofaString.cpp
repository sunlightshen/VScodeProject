#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
    bool cmp(char a){
        if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u'||a=='A'||a=='E'||a=='I'||a=='O'||a=='U')
        {
            return true;
        }
        else
            return false;
    }
    string reverseVowels(string s) {
        string t=s;
        int i=0;
        int j=t.length()-1;
        while (i<j)
        {
            if(!cmp(t[i]))
            {
                i++;
            }
            else if(!cmp(t[j]))
                j--;
            else
            {
                swap(t[i],t[j]);
                i++;
                j--;
            }
        }
        return t;
        
    }
};
int main()
{
    string s ="hEllo";
    Solution solution;
    string l =solution.reverseVowels(s);
    cout<<l<<endl;
}