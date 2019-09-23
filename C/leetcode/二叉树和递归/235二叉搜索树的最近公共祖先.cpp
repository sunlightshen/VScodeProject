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

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //结合搜索二叉树的特殊优点
        assert( p != NULL && q != NULL );

        if( root == NULL )
            return NULL;

        if( p->val < root->val && q->val < root->val )
            return lowestCommonAncestor( root->left, p, q);
        if( p->val > root->val && q->val > root->val )
            return lowestCommonAncestor( root->right, p, q);

        assert( p->val == root->val || q->val == root->val
                || (root->val-p->val)*(root->val-q->val) < 0 );

        return root;
    }
};

int main() {
    TreeNode *root = new TreeNode(6);
    TreeNode *node1 =new TreeNode(2);
    TreeNode *node2 =new TreeNode(8);
    TreeNode *node3 =new TreeNode(0);
    TreeNode *node4 =new TreeNode(4);
    TreeNode *node5 =new TreeNode(7);
    TreeNode *node6 =new TreeNode(9);
    TreeNode *node7 =new TreeNode(3);
    TreeNode *node8 =new TreeNode(5);
    root->left=node1;
    root->right=node2;
    node1->left=node3;
    node1->right=node4;
    node2->left=node5;
    node2->right=node6;
    node4->left=node7;
    node4->right=node8;
    TreeNode*p= new TreeNode(2);
    TreeNode*q=new TreeNode(6);
    Solution solution;
    TreeNode *res =solution.lowestCommonAncestor(root,p,q);
    cout<<"最近公共祖先对应的节点为："<<res->val<<endl;

    return 0;
}