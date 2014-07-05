#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define JENNY -1
#define EVA -2
#define STEVE -3
#define MAXLEN 20000000

int Jenny=0, Eva=0, Steve=0, Invalid=0;
int * delegater;
int maxId = 0;

void statistic(){
	int i,final,j;
	int * visited = (int *)malloc(sizeof(int)*MAXLEN);
	int visitedN = 0;
	for(i=1;i<=maxId;i++){
		if(delegater[i]==0){
			continue;
		}
		
		final = delegater[i];
		visitedN = 0;
		while(final>0){
			visited[visitedN++] = final;
			final = delegater[final];
			for(j=0;j<visitedN;j++){
				if(final == visited[j])
					final = 0;
			}

		}
		if(final==0)
			Invalid++;
		
		
		switch(final){
				case JENNY:
					Jenny++;
					break;
				case STEVE:
					Steve++;
					break;
				case EVA:
					Eva++;
					break;
		
		}
	}

}

int main() {
	int vid,delegatedVid;
	char name[10];
	delegater = (int *)malloc(sizeof(int)*MAXLEN);
	memset(delegater,0,sizeof(int)*MAXLEN);

	while(EOF != scanf("%d %s",&vid, name)){
		if(vid>maxId){
			maxId = vid;
		}
		if(strcmp(name,"Jenny")==0){
			delegater[vid] = JENNY;
		}
		else if(strcmp(name,"Eva")==0){
			delegater[vid] = EVA;
		}
		else if(strcmp(name,"Steve")==0){
			delegater[vid] = STEVE;
		}
		else{
			sscanf(name,"%d",&delegatedVid);
			delegater[vid] = delegatedVid;
		}
	}

	statistic();
	printf("Steve %d\nJenny %d\nEva %d\nInvalid %d\n",Steve,Jenny,Eva,Invalid);

}