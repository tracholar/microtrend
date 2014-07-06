#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>

using namespace std;
#define MAXLEN 10240
#define MAXWORD 1024
#define WORDMAXLEN 64

int mapLen = 0;
typedef struct{
	char key[WORDMAXLEN];
	int val;
}Node, *Map;

int mapFind(Map map, char * key){
	for(int i=0;i<MAXLEN;i++){
		if(strcmp(map[i].key,key)==0)
			return map[i].val;
		if(map[i].key[0] == 0)
			return 0;
	}
	return 0;
}

void mapInsert(Map map, char * key, int val){
	strcpy(map[mapLen].key , key);
	map[mapLen].val = val;
	mapLen++;
}
void mapInc(Map map, char *key){
	for(int i=0;i<MAXLEN;i++){
		if(strcmp(map[i].key,key)==0){
			map[i].val += 1;
			
		}
		if(map[i].key[0] == 0)
			return;
	}
}

void mapSet(Map map, char * key, int val){
	for(int i=0;i<MAXLEN;i++){
		if(strcmp(map[i].key,key)==0)
			map[i].val = val;
		
		if(map[i].key[0] == 0)
			return;
	}
}

void parse(char * s, Map map){
	int i, wordN = 0;
	char word[64];
	for(i=0;i<strlen(s);i++){
		// printf("%c",s[i]);
		if(s[i] == ' ' || s[i] == ',' || s[i] == '.' || s[i] == '"'){
			if(wordN!=0){
				word[wordN] = '\0';
				if(mapFind(map,word)!=0)
					mapInc(map, word);
				else
					mapInsert(map, word, 1);
			}
			wordN = 0;
		}else{
			word[wordN++] = s[i];
		}
	}
}

void print(Map map){
	for(int i=0;i<MAXLEN;i++){
		if(map[i].key==0)
			return;
		printf("%s\t%d\n",map[i].key,map[i].val);
	}

}

int istrendmicro(Map map){
	char * keep[] = {"Trend","Micro","Steve", "Jenny","1988","1984",
				"United","Asia"};
	int sum = 0;
	for(int i=0;i<8; i++){
		sum += mapFind(map, keep[i]);
	}
	//cout<<sum<<endl;
	return sum>5;
}



int main(){
	char news[MAXLEN];

	Map map = new Node[MAXWORD];
	while(NULL != fgets(news,MAXLEN, stdin)){
		
		memset(map,0,MAXWORD*sizeof(Node));
		mapLen = 0;

		parse(news, map);
		//print(map);
		printf("%d\n",istrendmicro(map));
		
	}

}
