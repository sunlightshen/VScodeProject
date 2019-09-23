#include<iostream>
#include<algorithm>
#include<vector> 
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int n=prices.size();
        //定义三个状态：出售状态、购买状态、冷冻期 
        vector<int> sell(n,0);
        vector<int> buy(n,0);
        vector<int> cooldown(n,0);
        buy[0]=-prices[0]; 
        for(int i=1;i<n;i++){
            sell[i]=max(sell[i-1],buy[i-1]+prices[i]);
            buy[i]=max(buy[i-1],cooldown[i-1]-prices[i]);
            cooldown[i]=max(cooldown[i-1],max(sell[i-1],buy[i-1]));
        }
        return sell.back();
    }
};

int main()
{
	int arr[]={1,2,3,0,2};
	vector<int> vec(arr,arr+sizeof(arr)/sizeof(int));
	int profits = Solution().maxProfit(vec);
	cout<<"The max profits is :"<<profits<<endl;
}
