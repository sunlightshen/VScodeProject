#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    /*最优化方法*/
    void moveZeroes(vector<int>& nums) {
		int k = 0;
		for (int i=0;i<nums.size();i++)
		{
			if(nums[i])
            {
                /*边界处理需要仔细思考*/
                if(k!=i)
				    swap(nums[k++],nums[i]);
                else
                {
                    k++;
                }
                
            }
		}
        
    }
    /*基本方法*/
    void moveZeroes1(vector<int>& nums) {
        int k = 0;
        vector<int> nonZeros;
        for (int i=0;i<nums.size();i++)
        {
            if(nums[i])
                nonZeros.push_back(nums[i]);
        }
        for(int i=0;i<nonZeros.size();i++)
        {
            nums[i]=nonZeros[i];
        }
        for(int i=nonZeros.size();i<nums.size();i++)
        {
            nums[i]=0;
        }
    }
    /*双索引*/
    void moveZeroes2(vector<int>& nums){
        int k=0;
        for(int i=0;i<nums.size();i++)
        {

            if(nums[i])
            {
                nums[k++] = nums[i];
            }

        }
        for(int i=k;i<nums.size();i++)
        {
            nums[i]=0;
        }

    }
};
int main()
{
	int a[10] = {1,0,2,0,4,5,7,0};
	vector<int> vec(a,a+sizeof(a)/sizeof(int));
	Solution solution;
	solution.moveZeroes(vec);
	for(int i=0;i<vec.size();i++)
	{
		cout<<vec[i]<<" ";
	}
}
 