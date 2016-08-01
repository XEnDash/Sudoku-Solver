#pragma once

extern int board[9][9];

#define REJECTED_ALL { 0, 0, 0, 0, 0, 0, 0, 0, 0 }
#define REJECTED_ALL_ROW { REJECTED_ALL, REJECTED_ALL, REJECTED_ALL, REJECTED_ALL, REJECTED_ALL, REJECTED_ALL, REJECTED_ALL, REJECTED_ALL, REJECTED_ALL }

static bool rejected_nums[9][9][9] =
{
	REJECTED_ALL_ROW,
	REJECTED_ALL_ROW,
	REJECTED_ALL_ROW,
	REJECTED_ALL_ROW,
	REJECTED_ALL_ROW,
	REJECTED_ALL_ROW,
	REJECTED_ALL_ROW,
	REJECTED_ALL_ROW,
	REJECTED_ALL_ROW,
};

#define DO_NOT_CHANGE_ROW { 0, 0, 0, 0, 0, 0, 0, 0, 0 }
static bool do_not_change[9][9] =
{
	DO_NOT_CHANGE_ROW,
	DO_NOT_CHANGE_ROW,
	DO_NOT_CHANGE_ROW,
	DO_NOT_CHANGE_ROW,
	DO_NOT_CHANGE_ROW,
	DO_NOT_CHANGE_ROW,
	DO_NOT_CHANGE_ROW,
	DO_NOT_CHANGE_ROW,
	DO_NOT_CHANGE_ROW
};

typedef struct
{
	//BacktrackStackFrame bt_stack[256];
	//int bt_size = 0;

	int x;
	int y;
	bool moving_forwards;
	bool brk;
} RecursiveBacktrackDS;

/*bool IsOnlyNumberOnRow(int n, int x, int y);
bool IsOnlyNumberOnColumn(int n, int x, int y);
bool IsOnlyNumberOnSub(int n, int x, int y);
void ClearAllRejectedInSlot(int x, int y);
bool MoveToNextSlot(RecursiveBacktrackDS *data);
bool MoveToPrevSlot(RecursiveBacktrackDS *data);*/
void RecursiveBacktrackFill(RecursiveBacktrackDS *data);
bool CheckBoard();