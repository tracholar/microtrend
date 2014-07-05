#include <stdio.h>
#include <stdlib.h>

#define MAX_ROUNDS 1000000
#define THE_GOAL   2048

extern int move(int board[4][4]);

static void die(const char* msg)
{
  printf("ERROR: %s\n", msg);
  exit(1);
}

static int won(int board[4][4])
{
  int row, col;
  for (row = 0; row < 4; ++row) {
    for (col = 0; col < 4; ++col) {
      if (board[row][col] >= THE_GOAL) {
        return 1;
      }
    }
  }
  return 0;
}

static int next(int board[4][4])
{
  static unsigned long round = 0;
  ++round;
  int empty = 0;
  int row, col;
  for (row = 0; row < 4; ++row) {
    for (col = 0; col < 4; ++col) {
      if (board[row][col] == 0) {
        ++empty;
      }
    }
  }
  if (empty > 0) {
    int tile = 2 * (round % 2 + 1);
    int skip = tile % empty;
    for (row = 0; row < 4; ++row) {
      for (col = 0; col < 4; ++col) {
        if (board[row][col] == 0) {
          --skip;
          if (skip <= 0) {
            board[row][col] = tile;
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

static void slide(int board[4][4], int direction)
{
  int row, col, pos;
  if (0) {
  } else if (direction == 1) { // LEFT
    for (row = 0; row < 4; ++row) {
      int fix = 0;
      for (col = 1; col < 4; ++col) {
        if (board[row][col] != 0) {
          int now = col;
          for (pos = col - 1; pos >= fix; --pos) {
            if (board[row][pos] == 0) {
              board[row][pos] = board[row][now];
              board[row][now] = 0;
              --now;
            }
            else if (board[row][pos] == board[row][now]) {
              board[row][pos] += board[row][now];
              board[row][now] = 0;
              fix = now;
            }
            else {
              fix = now;
              break;
            }
          }
        }
      }
    }
  } else if (direction == 2) { // RIGHT
    for (row = 0; row < 4; ++row) {
      int fix = 3;
      for (col = 2; col >= 0; --col) {
        if (board[row][col] != 0) {
          int now = col;
          for (pos = col + 1; pos <= fix; ++pos) {
            if (board[row][pos] == 0) {
              board[row][pos] = board[row][now];
              board[row][now] = 0;
              ++now;
            }
            else if (board[row][pos] == board[row][now]) {
              board[row][pos] += board[row][now];
              board[row][now] = 0;
              fix = now;
            }
            else {
              fix = now;
              break;
            }
          }
        }
      }
    }
  } else if (direction == 3) { // UP
    for (col = 0; col < 4; ++col) {
      int fix = 0;
      for (row = 1; row < 4; ++row) {
        if (board[row][col] != 0) {
          int now = row;
          for (pos = row - 1; pos >= fix; --pos) {
            if (board[pos][col] == 0) {
              board[pos][col] = board[now][col];
              board[now][col] = 0;
              --now;
            }
            else if (board[pos][col] == board[now][col]) {
              board[pos][col] += board[now][col];
              board[now][col] = 0;
              fix = now;
            }
            else {
              fix = now;
              break;
            }
          }
        }
      }
    }
  } else if (direction == 4) { // DOWN
    for (col = 0; col < 4; ++col) {
      int fix = 3;
      for (row = 2; row >= 0; --row) {
        if (board[row][col] != 0) {
          int now = row;
          for (pos = row + 1; pos <= fix; ++pos) {
            if (board[pos][col] == 0) {
              board[pos][col] = board[now][col];
              board[now][col] = 0;
              ++now;
            }
            else if (board[pos][col] == board[now][col]) {
              board[pos][col] += board[now][col];
              board[now][col] = 0;
              fix = now;
            }
            else {
              fix = now;
              break;
            }
          }
        }
      }
    }
  } else {
    die("Bad direction.");
  }
}

int main()
{
  int board[4][4] = {
    { 0, 0, 2, 0 },
    { 0, 0, 2, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
  };

  int round = 1;
  for (; round <= MAX_ROUNDS; ++round) {
    int direction = move(board);
    slide(board, direction);
    if (won(board)) {
      printf("You Win! [MAGIC STRING]\n");
      exit(0);
    }
    if (next(board) == 0) {
      break; // for(round)
    }
  }
  printf("You Loss!\n");
  return 0;
}

