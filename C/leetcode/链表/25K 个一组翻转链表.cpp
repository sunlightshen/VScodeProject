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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* pre=dummy;
        ListNode* cur=head;
        ListNode* tail=dummy;
        while(true){
            int count=0;
            tail=pre;
            while(tail!=NULL&&count<k){
                tail=tail->next; 
                count++;
            }
            if(tail==NULL)
                break;
            while(pre->next!=tail){ 
                cur=pre->next;
                pre->next=cur->next; 
                    
                cur->next=tail->next;
                tail->next=cur; 
                
            }
            pre=head;
            tail=head;
            head=pre->next;
        }
        return dummy->next;
    }
};


int main() {
	
	int arr1[]={1,2,3,4,5};
	int arr2[]={1,3,4};
	ListNode *head1 = createLinkedList(arr1,4);
	ListNode *head2 = createLinkedList(arr2,3);
	printLinkedList(head1);
	printLinkedList(head2); 
	Solution solution;
	ListNode *newhead = solution.reverseKGroup(head1,3);
	cout<<endl;
	printLinkedList(newhead);

    return 0;
}
