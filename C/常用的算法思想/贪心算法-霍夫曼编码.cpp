/*
	̰���㷨-���������� 
	��Ҫ˼�룺ÿ��Ѱ�Ҿֲ����Ž� 
*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
//����ȫ�ֱ�����
int count=0; 
zhaoling(double recv,double srecv ,int juzhen[])
{

	double give=recv-srecv;
	double money[3]={1.0,0.5,0.1};
	int l;
	for(int i=0;i<3;i++)
	{
		l=0;
		while(1)
		{
			l++;
			if(give-(double)l*money[i]<=0)
				break;
		}
		juzhen[i]=l-1;
		give=give+money[i];
	}
	return count;
}
int main()
{
	double sum1=2.7;
	double sum2=3.0;
	int juzhen[3]={0};
	int count=0;
	count=zhaoling(sum2,sum1,juzhen);
	for(int i=0;i<3;i++)
	{
		cout<<juzhen[i]<<" ";
	}
	cout<<endl;
	cout<<"��С����Ǯ��Ϊ��"<<count<<endl; 
	 
 	
}
