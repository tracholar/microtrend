#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NIL -1

int * talent, * parent , * sel;
int N;

typedef struct{
	int norootV, withrootV;
}MAXV;

bool isLeaf(int r){
	int i;
	for(i=0;i<N;i++){
		if(parent[i] == r)
			return false;
	}
	return true;
}

void findLeaf(int r, int * leaf, int & n){
	int i;
	n = 0;
	for(i=0;i<N;i++){
		if(parent[i] == r){
			leaf[n] = i;
			n++;
		}
	}
}

MAXV findMaxValue(int r){
	MAXV v, * leafV;
	int leaf[128], i;
	int leafN = 0;
	if(isLeaf(r)){
		v.norootV = 0;
		v.withrootV = talent[r];
		return v;
	}

	findLeaf(r,leaf,leafN);

	//leafV = (MAXV *)malloc(sizeof(MAXV)*leafN);
	//memset(leafV,0,sizeof(MAXV)*leafN);

	
	// 孩子节点没有被包含
	int norootV = talent[r], withrootV = 0;

	for(i=0;i<leafN;i++){
		v = findMaxValue(leaf[i]);
		//leafV[i].norootV = v.norootV;
		//leafV[i].withrootV = v.withrootV;
		norootV += v.norootV;
		withrootV += v.withrootV;
	}

	int leafs[100], n, j;
	if(norootV < withrootV){
		for(i=0;i<leafN;i++){
			if(talent[leaf[i]]!=0){
				sel[leaf[i]] = 1;
			}
			findLeaf(leaf[i],leafs,n);
			for(j=0;j<n;j++){
				sel[leafs[j]] = 0;
			}
		}
		v.norootV = withrootV;

	}else if(withrootV < norootV - talent[r]){
		v.norootV = norootV - talent[r];
	}else{
		v.norootV = withrootV;
		/*for(i=0;i<leafN;i++){
			sel[leaf[i]] = 1;
		}*/
	}
	

	

	v.withrootV = norootV;

	


	return v;
}

int main(){
	int  v, i, p;
	scanf("%d %d",&N, &v);
	talent = (int *) malloc(sizeof(int)*N);
	memset(talent,0,sizeof(int)*N);
	parent = (int *) malloc(sizeof(int)*N);
	memset(parent,0,sizeof(int)*N);

	sel = (int *) malloc(sizeof(int)*N);
	memset(sel,0,sizeof(int)*N);

	talent[0] = v;
	parent[0] = NIL;
	for(i=1;i<N;i++){
		scanf("%d %d", &parent[i], &talent[i]);
	}

	MAXV val = findMaxValue(0);
	int maxv = 0 , leafs[100], n;
	int j = 0;


	if(val.norootV < val.withrootV){
		sel[0] = 1;
		maxv = val.withrootV;

		
		findLeaf(0,leafs,n);
		for(j=0;j<n;j++){
			sel[leafs[j]] = 0;
		}
	}else{
		maxv = val.norootV;
	}
	printf("%d\n",maxv);
	
	j = 0;
	for(i=0;i<N;i++){
		
		if(sel[i]==1){
			if(j++!=0){
				printf(" ");
			}
			printf("%d",i);
		}
	}
	printf("\n");
}
