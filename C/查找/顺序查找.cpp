/*
	˳����� 
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct Student{
	int id;
	char name[20];
	float score;
} Student; 

int search(Student stu[],int key,int n){
	int i;
	for(i=0;i<n;i++){
		if(stu[i].id==key)
		{
			return i;
		}
	}
	return -1;
}
int main()
{
	//����ѧ��ʵ�� 
	Student stu[4] = {{1004,"Tom",89},{1001,"shenguang",0},{1002,"wangliang1",80},
	{1003,"liwei",99}};
	int addr;
	addr=search(stu,1001,4);
	printf("ѧ���˺�Ϊ:%d\n",stu[addr].id);
	printf("ѧ������Ϊ:%s\n",stu[addr].name);
	printf("ѧ���ɼ�Ϊ:%0.2f\n",stu[addr].score);
}
