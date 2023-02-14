#include "lib.h"

void initialize (int b[16][2], int w[16][2])
{

    for(int p = 0;p<16;p++){
        if(p<8)
        {
            b[p][0] = p;
            b[p][1] = 0;

            w[p][0] = 7-p;
            w[p][1] = 7;
        }
        else
        {
            b[p][0] = p-8;
            b[p][1] = 1;

            w[p][0] = 7-(p-8);
            w[p][1] = 6;
        }
    }
    
}

void draw_board(int b[16][2], int w[16][2])
{
    bool isPiece = false;

    printf("    0 1 2 3 4 5 6 7\n\n");

    for(int y = 0;y<8;y++)
    {   
        printf("%d   ", y);
        for(int x = 0;x<8;x++)
        {   
            for(int p = 0;p<16;p++)
            {   
                if((b[p][0] == x && b[p][1] == y) || (w[p][0] == x && w[p][1] == y))
                {   
                    if(p == 0 || p == 7){
                        printf("R ");
                    }
                    if(p == 1 || p == 6){
                        printf("H ");
                    }
                    if(p == 2 || p == 5){
                        printf("B ");
                    }
                    if(p == 3){
                        printf("Q ");
                    }
                    if(p == 4){
                        printf("K ");
                    }
                    if(p>7&&p<16){
                        printf("P ");
                    }
                    isPiece = true;
                }
            }
            if(isPiece == false)
            {
                printf("* ");
            }
            isPiece = false;

        }
        printf("\n");
    }


}

bool ifPiece(int b[16][2], int w[16][2], int px, int py, int piece, char color[6]){

    for(int y = 0;y<8;y++)
    {
        for(int x = 0;x<8;x++)
        {
            for(int p = 0;p<16;p++){
                if((b[p][0] == px && b[p][1] == py))
                {   
                    strcpy(color, "black");
                    piece = p;
                    return true;
                }
                else if((w[p][0] == px && w[p][1] == py))
                {
                    strcpy(color, "white");
                    piece = p;
                    return true;
                }
            }
        }
    }
    return false;
}