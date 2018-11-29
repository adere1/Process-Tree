#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

pid_t pid,ppid;

int calculatetree(char argv[0],int height,int child,int saved_height);	

 
int main(int argc , char *argv[] )
{ 
	int height,child,saved_height=0;
	
	if(argv[1] != NULL){
		height = atoi(argv[1]);
	}else{
		printf("\nInvalid Height..!");
	}

	if(argv[2] != NULL){
		child = atoi(argv[2]);
	}else{
	      printf("\nInvalid Number of Children..!");
	}

	if(argv[3] != NULL){
		saved_height = atoi(argv[3]);
	}else {
		saved_height = height;
	}
        
	int no_tabs = saved_height - height;
	int k = 0;						
	printf("\n");						
	for(k=0;k<abs(no_tabs);k++){
	        printf("  ");
	}
	
	printf("(%d): Process starting",getpid());
	printf("\n");
	for(k=0;k<abs(no_tabs);k++){
	        printf("  ");
	}
								
	printf("(%d): Parent's id = (%d)",getpid(),getppid());
	printf("\n");
	for(k=0;k<abs(no_tabs);k++){
	        printf("  ");
	}
						
	printf("(%d): Height in the tree = (%d)",getpid(),height);
	printf("\n");
	for(k=0;k<abs(no_tabs);k++){
	        printf("  ");
	}
	if(height-1 >0){
	   	printf("(%d): Creating (%d) children at height (%d)\n", getpid(),child,height-1);
	}				   
			   
        sleep(2);	
	int r = calculatetree(argv[0],height,child,saved_height);	
	sleep(3);		
	printf("\n(%d): Terminating at height (%d)\n",getpid(),r);	
	return 0;	 
}

int  calculatetree(char a[], int h, int c, int actual_height ){
	int i = 0;	
        int status;
	int saved_height = actual_height;
	
	if(h > 1 ){
		for(i=0;i<c;i++){
			
	 		if ((pid = fork()) < 0) { 
				fprintf(stderr, "fork failed\n"); 
				exit(1); 
			}

			if(pid == 0) {
			   char h1[10], c1[20], s1[20];			   
			   h = h-1;						
    			   snprintf(h1, sizeof(h1), "%d", h);
    			   snprintf(c1, sizeof(c1), "%d", c);
			   snprintf(s1, sizeof(c1), "%d", saved_height);
                           if(execlp(a,a, h1 ,c1, s1,NULL) == -1)						
			          fprintf(stderr, "execl failed\n");
			}
			
		}
		for(i=0;i<c;i++){
		     wait(&status);		
	       	}
	}
		 
 return h;
}
