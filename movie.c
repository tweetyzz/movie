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
} movInfo_t;

void* mv_genMvInfo(char* name, float score, int runTime, char* country)
{   
	movInfo_t* mvPtr;
	
	mvPtr = (movInfo_t*)malloc(sizeof(movInfo_t));
	
	if(mvPtr == NULL)
	{
		printf("Error\n");
		return NULL;
	}
	
	strcpy(mvPtr->madeIn,country);
	strcpy(mvPtr->name,name);
	mvPtr->runTime=runTime;
	mvPtr->score=score;
	
	// malloc 써야함  동적메모리 할당.  
	//allocate memory and set the member variables
	
	return (void*)mvPtr;
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

int mv_printAll(void* obj, void* arg)
{
	
	//거르는 곳 
}

int mv_printScore(void* obj, void* arg)
{
	
}

int mv_printRunTime(void* obj, void* arg)
{
	
}

int mv_printCountry(void* obj, void* arg)
{
	
}




