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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL)
            return res;
        TreeNode*queue[10000];
        int rear,front;
        int last;
        rear = front = -1;//不能为0，因为下面在循环外面把根节点入队了。
        last = 0;
        TreeNode* p = root;
        queue[++rear] = p;
        vector<int> floor;
        while(rear!=front)
        {
            p = queue[++front];
            floor.push_back(p->val);
            if(p->left!=NULL)
                queue[++rear] = p->left;
            if(p->right!=NULL)
                queue[++rear] = p->right;
            if(last == front)//如果相等就代表出队出到了我们指定的位置代表一层已经遍历完成。
            {
                last = rear;
                res.push_back(floor);
                floor.clear();
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

int main() {

    return 0;
}
