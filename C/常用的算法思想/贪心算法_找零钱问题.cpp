/*
	̰���㷨��С����Ǯ������ 
*/ 
#include<stdio.h>
#include<iostream>
#include<algorithm> 
using namespace std;

zhaoling(float sum,float recv,int v[])
{
	float tmp,l;
	float num;
	int j;
	num=recv-sum; 
	//sum��Ӧ�ս�recv��ʵ�յ�Ǯ��v�ҳ��ĸ������ֵĸ���������
	float money[3]={1.0,0.5,0.1};//���п��ҳ��ı���
	for(int i=0;i<3;i++){
		l=0;
		for(j=0;j<=5;j++)
		{
			if((num-money[i]*j)<=0)
				break;
		}
		v[i]=j-1;
		num=num-v[i]*money[i];
	} 
}

int main()
{
	float m,n;
	int v[3];
	cout<<"���������Ӧ���ܽ�"<<endl;
	cin>>m;
	cout<<"������ʵ���ܽ��:"<<endl;
	cin>>n;
	zhaoling(m,n,v);
	cout<<"������㷽��"<<endl;
	int sum=0; 
	for(int i=0;i<3;i++)
	{
		cout<<v[i]<<" ";
		sum=sum+v[i]; 
	 } 
	 cout<<endl;
	 cout<<"��С������ĿΪ:"<<endl;
	 cout<<sum;
	 
	
 } 
