#include <iostream>
#include <vector>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        map<int,int> record;
        int res[2]={0}; 
        for( int i = 0 ; i < nums.size() ; i ++ ){

            int complement = target - nums[i];
            if( record.find(complement) != record.end() ){
                res[0] = i;
				res[1]=record[complement]; 
            }

            record[nums[i]] = i;
        }
        return vector<int>(res, res + 2);
    }
};


int main() {

    const int nums[] = {-1, 0, 1, 2, -1};
    vector<int> nums_vec( nums, nums + sizeof(nums)/sizeof(int) );
    int target = 4;

    vector<int> res = Solution().twoSum(nums_vec, target);
    cout<<res[0]<<" , "<<res[1]<<endl;
}