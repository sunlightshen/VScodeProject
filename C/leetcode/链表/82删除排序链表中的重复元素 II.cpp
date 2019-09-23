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
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL) 
			return NULL;
 		ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
		map<int, int> m;
		ListNode* p = dummyHead;
		ListNode* next = dummyHead->next;
		while (p != NULL && next != NULL) {
			
			if (m[next->val] > 1) {
				p->next = next->next;
				next = next->next;
			}
			else{
				m[next->val]++;
				p = p->next;
				next = next->next;
			}		
		}
		cout<<"m[1]:"<<m[1]<<endl;
		ListNode* p1 = dummyHead;
		ListNode* next1 = dummyHead->next;
		while (p1 != NULL && next1 != NULL) {
			if (m[next1->val] > 1) {
				cout<<"000"<<endl;
				p1->next = next1->next;
				next1 = next1->next;
			}
			else{
				p1 = p1->next;
				next1 = next1->next;
			}		
		}
		printLinkedList(head);
		return dummyHead->next;
	}
};

int main() {
	
	int arr1[]={1,1};
	int arr2[]={5,6,4};
	ListNode *head1 = createLinkedList(arr1,2);
	ListNode *head2 = createLinkedList(arr2,3);
	printLinkedList(head1);
	printLinkedList(head2); 
	Solution solution;
	ListNode *newhead = solution.deleteDuplicates(head1);
	cout<<endl;
	printLinkedList(newhead);

    return 0;
}
