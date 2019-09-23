#include <iostream>
#include<vector>
using namespace std;

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void inorder(TreeNode* root,vector<int>& res)
    {
        if(root!=NULL)
        {
            inorder(root->left,res);
            res.push_back(root->val);
            inorder(root->right,res);
            
        }
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        vector<int> tmp ;
        inorder(root,tmp);
        for(int i=0;i<tmp.size()-1;i++)
        {
            if(tmp[i]>=tmp[i+1])
            {
                return false;
            }
        }
        return true;
        
    }
};

int main() {

    TreeNode* node1 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(-2);

    TreeNode* node3 = new TreeNode(3);
    node3->left = node1;
    node3->right = node2;

    TreeNode* node4 = new TreeNode(1);
    TreeNode* node5 = new TreeNode(2);
    node5->right = node4;

    TreeNode* node6 = new TreeNode(5);
    node6->left = node3;
    node6->right = node5;

    TreeNode* node7 = new TreeNode(11);
    TreeNode* node8 = new TreeNode(-3);
    node8->right = node7;

    TreeNode* node9 = new TreeNode(10);
    node9->left = node6;
    node9->right = node8;

    if(Solution().isValidBST(node9))
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
    

    return 0;
}