#include <Windows.h>

#include "..\sln\resource.h"

#include "sudoku.h"

static bool running = true;

static int EditIndicatorVector[9][9] = {
	{ ID_EDIT_M11, ID_EDIT_M12, ID_EDIT_M13, ID_EDIT_M14, ID_EDIT_M15, ID_EDIT_M16, ID_EDIT_M17, ID_EDIT_M18, ID_EDIT_M19 },
	{ ID_EDIT_M21, ID_EDIT_M22, ID_EDIT_M23, ID_EDIT_M24, ID_EDIT_M25, ID_EDIT_M26, ID_EDIT_M27, ID_EDIT_M28, ID_EDIT_M29 },
	{ ID_EDIT_M31, ID_EDIT_M32, ID_EDIT_M33, ID_EDIT_M34, ID_EDIT_M35, ID_EDIT_M36, ID_EDIT_M37, ID_EDIT_M38, ID_EDIT_M39 },

	{ ID_EDIT_M41, ID_EDIT_M42, ID_EDIT_M43, ID_EDIT_M44, ID_EDIT_M45, ID_EDIT_M46, ID_EDIT_M47, ID_EDIT_M48, ID_EDIT_M49 },
	{ ID_EDIT_M51, ID_EDIT_M52, ID_EDIT_M53, ID_EDIT_M54, ID_EDIT_M55, ID_EDIT_M56, ID_EDIT_M57, ID_EDIT_M58, ID_EDIT_M59 },
	{ ID_EDIT_M61, ID_EDIT_M62, ID_EDIT_M63, ID_EDIT_M64, ID_EDIT_M65, ID_EDIT_M66, ID_EDIT_M67, ID_EDIT_M68, ID_EDIT_M69 },

	{ ID_EDIT_M71, ID_EDIT_M72, ID_EDIT_M73, ID_EDIT_M74, ID_EDIT_M75, ID_EDIT_M76, ID_EDIT_M77, ID_EDIT_M78, ID_EDIT_M79 },
	{ ID_EDIT_M81, ID_EDIT_M82, ID_EDIT_M83, ID_EDIT_M84, ID_EDIT_M85, ID_EDIT_M86, ID_EDIT_M87, ID_EDIT_M88, ID_EDIT_M89 },
	{ ID_EDIT_M91, ID_EDIT_M92, ID_EDIT_M93, ID_EDIT_M94, ID_EDIT_M95, ID_EDIT_M96, ID_EDIT_M97, ID_EDIT_M98, ID_EDIT_M99 },
};

