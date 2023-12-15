#include <stdio.h>

char board[3][3]; 

void initialize_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void display_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j != 2) {
                printf("\t|");
            }
        }
        printf("\n");
        if (i != 2) {
            printf("\t-----------\n");
        }
    }
}

int check_win() {
    int i;

    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return 1;
        }
    }

    // Verificar colunas
    for (i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return 1;
        }
    }

 
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {
        return 1;
    }

    return 0;
}

int main() {
    int row, col, player = 1, total_moves = 0;

    initialize_board();

    printf("Bem-vindo ao Jogo da Velha!\n\n");

    do {
        display_board();

        
        player = (player % 2) ? 1 : 2;

        printf("Jogador %d, digite a linha e coluna para marcar (por exemplo, 1 1): \n", player);
        scanf("%d %d", &row, &col);

        if (board[row - 1][col - 1] == ' ') {
            board[row - 1][col - 1] = (player == 1) ? 'X' : 'O';
            total_moves++;
        } else {
            printf(" Posição inválida! Tente novamente.\n");
            player--;
        }

        if (check_win()) {
            display_board();
            printf("\t\nParabéns! Jogador %d venceu o jogo!\n", player);
            break;
        }

        if (total_moves == 9) {
            display_board();
            printf("\t\nEmpate! O jogo terminou sem vencedores.\n");
            break;
        }

        player++;
    } while (1);

    return 0;
}