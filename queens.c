#include "common.h"

#define BOARDSIZE   8
#define DIAGONAL    (2*BOARDSIZE-1)
#define DOWNOFFSET  7

void WriteBoard(void);
void AddQueen(void);

int queencol[BOARDSIZE];        /* column with the queen                    */
Boolean colfree[BOARDSIZE];     /* Is the column free?                      */
Boolean upfree[DIAGONAL];       /* Is the upward diagonal free?             */
Boolean downfree[DIAGONAL];     /* Is the downward diagonal free?           */
int queencount = -1,            /* row whos queen is currently placed       */
    numsol = 0;                 /* number of solutions found so far         */

/* Queen: Eight-queens program.
 * Pre:     None.
 * Post:    All solutions to the eight-queens problem are printed.
 * Uses:    Function AddQueen performs the recursive backtracking; WriteBoard
 *          prints the solutions.
 * */

int main(void) {
    int i;
    for(i=0; i<BOARDSIZE; i++)
        colfree[i] = TRUE;
    for(i=0; i<DIAGONAL; i++) {
        upfree[i] = TRUE;
        downfree[i] = TRUE;
    }
    AddQueen();
    return 0;
}

/* WriteBoard
 * Pre:     A solution has been found.
 * Post:    The solution has been printed.
 * Uses:    Funciton AddQueen
 * */
void WriteBoard(void) {
    numsol++;
    int i, j;
    printf("Solution %d\n", numsol);
    for(i=0; i<BOARDSIZE; i++) {
        for(j=0; j<BOARDSIZE; j++) {
            if(j==queencol[i])
                printf("Q ");
            else
                printf("- ");
        }
        printf("\n");
    }
    printf("\n");
}

/* AddQueen: add a queen to the board.
 * Pre:     Queens have been properly placed in rows 0 through queencount
 *          (provided queencount >= 0) and the information recorded in the
 *          above arrays.
 * Post:    All solutions beginning with this configuration have been
 *          printed. queencount, and values in all arrays have been returned
 *          to their original values.
 * Uses:    Global variable queencount, global arrays queencol colfree,
 *          upfree, and downfree, and function WriteBoard.
 * */
void AddQueen(void) {
    int col;
    queencount++;
    for(col=0; col<BOARDSIZE; col++)
        if(colfree[col] && upfree[queencount+col] &&
                downfree[queencount-col+DOWNOFFSET]) {
            /* Put a queen in position (queencount, col). */
            queencol[queencount] = col;
            colfree[col] = FALSE;
            upfree[queencount+col] = FALSE;
            downfree[queencount-col+DOWNOFFSET] = FALSE;
            if(queencount==BOARDSIZE-1)
                WriteBoard();
            else
                AddQueen();
            colfree[col] = TRUE;
            upfree[queencount+col] = TRUE;
            downfree[queencount-col+DOWNOFFSET] = TRUE;
        }
    queencount--;
}
