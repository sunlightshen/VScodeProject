#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring1(string s) {
        int r=-1;
        int l=0;
        int len =INT_MIN;
        int freq[256]={0};
		
        while (l<s.length())
        {
        	
        	if(freq[s[r+1]]==0&&r+1<s.length())
        	{
				freq[s[++r]]++;
        	}
        	else
        	{
        		freq[s[l++]]--;
			}
			len =max(len,r-l+1);		
        }  
        return len==INT_MIN?0:len;
    }
    int lengthOfLongestSubstring2(string s) {

        int freq[256] = {0};
        int l = 0, r = -1;
        int res = 0;

        while( r + 1 < s.size() ){
            while( r + 1 < s.size() && freq[s[r+1]] == 0 )
                freq[s[++r]] ++;
            res = max( res , r-l+1);

            if( r + 1 < s.size() ){
                freq[s[++r]] ++;
                while( l <= r && freq[s[r]] == 2 )
                    freq[s[l++]] --;
            }
        }

        return res;
    }
};
int main()
{
    string s="abcabcbb";
    Solution solution;
    int result =solution.lengthOfLongestSubstring2(s);
    cout<<"The longest substring is:"<<result<<endl;
}