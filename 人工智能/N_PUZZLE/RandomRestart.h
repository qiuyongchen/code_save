#ifndef RANDOMRESTART_H
#define RANDOMRESTART_H

#include "ChessStateGenerator.h"
#include "SteepestAscent.h"

class RandomRestart
{
public:
	RandomRestart();
	~RandomRestart();

	SteepestAscent steepestAscenter; // ���������������ɽ�㷨�е���ɽ��
	ChessStateGenerator generator;
	CHESS_STATE initState;
	int stateGenerated;

	RandomRestart(CHESS_STATE chessState);

	// ��ʼ��ɽ
	CHESS_STATE climbing();
private:

};

#endif