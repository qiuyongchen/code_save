#ifndef CHESSSTATEGENERATOR_H
#define CHESSSTATEGENERATOR_H

#include "ChessState.h"
#define random(x) (rand()%x)

// ����״̬������
class ChessStateGenerator
{
public:
	ChessStateGenerator();
	~ChessStateGenerator();

	// �������һ������״̬
	CHESS_STATE getNewState();
private:

};

#endif