void SetEditsLimit(HWND hwndDlg)
{
	SendDlgItemMessage(hwndDlg, ID_EDIT_M11, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M12, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M13, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M14, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M15, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M16, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M17, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M18, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M19, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character

	SendDlgItemMessage(hwndDlg, ID_EDIT_M21, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M22, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M23, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M24, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M25, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M26, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M27, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M28, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M29, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character

	SendDlgItemMessage(hwndDlg, ID_EDIT_M31, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M32, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M33, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M34, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M35, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M36, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M37, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M38, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M39, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character

	SendDlgItemMessage(hwndDlg, ID_EDIT_M41, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M42, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M43, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M44, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M45, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M46, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M47, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M48, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M49, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character

	SendDlgItemMessage(hwndDlg, ID_EDIT_M51, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M52, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M53, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M54, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M55, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M56, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M57, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M58, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M59, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character

	SendDlgItemMessage(hwndDlg, ID_EDIT_M61, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M62, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M63, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M64, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M65, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M66, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M67, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M68, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M69, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character

	SendDlgItemMessage(hwndDlg, ID_EDIT_M71, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M72, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M73, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M74, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M75, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M76, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M77, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M78, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M79, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character

	SendDlgItemMessage(hwndDlg, ID_EDIT_M81, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M82, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M83, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M84, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M85, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M86, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M87, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M88, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M89, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character

	SendDlgItemMessage(hwndDlg, ID_EDIT_M91, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M92, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M93, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M94, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M95, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M96, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M97, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M98, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
	SendDlgItemMessage(hwndDlg, ID_EDIT_M99, EM_LIMITTEXT, (WPARAM)(1), (LPARAM)(0)); // NOTE(Daniel): limit text edit length to 1 character
}

int GetEditNum(int edit_indicator, HWND hwndDlg)
{
	LRESULT line_length = SendDlgItemMessage(hwndDlg, edit_indicator, EM_LINELENGTH, (WPARAM)(0), (LPARAM)(0));

	if (line_length == 0)
		return 0; // NOTE(Daniel): If the edit is empty, assume it is zero

	char c;
	LRESULT get_line = SendDlgItemMessage(hwndDlg, edit_indicator, EM_GETLINE, (WPARAM)(0), (LPARAM)(&c));
	if (get_line == 0)
		return -1;
	
	return atoi(&c);
}

bool SetEditNum(int edit_indicator, HWND hwndDlg, int i)
{
	if (i > 9 || i < 1)
		return false;
	
	char c[8];
	_itoa_s(i, c, 2, 10);
	if (SetDlgItemText(hwndDlg, edit_indicator, c) == 0)
	{
		// TODO(Daniel): error handling
	}
	
	return true;
}

bool GetEntireBoard(HWND hwndDlg)
{
	for (int x = 0; x < 9; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			board[x][y] = GetEditNum(EditIndicatorVector[x][y], hwndDlg);

			if (board[x][y] == -1)
				return false;
		}
	}

	return true;
}

bool SetEntireBoard(HWND hwndDlg)
{
	for (int x = 0; x < 9; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			SetEditNum(EditIndicatorVector[x][y], hwndDlg, board[x][y]);

			if (!SetEditNum(EditIndicatorVector[x][y], hwndDlg, board[x][y]))
				return false;
		}
	}

	return true;
}

// WARNING(Daniel): this will not work properly, and probably never will
void DebugDisplayBoard()
{
	char message[2048];
	wsprintf(message, " [%i], [%i], [%i], [%i], [%i], [%i], [%i], [%i], [%i] \n  [%i], [%i], [%i], [%i], [%i], [%i], [%i], [%i], [%i] \n  [%i], [%i], [%i], [%i], [%i], [%i], [%i], [%i], [%i] \n  [%i], [%i], [%i], [%i], [%i], [%i], [%i], [%i], [%i] \n  [%i], [%i], [%i], [%i], [%i], [%i], [%i], [%i], [%i] \n  [%i], [%i], [%i], [%i], [%i], [%i], [%i], [%i], [%i] \n",
		board[0][0], board[0][1], board[0][2], board[0][3], board[0][4], board[0][5], board[0][6], board[0][7], board[0][8],
		board[1][0], board[1][1], board[1][2], board[1][3], board[1][4], board[1][5], board[1][6], board[1][7], board[1][8],
		board[2][0], board[2][1], board[2][2], board[2][3], board[2][4], board[2][5], board[2][6], board[2][7], board[2][8],

		board[3][0], board[3][1], board[3][2], board[3][3], board[3][4], board[3][5], board[3][6], board[3][7], board[3][8],
		board[4][0], board[4][1], board[4][2], board[4][3], board[4][4], board[4][5], board[4][6], board[4][7], board[4][8],
		board[5][0], board[5][1], board[5][2], board[5][3], board[5][4], board[5][5], board[5][6], board[5][7], board[5][8],

		board[6][0], board[6][1], board[6][2], board[6][3], board[6][4], board[6][5], board[6][6], board[6][7], board[6][8],
		board[7][0], board[7][1], board[7][2], board[7][3], board[7][4], board[7][5], board[7][6], board[7][7], board[7][8],
		board[8][0], board[8][1], board[8][2], board[8][3], board[8][4], board[8][5], board[8][6], board[8][7], board[8][8]);

	MessageBox(0, message, "Board", 0);
}

INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		SetEditsLimit(hwndDlg);
		return TRUE;
	} break;
	
	case WM_COMMAND:
	{
		int control_code = HIWORD(wParam);
		int control_identifier = LOWORD(wParam);
		switch (control_identifier)
		{
			case ID_BTN_SOLVE:
			{
				GetEntireBoard(hwndDlg);

				RecursiveBacktrackDS rbds = { 0, 0, true, false };
				RecursiveBacktrackFill(&rbds);
				
				if (!CheckBoard())
				{
					MessageBox(0, "Board Not Ok!!!", "Message", 0);
				}
				else
				{
					MessageBox(0, "Board Ok!!!", "Message", 0);
				}
				
				SetEntireBoard(hwndDlg);

				SetFocus(hwndDlg);
			} break;
		}

		return TRUE;
	} break;

	case WM_QUIT:
	case WM_CLOSE:
	{
		running = false;
	} break;
	}

	return FALSE;
}

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND dialog = CreateDialog(hInstance, MAKEINTRESOURCE(ID_DIALOG_MAIN), 0, (DLGPROC)DialogProc);

	ShowWindow(dialog, SW_SHOW);

	while (running)
	{
		MSG msg;
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (!IsDialogMessage(dialog, &msg))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
	}

	// TODO(dShamir): should we do clean up and deleting of stuff?

	return 0;
}