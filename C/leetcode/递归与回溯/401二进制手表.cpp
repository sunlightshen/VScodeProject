#include<iostream>
#include<string>
#include<vector> 
#include<algorithm> 
using namespace std;

class Solution {
public:
vector<string> ans;
vector<string> readBinaryWatch(int num) {
    DFS(num, 0, vector<int>(10));
    return ans;
}
void DFS(int num, int pos, vector<int>time) {
    if (num == 0) {
        int hour = time[0] + 2 * time[1] + 4 * time[2] + 8 * time[3];
        int minute = time[4] + 2 * time[5] + 4 * time[6] + 8 * time[7] + 16 * time[8] + 32 * time[9];
        if (hour < 12 && minute < 60) {
            char buffer[6];
            sprintf(buffer, "%d:%.2d", hour, minute);
            ans.push_back(buffer);
        }
        return;
    }
    for (int i = pos; i <= 10 - num; i++) {
        time[i]++;
        DFS(num-1, i + 1, time);
        time[i]--;
    }
}
};
int main()
{
	vector<string> num =Solution().readBinaryWatch(1); 
	for(int i=0;i<num.size();i++)
	{
		cout<<num[i]<<" ";
	}
 } 
