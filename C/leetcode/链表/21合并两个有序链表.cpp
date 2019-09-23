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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* newnode = new ListNode(0);
        ListNode* p1=l1;
        ListNode* p2=l2;
        ListNode* tmp=newnode;
        while(p1!=NULL && p2!=NULL)
        {
        	if(p1->val<=p2->val)
        	{
        		tmp->next =p1;
        		tmp=tmp->next;
        		p1=p1->next;
        	}
        		
        	else
        	{
        		tmp->next =p2;
        		p2=p2->next;
        		tmp=tmp->next;
			}	
		}
		if(p1==NULL)
		{
			tmp->next=p2;
		}
		if(p2==NULL)
		{
			tmp->next=p1;
		}
		return newnode->next;
    }
};

int main() {
	
	int arr1[]={1,2,4};
	int arr2[]={1,3,4};
	ListNode *head1 = createLinkedList(arr1,3);
	ListNode *head2 = createLinkedList(arr2,3);
	printLinkedList(head1);
	printLinkedList(head2); 
	Solution solution;
	ListNode *newhead = solution.mergeTwoLists(head1,head2);
	cout<<endl;
	printLinkedList(newhead);

    return 0;
}
