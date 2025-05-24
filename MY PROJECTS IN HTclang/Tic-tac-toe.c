#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
void sleep_ms(int milliseconds) {
#ifdef _WIN32
    Sleep(milliseconds);
#else
    usleep(milliseconds * 1000);
#endif
}
int *initBoard() {
    int *board = malloc(9 * sizeof(int));
    if (!board) {
        perror("malloc failed");
        return NULL;
    }
    for (size_t A_Index1 = 0; A_Index1 < 9 + 0; A_Index1++) {
        board[A_Index1] = 0;
    }
    return board;
}
int win(int *board) {
    int win = 0;
    if (board[0] == 1 && board[1] == 1 && board[2] == 1) {
        win = 1;
    }
    else if (board[3] == 1 && board[4] == 1 && board[5] == 1) {
        win = 1;
    }
    else if (board[6] == 1 && board[7] == 1 && board[8] == 1) {
        win = 1;
    }
    else if (board[0] == 1 && board[3] == 1 && board[6] == 1) {
        win = 1;
    }
    else if (board[1] == 1 && board[4] == 1 && board[7] == 1) {
        win = 1;
    }
    else if (board[2] == 1 && board[5] == 1 && board[8] == 1) {
        win = 1;
    }
    else if (board[0] == 1 && board[4] == 1 && board[8] == 1) {
        win = 1;
    }
    else if (board[2] == 1 && board[4] == 1 && board[6] == 1) {
        win = 1;
    }
    else if (board[0] == 2 && board[1] == 2 && board[2] == 2) {
        win = 2;
    }
    else if (board[3] == 2 && board[4] == 2 && board[5] == 2) {
        win = 2;
    }
    else if (board[6] == 2 && board[7] == 2 && board[8] == 2) {
        win = 2;
    }
    else if (board[0] == 2 && board[3] == 2 && board[6] == 2) {
        win = 2;
    }
    else if (board[1] == 2 && board[4] == 2 && board[7] == 2) {
        win = 2;
    }
    else if (board[2] == 2 && board[5] == 2 && board[8] == 2) {
        win = 2;
    }
    else if (board[0] == 2 && board[4] == 2 && board[8] == 2) {
        win = 2;
    }
    else if (board[2] == 2 && board[4] == 2 && board[6] == 2) {
        win = 2;
    }
    // returns who wins if its 0 no one wins
    return win;
}
bool checkForDraw(int *board) {
    for (size_t A_Index2 = 0; A_Index2 < 9 + 0; A_Index2++) {
        if (board[A_Index2] == 0) {
            return false;
        }
    }
    return true;
}
// main func
int main(int argc, char* argv[]) {
    int *board = initBoard();
    if (board == NULL) {
        return 1;
    }
    int player1 = 1;
    int player2 = 2;
    int turn = 1;
    bool game = true;
    int pin = 0;
    while (game == true) {
        for (size_t A_Index3 = 0; A_Index3 < 9 + 0; A_Index3++) {
            printf("%d|", board[A_Index3]);
            if (A_Index3 == 2 || A_Index3 == 5 || A_Index3 == 8) {
                printf("\n%s\n", "------");
            }
        }
        printf("%s", "Enter 1-9 to place you'r pin: ");
        int res = scanf("%d", &pin);
        if (res != 1) {
            printf("%s\n", "ERROR YOU need to enter a number bettwen 1 to 9");
            int c = 0;
            while ((c=getchar()) != (char)10 && c != EOF) {
            }
            continue;
        }
        if (pin < 1 || pin > 9) {
            printf("%s\n", "ERROR YOU need to enter a number bettwen 1 to 9");
        } else {
            printf("%s\n", "NICE!!!");
            if (turn == 1) {
                if (board[pin - 1] == 0) {
                    board[pin - 1] = 2;
                    turn = 2;
                }
            }
            else if (turn == 2) {
                if (board[pin - 1] == 0) {
                    board[pin - 1] = 1;
                    turn = 1;
                }
            }
            if (win(board) == 1) {
                for (size_t A_Index4 = 0; A_Index4 < 5 + 0; A_Index4++) {
                    printf("%s\n", "============");
                }
                for (size_t A_Index5 = 0; A_Index5 < 9 + 0; A_Index5++) {
                    printf("%d|", board[A_Index5]);
                    if (A_Index5 == 2 || A_Index5 == 5 || A_Index5 == 8) {
                        printf("\n%s\n", "------");
                    }
                }
                printf("%s\n", "Player 1 WON!!!\nGG");
                printf("%s\n", "EXITING...");
                sleep_ms(2500);
                game = false;
            }
            else if (win(board) == 2) {
                for (size_t A_Index6 = 0; A_Index6 < 5 + 0; A_Index6++) {
                    printf("%s\n", "============");
                }
                for (size_t A_Index7 = 0; A_Index7 < 9 + 0; A_Index7++) {
                    printf("%d|", board[A_Index7]);
                    if (A_Index7 == 2 || A_Index7 == 5 || A_Index7 == 8) {
                        printf("\n%s\n", "------");
                    }
                }
                printf("%s\n", "Player 2 WON!!!\nGG");
                printf("%s\n", "EXITING...");
                sleep_ms(2500);
                game = false;
            }
            else if (checkForDraw(board)) {
                for (size_t A_Index8 = 0; A_Index8 < 5 + 0; A_Index8++) {
                    printf("%s\n", "============");
                }
                for (size_t A_Index9 = 0; A_Index9 < 9 + 0; A_Index9++) {
                    printf("%d|", board[A_Index9]);
                    if (A_Index9 == 2 || A_Index9 == 5 || A_Index9 == 8) {
                        printf("\n%s\n", "------");
                    }
                }
                printf("%s\n", "DRAW DRAW DRAW DRAW\nNO ONE WINS :(");
                printf("%s\n", "EXITING...");
                sleep_ms(2500);
                game = false;
            }
        }
    }
    //;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    // after use free it
    free(board);
    return 0;
}
