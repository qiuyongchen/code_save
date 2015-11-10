#ifndef CHESSSTATE_H
#define CHESSSTATE_H

#include <list>
#include <vector>
#include <set>
#include "ChessMan.h"

#define SIZE 9
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
	double ddd = 0.001;

	int evalution; // �������̵�����ֵ
	int size; // ���̵Ĵ�С
	std::vector<int> chessMans; // �������ӵķֲ����
	std::vector<CHESS_STATE> nextStates; // �ƶ�һ���ʺ�֮�������״̬�ļ���

	CHESS_STATE();

	CHESS_STATE(const CHESS_STATE & s);

	CHESS_STATE(std::vector<int> chessMans_);

	~CHESS_STATE();

	// ���������̵�����ֵ
	int getEvalution();

	bool calculateLinearConflict(int ai, int aj, int bi, int bj, int aGoalI, int aGoalJ, int bGoalI, int bGoalJ);

	bool isTheSame(double a, double b);

	int calculateManhattanDistance(int ai, int aj, int bi, int bj);

	// ���ƶ�һ���ʺ�֮�������״̬�ļ���
	std::vector<CHESS_STATE> getNextStates();

	int getNextStatesSize();

	// ����ƶ�һ���ʺ�������״̬
	CHESS_STATE getRandomState();

	int getSize();

	void setSize(int size_);

private:

};


#endif