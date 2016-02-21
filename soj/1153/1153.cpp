/*

  ע�����հ���soj1152�����εĴ��룬��û�о����κ��޸ĵ�����£����س�ʱ������������û�ܳ�һ���⣩
  ������Ҫ�Ż�һ�£��Ż��ķ�����Ҳ������ν�ġ���ĳ�������ߺ��ܼ����ߵķ���Խ�٣�С���Խϲ������
  ���������ߺ󣬻�����4�����������ߺ󣬻�����3������С����������±ߡ�

*/

#include <iostream>

// λ������
struct position
{
	int x;
	int y;
	int Heuristic; // С����ڸ�λ�����ߵĵķ��������
	position() {}
	position(int a, int b) { x = a; y = b; Heuristic = 0; }
};

// С������ߵķ�������ڵ�ǰλ�õ�offset
position direction[8] = {
	position(1, -2), position(2, -1),
	position(2, 1), position(1, 2),
	position(-1, 2), position(-2, 1),
	position(-2, -1), position(-1, -2)
};

bool ifPassed[8][8]; // ��¼�������̵ġ����������
int passSum;
position output[64];
position start;
bool ifFound; // �Ƿ��Ѿ��ҵ���ı�־

// ��������������ֵ�Ǹ�������ġ��������߷��򡱵�����
int getHeuristic(position pos) {
	int Heuristic = 0;
	int i = 8;
	for (int i = 0; i < 8; i++)
	{
		if (pos.x + direction[i].x >= 0 && pos.x + direction[i].x < 8 && pos.y + direction[i].y >= 0 && pos.y + direction[i].y < 8)
		{
			Heuristic++;
		}
	}
	return Heuristic;
}

void DFS(position now) {
	if (ifFound)
		return;

	// ��������������������������
	for (int i = 0; i < 8; i++)
	{
		direction[i].Heuristic = getHeuristic(position(now.x + direction[i].x, now.y + direction[i].y));
	}

	// ������ֵ��С�ķ����ǰ�棬������
	position temp;
	for (int i = 0; i < 7; i++)
	{
		for (int j = i + 1; j < 8; j++) {
			if (direction[i].Heuristic > direction[j].Heuristic)
			{
				temp = direction[i];
				direction[i] = direction[j];
				direction[j] = temp;
			}
		}
	}

	// С������������ߣ���Ȼ�����ÿ��÷����ܷ��ߣ���Ȼ��ײǽ���ص����ޡ��ˣ�
	position next;
	for (int i = 0; i < 8; i++)
	{
		next.x = now.x + direction[i].x;
		next.y = now.y + direction[i].y;

		// ���С����Ѿ��߹��÷���
		if (ifPassed[next.x][next.y])
			continue;

		// ȷ��û��ײǽ
		if (next.x >= 0 && next.x < 8 && next.y >= 0 && next.y < 8)
		{
			ifPassed[next.x][next.y] = true;
			passSum++;
			output[passSum] = next;

			if (passSum == 63)
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
		start.y = (N - 1) % 8;
		start.x = (N - 1) / 8;

		passSum = 0;
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++) {
				ifPassed[i][j] = false;
				// passDate[i][j] = -1;
			}

		passSum = 0;
		ifPassed[start.x][start.y] = true;
		output[0] = start;
		ifFound = false;

		DFS(start);

		for (int i = 0; i < 64; i++)
		{
			if (i == 0)
			{
				std::cout << output[i].x * 8 + output[i].y + 1;
			}
			else
			{
				std::cout << " " << output[i].x * 8 + output[i].y + 1;
			}
		}
		std::cout << std::endl;

		std::cin >> N;
	}
	return 0;
}

/*
 ��ǣ���Ȼ����һ�ξ͹�����ô��������...
       �ҽ�����ѡ�˺�������չ�������ٵķ�����ѣ���Ȼ˲�佫�������㲻���Ľ��������ˣ��㷨����һ������Ķ�����
	   ��ʵ�ϣ�����㷨���������������������̵ı�Ե�ߣ����ߵ����̵����ģ�ĳ�̶ֳ���������ʽ�㷨��
	   ���������Ǽ����������չ������
*/