#pragma once

namespace constants
{
	constexpr int size{ 3 };
	

}
class TicTacToe
{

private:
	//private variables
	char** board;
	void generate_board();
	int turn;
	char x;
	char y;
	char play_again;


public:

	//public methods

	//Constructor, deconstructor
	TicTacToe();
	~TicTacToe();
	
	//Display our whole board
	void pboard();

	//if Player1 or Player 2 wins, reset board
	void reset_board();


	//Check whose turn is it now
	void x_y_turn();
	
	//this method checks if at current stage someone has already won
	//if all of the fields are taken, it means that we have a draw
	//else check all possible winning combinations
	bool check_status();



	//final result of our winner
	//if our turn is even and check_status returned true, "O" must have won
	// otherwise X wins
	void who_won();
	
	//starting game
	//drawind and generating board and waiting for players input
	void start_game();
	
};


