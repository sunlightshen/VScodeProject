#include<iostream>
#include<algorithm>
#include<vector>
#include <iostream>
#include<map>
using namespace std;

/*��������ṹ��*/ 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*��������*/
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
/*��ӡ����ڵ�*/ 
void printLinkedList(ListNode* head){

    ListNode* curNode = head;
    while( curNode != NULL ){
        cout << curNode->val << " -> ";
        curNode = curNode->next;
    }

    cout<<"NULL"<<endl;

    return;
}
/*��������ڴ�*/ 
void deleteLinkedList(ListNode* head){

    ListNode* curNode = head;
    while( curNode != NULL ){
        ListNode* delNode = curNode;
        curNode = curNode->next;
        delete delNode;
}
    return;
}

// ʱ�临�Ӷ�: O(n)
// �ռ临�Ӷ�: O(1)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode* p = dummyHead;
        while( p->next && p->next->next ){
            ListNode* node1 = p->next;
            ListNode* node2 = node1->next;
            ListNode* next = node2->next;
            node2->next = node1;
            node1->next = next;
            p->next = node2;
            p = node1;
        }

        ListNode* retHead = dummyHead->next;
        delete dummyHead;

        return retHead;
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
	ListNode *newhead = solution.swapPairs(head1);
	cout<<endl;
	printLinkedList(newhead);

    return 0;
}
