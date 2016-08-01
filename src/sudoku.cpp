#include "sudoku.h"

int board[9][9] = { 0 };
int check_if_impossible = 0;

#define REJECTED_ALL { 0, 0, 0, 0, 0, 0, 0, 0, 0 }
#define REJECTED_ALL_ROW { REJECTED_ALL, REJECTED_ALL, REJECTED_ALL, REJECTED_ALL, REJECTED_ALL, REJECTED_ALL, REJECTED_ALL, REJECTED_ALL, REJECTED_ALL }

bool rejected_nums[9][9][9] =
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
bool do_not_change[9][9] =
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

bool IsOnlyNumberOnRow(int n, int x, int y)
{
	for (int x0 = 0; x0 < 9; x0++)
	{
		if (x0 == x)
			continue;

		if (board[x0][y] == n)
			return false;
	}

	return true;
}

bool IsOnlyNumberOnColumn(int n, int x, int y)
{
	for (int y0 = 0; y0 < 9; y0++)
	{
		if (y0 == y)
			continue;

		if (board[x][y0] == n)
			return false;
	}

	return true;
}

bool IsOnlyNumberOnSub(int n, int x, int y)
{
	int tx = x / 3;
	int ty = y / 3;

	for (int x0 = tx * 3; x0 < tx * 3 + 3; x0++)
	{
		for (int y0 = ty * 3; y0 < ty * 3 + 3; y0++)
		{
			if (x0 == x && y0 == y)
				continue;

			if (board[x0][y0] == n)
				return false;
		}
	}

	return true;
}


void ClearAllRejectedInSlot(int x, int y)
{
	for (int n = 0; n < 9; n++)
	{
		rejected_nums[x][y][n] = false;
	}
}

bool MoveToNextSlot(RecursiveBacktrackDS *data)
{
	data->moving_forwards = true;

	if (data->y > 8)
		return false;

	data->x += 1;
	if (data->x > 8)
	{
		data->x = 0;
		data->y += 1;

#ifdef SUDOKU_DEBUG
		PrintBoard();
#endif

		if (data->y > 8)
		{
			return false;
			data->brk = true;
		}
	}

	return true;
}

bool MoveToPrevSlot(RecursiveBacktrackDS *data)
{
	data->moving_forwards = false;

	if (data->y < 0)
		return false;

	data->x--;
	if (data->x < 0)
	{
		data->x = 8;
		data->y--;
		if (data->y < 0)
		{
			return false;
			data->brk = true;
		}
	}

	return true;
}

void RecursiveBacktrackFill(RecursiveBacktrackDS *data)
{
	check_if_impossible++;
	if (check_if_impossible >= PROBABLY_IMPOSSIBLE_MAGIC_NUM)
	{
		data->impossible = true;
	}

	if (data->impossible)
		return;

	if (data->brk)
		return;

	if (do_not_change[data->x][data->y])
	{
		if (data->moving_forwards)
		{
			if (!MoveToNextSlot(data))
				return;
		}
		else
		{
			if (!MoveToPrevSlot(data))
				return;
		}

		RecursiveBacktrackFill(data);
		return;
	}

	bool found_match = false;

	for (int n = 1; n <= 9; n++)
	{
		if (rejected_nums[data->x][data->y][n - 1])
			continue;

		if (IsOnlyNumberOnRow(n, data->x, data->y) &&
			IsOnlyNumberOnColumn(n, data->x, data->y) &&
			IsOnlyNumberOnSub(n, data->x, data->y))
		{
			board[data->x][data->y] = n;
			found_match = true;
			break;
		}
		else
		{
			rejected_nums[data->x][data->y][n - 1] = true;
		}
	}

	if (!found_match)
	{
		ClearAllRejectedInSlot(data->x, data->y);

		if (!MoveToPrevSlot(data))
			return;

		while (do_not_change[data->x][data->y])
		{
			if (!MoveToPrevSlot(data))
				return;
		}

		int n = board[data->x][data->y];
		board[data->x][data->y] = 0;

		rejected_nums[data->x][data->y][n - 1] = true;

		RecursiveBacktrackFill(data);
	}

	if (!MoveToNextSlot(data))
		return;

	RecursiveBacktrackFill(data);
}

bool CheckBoard()
{
	bool board_ok = true;

	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			int n = board[x][y];

			if (IsOnlyNumberOnRow(n, x, y) &&
				IsOnlyNumberOnColumn(n, x, y) &&
				IsOnlyNumberOnSub(n, x, y) &&
				n != 0)
			{
			}
			else
			{
				board_ok = false;
			}
		}
	}

	return board_ok;
}