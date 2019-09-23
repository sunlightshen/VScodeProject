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
    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return;
        }
        ListNode* mid=findMid(head);
        ListNode* l2=mid->next;
        mid->next=NULL;
        l2=reverse(l2);
        ListNode* l1=head;
        while(l1!=NULL&&l2!=NULL){
            ListNode* next=l1->next;
            l1->next=l2;
            l2=l2->next;
            l1->next->next=next;
            l1=next;
        }
    }
private:
    ListNode* findMid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL&&fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode* pre=NULL;
        ListNode* next=NULL;
        ListNode* cur=head;
        while(cur!=NULL){
            next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        return pre;
    }
}; 



int main() {
	
	int arr1[]={1,2,3,4};
	int arr2[]={1,3,4};
	ListNode *head1 = createLinkedList(arr1,4);
	ListNode *head2 = createLinkedList(arr2,3);
	printLinkedList(head1);
	printLinkedList(head2); 
	Solution solution;
	solution.reorderList(head1);
	cout<<endl;
	printLinkedList(head1);

    return 0;
}
