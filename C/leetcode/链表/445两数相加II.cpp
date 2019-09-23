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
    ListNode* reverseList(ListNode* head) {

    ListNode* pre = NULL;
    ListNode* cur = head;
    while( cur != NULL ){
        ListNode* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}
ListNode* addTwo(ListNode* l1, ListNode* l2) {
        
		ListNode *newList = l1, *pre ;
		int flag = 0;  
		while (l1||l2)
		{
			int value;
			(l1) ? (pre = l1,l1 = l1->next, value = pre->val + flag) : (pre->next=l2, pre = l2, value= flag);
			(l2) ? (value += l2->val, l2 = l2->next) : (pre->next=l1);
			pre->val = value % 10;
			(value > 9) ? (flag = 1) : (flag = 0);
		}
		if (l1 == NULL && l2 == NULL && flag == 1)
			pre->next = new ListNode(1);
		return newList;
        
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode* reverseL1 = reverseList(l1);
        ListNode* reverseL2 = reverseList(l2);
        return reverseList(addTwo(reverseL1, reverseL2));
        
    }
};

int main() {
	
	int arr1[]={7,2,4,3};
	int arr2[]={5,6,4};
	ListNode *head1 = createLinkedList(arr1,4);
	ListNode *head2 = createLinkedList(arr2,3);
	printLinkedList(head1);
	printLinkedList(head2); 
	Solution solution;
	ListNode *newhead = solution.addTwoNumbers(head1,head2);
	cout<<endl;
	printLinkedList(newhead);

    return 0;
}
