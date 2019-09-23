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
        //在这节点及虚进行比较实际上是进行节点的值进行比较，这样现对于节点的比较更加的节省时间（前提是节点对应的数值是独立的且是唯一的）
        if(root == NULL || root->val == p->val || root->val == q->val)
        {
            return root; 
        }
        //分别查看左子树和右子树上进行查找
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left==NULL)
            return right;
        else
        {
            if(right==NULL)
                return left;
            else
                return root;
        }
        
       // return left == NULL? right : (right == NULL? left : root); 
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
    TreeNode*q=new TreeNode(8);
    Solution solution;
    TreeNode *res =solution.lowestCommonAncestor(root,p,q);
    cout<<"最近公共祖先对应的节点为："<<res->val<<endl;
    return 0;
}