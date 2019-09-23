#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

class Solution {
private:
    const string letterMap[10] = {
            " ",    
            "",     
            "abc",  
            "def",  
            "ghi",  
            "jkl",  
            "mno",  
            "pqrs", 
            "tuv",  
            "wxyz"  
    };
    void findCombination(const string &digits, int index, const string &s,vector<string> &res){

        if( index == digits.size() ){
            res.push_back( s );
            return;
        }

        char c = digits[index];
        assert( c >= '0' && c <= '9' && c != '1');
        string letters = letterMap[c-'0'];
        for( int i = 0 ; i < letters.size() ; i ++ ){
            findCombination(digits, index+1, s + letters[i],res);
        }
        return;
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if( digits == "" )
            return res;
        findCombination(digits, 0, "",res);
        return res;
    }
};

int main() {

    vector<string> res = Solution().letterCombinations("234");
    string s="";
    s=s+'a'+'b'+'c';
    cout<<s<<endl;


    return 0;
}