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
};

int main() {
	
	int arr1[]={7,2,4,3};
	ListNode *head1 = createLinkedList(arr1,4);
	printLinkedList(head1);
	Solution solution;
	ListNode *newhead = solution.reverseList(head1);
	cout<<endl;
	printLinkedList(newhead);

    return 0;
}
