/*
	���ܣ��ݹ��˼��ʵ�������Ļ��� 
*/
#include<stdlib.h>
#include<stdio.h> 
//�����������ֵĵݹ麯�� 
int P(int n,int m){
	if(m==1) return 1;
	if(n<m)  return P(n,n);
	if(n==m) return 1+P(n,n-1);
	return (P(n,m-1)+P(n-m,m));
}
int main()
{
	int n;
	printf("������n��\n");
	scanf("%d",&n);
	int sum=P(n,n);
	printf("�ܵĻ�����ĿΪ��%d",sum); 
}
