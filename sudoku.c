#include <stdio.h>
#include <time.h>

const short shift[10] = {0, 1, 2, 4, 8, 16, 32, 64, 128, 256};
int calls = 0;

typedef struct {
    // This represents the 9x9 Sudoku grid. Char values range from 0 to 9. An empty cell is represented by 0.
    unsigned char grid[9][9];
    // This short represents the values that have been used in a given row. Only bitwise operations are applied to this variable.
    unsigned short row[9]; 
    // This short represents the values that have been used in a given column. Only bitwise operations are applied to this variable.
    unsigned short col[9]; 
    // This short represents the values that have been used in a given box (or square). Only bitwise operations are applied to this variable.
    unsigned short box[9]; 
    // This char represents the position of the last filled cell. The first 4 and last 4 bits represent the row and column of the last filled cell respectively.
    unsigned char pos; 
} Sudoku;

Sudoku init(char puzzle[9][9]) {
    // Initializes the Sudoku struct given a puzzle as represented by a 2D array of chars.
    Sudoku mySud = {.row = {0}, .col = {0}, .box = {0}};
    char r, c;
    char val;
    short one;
    for (r = 0; r < 9; r++) {
        for (c = 0; c < 9; c++) {
            // This block is also used in the solve function. The explanation is there too.
            val = puzzle[r][c];
            one = shift[val];
            mySud.grid[r][c] = val;
            mySud.row[r] |= one;
            mySud.col[c] |= one;
            mySud.box[(c/3) + 3*(r/3)] |= one;
        }
    }
    mySud.pos = 0;
    return mySud;
}

void print(Sudoku myPuzzle) {
    // Prints the sudoku.
    char r,c;
    for (r = 0; r < 9; r++) {
        for (c = 0; c < 9; c++) {
            printf("%d  ", myPuzzle.grid[r][c]);
        }
        printf("\n\n");
    }
    printf("\n");
}

int main(void) {

    // Empty example
    // Multiple solutions
    // char Puz[9][9] = {{0,0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0}};

    // Difficulty = Easy
    // char Puz[9][9] = {{0,9,3,0,5,0,0,0,4}, {0,0,7,0,0,0,0,8,0}, {5,6,0,9,0,0,0,0,7}, {0,8,0,0,3,9,4,2,0}, {0,4,0,8,2,7,0,3,0}, {0,3,5,6,1,0,0,9,0}, {9,0,0,0,0,5,0,4,2}, {0,7,0,0,0,0,1,0,0}, {3,0,0,0,4,0,8,7,0}};

    // Difficulty = Medium
    // Multiple solutions
    // char Puz[9][9] = {{0,0,8,0,0,1,7,0,0}, {0,3,0,0,6,4,0,0,9}, {2,0,0,3,0,0,0,0,0}, {0,0,5,0,0,0,6,0,0}, {0,0,2,8,4,6,5,0,0}, {0,0,1,0,0,0,9,0,0}, {0,0,0,0,0,9,0,0,2}, {7,0,0,4,5,0,0,9,0}, {0,0,9,7,0,0,4,0,0}};

    // Difficulty = High
    char Puz[9][9] = {{8,5,0,0,0,2,4,0,0}, {7,2,0,0,0,0,0,0,9},{0,0,4,0,0,0,0,0,0},{0,0,0,1,0,7,0,0,2},{3,0,5,0,0,0,9,0,0},{0,4,0,0,0,0,0,0,0},{0,0,0,0,8,0,0,7,0},{0,1,7,0,0,0,0,0,0},{0,0,0,0,3,6,0,4,0}};

    clock_t begin, end;
    double time_spent;
    begin = clock();

    // Timer starts here

    Sudoku myPuzzle = init(Puz);
    solve(myPuzzle);

    // Timer ends here

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n\nElapsed: %g seconds\n", time_spent);

    return 0;

}
