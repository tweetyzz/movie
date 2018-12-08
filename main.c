#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
#include "linkedList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	FILE *fp; //FILE pointer for reading movie data 
	char name[200]; //movie name
	char country[10]; //movie country
	int runTime; //movie runtime
	float score; //movie score
	
	int exit_flag = 0; //flag variable for while loop
	int option; //user input option
	void *list, *mvInfo; //pointers for linked list and a specific structure instance for a movie data
	int (*repFunc)(void* obj, void* arg); //function pointer for using list_repeatFunc() function
	void *arg; //a void pointer for passing argument to repFunc
	int cnt; //integer variable
	
	//1. reading the movie.dat-----------------------------
	
	fp=fopen("movie.dat.dat","r"); //영화 정보가 들어있는 dat 파일을 읽어온다. 
	//1.1 FILE open
	
	
	//1.2 list generation (use function list_genList() )
	list = list_genList();//영화 정보를 담을 그릇(리스트) 
	
	//1.3 read each movie data from the file and add it to the linked list
	while (EOF != fscanf(fp,"%s%s%d%f",name,country,&runTime,&score)/* read name, country, runtime and score*/ )
	{	//fscanf로 파일 속 정보들을 받는다.
	   
	   void* mvInfo= mv_genMvInfo(name,score,runTime,country);
	   //mv_genMvInfo 에 받은 정보를 넣는다. 
	   list_addTail(mvInfo, list);// 리스트 꼬리(뒤)에 계속 리스트를 추가한다. 

	//generate a movie info instance(mvInfo) with function mv_genMvInfo()
		
	}
    
    fclose(fp);
	//1.4 FILE close
	
	//2. program start
	while(exit_flag == 0)
   {    
        printf("Reading the data files...\n");
        printf("Reading done! 10 items are read \n\n\n\n");
        printf("------------------Menu------------------\n");
	    printf("1. print all the movies\n");
	    printf("2. search for specific contry movies\n");
	    printf("3. search for specific runtime movies\n");
	    printf("4. search for specific score movies\n");
	    printf("5. exit\n");
	    printf("------------------Menu------------------\n");
	
	    printf("--select an option : ");
	    scanf("%d",&option);

		//2.1 print menu message and get input option
		
		switch(option)
		{
			case 1: //print all the movies
				printf("\nprinting all the movies in the list.....\n\n\n");
				printf("----------------------------------------\n");
				
				repFunc = mv_printAll; 
				arg = NULL; // 모든 영화 정보이기 때문에 특정 arg가 존재하지 않음. 
			
				break;
				
			case 2: //print movies of specific country
			    printf("\nselect a country : ");
			    scanf("%s",&country);// 출력하고자 하는 나라의 정보를 입력받는다.  
			    
			    repFunc = mv_printCountry; //모든 영화 정보중 나라 정보만 따짐  
				arg = country;// 입력받은 정보(arg)는 여기서 country가 됨. 
			    
				break;
				
			case 3: //print movies with long runtime
			    printf("\nlowest runTime : ");
			    scanf("%d",&runTime);// 최소 상영시간을 입력받는다.  
			    
			    repFunc = mv_printRunTime; //모든 영화 정보 중 상영시간에 대해서만 따짐  
				arg = &runTime; //runTime은 int 형으로 받아야 하므로 &연산자를 써준다. 

				break;
				
			case 4: //print movies with high score
			    printf("\nlowest score : ");
			    scanf("%f",&score);
			    
			    repFunc = mv_printScore; // 모든 영화 정보 중 평점에 대해서만 따짐  
				arg = &score; //score는 float형으로 받아야 하므로 &연산자를 써준다.  
				
				break;
				
			case 5:
				printf("\n\nBye!\n\n");
				exit_flag = 1; // 빠져나감. 
				
				break;
				
			default:
				printf("wrong command! input again\n"); // 1~5 밖의 숫자 선택 시 다시 선택하도록 함. 
				break;
		}
		
		//list_repeatFunc(repFunc,arg,list); 
		cnt=list_repeatFunc(repFunc,arg,list); // list_repeatFunc은 각 리스트(각 영화)별로 반복하고 정보를 만족하는 영화만 거르는 것 이므로 cnt는 정보를 만족한 영화의 개수라고 할 수 있음. 
		printf("\n  -totally %d movies are listed!\n\n\n",cnt); // 정보와 일치하는 영화 개수(cnt)도 출력함. 
		//2.2 printing operation by function pointer (list_repeatFunc() is called here)
		//2.3 print number of movies
	}
	
	return 0;
}
