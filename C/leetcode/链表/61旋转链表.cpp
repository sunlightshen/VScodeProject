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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || !head || !(head -> next))  return head;
        ListNode *temp = head;
        int len = 0;
        while(temp){
            ++ len;
            temp = temp -> next;
        }
        k = k % len;
        temp = head;
        for(int i = len - 1; i > 0; -- i)   temp = temp -> next;
        temp -> next = head;
        temp = head;
        for(int j = len - k; j > 0; -- j)   temp = temp -> next;
        head = temp;
        for(int m = len - 1; m > 0; -- m)   temp = temp -> next;
        temp -> next = NULL;
        return head;
    }
};



int main() {
	
	int arr1[]={1,2,3,4,5};
	int arr2[]={1,3,4};
	ListNode *head1 = createLinkedList(arr1,5);
	ListNode *head2 = createLinkedList(arr2,3);
	printLinkedList(head1);
	printLinkedList(head2); 
	Solution solution;
	ListNode *newhead = solution.rotateRight(head1,2);
	cout<<endl;
	printLinkedList(newhead);

    return 0;
}
