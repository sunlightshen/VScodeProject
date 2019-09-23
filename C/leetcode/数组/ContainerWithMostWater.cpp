#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    /*
        用暴力方法时间复杂度为O(n2)，这里用双指针，时间复杂度为O(n)
    */
    int maxArea(vector<int>& height) {
        if(height.size() <= 1) return -1;
        int i = 0, j = height.size() - 1, res = 0;
        while(i < j){
            res = max(res, min(height[i], height[j])*(j-i));
            if(height[i] < height[j]) 
                i++;
            else 
                j--;
        }
        return res;
    }
};
int main()
{
    int a[]={1,8,6,2,5,4,8,3,7};
    vector<int> vec(a,a+sizeof(a)/sizeof(int));
    Solution solution;
    int area = solution.maxArea(vec);
    cout<<"The max area is :"<<area<<endl;

}