#pragma once
#include <stdio.h>
#include <stdbool.h>

int read_number_from_user(const char* message);
bool is_user_asked_to_exit(int row, int col);
bool is_move_valid(enum CELL board[3][3], int move_row, int move_col);
void make_move(enum CELL board[3][3], int move_row, int move_col, enum CELL piece);
void announce_winner(enum CELL who);
void announce_tie();
enum cell who_won(enum CELL board[3][3]);
bool is_board_full(board);