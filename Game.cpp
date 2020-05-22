#include "Game.h"

void Game::initialize(Player* p1, Player* p2)
{

       players[0] = p1;
       players[1] = p2;

        if (p1->isWhiteSide()) {
            this->currentTurn = p1;
        }
        else {
            this->currentTurn = p2;
        }

        movesPlayed.clear();

}

bool Game::isEnd()
{
    return this->getStatus() != this->ACTIVE ;
}

bool Game::getStatus()
{
    return this->status ;
}

void Game::setStatus(GameStatus status)
{
    this->status = status;
}

bool Game::playerMove(Player* player, int startX, int startY, int endX, int endY)
{
    Spot* startBox = board.boxes[startX][startY];
    Spot* endBox = board.boxes[endX][endY];
    Move* move1 = new Move(player, startBox, endBox);
    return this->makeMove(*move1, player);

}

bool Game::makeMove(Move move1, Player* player)
{
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
        Piece* destPiece = move1.getStart()->getPiece();
        if (destPiece != nullptr) {
            destPiece->setKilled(true);
            move1.setPieceKilled(destPiece);
        }


        // store the move
        movesPlayed.push_back(move1);

        // move piece from the stat box to end box
        move1.getEnding()->setPiece(move1.getStart()->getPiece());
        move1.getStart()->setPiece(nullptr);

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

//void Game::printBoard()
//{


//}





