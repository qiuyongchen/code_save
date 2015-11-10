#ifndef CHESSSTATE_H
#define CHESSSTATE_H

#include <list>
#include <cstdlib>
#include <vector>
#include "ChessMan.h"

#define SIZE 8
#define random(x) (rand()%x)

/*
���̵�״̬������
�������̵�����ֵ������ֵΪ0��ʾ�Ѿ��ﵽ���ţ����ʺ��λ�ö���ȷ����
���̵Ĵ�С��
������������ηֲ��ģ������ʺ������
���������״̬�������ƶ�һ���ʺ�֮�������״̬�ļ��ϡ�

*/
class CHESS_STATE
{
public:

	int evalution; // �������̵�����ֵ
	int size; // ���̵Ĵ�С
	std::vector<CHESSMAN> chessMans; // �������ӵķֲ����
	std::vector<CHESS_STATE> nextStates; // �ƶ�һ���ʺ�֮�������״̬�ļ���

	CHESS_STATE();

	CHESS_STATE(const CHESS_STATE & s);

	CHESS_STATE(std::vector<CHESSMAN> chessMans_);

	~CHESS_STATE();

	// ���������̵�����ֵ
	int getEvalution();

	// ���ƶ�һ���ʺ�֮�������״̬�ļ���
	std::vector<CHESS_STATE> getNextStates();

	int getNextStatesSize();

	// ����ƶ�һ���ʺ�������״̬
	CHESS_STATE getRandomState();

	int getSize();

};


#endif