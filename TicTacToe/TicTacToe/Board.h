#pragma once

#include <stdint.h>
#include<stdbool.h>
#include <stdio.h>
enum CELL {
	X_CELL,
	O_CELL,
	EMPTY_CELL
};

void draw_board(enum CELL board[3][3]);
void clean_board(enum CELL board[3][3]);
void set_cell(enum CELL board[3][3], uint8_t row_index, uint8_t column_index, enum CELL value);
enum CELL get_cell(enum CELL board[3][3], uint8_t row_index, uint8_t column_index);
enum CELL who_wins_at_row(enum CELL board[3][3], uint8_t row_index);
enum CELL who_wins_at_column(enum CELL board[3][3], uint8_t col_index);
enum CELL who_wins_at_diagonal(enum CELL board[3][3], bool is_top_left_to_bottom_right);
static void read_move_from_user(key);
//enum CELL who_won(enum CELL board[3][3], uint8_t row_index, uint8_t column_index);
void print_cell(enum CELL who);

