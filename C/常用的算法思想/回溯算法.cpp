/*
	�����㷨ʵ��-�Ļʺ����� 
	����Ҫ˼��������������ȱ��� ��ͨ�����������������ҵ������������������Ľ� 
*/ 
#include<stdio.h> 
#include<iostream>
#include<conio.h>
using namespace std;

int count=0;
//�жϸ�����λ���Ƿ���԰�������
int isCorrect(int i,int j,int (*Q)[8])
{
	int n=8;
	int s,t;
	for(s=i,t=0;t<n;t++)
		if(Q[s][t]==1) return 0;
	for(s=j,t=0;t<n;t++)
		if(Q[t][s]==1) return 0;
	for(s=i+1,t=j+1;s<n,t<n;s++,t++)
		if(Q[s][t]==1)	return 0;
	for(s=i-1,t=j-1;s>=0,t>=0;s--,t--)
		if(Q[s][t]==1) return 0;
	for(s=i-1,t=j+1;s>=0,t<n;s--,t++)
		if(Q[s][t]==1) return 0;
	for(s=i+1,t=j-1;s<n,t>=0;t--,s++)
		if(Q[s][t]==1) return 0;
	return 1;	
 } 
//����Ѱ�һʺ��� 
void Queue(int j,int (*Q)[8])
{
	int n=8;
	if(j==n)
	{
		count++;
		cout<<"��������������"<<endl; 
		for(int i=0;i<n;i++)
		{
			for(int k=0;k<n;k++)
			{
				cout<<Q[i][k]<<" ";
			 } 
			cout<<endl;
		} 
		
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(isCorrect(i,j,Q))
		{
			Q[i][j]=1;
			Queue(j+1,Q);
			Q[i][j]=0;
			//���ҵ����������Ľ��Ҫ��������ı����������Ҫ���½��ó��Ļظ���0�ſ��� 
		}
	}
	
 } 
int main()
{
	int n=8;
	int Q[8][8];
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
		Q[i][j]=0;
	Queue(0,Q);
	cout<<"��������������Ϊ��"<<count<<endl; 
}
