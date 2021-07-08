#include <iostream>
#include <conio.h>
#include "windows.h" 


class TicTacToe
{

private:
	
	 char **board;
	void generate_board();
	int turn;
	char x;
	char y;
	char play_again;
	
	
public:
	TicTacToe()
	{
		
		this->generate_board();
		this->turn = 0;
		this->x = 'X';
		this->y = 'O';
		this->play_again = 'y';
		
	}
	~TicTacToe()
	{
		 for (int count = 0; count < 10; ++count)
		  delete[] board[count];
  delete[] board;
	}
	
	void pboard()
	{

     // board display
    std::cout << "Use num-pad to select fields, enjoy!" << '\n';
    
		std::cout << " ============================" << '\n';
		std::cout << "|" << "   " << board[0][0] << "    |    " << board[0][1] << "    |    " << board[0][2] << "    |    " << '\n';
		std::cout << "|============================|" << '\n';
		std::cout << "|" << "   " << board[1][0] << "    |    " << board[1][1] << "    |    " << board[1][2] << "    |    " << '\n';
		std::cout << "|============================|" << '\n';
		std::cout << "|" << "   " << board[2][0] << "    |    " << board[2][1] << "    |    " << board[2][2] << "    |    " << '\n';
		std::cout << " ============================" << '\n';

		

	}
	void reset_board()
	{
  // reseting board if we want to play again
		for (int i{ 0 }; i < 3; ++i)
		{
			for (int j{ 0 }; j < 3; ++j)
			{
				board[i][j] = ' ';
			}
		}

	}
	void x_y_turn()
	{
		//waiting for a key
		while ( _getch())
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

	bool check_status()
	{
    //if turn is 9(which means all fields are full) it must be draw 
    //else check whether X or O won
    // if somebody won return true else return false
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
	
		
		
	void who_won()
	{
		if (turn == 9)
			std::cout << "Draw" << '\n';
		else if (turn % 2 == 0)
			std::cout << "O won" << '\n';
		else if (turn % 2 != 0)
			std::cout << "X won" << '\n';

		std::cout << "Wanna play again? y/n ";
	}
	void start_game()
	{
		
		
		
		
		do
		{

			while (true)
			{

				Sleep(1000);
				system("cls");
				pboard();
				x_y_turn();
				system("cls");
				pboard();
				if (turn > 3) { // to win you must do at least 3 moves so start checking if somebody win after turn 3
					if (check_status())
						break;
				}
			}
			who_won();
			std::cin >> this->play_again;
			reset_board();
		} while (this->play_again == 'y');
			
	}
};
void TicTacToe::generate_board()
{

  //allocating board
	this->board = new char*[3];
	for (int i = 0; i < 3; ++i) {
		board[i] = new char[3];
		for (int j = 0; j < 3; ++j) {
			board[i][j] = ' ';
		}
	}
	

}
int main()
{

	
	
	TicTacToe game;
	game.start_game();
	

	return 0;

}
