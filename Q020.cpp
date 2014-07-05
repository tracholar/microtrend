#include<stdio.h>
#include<stdlib.h>

#define min(x,y) (x>y? y:x)
#define max(x,y) (x>y? x:y)

static 	int enx[10],eny[10],ex[10],ey[10];
static 	char end[10],ed[10];
static int used = 1;
static int A[10][10];  // 1:L 2:R
static int count = 0;
static int datac = 0;

#define L 1
#define R 2
#define N 0


void printMirror(){
	char * shape = " \\/";
	int i,j;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			printf("%c ", shape[A[i][j]]);
		}
		putchar('\n');
	}	
}

int preScan(){

	while(feof(stdin)){
		fscanf(stdin,"%d %d %c %d %d %c",&enx[datac],&eny[datac],&end[datac],&ex[datac],&ey[datac],&ed[datac]);
		
		if((end[datac]=='n' && ed[datac]=='e') || (end[datac]=='s' && ed[datac]=='w')){
			A[ex[datac]][eny[datac]] = L;
			count++;
		}else if((end[datac]=='e' && ed[datac]=='n') || (end[datac]=='w' && ed[datac]=='s')){
			A[enx[datac]][ey[datac]] = L;
			count++;
		}else if((end[datac]=='w' && ed[datac]=='n') || (end[datac]=='e' && ed[datac]=='s')){
			A[enx[datac]][ey[datac]] = R;
			count++;
		}else if((end[datac]=='s' && ed[datac]=='e') || (end[datac]=='n' && ed[datac]=='w')){
			A[ex[datac]][eny[datac]] = R;
			count++;
		}
	}
	printf("read data ready!\n");
	
}

bool testPlaceMirror(int x1,int y1,int d1,int x2, int y2, int d2, int & mirron){

	if(x1==x2){
		for(int y=min(y1,y2)+1;y<max(y1,y2);y++){
			if(A[x1][y]!=0)
				return false;
		}
	}
	if(y1==y2){
		for(int x=min(x1,x2)+1;x<max(x1,x2);x++){
			if(A[x][y1]!=0)
				return false;
		}
	}
	if((A[x1][y1]!=0) && (A[x2][y2]!=0)){
		mirron += 2;
		return true;
	}
	else if(((A[x1][y1]==d1) && (A[x2][y2]==0)) || ((A[x1][y1]==0) && (A[x2][y2]==d2))){
		mirron += 1;
		return true;
	}
	else if( (A[x1][y1]==d1) && (A[x2][y2]==d2) ){
		return true;
	}
	
	return false;
}

bool testMirror(int datai, int mirrorn){
	if(mirrorn>5 || datai>=datac)
		return false;
	
	if(end[datai]=='e' && end[datai]=='w'){
		int x = 0;
		while(!testPlaceMirror(x,eny[datai],L,x,ey[datai],R,mirrorn)){
			if(x==9){
				return false;
			}
			
			x++;
		}
		
		return testMirror(datai+1,mirrorn);
	}
	else if(end[datai]=='w' && end[datai]=='e'){
		int x = 9;
		while(!testPlaceMirror(x,eny[datai],R,x,ey[datai],L,mirrorn)){
			if(x==0){
				return false;
			}
			x--;
		}
		
		return testMirror(datai+1,mirrorn);
	}
	else if(end[datai]=='s' && end[datai]=='n'){
		int y = 0;
		while(!testPlaceMirror(enx[datai],y,L,ex[datai],y,R,mirrorn)){
			if(y==9){
				return false;
			}
			y++;
		}
		
		return testMirror(datai+1,mirrorn);
	}
	else if(end[datai]=='n' && end[datai]=='s'){
		int y = 9;
		while(!testPlaceMirror(enx[datai],y,R,ex[datai],y,L,mirrorn)){
			if(y==0){
				return false;
			}
			y--;
		}
		
		return testMirror(datai+1,mirrorn);
	}
}

int main(){
	int i,j;
	char * shape = " \\/";
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			A[i][j] = N;
		}
	}
	
	preScan();
	testMirror(0,count);
	printMirror();
}








