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
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next) return true;   //������������ֻ��һ��Ԫ��
        ListNode *slow=head,*fast=head;       //����ָ��
        for( ; fast&&fast->next ; fast=fast->next->next,slow=slow->next); //����ָ��������е�
        ListNode *cur=slow,*nex=NULL,*back = NULL;            //back��ʾ�������ͷָ��
        for( ; cur ; nex=cur->next, cur->next=back, back=cur, cur=nex);  //��ת�������   
        for(ListNode* front=head ; front&&back ; front=front->next,back=back->next) //front:ǰ������ͷָ��
            if(back->val!=front->val) return false;   //ǰ����������������Ԫ�رȽ�
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
