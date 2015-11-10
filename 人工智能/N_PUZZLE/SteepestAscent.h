#ifndef STEEPESTASCENT_H
#define STEEPESTASCENT_H

#include "ChessState.h"

class SteepestAscent
{
public:
	CHESS_STATE initState;
	int stateGenerated;

	SteepestAscent();
	~SteepestAscent();

	SteepestAscent(CHESS_STATE chessState);

	void resetState(CHESS_STATE chessState);

	// ��ʼ��ɽ
	CHESS_STATE climbing();
private:

};

#endif