/*

1152. �򵥵�����������

Constraints

Time Limit: 1 secs, Memory Limit: 32 MB , Special Judge

Description


��һ��5 * 6�������е�ĳ��λ����һֻ���������29�����þ���������������λ�ø�һ�Σ�����һ���߷�����������·�ߣ������һ���㷨���Ӹ��������������ҳ�����һ������·�ߡ�

Ϊ�˱��ڱ�ʾһ�����̣����ǰ��մ��ϵ��£������Ҷ����̵ķ����ţ�������ʾ��

1     2     3       4     5     6

7     8     9       10    11       12

13    14       15    16       17    18

19    20       21    22       23    24

25    26       27    28       29    30
����߷��ǡ��ա�����·�ߣ����統����λ��15��ʱ�������Ե���2��4��7��11��19��23��26��28�����ǹ涨���ǲ�������������ģ������λ��1ֻ�ܵ���9��14��

Input

�����������С�ÿ��һ������N(1<=N<=30)����ʾ�����㡣���һ����-1��ʾ���������ô���

Output

�������ÿһ����㣬��һ��������·����Ӧ�����һ�У���30������������㿪ʼ��˳�������ÿ�ξ��������̷���ı�š����ڵ�������һ���ո�ֿ���

Sample Input
4
-1


Sample Output
ע�⣺���������������Ĳ�ͬ���ظ���ξ���ͬһ��������еķ���û�б����������ᱻ��Ϊ�Ǵ���ġ�

Problem Source

ZSUACM Team Member

˼·��
    �͹���PPT��˵һ�£�ʹ�û����㷨

	���ݽṹ�������£�
	struct position{int x,int y} λ�ü�¼
	position direction[8] ��¼�����һ������
	bool ifPassed[5][6] ��¼���Ƿ��߹���λ��
	int passSum ���Ѿ��ߵĲ���������29�����ɹ�����
	int passDate[5][6] ���߹���λ�õ�ʱ�䣬�������
	position start �����ʼλ��

	bool ifFound �Ƿ��Ѿ��ҵ������ν⣬���ھ����ݹ�ļ�������ͣ

	�ݹ��㷨ԭ��
	����Ѿ��ҵ��⣬ֱ�ӷ��أ�����
	��ȷ����һ����λ�ã�
	���λ���������ڶ���û�б��߹�����ô
	    ��Ǹ�λ�ã�ifPassed = true passSum++ passDate = passSum����
		��ʾ�Ѿ��߹���λ��
		���passSum == 29�����ҵ��⣬ifFind = true
		����ݹ��λ��
		����Ǹ�λ�ã�ifPassed = false passSum-- passDate = -1��
	�����㷨

	������
*/

#include <iostream>

struct position
{
	int x;
	int y;
	position() {}
	position(int a, int b) { x = a; y = b; }
};

position direction[8] = {
	position(1, -2), position(2, -1),
	position(2, 1), position(1, 2),
	position(-1, 2), position(-2, 1),
	position(-2, -1), position(-1, -2)
};

bool ifPassed[5][6];
int passSum;
int passDate[5][6];
position output[30];
position start;
bool ifFound;

void DFS(position now) {
	if (ifFound)
		return;

	position next;
	for (int i = 0; i < 8; i++)
	{
		next.x = now.x + direction[i].x;
		next.y = now.y + direction[i].y;
		if (ifPassed[next.x][next.y])
			continue;
		if (next.x >= 0 && next.x < 5 && next.y >= 0 && next.y < 6)
		{
			ifPassed[next.x][next.y] = true;
			passSum++;
			// passDate[next.x][next.y] = passSum;
			output[passSum] = next;

			if (passSum == 29)
			{
				ifFound = true;
				continue;
			}

			DFS(next);
			if (ifFound)
				return;
			ifPassed[next.x][next.y] = false;
			passSum--;
			// passDate[next.x][next.y] = -1;
		}
	}
}

int main() {
	int N;
	

	std::cin >> N;
	while (N != -1)
	{
		start.y = (N - 1) % 6;
		start.x = (N - 1) / 6;

		passSum = 0;
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 6; j++) {
				ifPassed[i][j] = false;
				// passDate[i][j] = -1;
			}

		passSum = 0;
		ifPassed[start.x][start.y] = true;
		passDate[start.x][start.y] = 0;
		output[0] = start;
		ifFound = false;
		
		DFS(start);

		for (int i = 0; i < 30; i++)
		{
			if (i == 0)
			{
				std::cout << output[i].x * 6 + output[i].y + 1;
			}
			else
			{
				std::cout << " " << output[i].x * 6 + output[i].y + 1;
			}
		}
		std::cout << std::endl;

		std::cin >> N;
	}
	return 0;
}

/*
��ǣ�
    �����������⻹���Ǽ򵥣��ݹ���ݣ�������ȣ�
*/