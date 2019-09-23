#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:

    void reverseString(vector<char>& s) { 
        int i=0;
        int j=s.size()-1;
        while (i<j)
        {
            cout<<i<<" "<<j<<endl;
            char tmp =s[i];
            s[i] = s[j];
            s[j] = tmp;
            i++;
            j--;
        }
        
    }
};

int main()
{
    char s[]="hello";
    Solution solution;
    vector<char> vec(s,s+sizeof(s)/sizeof(char));
    for (int i = 0; i < vec.size(); i++)
    {
        cout<<vec[i];
    }
    solution.reverseString(vec);
    cout<<"----"<<endl;
    for (int i = 0; i < vec.size(); i++)
    {
        cout<<vec[i];
    }
    
}