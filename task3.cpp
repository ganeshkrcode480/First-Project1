// Program for Sudoku Solver using C++ programming language.

#include <iostream>
using namespace std;

#define UNASSIGNED 0
#define N 9

// Function to check if it's safe to place a number in a specific cell
bool isSafe(int grid[N][N], int row, int col, int num) 
{
    // Check if the number is not in the current row and column
    for (int x = 0; x < N; x++) 
    {
        if (grid[row][x] == num || grid[x][col] == num) 
        {
            return false;
        }
    }

    // Check if the number is not in the current 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if (grid[i + startRow][j + startCol] == num) 
            {
                return false;
            }
        }
    }

    return true;
}

// Function to find an unassigned location in the grid
bool findUnassignedLocation(int grid[N][N], int &row, int &col) 
{
    for (row = 0; row < N; row++) 
    {
        for (col = 0; col < N; col++) 
        {
            if (grid[row][col] == UNASSIGNED) 
            {
                return true;
            }
        }
    }
    return false;
}

// Function to solve the Sudoku using backtracking
bool solveSudoku(int grid[N][N]) 
{
    int row, col;

    // If there is no unassigned location, we are done
    if (!findUnassignedLocation(grid, row, col)) 
    {
        return true;
    }

    // Consider digits 1 to 9
    for (int num = 1; num <= 9; num++) 
    {
        // If the number is safe to place, assign it
        if (isSafe(grid, row, col, num)) 
        {
            grid[row][col] = num;

            // Recursively try to solve the rest of the grid
            if (solveSudoku(grid)) 
            {
                return true;
            }

            // If it doesn't lead to a solution, unassign and backtrack
            grid[row][col] = UNASSIGNED;
        }
    }

    // Trigger backtracking
    return false;
}

// Function to print the Sudoku grid
void printGrid(int grid[N][N]) 
{
    for (int row = 0; row < N; row++) 
    {
        for (int col = 0; col < N; col++) 
        {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

int main() 
{
    // Example Sudoku puzzle
    int grid[N][N] = 
    {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudoku(grid)) 
    {
        printGrid(grid);
    }
     else 
    {
        cout << "No solution exists" << endl;
    }

    return 0;
}