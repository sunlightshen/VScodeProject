#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
using namespace std;
/*区分大小写字母的*/
class Solution {
private:
	static bool cm(const pair<char, int>& a, const pair<char, int>& b) {
	        return a.second > b.second;
	}

public:

	string frequencySort(string s)
	{
	    map<char,int> demo1;
	    vector<char> result;
	    for(int i=0;i<s.length();i++)
	        demo1[s[i]]++;
	    vector< pair<char, int> > vec(demo1.begin(), demo1.end());
	
	    sort(vec.begin(), vec.end(), cm);
	    int index=0;
	    for (int i = 0; i < vec.size(); i++)
	    {
	    	for(int j=0;j<vec[i].second;j++)
	    	{
				result.push_back(vec[i].first);
			}
		}
		return string(result.begin(),result.end());
	
	}
};

int main()
{
    string s="tree";
    Solution solution;
    string t = solution.frequencySort(s);
    cout<<t<<endl;
}