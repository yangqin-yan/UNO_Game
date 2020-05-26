Name: Yan Yangqin
ID: 528370910065

************
* Project 2 *
************
---UNO---

#Game Description
UNO is an ancient Spanish card game. At the beginning of this game, every participant receives the same number of cards from the deck. Then participants follow the rules to play the card. The person who plays all the cards from his or her hand first will win the game.

The card-playing rule: 
-The game round goes on counter clockwise.
-Players can only play the card which has the same number or the same suit. 
-Each player can only play at most one card at a time.
-If one player does not have the proper card to play, he or she should draw a card from the deck and then is the next player's turn.
-Attack cards: cards with rank 2 can make next player draw 2 cards from the stock pile if the next player cannot play cards with rank 2 of any suit or rank 7 of the same suit.
Cards with rank 3 can make next player draw 3 cards from the stock pile if the next player cannot play cards with rank 3 of any suit or rank 7 of the same suit.
Defence cards: cards with rank 7: cancel an attack, i.e. do not draw any card if a 2 or a 3 was played before.
(Note:  Effect of attack cards are cumulative. To avoid the attack, the user can play the card with the same number or the card with the same suit and the number 7, or the player can use Jack to redirect the attack to the next next player and Queen cards to the player before.)
-Action cards: 
Queen cards: reverse the playing order from counter-clockwise to clockwise or clockwise to counterclockwise.
Jack cards: skip the next player.
(Note: Action cards are not influenced by cards with rank 7 and the effect cannot be deleted. A Queen or a Jack, of same suit as the previous card, can be played to redirect an attack on the previous player, or the player after the next one, respectively)

Judgement of winner:
In this game we use penalties to give each player minus scores. So at the end of the game the player who has the highest score will win finally. Winners can be multiple players if their scores are the same.
When a player plays all his or her cards, the player wins this round and have no deduction. However other players will be deducted by the number of cards in the player's hand. Scores of each player are cumulative in the course of game.


#Program
This program simulates the game mode of UNO.


#Input
When entering the game with command line, there are some key commands to guide you which are written in help documentation.
-h|--help print this help message
--log filename write the logs in filename (default: onecard.log)
-n n|--player-number=n n players, n must be larger than 2 (default: 4)
-c c|--initial-cards=c deal c cards per player, c must be at least 2 (default: 5)
-d d|--decks=d use d decks 52 cards each, d must be at least 2 (default: 2)
-r r|--rounds=r play r rounds, r must be at least 1 (default: 1)
-a|--auto run in demo mode
Then the system will give you tips to input the name of each player. The form is like:
Player 1, your name is:
Player 2, your name is:
...
Then the user can input the name of each player. Press enter to end the input of one name of a player and input the name of another one.
If it is the demo mode(auto mode), then the user can simply wait the program to print the outcome.
If it is not the demo mode, then when the game starts, the user should follow the rules to input the corresponding card. If there is no card to play, then the player should input "NaN draw" to draw card(s). If a player plays a card with Jack number, then the next player can only press enter to end his or her turn and go to his or her next player's turn.
Note: 
1. In the command "--log", the user should input within 49 characters.


#Output
All the cards played in the game are output properly in the game. The form is like"-spade 2", "-diamond Jack".
In the demo mode, the system will output the information of how players play the cards and draw the cards until all the rounds end. Then the system will output the scores of each player and the eventual winner.
Besides, all the information in the game will be stored in a log file whose name is onecard.log. Of course, you can rename it by inputing "--log". 

(To be continued)

#Bugs & Restrictions
1. Sometimes the pointer pointing to the player information will point to NULL. This always happens when the number of rounds is very big (usually bigger than 200 approximately).
2. The program cannot output the distribution of cards to all the players at the same time. Instead it can only output the cards in the hand of the current player.
3. When freeing the memory of the information of player, some errors occur. The error is: Signal: SIGTRAP (Trace/breakpoint trap).

#Reference
1. p2.pdf
