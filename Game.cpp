//Game class implementation file

#include "Game.h"

//Constructor
Game::Game()
{

string choice ;

cout << "Welcome to my Chess Program\n\n" ;
cout << "Would you like to play a game?" << endl ;
cout << "Yes or No: " ;
cin >> choice;

while(choice != "Yes" && choice != "No")    // ensures correct output
{
    cout << "Would you like to play a game?" << endl ;
    cout << "Yes or No: " ;
    cin >> choice;

}
    if(choice == "Yes")
        this->playGame() ;
    else
        cout << "Okay thanks for coming, bye!" << endl;



}

// Loops actual game until King is kjlled or user terminates by entering Q .
void Game::playGame()
{

    string name,choice,start,ending ;
    int startX,startY,endX,endY  ;



    cout << "Would you like to play on the white or black side?" << endl ;
    cout << "White or Black: " ;
    cin >> choice ;

    while(choice != "White" && choice != "Black") // ensures correct output
    {
        cout << "Would you like to play on the white or black side?" << endl ;
        cout << "White or Black: " ;
        cin >> choice ;
    }

    if(choice == "White")
    {
        cout << "What is your name: " ;
        cin >> name ;
        Player* p1 = new HumanPlayer(name,true) ;

        cout << "What is second players name: " ;
        cin >> name ;
        Player* p2 = new HumanPlayer(name,false) ;

        // Create a game pass players initialize board

        this->initialize(p1,p2) ;

        //Loop in Game until Game ends
        while(this->status == this->ACTIVE)
        {
            this->board.printBoard() ;

            if(this->currentTurn == p1)
            {
                cout << "Player 1 make a move: " << endl ;
                cout << "eg: A0 to B0 "  << endl ;

                cout << "start: " ;
                cin >> start ;
                                                        if(start[0] == 'Q')
                                                        {
                                                            cout << "\n Game terminated" ;
                                                            exit(0) ;
                                                        }

                cout << "end: " ;
                cin>> ending ;

                this->parseS(start,startX,startY) ;
                this->parseS(ending,endX,endY) ;

                cout << startX << startY ;
                cout << " to " ;
                cout << endX << endY << endl ;

                this->playerMove(p1,startX,startY,endX,endY) ;
                this->board.printBoard() ;


            }
            else
            {
                cout << "Player 2 make a move: " ;
                cout << "eg: A0 to B0 "  << endl ;

                cout << "start: " ;
                cin >> start ;

                 if(start[0] == 'Q')
                    {
                        cout << "\n Game terminated" ;
                        exit(0) ;
                    }

                cout << "end: " ;
                cin>> ending ;

               this->parseS(start,startX,startY) ;
               this->parseS(ending,endX,endY) ;

                cout << startX << startY ;
                cout << " to " ;
                cout << endX << endY << endl ;

                this->playerMove(p2,startX,startY,endX,endY) ;
                this->board.printBoard() ;

            }


        }


    }
    else
    {
        cout << "What is your name: " ;
        cin >> name ;
        Player* p1 = new HumanPlayer(name,false) ;

        cout << "What is second players name: " ;
        cin >> name ;
        Player* p2 = new HumanPlayer(name,true) ;

        // Create a game pass players and start

        this->initialize(p1,p2) ;


        //Loop in Game until Game ends
        while(this->status == this->ACTIVE)
        {
            this->board.printBoard() ;

            if(this->currentTurn == p1)
            {
                cout << "Player 1 make a move: " ;
                cout << "eg: A0 to B0 "  << endl ;

                cout << "start: " ;
                cin >> start ;

                 if(start[0] == 'Q')
                {
                    cout << "\n Game terminated" ;
                    exit(0) ;
                }

                cout << "end: " ;
                cin>> ending ;

               this->parseS(start,startX,startY) ;
                this->parseS(ending,endX,endY) ;

                cout << startX << startY ;
                cout << " to " ;
                cout << endX << endY << endl ;

               this->playerMove(p1,startX,startY,endX,endY) ;
                this->board.printBoard() ;
            }
            else
            {
                cout << "Player 2 make a move: " ;
                cout << "eg: A0 to B0 "  << endl ;

                cout << "start: " ;
                cin >> start ;

                 if(start[0] == 'Q')
                 {
                    cout << "\n Game terminated" ;
                    exit(0) ;
                 }

                cout << "end: " ;
                cin>> ending ;

               this->parseS(start,startX,startY) ;
               this->parseS(ending,endX,endY) ;

                cout << startX << startY ;
                cout << " to " ;
                cout << endX << endY << endl ;

                this->playerMove(p2,startX,startY,endX,endY) ;
                this->board.printBoard() ;
            }


        }



    }


}

