/*
	��ֵ�����㷨 
*/
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

//ʵ������һ�ֽ��Ƶķ��������ֵ�ֵ 
double Darts(int n)
{
	double x,y;
	time_t t;
	int i,count=0;
	srand((unsigned)time(&t));//��ʱ������ֵ���Ա�֤ÿ�����������ֵ���ǲ���ͬ�� 
	for(i=0;i<n;i++)
	{
		x=rand()%100/100.0;
		y=rand()%100/100.0;
		if(y<=1-pow(x,2))
		{
			count++;
		}
	}
	return (double)count/(double)n;
	//int���͵ĺ�����ʹ����ֵ����ΪdoubleҲ�ᱻǿ��ת��Ϊint���͵ı��� 
	
 } 
int main()
{
	int n;
	cout<<"�������������ľ��ȣ�"<<endl;
	cin>>n;
	double sum;
	sum=Darts(n);
	cout<<"����ֵΪ��"<<sum<<endl;
	
 } 
