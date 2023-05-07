#include "Board.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

void draw_board(enum CELL board[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			print_cell(board[i][j]);
		}
		printf("\n");
	}

}
void clean_board(enum CELL board[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = EMPTY_CELL;
		}
	}
}
void set_cell(enum CELL board[3][3], uint8_t row_index, uint8_t column_index, enum CELL value) {
	board[row_index][column_index] = value;

}
enum CELL get_cell(enum CELL board[3][3], uint8_t row_index, uint8_t column_index) {
	return board[row_index][column_index];
}
enum CELL who_wins_at_row(enum CELL board[3][3], uint8_t row_index) {
	for (int i = 0; i < 2; i++) {//ריצה על שורה אחת
		if (board[row_index][i] != board[row_index][i + 1])
			return EMPTY_CELL;
	}
	return board[row_index][0];
}
enum CELL who_wins_at_column(enum CELL board[3][3], uint8_t col_index) {
	for (int i = 0; i < 2; i++) {
		if (board[i][col_index] != board[i+1][col_index])
			return EMPTY_CELL;
	}
	return board[0][col_index];
}
enum CELL who_wins_at_diagonal(enum CELL board[3][3], bool is_top_left_to_bottom_right) {
	int row = 0, col = 0;
	if (is_top_left_to_bottom_right == false) {
		col = 2;
		for (int i = row,j = col; i < 2; i++, j--) {

				if (board[i][j] != board[i + 1][j - 1]) {
					return EMPTY_CELL;
				}
		
		}
		return board[1][1];
	}
	else{ 
		for (int i = row; i < 2; i++) {
			 
				if (board[i][i] != board[i + 1][i + 1]) {
					return EMPTY_CELL;
				}
			
		}
	}
	return board[1][1];
}
void print_cell(enum CELL who) {

	switch (who)
	{
	case X_CELL:
		printf("X");
		break;
	case O_CELL:
		printf("O");
		break;
	case EMPTY_CELL:
		printf("-");
		break;
	default:
		break;
	}
}