//Function called to set Players in this Game
void Game::initialize(Player* p1, Player* p2)
{

       players[0] = p1;
       players[1] = p2;

//Determines which player is to go first based on side they chose
        if (p1->isWhiteSide() == true) {
            this->currentTurn = p1;
        }
        else {
            this->currentTurn = p2;

        }

        this->setStatus(ACTIVE);    // sets game to running
        movesPlayed.clear();        // and List structure is ready to hold Moves

}

//Determines if game is over
bool Game::isEnd()
{
    return this->getStatus() != this->ACTIVE ;
}

//Getter
bool Game::getStatus()
{
    return this->status ;
}

//Setter
void Game::setStatus(GameStatus status)
{
    this->status = status;
}

//Called by Player to make a move, and starting and ending coordinates are passed
bool Game::playerMove(Player* player, int startX, int startY, int endX, int endY)
{

    Spot* startBox = board.boxes[startX][startY];
    Spot* endBox = board.boxes[endX][endY];
    move1 = new Move(player, startBox, endBox);
    return this->makeMove(*move1, player);  // calls function to verify, and make move

}

//Function used to verify, store, and make move indicated by Player
bool Game::makeMove(Move move1, Player* player)
{
//Checks if there is a Piece to move at that Spot
Piece* sourcePiece = move1.getStart()->getPiece();
        if (sourcePiece == nullptr) {
            return false;
        }

        // valid player
        if (player != currentTurn) {
            return false;
        }


        if (sourcePiece->isWhite() != player->isWhiteSide()) {
            return false;
        }


        // valid move?
        if (!sourcePiece->canMove(&board, move1.getStart(), move1.getEnding())) {
            return false;
        }

        // kill?
        Piece* destPiece = move1.getEnding()->getPiece();
        if (destPiece != nullptr) {
            destPiece->setKilled(true);
            move1.setPieceKilled(destPiece);
        }


        // store the move
        movesPlayed.push_back(move1);

        // move piece from the start box to end box
        move1.getEnding()->setPiece(move1.getStart()->getPiece());
        move1.getStart()->setPiece(nullptr);

        //check if the move results in King dying terminating the game
        if (destPiece != nullptr && dynamic_cast<King*>(destPiece)) {
            if (player->isWhiteSide()) {
                this->setStatus(this->WHITE_WIN);
            }
            else {
                this->setStatus(this->BLACK_WIN);
            }
        }

        // set the current turn to the other player
        if (this->currentTurn == players[0]) {
            this->currentTurn = players[1];
        }
        else {
            this->currentTurn = players[0];
        }

        return true;
    }



//to parse user input for player moves (eg: A0 to B0) or Q for quit.
void Game:: parseS(string start,int &num1, int &num2)
{
  char letter = start[0] ;

  switch(letter)
  {
      case 'A':
      {
          num1 = 0 ;
          break ;
      }
      case 'B':
      {
          num1 = 1;
          break ;
      }
       case 'C':
      {
          num1 = 2;
          break ;
      }
       case 'D':
      {
          num1 = 3;
          break ;
      }
       case 'E':
      {
          num1 = 4;
          break ;
      }
       case 'F':
      {
          num1 = 5;
          break ;
      }
       case 'G':
      {
          num1 = 6;
          break ;
      }
       case 'H':
      {
          num1 = 7;
          break ;
      }

       case 'Q':
      {
        cout << "\nGame terminated ";
        exit(0) ;
      }
  }

  letter = start[1] ;
  num2 = letter - 48 ;


}



























//Destructor for Game class

Game::~Game()
{
   //delete move1 ;
    cout << "Game class destructor called" ;
}


