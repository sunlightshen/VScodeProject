#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            res.push_back(q.back()->val);
            int size=q.size();
            for(int i=0;i<size;++i){
                TreeNode* t=q.front(); q.pop();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }           
        }
        return res;
    }
};
int main() {

    return 0;
}
