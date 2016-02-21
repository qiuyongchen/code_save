// Problem#: 1172
// Submission#: 4360548
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
/*

1172. Queens, Knights and Pawns

Constraints

Time Limit: 1 secs, Memory Limit: 64 MB

Description

You all are familiar with the famous 8-queens problem which asks you
to place 8 queens on a chess board so no two attack each other. In
this problem, you will be given locations of queens and knights and
pawns and asked to find how many of the unoccupied squares on the board
are not under attack from either a queen or a knight (or both). We'll
call such squares "safe" squares. Here, pawns will only serve as
blockers and have no capturing ability. The board below has 6 safe
squares. (The shaded squares are safe.)

Recall that a knight moves to any unoccupied square that is on the
opposite corner of a 2x3 rectangle from its current position; a queen
moves to any square that is visible in any of the eight horizontal,
vertical, and diagonal directions from the current position. Note
that the movement of a queen can be blocked by another piece,
while a knight's movement can not.

Input

There will be multiple test cases. Each test case will consist of
4 lines. The first line will contain two integers n and m, indicating
the dimensions of the board, giving rows and columns, respectively.
Neither integer will exceed 1000. The next three lines will
each be of the form
k r1 c1 r2 c2 ... rk ck
indicating the location of the queens, knights and pawns,
respectively. The numbering of the rows and columns will start at
one. There will be no more than 100 of any one piece. Values of
n = m = 0 indicate end of input.


Output


Each test case should generate one line of the form
Board b has s safe squares.
where b is the number of the board (starting at one) and you
supply the correct value for s.


Sample Input
4 4
2 1 4 2 4
1 1 2
1 2 3
2 3
1 1 2
1 1 1
0
1000 1000
1 3 3
0
0
0 0


Sample Output
Board 1 has 6 safe squares.
Board 2 has 0 safe squares.
Board 3 has 996998 safe squares.

˼·��
ģ���⣿ģ�������������...
*/

#include <iostream>
#include <memory.h>

// ���̴�С
int row, columns;
//  ��������
int board[1001][1001];
// �ʺ��ǰ������
int queenDir[2][8] = { { 1, 1, 0, -1, -1, -1, 0, 1 },{ 0, 1, 1, 1, 0, -1, -1, -1 } };
// ��ʿ��ǰ������
int knightDir[2][8] = { { 2, 1, -1, -2, -2, -1, 1, 2 },{ 1, 2, 2, 1, -1, -2, -2, -1 } };

bool canMove(int x, int y) {
	// Խ��
	if (x <= 0 || y <= 0 || x > row || y > columns)
	{
		return false;
	}
	// ��λ�ñ���ռ
	if (board[x][y] == 999)
	{
		return false;
	}

	return true;
}

int main() {

	int numKnight, numPawns, numQueen; // ��������

	int posKnight[1000][2], posPawns[1000][2], posQueen[1000][2]; // �������ӵ�λ��

	int caseNum = 0;
	int squaresNum = 0;

	while (std::cin >> row >> columns && row != 0 && columns != 0)
	{
		// ��ʼ�����̡�����ȫ��������
		memset(board, 0, sizeof(board));
		squaresNum = 0;

		// �����������ӵ�λ��
		std::cin >> numQueen;
		for (int i = 0; i < numQueen; i++)
		{
			std::cin >> posQueen[i][0] >> posQueen[i][1];
			board[posQueen[i][0]][posQueen[i][1]] = 999;
		}
		std::cin >> numKnight;
		for (int i = 0; i < numKnight; i++)
		{
			std::cin >> posKnight[i][0] >> posKnight[i][1];
			board[posKnight[i][0]][posKnight[i][1]] = 999;
		}
		std::cin >> numPawns;
		for (int i = 0; i < numPawns; i++)
		{
			std::cin >> posPawns[i][0] >> posPawns[i][1];
			board[posPawns[i][0]][posPawns[i][1]] = 999;
		}

		// ������лʺ��������Χ
		for (int i = 0; i < numQueen; i++)
		{
			int nextRow, nextColumn;

			// �ʺ������8������
			for (int j = 0; j < 8; j++)
			{
				nextRow = posQueen[i][0] + queenDir[0][j];
				nextColumn = posQueen[i][1] + queenDir[1][j];

				// ����ÿ�������ߵ���ͷ
				while (true)
				{
					if (canMove(nextRow, nextColumn)) {
						board[nextRow][nextColumn] = 1; // �ø��Ӳ���ȫ��
					}
					else
					{
						break;
					}

					nextRow += queenDir[0][j];
					nextColumn += queenDir[1][j];
				}
			}
		}

		// ���������ʿ��������Χ
		for (int i = 0; i < numKnight; i++)
		{
			int nextRow, nextColumn;

			// ��ʿҲ������8������
			for (int j = 0; j < 8; j++)
			{
				nextRow = posKnight[i][0] + knightDir[0][j];
				nextColumn = posKnight[i][1] + knightDir[1][j];

				if (canMove(nextRow, nextColumn)) {
					board[nextRow][nextColumn] = 1; // �ø��Ӳ���ȫ��
				}

			}
		}

		// ���������ȫ�ĸ�������
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= columns; j++) {
				if (board[i][j] == 1 || board[i][j] == 999)
				{
					squaresNum++;
				}
			}
		}

		caseNum++;
		std::cout << "Board " << caseNum << " has " << row * columns - squaresNum << " safe squares.\n";
	}
	return 0;
}

/*
��ǣ�
����ѵ��...memset�Ĵ�С��λΪ�ֽڣ�����sizeof()���á�
��ֱ�Ӵ��˸�1001 * 1001��ȥ�����԰��죬���ǿ��Թ���׼������wrong answer��
�ҾͲµ������Ǵ����ݵ��µĳ�����Ȼ������������������ʱ��
����������û����ȫ���ɾ����ݡ�

���ǽ���
*/