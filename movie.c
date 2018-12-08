#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"

//structure definition
typedef struct movInfo {
	char name[100];
	float score;
	int runTime;
	char madeIn[10];
} movInfo_t; //��ȭ ���� ����ü  

void* mv_genMvInfo(char* name, float score, int runTime, char* country) //����ü�� ���� �־ ���� ��� ����. 
{   
	movInfo_t* mvPtr;   
	
	mvPtr = (movInfo_t*)malloc(sizeof(movInfo_t)); //malloc �Լ��� �̿��ؼ� ���� �޸� �Ҵ�. 
	
	if(mvPtr == NULL)
	{
		printf("Error\n");
		return NULL;
	} 
	
	strcpy(mvPtr->madeIn,country); //������ ���ڿ��̹Ƿ� ���ڿ� ���縦 �̿��ؼ� ����ü �ȿ� ������ �����Ѵ�. 
	strcpy(mvPtr->name,name); //���� ������ ���������� ���ڿ��̹Ƿ� ���ڿ� ���縦 �̿��Ѵ�. 
	mvPtr->runTime=runTime; //��Ÿ�Ӱ� ���ھ�� ������ �����̹Ƿ� ���� �������� �ʰ� �ٷ� ����ü�� ������ �����Ѵ�. 
	mvPtr->score=score;
	
	  
	//allocate memory and set the member variables
	
	return (void*)mvPtr; // void*�� mvptr�� ��ȯ�� �ش�.(��ȭ �ϳ��ϳ��� ���� ����ü�� ���� ���̹Ƿ� ��ȯ�� �����) 
}

void printMv(void* obj)
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	if (mvPtr == NULL)
	{
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}
	
	printf("Name : %s (%s)\n", mvPtr->name, mvPtr->madeIn);
	printf("running time : %i, score : %f\n", mvPtr->runTime, mvPtr->score);
	
	return;
}

int mv_printAll(void* obj, void* arg) //��� ��ȭ ������ ����ϴ� �Լ�  
{
	printMv(obj);//obj ������  
	printf("------------------------------------\n");
	
	return 1; 

}

int mv_printScore(void* obj, void* arg) //�Է¹��� ���ھ�� ���� �ִ� ��ȭ ������ ����ϴ� �Լ�  
{
	movInfo_t* mvPtr = (movInfo_t*)obj; //Ư�� ����(obj)�� ���ؼ��� ��. 
	
	if( ((mvPtr-> score) >= *(float*)arg))// �Է¹��� �ּ� ����(arg)���� ũ�ų� ���� score�� ��  
	{
		printMv(obj);// ������ �����ϴ� obj�� ���  
	    printf("------------------------------------\n");
	    return 1; // ��ȭ �ϳ��� ���� �� �̹Ƿ� �����ϸ� 1�� ��ȯ�ؼ� ���, �ƴҰ�� 0���� ��ȯ, �׳� �Ѿ.  
	}
	
	return 0;
}

int mv_printRunTime(void* obj, void* arg) //�Է¹��� ��Ÿ�Ӱ�  ���� �ִ� ��ȭ ������ ����ϴ� �Լ�
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	
	if((mvPtr-> runTime) >= *(int*) arg )// �Է¹��� �ּ� �󿵽ð� (arg)���� ũ�ų� ���� runTime�� ��
	{
		printMv(obj); // ������ �����ϴ� obj�� ��� 
	    printf("------------------------------------\n");
	    return 1; // ��ȭ �ϳ��� ���� �� �̹Ƿ� �����ϸ� 1�� ��ȯ�ؼ� ���, �ƴҰ�� 0���� ��ȯ, �׳� �Ѿ.
	}
	return 0;
	
}

int mv_printCountry(void* obj, void* arg) //�Է¹��� ������  ���� �ִ� ��ȭ ������ ����ϴ� �Լ�
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	
	if(strcmp(mvPtr->madeIn, (char*)arg)==0) //�Է¹��� ����(arg)�� ���� ���       
	{
		printMv(obj);// ������ �����ϴ� obj�� ���
	    printf("------------------------------------\n");
	    return 1;// ��ȭ �ϳ��� ���� �� �̹Ƿ� �����ϸ� 1�� ��ȯ�ؼ� ���, �ƴҰ�� 0���� ��ȯ, �׳� �Ѿ.
	}
	return 0;
}




