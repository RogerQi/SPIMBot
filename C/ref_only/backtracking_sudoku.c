// A Backtracking program in C++ to solve Sudoku problem 
#include <stdio.h> 
#include <stdbool.h>

// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED '*'

// N is used for the size of Sudoku grid. Size will be NxN 
#define N 16

// This function finds an entry in grid that is still unassigned 
bool FindUnassignedLocation(char grid[N][N], int row, int col); 

// Checks whether it will be legal to assign num to the given row, col 
bool isSafe(char grid[N][N], int row, int col, char num); 

char sixteen[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
/* Takes a partially filled-in grid and attempts to assign values to 
all unassigned locations in such a way to meet the requirements 
for Sudoku solution (non-duplication across rows, columns, and boxes) */
bool SolveSudoku(char grid[N][N]) 
{ 
	int row, col; 

	// If there is no unassigned location, we are done 
	if (!FindUnassignedLocation(grid, row, col)) 
	return true; // success! 

	// consider digits 1 to 9 
	for (int num = 0; num < 16; num++) 
	{ 
		// if looks promising 
		if (isSafe(grid, row, col, sixteen[num])) 
		{ 
			// make tentative assignment 
			grid[row][col] = sixteen[num]; 

			// return, if success, yay! 
			if (SolveSudoku(grid)) 
				return true; 

			// failure, unmake & try again 
			grid[row][col] = UNASSIGNED; 
		} 
	} 
	return false; // this triggers backtracking 
} 

/* Searches the grid to find an entry that is still unassigned. If 
found, the reference parameters row, col will be set the location 
that is unassigned, and true is returned. If no unassigned entries 
remain, false is returned. */
bool FindUnassignedLocation(char grid[N][N], int row, int col) 
{ 
	for (row = 0; row < N; row++) 
		for (col = 0; col < N; col++) 
			if (grid[row][col] == UNASSIGNED) 
				return true; 
	return false; 
} 

/* Returns a boolean which indicates whether an assigned entry 
in the specified row matches the given number. */
bool UsedInRow(char grid[N][N], int row, char num) 
{ 
	for (int col = 0; col < N; col++) 
		if (grid[row][col] == num) 
			return true; 
	return false; 
} 

/* Returns a boolean which indicates whether an assigned entry 
in the specified column matches the given number. */
bool UsedInCol(char grid[N][N], int col, char num) 
{ 
	for (int row = 0; row < N; row++) 
		if (grid[row][col] == num) 
			return true; 
	return false; 
} 

/* Returns a boolean which indicates whether an assigned entry 
within the specified 3x3 box matches the given number. */
bool UsedInBox(char grid[N][N], int boxStartRow, int boxStartCol, char num) 
{ 
	for (int row = 0; row < 4; row++) 
		for (int col = 0; col < 4; col++) 
			if (grid[row+boxStartRow][col+boxStartCol] == num) 
				return true; 
	return false; 
} 

/* Returns a boolean which indicates whether it will be legal to assign 
num to the given row,col location. */
bool isSafe(char grid[N][N], int row, int col, char num) 
{ 
	/* Check if 'num' is not already placed in current row, 
	current column and current 3x3 box */
	return !UsedInRow(grid, row, num) && 
		!UsedInCol(grid, col, num) && 
		!UsedInBox(grid, row - row%4 , col - col%4, num)&& 
			grid[row][col]==UNASSIGNED; 
} 

/* A utility function to print grid */
void printGrid(char grid[N][N]) 
{ 
	for (int row = 0; row < N; row++) 
	{ 
	for (int col = 0; col < N; col++) 
			printf("%2d", grid[row][col]); 
		printf("\n"); 
	} 
} 

/* Driver Program to test above functions */
int main() 
{ 
	// 0 means unassigned cells 
	// char grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0}, 
	// 				{5, 2, 0, 0, 0, 0, 0, 0, 0}, 
	// 				{0, 8, 7, 0, 0, 0, 0, 3, 1}, 
	// 				{0, 0, 3, 0, 1, 0, 0, 8, 0}, 
	// 				{9, 0, 0, 8, 6, 3, 0, 0, 5}, 
	// 				{0, 5, 0, 0, 9, 0, 6, 0, 0}, 
	// 				{1, 3, 0, 0, 0, 0, 2, 5, 0}, 
	// 				{0, 0, 0, 0, 0, 0, 0, 7, 4}, 
	// 				{0, 0, 5, 2, 0, 6, 3, 0, 0}}; 
    char grid[N][N] = {"*1CB**8**F**DGE*",
                        "*F**C******3**2*",
                        "3***5*29G8*7***A",
                        "E2*9********4*7F",
                        "C**F**D543**B**8",
                        "**2*E*43CB*1*6**",
                        "B*136******DF4*E",
                        "*E4**8F**69**DC*",
                        "*7F**4B**GC**A3*",
                        "1*BE3******4G2*C",
                        "**3*A*9EB2*F*5**",
                        "8**5**C67D**E**4",
                        "9B*2********5*1D",
                        "6***1*E495*B***3",
                        "*5**7******8**6*",
                        "*371**5**C**8E4*"};
	if (SolveSudoku(grid) == true) 
		printGrid(grid); 
	else
		printf("No solution exists"); 

	return 0; 
} 
