#include "../TicTacToe/Board.h"
#include "../TicTacToe/Game.h"

// test who_wins_at_column 

int who_wins_at_column_when_bord_empty_then_NoOneWon() {
	//arrange
	enum CELL board[3][3] = { {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL},
								{EMPTY_CELL, EMPTY_CELL, EMPTY_CELL},
								{EMPTY_CELL, EMPTY_CELL, EMPTY_CELL}
	};


	enum CELL expected = EMPTY_CELL;
	//act assert
	
		enum CELL actual = who_wins_at_column(board,0);

		return expected == actual ? 0 : 1;

}
int who_wins_at_column_when_x_one_then_X_CELL() {

	//arrange
	enum CELL board[3][3] = { {X_CELL, X_CELL,X_CELL},
								{X_CELL, EMPTY_CELL, EMPTY_CELL},
								{X_CELL, EMPTY_CELL, EMPTY_CELL}
	};


	enum CELL expected = X_CELL;

	//act
	enum CELL actual = who_wins_at_column(board, 0);

	//assert

	return expected == actual ? 0 : 1;


}
int who_wins_at_column_when_o_one_then_O_CELL() {

	enum CELL board[3][3] = { {X_CELL, O_CELL,X_CELL},
								{X_CELL,O_CELL, EMPTY_CELL},
								{X_CELL,O_CELL, EMPTY_CELL}
	};


	enum CELL expected = O_CELL;

	enum CELL actual = who_wins_at_column(board, 1);

	return expected == actual ? 0 : 1;

}
int who_wins_at_column_when_no_one_won_then_EMPTY_CELL() {

	enum CELL board[3][3] = { {X_CELL, X_CELL,X_CELL},
								{O_CELL,O_CELL, EMPTY_CELL},
								{X_CELL,O_CELL, EMPTY_CELL}
	};


	enum CELL expected = EMPTY_CELL;

	enum CELL actual = who_wins_at_column(board, 1);
	
		return expected == actual ? 0 : 1;


}

// test	who_wins_at_diagonal
int who_wins_at_diagonal__When_bord_empty_then_NoOneWon() {
	//arrange
	enum CELL board[3][3] = { {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL},
								{EMPTY_CELL, EMPTY_CELL, EMPTY_CELL},
								{EMPTY_CELL, EMPTY_CELL, EMPTY_CELL}
	};


	enum CELL expected = EMPTY_CELL;
	//act assert

	enum CELL actual = who_wins_at_diagonal(board, true);
	enum CELL actual1 = who_wins_at_diagonal(board, false);
	return expected == actual && expected == actual1 ? 0 : 1;

}
int who_wins_at_diagonal__When_x_won_then_X_CELL() {
	//arrange
	enum CELL board[3][3] = { {X_CELL, EMPTY_CELL, X_CELL},
								{EMPTY_CELL, X_CELL, EMPTY_CELL},
								{X_CELL, EMPTY_CELL, X_CELL}
	};
	

	enum CELL expected = X_CELL;
	//act assert

	enum CELL actual = who_wins_at_diagonal(board, true);
	enum CELL actual1 = who_wins_at_diagonal(board, false);
	return expected == actual && expected == actual1 ? 0 : 1;

}
int who_wins_at_diagonal__When_O_won_then_O_CELL() {
	//arrange
	enum CELL board[3][3] = { {O_CELL, EMPTY_CELL, O_CELL},
								{EMPTY_CELL, O_CELL, EMPTY_CELL},
								{O_CELL, EMPTY_CELL, O_CELL}
	};


	enum CELL expected = O_CELL;
	//act assert

	enum CELL actual = who_wins_at_diagonal(board, true);
	enum CELL actual1 = who_wins_at_diagonal(board, false);
	return expected == actual && expected == actual1 ? 0 : 1;

}
int who_wins_at_diagonal__When_no_one_won_then_EMPTY_CELL() {
	//arrange
	enum CELL board[3][3] = { {X_CELL, X_CELL, O_CELL},
								{O_CELL, X_CELL, X_CELL},
								{O_CELL, X_CELL, O_CELL}
	};


	enum CELL expected = EMPTY_CELL;
	//act assert

	enum CELL actual = who_wins_at_diagonal(board, true);
	enum CELL actual1 = who_wins_at_diagonal(board, false);
	return expected == actual && expected == actual1 ? 0 : 1;

}
int main() {

	bool right = (0 == who_wins_at_diagonal__When_no_one_won_then_EMPTY_CELL());
	if (right)
	{
		printf("ok!!!");
	}

	else
		printf("not ok!!!");
}