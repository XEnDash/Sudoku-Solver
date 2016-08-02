#pragma once

extern int board[9][9];

#define PROBABLY_IMPOSSIBLE_MAGIC_NUM 99499999
extern int check_if_impossible;

extern bool rejected_nums[9][9][9];
extern bool do_not_change[9][9];

typedef struct
{
	//BacktrackStackFrame bt_stack[256];
	//int bt_size = 0;

	int x;
	int y;
	bool moving_forwards;
	bool brk;
	bool impossible;
} RecursiveBacktrackDS;

/*bool IsOnlyNumberOnRow(int n, int x, int y);
bool IsOnlyNumberOnColumn(int n, int x, int y);
bool IsOnlyNumberOnSub(int n, int x, int y);
void ClearAllRejectedInSlot(int x, int y);
bool MoveToNextSlot(RecursiveBacktrackDS *data);
bool MoveToPrevSlot(RecursiveBacktrackDS *data);*/
void RecursiveBacktrackFill(RecursiveBacktrackDS *data);
bool CheckBoard();