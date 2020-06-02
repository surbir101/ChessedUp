/* Board class implementation file

Constructor creates board by dynamically allocating
Spots with proper coordinates, and dynamically allocating
relevant Pieces at the relevant Spots.

Upon board creation success output message is displayed
and Chess Board is created.

*/

#include <iostream>
#include <string>
#include "Piece.h"
#include "Spot.h"
#include "King.h"
#include "Board.h"
#include "Knight.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "Pawn.h"
#include "Spot.h"
#include "Piece.h"



//Constructor
Board::Board()
{
//Indicates successfull call of Constructor, and start of creation and placement of Board elements
    cout << "Placing board pieces.." << endl ;

//Creating Spots and Placing white pieces in first row
    boxes[0][0] = new Spot(0,0,new Rook(true,false)) ;
    boxes[0][1] = new Spot(0,1,new Knight(true,false)) ;
    boxes[0][2] = new Spot(0,2,new Bishop(true,false)) ;
    boxes[0][3] = new Spot(0,3,new King(true,false)) ;
    boxes[0][4] = new Spot(0,4,new Queen(true,false)) ;
    boxes[0][5] = new Spot(0,5,new Bishop(true,false)) ;
    boxes[0][6] = new Spot(0,6,new Knight(true,false)) ;
    boxes[0][7] = new Spot(0,7,new Rook(true,false)) ;

//Creating Spots and Placing white Pawns in second row
    for(int i = 0; i<8; i++)
    {
        boxes[1][i] = new Spot(1,i,new Pawn(true,false)) ;

    }

//Creating Spots and Placing black pieces in last row
    boxes[7][0] = new Spot(7,0,new Rook(false,false)) ;
    boxes[7][1] = new Spot(7,1,new Knight(false,false)) ;
    boxes[7][2] = new Spot(7,2,new Bishop(false,false)) ;
    boxes[7][3] = new Spot(7,3,new King(false,false)) ;
    boxes[7][4] = new Spot(7,4,new Queen(false,false)) ;
    boxes[7][5] = new Spot(7,5,new Bishop(false,false)) ;
    boxes[7][6] = new Spot(7,6,new Knight(false,false)) ;
    boxes[7][7] = new Spot(7,7,new Rook(false,false)) ;

//Creating Spots and Placing black Pawns in second to last row
    for(int i = 0; i<8; i++)
    {
      boxes[6][i] = new Spot(6,i,new Pawn(false,false)) ;

    }


//Creating Spots and passing relevant coordinates for empty Spots in middle of Chess Board
       for(int i = 2; i<6; i++)
    {
        for(int j = 0; j<8 ; j++)
        {
          boxes[i][j] = new Spot(i,j,nullptr) ; //nullptr indicates no Piece is yet present there Spot is empty/free.

        }

    }

//Indicates Board object successfully created, with relevant Spots & Pieces placed.
    cout << "Pieces placed" << endl ;

}


//Used to print board to screen to show players state of the game
void Board::printBoard()
{

//Loop used to display x plane index ( 0-7) across top of board
    cout << " " << " ";
    for(int i =0; i<8; i++)
    {
        cout << i << " " << " "   ;
    }
    cout << endl ;

int num = 65; //ascii value for A
//Nested loop to display each row of chess board
    for(int i =0; i < 8; i++)
    {
        cout << char(num++) << " " ;     // start of each row begins with relevant y coordinate plane index (0 - 7)
        for(int j = 0; j < 8; j++)
        {
            if(boxes[i][j]->getPiece() == nullptr)  //if spot has no piece display empty space
                cout << " " << " " << " " ;
            else
                boxes[i][j]->getPiece()->printP();  //else print piece to screen

        }

    cout << endl ;
    }

    cout << endl ;

}


//Board class Destructor
Board::~Board()
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0 ; j < 8 ; j++)
        {
            delete boxes[i][j] ;
        }
    }

}

