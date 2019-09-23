    
#include <iostream>
#include<vector>
#include<algorithm>
#include <cassert>

using namespace std;

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
    
class Solution{
private:
    //求二分搜索树的最小值
    int minnumber(TreeNode *node){
        //最小值一定是在左侧的
        if (node!=NULL)
        {
            if (node->left==NULL)
                return node->val;
            else
                return minnumber(node->left);
        }
    }
    TreeNode* remvmin(TreeNode*node){
        if (node!=NULL && node->left ==NULL)
        {
            TreeNode* rightnode=node->right;
            return rightnode;
        }
        node->left = remvmin(node->left);
        return node;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key){
        if (root==NULL)
            return NULL;
        if (key<root->val)
        {
            root->left = deleteNode(root->left,key);
            return root;
        }
        else if(key>root->val)
        {
            root->right = deleteNode(root->right,key);
            return root;
        }
        else
        {
            if (root->left==NULL)
            {
                TreeNode *rightnode = root->right;
                delete root;
                return rightnode;
            }
            else if (root->right=NULL)
            {
                TreeNode *leftnode = root->left;
                delete root;
                return leftnode;
            }
            else
            {
                TreeNode *newnode = new TreeNode(minnumber(root->right));
                newnode->right = remvmin(root->right);
                newnode->left = root->left;
                return newnode;
            }
        }
    }
};
