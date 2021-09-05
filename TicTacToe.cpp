#include "TicTacToe.h"
#include <iostream>
#include <conio.h>
#include "windows.h" 

TicTacToe::TicTacToe()
{

	this->generate_board();
	this->turn = 0;
	this->x = 'X';
	this->y = 'O';
	this->play_again = 'y';

}
TicTacToe::~TicTacToe()
{
	for (int count{ 0 }; count < 10; ++count)
		delete[] board[count];
	delete[] board;
}

void TicTacToe::pboard()
{

	
	std::cout << "Use num-pad to select fields, enjoy!" << '\n';

	std::cout << " ============================" << '\n';
	std::cout << "|" << "   " << board[0][0] << "    |    " << board[0][1] << "    |    " << board[0][2] << "    |    " << '\n';
	std::cout << "|============================|" << '\n';
	std::cout << "|" << "   " << board[1][0] << "    |    " << board[1][1] << "    |    " << board[1][2] << "    |    " << '\n';
	std::cout << "|============================|" << '\n';
	std::cout << "|" << "   " << board[2][0] << "    |    " << board[2][1] << "    |    " << board[2][2] << "    |    " << '\n';
	std::cout << " ============================" << '\n';



}
void TicTacToe::reset_board()
{
	
	for (int i{ 0 }; i < constants::size; ++i)
	{
		for (int j{ 0 }; j < constants::size; ++j)
		{
			board[i][j] = ' ';
		}
	}

}
void TicTacToe::x_y_turn()
{
	
	while (_getch())
	{
		//if numpad key is pressed and this field on the board is empty -> put marker depends on the turn 


		if (GetAsyncKeyState(VK_NUMPAD7) && board[0][0] == ' ') {
			turn % 2 == 0 ? board[0][0] = this->x : board[0][0] = this->y; break;
		}
		else if (GetAsyncKeyState(VK_NUMPAD8) && board[0][1] == ' ') {
			turn % 2 == 0 ? board[0][1] = this->x : board[0][1] = this->y; break;
		}
		else if (GetAsyncKeyState(VK_NUMPAD9) && board[0][2] == ' ') {
			turn % 2 == 0 ? board[0][2] = this->x : board[0][2] = this->y; break;
		}
		else if (GetAsyncKeyState(VK_NUMPAD4) && board[1][0] == ' ') {
			turn % 2 == 0 ? board[1][0] = this->x : board[1][0] = this->y; break;
		}
		else if (GetAsyncKeyState(VK_NUMPAD5) && board[1][1] == ' ') {
			turn % 2 == 0 ? board[1][1] = this->x : board[1][1] = this->y; break;
		}
		else if (GetAsyncKeyState(VK_NUMPAD6) && board[1][2] == ' ') {
			turn % 2 == 0 ? board[1][2] = this->x : board[1][2] = this->y; break;
		}
		else if (GetAsyncKeyState(VK_NUMPAD1) && board[2][0] == ' ') {
			turn % 2 == 0 ? board[2][0] = this->x : board[2][0] = this->y; break;
		}
		else if (GetAsyncKeyState(VK_NUMPAD2) && board[2][1] == ' ') {
			turn % 2 == 0 ? board[2][1] = this->x : board[2][1] = this->y; break;
		}
		else if (GetAsyncKeyState(VK_NUMPAD3) && board[2][2] == ' ') {
			turn % 2 == 0 ? board[2][2] = this->x : board[2][2] = this->y; break;
		}
	}


	++turn;

}

bool TicTacToe::check_status()
{
	
	if (this->turn == 9)
		return true;
	if ((board[0][0] == this->x) && (board[0][1] == this->x) && (board[0][2] == this->x) || (board[0][0] == this->y) && (board[0][1] == this->y) && (board[0][2] == this->y))
		return true;
	else if ((board[1][0] == this->x) && (board[1][1] == this->x) && (board[1][2] == this->x) || (board[1][0] == this->y) && (board[1][1] == this->y) && (board[1][2] == this->y))
		return true;
	else if ((board[2][0] == this->x) && (board[2][1] == this->x) && (board[2][2] == this->x) || (board[2][0] == this->y) && (board[2][1] == this->y) && (board[2][2] == this->y))
		return true;
	else if ((board[0][2] == this->x) && (board[1][2] == this->x) && (board[2][2] == this->x) || (board[0][2] == this->y) && (board[1][2] == this->y) && (board[2][2] == this->y))
		return true;
	else if ((board[0][1] == this->x) && (board[1][1] == this->x) && (board[2][1] == this->x) || (board[0][1] == this->y) && (board[1][1] == this->y) && (board[2][1] == this->y))
		return true;
	else if ((board[0][0] == this->x) && (board[1][0] == this->x) && (board[2][0] == this->x) || (board[0][0] == this->y) && (board[1][0] == this->y) && (board[2][0] == this->y))
		return true;
	else if ((board[0][2] == this->x) && (board[1][1] == this->x) && (board[2][0] == this->x) || (board[0][2] == this->y) && (board[1][1] == this->y) && (board[2][0] == this->y))
		return true;
	else if ((board[0][0] == this->x) && (board[1][1] == this->x) && (board[2][2] == this->x) || (board[0][0] == this->y) && (board[1][1] == this->y) && (board[2][2] == this->y))
		return true;

	else
		return false;


}



void TicTacToe::who_won()
{
	if (turn == 9)
		std::cout << "Draw" << '\n';
	else if (turn % 2 == 0)
		std::cout << "O won" << '\n';
	else if (turn % 2 != 0)
		std::cout << "X won" << '\n';

	std::cout << "Wanna play again? y/n ";
}
void TicTacToe::start_game()
{




	do
	{

		while (true)
		{
			//wait 1 sec
			Sleep(1000);

			//clear the board
			system("cls");

			
			pboard();x_y_turn();
			system("cls");
			pboard();

			//You have to make at least 3 moves to win
			//so there's no need to check who won in first 2 moves
			if (turn > 3) { 
				if (check_status())
					break;
			}
		}
		who_won();
		std::cin >> this->play_again;
		reset_board();
	} while (this->play_again == 'y');

}

void TicTacToe::generate_board()
{

	//allocating board
	this->board = new char* [constants::size];
	for (int i = 0; i < constants::size; ++i) {
		board[i] = new char[constants::size];
		for (int j = 0; j < constants::size; ++j) {
			board[i][j] = ' ';
		}
	}


};
