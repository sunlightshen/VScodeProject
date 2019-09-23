#include<iostream>
#include<algorithm>
#include<vector>
#include <iostream>
#include<map>
using namespace std;

/*创建链表结构体*/ 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*创建链表*/
ListNode* createLinkedList(int arr[], int n){

    if( n == 0 )
        return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* curNode = head;
    for( int i = 1 ; i < n ; i ++ ){
        curNode->next = new ListNode(arr[i]);
        curNode = curNode->next;
    }

    return head;
}
/*打印链表节点*/ 
void printLinkedList(ListNode* head){

    ListNode* curNode = head;
    while( curNode != NULL ){
        cout << curNode->val << " -> ";
        curNode = curNode->next;
    }

    cout<<"NULL"<<endl;

    return;
}
/*清除链表内存*/ 
void deleteLinkedList(ListNode* head){

    ListNode* curNode = head;
    while( curNode != NULL ){
        ListNode* delNode = curNode;
        curNode = curNode->next;
        delete delNode;
}
    return;
}

// 时间复杂度: O(n)
// 空间复杂度: O(1)
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return mergesort(head);
    }
    ListNode* mergesort(ListNode* node)
    {
        if(!node || !node->next) return node;
        ListNode *fast=node;//快指针走两步
        ListNode *slow=node;//慢指针走一步
        ListNode *brek=node;//断点
        while(fast && fast->next)
        {
            fast=fast->next->next;
            brek=slow;
            slow=slow->next;
        }
        brek->next=NULL;
        ListNode *l1=mergesort(node);
        ListNode *l2=mergesort(slow);
        return merge(l1,l2);
    }
    ListNode* merge(ListNode* l1,ListNode* l2)
    {
        if(l1==NULL)
        {
            return l2;
        }
        if(l2==NULL)
        {
            return l1;
        }
        if(l1->val < l2->val)
        {
            l1->next=merge(l1->next,l2);
            return l1;
        }
        else
        {
            l2->next=merge(l2->next,l1);
            return l2;
        }
    }
};



int main() {
	
	int arr1[]={4,2,1,3};
	int arr2[]={1,3,4};
	ListNode *head1 = createLinkedList(arr1,4);
	ListNode *head2 = createLinkedList(arr2,3);
	printLinkedList(head1);
	printLinkedList(head2); 
	Solution solution;
	ListNode *newhead = solution.sortList(head1);
	cout<<endl;
	printLinkedList(newhead);

    return 0;
}
