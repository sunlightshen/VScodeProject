/*
	���ܣ��ݹ���۰�����㷨�� 
*/  
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
//����ݹ��۰���Һ��� 
int bin_search(int key[],int low,int high,int k){
	int mid;
	if(low>high) return-1;
	else{
		mid=(low+high)/2;
		if(key[mid]==k)
			return mid;
		if(k>key[mid])
			return bin_search(key,mid+1,high,k);
		else
			return bin_search(key,low,mid-1,k); 
	}
}
int main(){
	int n,i,addr;
	int A[10]={2,3,5,7,8,10,12,15,19,21};
	printf("��Ҫ���ҵ�����Ϊ��\n");
	for(int i=0;i<10;i++){
		printf("%d ",A[i]);
	} 
	printf("\n");
	printf("��������Ҫ���ҵ�����\n");
	scanf("%d",&n);
	addr=bin_search(A,0,9,n);
	if(addr!=-1){
		cout<<n<<"�ǵ�"<<addr+1<<"��Ԫ�أ�"<<endl;
	}
	else
		cout<<"�����в�����"<<n<<"!"<<endl;
} 
