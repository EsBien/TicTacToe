
#include "Game.h"
#include "Board.h"
#include <stdio.h>


int read_number_from_user(const char* message)
{
	int num = -1;
	printf(message);
	scanf("%d", &num);
	return num;
}
bool is_user_asked_to_exit(int row, int col)
{
	return row == -1 || col == -1;
}
bool is_move_valid(enum CELL board[3][3], int move_row, int move_col)
{
	return 0 <= move_row && move_row < 3
		&& 0 <= move_col && move_col < 3
		&& get_cell(board, move_row, move_col) == EMPTY_CELL;//מקום ריק
}
void make_move(enum CELL board[3][3], int move_row, int move_col, enum CELL piece)
{
	set_cell(board, move_row, move_col, piece);
}
void announce_winner(enum CELL who)
{
	printf("We have a winner !!! ");
	print_cell(who);
	printf(" has won !!!\n");
}
void announce_tie()
{
	printf("We have a Tie !!! \n");
}
enum cell who_won(enum CELL board[3][3])
{

	enum cell winner = EMPTY_CELL;

	for (int i = 0; i < 3; i++)
	{
		winner = who_wins_at_row(board, i);//ריצה על השורות

		if (winner != EMPTY_CELL)
		{
			return winner;
		}

		winner = who_wins_at_column(board, i);

		if (winner != EMPTY_CELL)
		{
			return winner;
		}


	}


	winner = who_wins_at_diagonal(board, true);

	if (winner != EMPTY_CELL)
	{
		return winner;
	}

	winner = who_wins_at_diagonal(board, false);

	if (winner != EMPTY_CELL)
	{
		return winner;
	}

}
bool is_board_full(enum cell board[3][3]) {

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == EMPTY_CELL) {
				return false;
			}
		}
	}

	return true;
}
int main()
{
	enum CELL board[3][3];

	bool should_exit = false;

	while (!should_exit)
	{
		// prepare a fresh new game:
		bool game_over = false;
		bool is_X_turn = true;
		clean_board(board);
		// game loop:
		printf("%s", "To exit, enter -1, an invalid index will end the game\n");
		while (!game_over)
		{
			draw_board(board);
			enum CELL piece = is_X_turn ? X_CELL : O_CELL;
			printf(is_X_turn ? " *** X move! *** \n" : " *** O move! *** \n");
			int move_row = read_number_from_user("Next move row?");
			int move_col = read_number_from_user("Next move column?");

			if (is_user_asked_to_exit(move_row, move_col))//הכניס מינוס 1
			{
				should_exit = true;
				game_over = true;
				continue;
			}

			if (!is_move_valid(board, move_row, move_col))
			{
				printf("Invalid move, please try again :)\n");
				continue;
			}

			make_move(board, move_row, move_col, piece);

			is_X_turn = !is_X_turn;

			enum CELL winner = who_won(board);//check for a winner
			bool we_have_a_winner = EMPTY_CELL != winner;
			if (we_have_a_winner)
			{
				announce_winner(winner);
				game_over = true;
			}
			else if (is_board_full(board))
			{
				announce_tie();
				game_over = true;
			}
		}
		printf("Good game !\n");
	}
	printf("Bye Bye !\n");

	return 0;
}
