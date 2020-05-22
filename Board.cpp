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




Board::Board()
{
    cout << "Placing board pieces.." << endl ;

    boxes[0][0] = new Spot(0,0,new Rook(true,false)) ;
    boxes[0][1] = new Spot(0,1,new Knight(true,false)) ;
    boxes[0][2] = new Spot(0,2,new Bishop(true,false)) ;
    boxes[0][3] = new Spot(0,3,new King(true,false)) ;
    boxes[0][4] = new Spot(0,4,new Queen(true,false)) ;
    boxes[0][5] = new Spot(0,5,new Bishop(true,false)) ;
    boxes[0][6] = new Spot(0,6,new Knight(true,false)) ;
    boxes[0][7] = new Spot(0,7,new Rook(true,false)) ;

    for(int i = 0; i<8; i++)
    {
        boxes[1][i] = new Spot(1,i,new Pawn(true,false)) ;

    }

    boxes[7][0] = new Spot(7,0,new Rook(false,false)) ;
    boxes[7][1] = new Spot(7,1,new Knight(false,false)) ;
    boxes[7][2] = new Spot(7,2,new Bishop(false,false)) ;
    boxes[7][3] = new Spot(7,3,new King(false,false)) ;
    boxes[7][4] = new Spot(7,4,new Queen(false,false)) ;
    boxes[7][5] = new Spot(7,5,new Bishop(false,false)) ;
    boxes[7][6] = new Spot(7,6,new Knight(false,false)) ;
    boxes[7][7] = new Spot(7,7,new Rook(false,false)) ;

        for(int i = 0; i<8; i++)
    {
      boxes[6][i] = new Spot(6,i,new Pawn(false,false)) ;

    }
    // now initialize empty spots with x,y,nullptr

       for(int i = 2; i<6; i++)
    {
        for(int j = 0; j<8 ; j++)
        {
          boxes[i][j] = new Spot(i,j,nullptr) ;

        }

    }


    cout << "Pieces placed" << endl ;

}

void Board::printBoard()
{

cout << " " << " ";
    for(int i =0; i<8; i++)
    {
        cout << i << " " << " "   ;
    }
    cout << endl ;

    for(int i =0; i < 8; i++)
{
    cout << i << " " ;
    for(int j = 0; j < 8; j++)
    {
        if(boxes[i][j]->getPiece() == nullptr)
            cout << " " << " " << " " ;
        else
            boxes[i][j]->getPiece()->printP();

    }

    cout << endl ;
}

    cout << endl ;


}


/*
Board::~Board()
{
    delete[] boxes ;

}
*/
