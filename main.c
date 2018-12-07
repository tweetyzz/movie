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
	
	fp=fopen("movie.dat.dat","r");
	//1.1 FILE open
	
	
	//1.2 list generation (use function list_genList() )
	list = list_genList();
	
	//1.3 read each movie data from the file and add it to the linked list
	while (EOF != fscanf(fp,"%s%s%d%f",name,country,&runTime,&score)/*수정한것 /* read name, country, runtime and score*/ )
	{	
	   void* mvInfo= mv_genMvInfo(name,score,runTime,country);
	   //printMv(mvInfo);
	   list_addTail(mvInfo, list);
	   
	   //깃허브 10장 문자열 하나씩 읽어오는 거 참고./ 
	    //movInfo_t();
	    //mv_genMvInfo()
	    //구조체 만들기 movinfo이용, 와플 찍는곳 
	    //mv_genMvInfo()
	    //printf("%s",mv_genMvInfo);//새로 쓴거  

	//generate a movie info instance(mvInfo) with function mv_genMvInfo()
		
	}
    
    fclose(fp);
	//1.4 FILE close
	
	//2. program start
	while(exit_flag == 0)
   {    
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
				arg = NULL;
			
				break;
				
			case 2: //print movies of specific country
			    printf("\nselect a country : ");
			    scanf("%s",&country);
			    
			    repFunc = mv_printScore;
				arg = country; 
			    
				break;
				
			case 3: //print movies with long runtime
			    printf("\nlowest runTime : ");
			    scanf("%d",&runTime);
			    
			    repFunc = mv_printRunTime;
				arg = &runTime;

				break;
				
			case 4: //print movies with high score
			    printf("\nlowest score : ");
			    scanf("%f",&score);
			    
			    repFunc = mv_printCountry;
				arg = &score;
				
				break;
				
			case 5:
				printf("\n\nBye!\n\n");
				exit_flag = 1;
				
				break;
				
			default:
				printf("wrong command! input again\n");
				break;
		}
		
		//list_repeatFunc(repFunc,arg,list); 
		cnt=list_repeatFunc(repFunc,arg,list);
		printf("\n  -totally %d movies are listed!\n\n\n",cnt);
		//2.2 printing operation by function pointer (list_repeatFunc() is called here)
		//2.3 print number of movies
	}
	
	return 0;
}
