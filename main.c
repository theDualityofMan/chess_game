#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void initialize (int b[16][2], int w[16][2]);

void draw_board(int b[16][2], int w[16][2]);

bool ifPiece(int b[16][2], int w[16][2], int x, int y, int piece, char color[6]);


int b_pos[16][2], w_pos[16][2], counter, move[2], piece[2], p_sel;

bool game_over = false;

char cur_player[6], enem_player[6], col_sel[6];


int main(){

    initialize(b_pos, w_pos);

    printf("Enter which player starts, black or white: ");

    scanf("%s", cur_player);

    if(strcmp(cur_player, "black") == 0)
    {
        strcpy(enem_player, "white");
    }
    else
    {
        strcpy(enem_player, "black");
    }

    while(game_over==false)
    {
        printf("\n      %s's turn! \n\n", cur_player);

        draw_board(b_pos, w_pos);

        printf("\nEnter the coordinates of piece to move in the format [x y], separated by a space: ");

        scanf("%d %d", &piece[0], &piece[1]);

        while(ifPiece(b_pos, w_pos, piece[0], piece[1], p_sel, col_sel) == false)
        {
            printf("There is no piece at selected location, please try again: ");

            scanf("%d %d", &piece[0], &piece[1]);

        }

        while((ifPiece(b_pos, w_pos, piece[0], piece[1], p_sel, col_sel) == true) && (strcmp(cur_player, col_sel) != 0))
        {
            printf("You have selected the wrong color, please try again: ");

            scanf("%d %d", &piece[0], &piece[1]);

        }
        
        printf("There is a piece at selected location");

        printf("\nEnter the coordinates to move to in the format [x y], separated by a space: ");

        scanf("%d %d", &move[0], &move[1]);

        while(ifPiece(b_pos, w_pos, move[0], move[1], p_sel, col_sel) == true && strcmp(col_sel, cur_player)==0)
        {   
            printf("%s", col_sel);
            printf("There is an allied piece at selected location, please try again: ");

            scanf("%d %d", &move[0], &move[1]);

        }

        if(strcmp(cur_player, "black") == 0)
        {
            b_pos[p_sel][0] = move[0];
            b_pos[p_sel][1] = move[1];
        }
        else
        {
            w_pos[p_sel][0] = move[0];
            w_pos[p_sel][1] = move[1];
        }

        printf("\n");

        if(strcmp(cur_player, "black") == 0)
        {
            strcpy(cur_player, "white");
            strcpy(enem_player, "black");
        }
        else
        {
            strcpy(cur_player, "black");
            strcpy(enem_player, "white");
        }

    }

    return 0;
}