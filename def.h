#include <iostream>
#include "dec.h"
#include <ctime>
#include <windows.h>

int p_card;
int d_card;
int p_totalcards;
int d_totalcards;
char choice;
char ace;
int p_funds = 100;
int d_funds = 100;
int bet;
int sum;

void log_in()
{
	// This is the username and password for the program:
	std::string real_user = "user123";
	std::string real_password = "pass123";

	std::string user;
	std::string password;

	int x;

	for (x = 0; x < 3; x++) {
		std::cout << " #####  #      #####  #####  #   #      #  #####  #####  #   #	" << std::endl;
		std::cout << " #   #  #      #   #  #      #  #       #  #   #  #      #  #	" << std::endl;
		std::cout << " ####   #      #####  #      ###        #  #####  #      ###	" << std::endl;
		std::cout << " #   #  #      #   #  #      #  #   #   #  #   #  #      #  #	" << std::endl;
		std::cout << " #####  #####  #   #  #####  #   #   ###   #   #  #####  #   #	" << std::endl;
		std::cout << " " << std::endl;
		std::cout << "Login:" << std::endl;
		std::cout << "Enter username:" << std::endl;
		std::cin >> user;
		std::cout << "Enter password:" << std::endl;
		std::cin >> password;

		if (user == real_user && password == real_password) {
			system("CLS");
			std::cout << "Access granted." << std::endl;
			x = 3; // stops loop
			rules();

		}

		else if (x == 2) {
			system("CLS");
			std::cout << "You entered the wrong username or password too many times." << std::endl;
			std::cout << "Exiting program..." << std::endl;
			exit(0);
		}

		else {
			system("CLS");
			std::cout << "Access denied." << std::endl;
			std::cout << "Wrong username or password." << std::endl;
			std::cout << "You have " << 2 - x << " tries left." << std::endl;
			std::cout << " " << std::endl;
		}
	}while (x < 3);
}
void rules()
{
	system("CLS");
	std::cout << "WELCOME TO BLACKJACK!" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "Rules:" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "Player and House has 100$ each as a start capital. " << std::endl;
	std::cout << "The minimum fee for starting a game is 10 $." << std::endl;
	std::cout << "After the player has drawn cards, they bet the sum of money." << std::endl;
	std::cout << "The game goes on for as many rounds necessary. The one that wins the opponents money, wins the whole game!" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "You pick a card that can be from 1 to 10." << std::endl;
	std::cout << "You pick as many cards as you want, until you reach 21. If you go above 21, you lose 10$." << std::endl;
	std::cout << "1 (the ace) can be 1 or 11 (Player chooses)." << std::endl;
	std::cout << " " << std::endl;
	std::cout << "The house will then draw cards." << std::endl;
	std::cout << "The house must draw cards until it matches your score or gets a better score." << std::endl;
	std::cout << "If it gets a match, it is a draw, and you play again." << std::endl;
	std::cout << "The one that has the best score <= 21 wins." << std::endl;
	std::cout << " " << std::endl;
	std::cout << "Press [ENTER] to continue." << std::endl;

	std::cin.ignore();
	std::cin.get();
	player_draw();
}
void player_draw()
{
	winner();

	system("CLS");
	std::cout << "You have " << p_funds << " credits." << std::endl;
	std::cout << "House has " << d_funds << " credits." << std::endl;

	srand(time(0));
	p_card = rand() % 13 + 1;

	if (p_totalcards > 21) {
		system("CLS");
		d_funds = d_funds + 10;
		p_funds = p_funds - 10;
		std::cout << "You went above 21. You lost 10 credits." << std::endl;
		std::cout << "Returning back to the game..." << std::endl;
		Sleep(3500);
		reset();
		player_draw();
	}

	std::cout << " " << std::endl;
	std::cout << "Players cards (total):" << std::endl;
	std::cout << " " << std::endl;
	std::cout << p_totalcards << std::endl;
	std::cout << " " << std::endl;

	std::cout << "do you wish to draw a card?" << std::endl;
	std::cout << "Press Y for Yes." << std::endl;
	std::cout << "Press N for No. (Bet your credits.)" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "(Press R to see the rules.)" << std::endl;
	std::cout << "(Press Q to exit the program.)" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "Your choice:" << std::endl;
	std::cin >> choice;

	switch (choice) {
	case 'Y': case 'y':
		if (p_card == 1) {
			player_ace();
		}
		else if (p_card == 11){
			p_totalcards += 10;
			std::cout << "You got a knight. The knight counts as 10." << std::endl;
			Sleep(2500);
			player_draw();
		}
		else if (p_card == 12) {
			p_totalcards += 10;
			std::cout << "You got a queen. The queen counts as 10." << std::endl;
			Sleep(2500);
			player_draw();
		}
		else if (p_card == 13) {
			p_totalcards += 10;
			std::cout << "You got a king. The king counts as 10." << std::endl;
			Sleep(2500);
			player_draw();
		}
		p_totalcards += p_card;
		player_draw();
		break;
	case 'N': case 'n':
		system("CLS");
		funds();
		dealer_draw();
		break;
	case 'R': case 'r':
		rules();
		break;
	case 'Q': case 'q':
		system("CLS");
		std::cout << " " << std::endl;
		std::cout << "Quitting program." << std::endl;
		std::cout << " " << std::endl;
		exit(0);
		break;
	default:
		system("CLS");
		std::cout << "Invalid input." << std::endl;
		player_draw();
		break;
	}while (choice != 'Q' && choice != 'q');
}
void funds()
{
	system("CLS");
	std::cout << "You have " << p_funds << " credits." << std::endl;
	std::cout << "House has " << d_funds << " credits." << std::endl;
	std::cout << " " << std::endl;
	std::cout << "How much do you wish to bet?" << std::endl;
	std::cin >> bet;


	if (bet < 10) {
		std::cout << "You need to bet a minimum of 10 credits." << std::endl;
		Sleep(3000);
		funds();
	}
	else if (bet > p_funds) {
		std::cout << "You do not have enough credits." << std::endl;
		Sleep(3000);
		funds();
	}
	else if (bet > d_funds) {
		std::cout << "House can not match your bet." << std::endl;
		Sleep(3000);
		funds();
	}

	std::cout << "You bet " << bet << " credits." << std::endl;

	dealer_draw();
}
void dealer_draw()
{
	while (d_totalcards < 100) {

		srand(time(0));
		d_card = rand() % 13 + 1;

		if (d_totalcards < p_totalcards)
		{
			if (d_card == 1) {
				dealer_ace();
			}
			else if (d_card == 11) {
				d_totalcards += 10;
				std::cout << "House got a knight. The knight counts as 10." << std::endl;
				std::cout << "Dealer has:" << std::endl;
				std::cout << d_totalcards << std::endl;
				Sleep(2500);
				dealer_draw();
			}
			else if (d_card == 12) {
				d_totalcards += 10;
				std::cout << "House got a queen. The queen counts as 10." << std::endl;
				std::cout << "Dealer has:" << std::endl;
				std::cout << d_totalcards << std::endl;
				Sleep(2500);
				dealer_draw();
			}
			else if (d_card == 13) {
				d_totalcards += 10;
				std::cout << "House got a king. The king counts as 10." << std::endl;
				std::cout << "Dealer has:" << std::endl;
				std::cout << d_totalcards << std::endl;
				Sleep(2500);
				dealer_draw();
			}
			d_totalcards = d_totalcards + d_card;
			std::cout << "Dealer has:" << std::endl;
			std::cout << d_totalcards << std::endl;
			Sleep(2000);
		}

		else if (d_totalcards == p_totalcards)
		{
			system("CLS");
			std::cout << "It's a draw." << std::endl;
			Sleep(2000);
			reset();
			player_draw();
		}

		else if (d_totalcards > p_totalcards && d_totalcards <= 21)
		{
			system("CLS");
			d_funds = d_funds + bet;
			p_funds = p_funds - bet;
			std::cout << "House wins. You lose." << std::endl;
			Sleep(2000);
			reset();
			player_draw();
		}

		else
		{
			system("CLS");
			p_funds = p_funds + bet;
			d_funds = d_funds - bet;
			std::cout << "You win. House loses." << std::endl;
			Sleep(2000);
			reset();
			player_draw();
		}
	}
}
void reset()
{
	p_totalcards = 0;
	d_totalcards = 0;
}
void player_ace()
{
	system("CLS");
	std::cout << "You got an ace." << std::endl;
	std::cout << "You can count the ace as either 1 or 11." << std::endl;
	std::cout << "Your total cards: " << p_totalcards << "." << std::endl;
	std::cout << "Press A for ace = 1" << std::endl;
	std::cout << "Press B for ace = 11" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "(Press R to see the rules.)" << std::endl;
	std::cout << "(Press Q to exit the program.)" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "Your Choice:" << std::endl;
	std::cin >> ace;
	switch (ace) {
	case 'A': case 'a':
		p_totalcards += 1;
		player_draw();
		break;
	case 'B': case 'b':
		p_totalcards += 11;
		player_draw();
		break;
	case 'R': case 'r':
		rules();
		break;
	case 'Q': case 'q':
		system("CLS");
		std::cout << " " << std::endl;
		std::cout << "Quitting program." << std::endl;
		std::cout << " " << std::endl;
		exit(0);
		break;
	default:
		std::cout << "Invalid input." << std::endl;
		Sleep(2000);
		player_ace();
		break;
	}while (choice != 0);
}
void dealer_ace()
{
	std::cout << "Dealer got an ace." << std::endl;
	if (d_totalcards <= 10) {
		d_totalcards += 11;
		std::cout << "Dealer chose ace = 11" << std::endl;
		std::cout << "Dealer cards (total):" << std::endl;
		std::cout << d_totalcards << std::endl;
		Sleep(3500);
		dealer_draw();
	}
	else {
		d_totalcards += 1;
		std::cout << "Dealer chose ace = 1" << std::endl;
		std::cout << "Dealer cards (total):" << std::endl;
		std::cout << d_totalcards << std::endl;
		Sleep(3500);
		dealer_draw();
	}
}
void winner() {
	if (p_funds < 10) {
		std::cout << "You do not meet the minimum fee of 10$." << std::endl;
		std::cout << "Better luck next time." << std::endl;
		Sleep(2000);
		std::cout << "Exiting program in 5 seconds..." << std::endl;
		Sleep(5000);
		exit(0);
	}
	if (p_funds == 0) {
		std::cout << "You lost all your credits." << std::endl;
		std::cout << "Better luck next time." << std::endl;
		Sleep(2000);
		std::cout << "Exiting program in 5 seconds..." << std::endl;
		Sleep(5000);
		exit(0);
	}
	if (d_funds < 10) {
		std::cout << "Congratulations!" << std::endl;
		std::cout << "You won the game!" << std::endl;
		std::cout << "House does not meet the minimum fee of 10$." << std::endl;
		std::cout << "You won " << p_funds << " credits." << std::endl;
		Sleep(2000);
		std::cout << "Exiting program in 5 seconds..." << std::endl;
		Sleep(5000);
		exit(0);
	}
}