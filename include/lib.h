#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void initialize (int b[16][2], int w[16][2]);

void draw_board(int b[16][2], int w[16][2]);

bool ifPiece(int b[16][2], int w[16][2], int x, int y, int piece, char color[6]);