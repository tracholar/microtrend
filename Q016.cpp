
#include<math.h>
#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4

extern void slide(int board[4][4], int direction);

double smooth(int board[4][4]){
	return 0;
}
double empty(int board[4][4]){
	return 0;
}
double mono(int board[4][4]){
	return 0;
}
double maxV(int board[4][4]){
	return 0;
}
double eval(int newBoard[4][4]){
	double smoothW = 0.1, mono2W = 1.,
			emptyW = 2.7, maxW = 1.;
	return mono(newBoard)*mono2W + empty(newBoard)*emptyW
			+ maxV(newBoard)*maxW + smooth(newBoard)*smoothW;
}

int move(int board[4][4]){
	double up,down,left,right;
	board[0][0] = 2048;
	return UP;
}