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
ListNode* insertionSortList(ListNode* head) {
        if(NULL == head) return NULL;
        ListNode* complete = head;
        ListNode* execute  = head->next;
        complete->next = NULL;
        if(NULL == execute) return complete;
        do{
            ListNode* node = execute;
            execute = execute->next;
            ListNode* prev = NULL;
            ListNode* next = complete;
            while(next && next->val <= node->val){
                prev = next;
                next = next->next;
            }
            if(prev)
                prev->next = node;
            else
                complete = node;
            node->next = next;
        }while(execute);
        return complete;
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
	ListNode *newhead = solution.insertionSortList(head1);
	cout<<endl;
	printLinkedList(newhead);

    return 0;
}
