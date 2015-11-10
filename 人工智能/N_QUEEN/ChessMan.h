#ifndef CHESSMAN_H
#define CHESSMAN_H

#include <list>
#include <math.h>
#define SIZE 8

/*
 ����
*/
class CHESSMAN
{
public:
	int row;
	int column;

	CHESSMAN() {}
	~CHESSMAN() {}

	CHESSMAN(int r, int c);

	int getRow();

	int getColumn();

	void setRow(int r);

	void setColumn(int c);

	// �����ʺ�֮���Ƿ��ͻ
	bool isConfig(CHESSMAN & chessMan);

	// ĳһ�еĻʺ������ƶ�offset������
	void action(int offset);

private:

};

#endif