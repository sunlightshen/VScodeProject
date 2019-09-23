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
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next) return true;   //空链表表或链表只有一个元素
        ListNode *slow=head,*fast=head;       //快慢指针
        for( ; fast&&fast->next ; fast=fast->next->next,slow=slow->next); //快慢指针迭代找中点
        ListNode *cur=slow,*nex=NULL,*back = NULL;            //back表示后半链表头指针
        for( ; cur ; nex=cur->next, cur->next=back, back=cur, cur=nex);  //反转后半链表   
        for(ListNode* front=head ; front&&back ; front=front->next,back=back->next) //front:前半链表头指针
            if(back->val!=front->val) return false;   //前半链表与后半链表逐元素比较
        return true;
    }
};
int main() {
	
	int arr1[]={1,2,2,1};
	int arr2[]={1,3,4};
	ListNode *head1 = createLinkedList(arr1,4);
	ListNode *head2 = createLinkedList(arr2,3);
	printLinkedList(head1);
	printLinkedList(head2); 
	Solution solution;
	bool flag = solution.isPalindrome(head1);
	cout<<endl;
	if(flag)
	{
		cout<<"true!"<<endl;
	}

    return 0;
}
