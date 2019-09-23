#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;
/*创建链表结构体*/ 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
    static bool cmp (const ListNode* a,const ListNode* b){
    return a->val<b->val;
		}
public:  
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode *>node_ptr_vec;
        ListNode *head;
        for(int i=0;i<lists.size();i++){
            head=lists[i];
            while( head){
                node_ptr_vec.push_back( head );
                head=head->next;
            }
        }
        if(node_ptr_vec.size()==0)
            return NULL;
        sort(node_ptr_vec.begin(),node_ptr_vec.end(),cmp);
        for(int i=0;i<node_ptr_vec.size()-1;i++)
            node_ptr_vec[i]->next=node_ptr_vec[i+1];
        node_ptr_vec[node_ptr_vec.size()-1]->next=NULL;
        return node_ptr_vec[0];
    }
};

int main()
{
	return 0;
 } 
