#include <iostream>
#include <stack>
#include <cassert>
#include<vector>
using namespace std;

class Solution {
public:
string simplifyPath(string path) 
    {
        vector<string> dir ;
        int loc = 0;
        while(loc < path.size())
        {
            string name = "";
            while(loc<path.size() && path[loc] != '/')
            {
                name += path[loc];
                loc++;
            }
            if(name != "" && name != ".." && name != ".")
                dir.push_back(name);
            if(name == ".." && dir.size()>0)
                dir.pop_back();
            loc++;
        }
        string dirpath = "/";
        if(dir.size() == 0)
            return dirpath;
        for(int i=0;i<dir.size()-1;i++)
        {
            dirpath += dir[i];
            dirpath += "/";
        }
        dirpath += dir[dir.size()-1];
        return dirpath;
    }
};

int main()
{
	string str1="/home/";
	string str2="/../";
	cout<<str1<<": "<<Solution().simplifyPath(str1)<<endl;
	cout<<str2<<": "<<Solution().simplifyPath(str2)<<endl;
	
}
