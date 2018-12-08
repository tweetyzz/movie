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
} movInfo_t; //영화 정보 구조체  

void* mv_genMvInfo(char* name, float score, int runTime, char* country) //구조체에 정보 넣어서 와플 찍는 과정. 
{   
	movInfo_t* mvPtr;   
	
	mvPtr = (movInfo_t*)malloc(sizeof(movInfo_t)); //malloc 함수를 이용해서 동적 메모리 할당. 
	
	if(mvPtr == NULL)
	{
		printf("Error\n");
		return NULL;
	} 
	
	strcpy(mvPtr->madeIn,country); //국가는 문자열이므로 문자열 복사를 이용해서 규조체 안에 정보를 전달한다. 
	strcpy(mvPtr->name,name); //제목도 국가와 마찬가지로 문자열이므로 문자열 복사를 이용한다. 
	mvPtr->runTime=runTime; //런타임과 스코어는 정수형 변수이므로 굳이 복사하지 않고 바로 구조체로 정보를 전달한다. 
	mvPtr->score=score;
	
	  
	//allocate memory and set the member variables
	
	return (void*)mvPtr; // void*형 mvptr를 반환해 준다.(영화 하나하나에 대해 구조체를 만들 것이므로 반환해 줘야함) 
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

int mv_printAll(void* obj, void* arg) //모든 영화 정보를 출력하는 함수  
{
	printMv(obj);//obj 모두출력  
	printf("------------------------------------\n");
	
	return 1; 

}

int mv_printScore(void* obj, void* arg) //입력받은 스코어와 연관 있는 영화 정보만 출력하는 함수  
{
	movInfo_t* mvPtr = (movInfo_t*)obj; //특정 정보(obj)에 대해서만 봄. 
	
	if( ((mvPtr-> score) >= *(float*)arg))// 입력받은 최소 평점(arg)보다 크거나 같은 score일 때  
	{
		printMv(obj);// 조건을 만족하는 obj만 출력  
	    printf("------------------------------------\n");
	    return 1; // 영화 하나씩 따질 것 이므로 만족하면 1로 반환해서 출력, 아닐경우 0으로 반환, 그냥 넘어감.  
	}
	
	return 0;
}

int mv_printRunTime(void* obj, void* arg) //입력받은 런타임과  연관 있는 영화 정보만 출력하는 함수
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	
	if((mvPtr-> runTime) >= *(int*) arg )// 입력받은 최소 상영시간 (arg)보다 크거나 같은 runTime일 때
	{
		printMv(obj); // 조건을 만족하는 obj만 출력 
	    printf("------------------------------------\n");
	    return 1; // 영화 하나씩 따질 것 이므로 만족하면 1로 반환해서 출력, 아닐경우 0으로 반환, 그냥 넘어감.
	}
	return 0;
	
}

int mv_printCountry(void* obj, void* arg) //입력받은 국가와  연관 있는 영화 정보만 출력하는 함수
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	
	if(strcmp(mvPtr->madeIn, (char*)arg)==0) //입력받은 국가(arg)와 같을 경우       
	{
		printMv(obj);// 조건을 만족하는 obj만 출력
	    printf("------------------------------------\n");
	    return 1;// 영화 하나씩 따질 것 이므로 만족하면 1로 반환해서 출력, 아닐경우 0으로 반환, 그냥 넘어감.
	}
	return 0;
}




