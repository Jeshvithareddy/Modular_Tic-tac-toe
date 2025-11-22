#include <stdio.h>

char board[3][3];

void Board() {
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            board[i][j] = ' ';
}

void printboard() {
    printf("\n");
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            printf(" %c ", board[i][j]);
            if(j < 2) printf("|");
        }
        if(i < 2) printf("\n---+---+---\n");
    }
    printf("\n\n");
}

int win(char p) {

    for(int i=0;i<3;i++){
        if(board[i][0]==p && board[i][1]==p && board[i][2]==p) return 1;
        if(board[0][i]==p && board[1][i]==p && board[2][i]==p) return 1;
    }
    if(board[0][0]==p && board[1][1]==p && board[2][2]==p) return 1;
    if(board[0][2]==p && board[1][1]==p && board[2][0]==p) return 1;

    return 0;
}

int full() {
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(board[i][j] == ' ')
                return 0;
    return 1;
}

int validmove(int r, int c) {
    if(r < 1 || r > 3 || c < 1 || c > 3) return 0;
    if(board[r-1][c-1] != ' ') return 0;
    return 1;
}

void makemove(int r, int c, char p) {
    board[r-1][c-1] = p;
}

int main() {
    int r, c, turn = 0;
    char player;
    Board();

    printf("Modular Tic-Tac-Toe (3x3):\n");
    printboard();

    while(1) {
        player = (turn % 2 == 0) ? 'X' : 'O';
        printf("Player %c, enter row and col (1-3 1-3): ", player);
        scanf("%d %d", &r, &c);

        if(!validmove(r, c)) {
            printf("Invalid move, try again.\n");
            continue;
        }

        makemove(r, c, player);
        printboard();

        if(win(player)) {
            printf("Player %c wins!\n", player);
            break;
        }

        if(full()) {
            printf("Game is a draw.\n");
            break;
        }

        turn++;
    }

    return 0;
}
