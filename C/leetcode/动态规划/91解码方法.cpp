#include<iostream>
#include<iostream>
#include<vector>
using namespace std;
class Solution{
        public:
        int numDecodings(string s) {
        if (s.empty() || s.length() == 0) {
            return 0;
        }
        int len = s.length();
        int dp[len + 1];
        dp[len] = 1;
        if (s[len - 1] == '0') {
            dp[len - 1] = 0;
        } else {
            dp[len - 1] = 1;
        }
        for (int i = len - 2; i >= 0; i--) {
            if (s[i] == '0') {
                dp[i] = 0;
                continue;
            }
            if ((s[i]- '0') * 10 + (s[i+1] - '0') <= 26) {
                        dp[i] = dp[i + 1] + dp[i + 2];
            } else {
                dp[i] = dp[i + 1];
            }
        }
        return dp[0];
    }

};
int main()
{
    string s="123456";
    cout<<"The total number is :"<<Solution().numDecodings(s)<<endl;

}