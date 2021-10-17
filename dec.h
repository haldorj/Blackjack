#ifndef DEC_H
#define DEC_H

void log_in();		//function for user to log in.
void rules();		//displays game rules.
void player_draw();	//function for player to draw cards.
void funds();		//function to manage bets and funds.
void dealer_draw();   //function for house to draw cards.
void reset();		//function to end the round (new game).
void player_ace();	//function for when player gets an ace.
void dealer_ace();	//function for when house gets an ace.
void winner();		//checks for a winner.

#endif
