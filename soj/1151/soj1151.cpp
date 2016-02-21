/*

1151. ħ��


Constraints

Time Limit: 1 secs, Memory Limit: 32 MB , Special Judge


Description


��Ŀ��A����ͬ�����������ǰ����ݷ�Χ����N���ܳ���10��
����ϸ���Ǹ��������


Input


����������Ҫ����ħ�壬ÿ��ħ��������������

��һ�в���N����ʾ�������Ĳ�����

�ڶ��������б�ʾĿ��״̬������ħ�����״����ɫ��1��8�ı�ʾ��
��N����-1��ʱ�򣬱�ʾ���������


Output


����ÿһ��Ҫ����ħ�壬���һ�С�

������һ������M����ʾ���ҵ��������Ҫ�Ĳ������������ɸ��ո�֮�󣬴ӵ�һ����ʼ��˳�����M��������ÿһ����A��B��C����������������֮��û���κοո�
ע�⣺������ܴﵽ����M���-1���ɡ�


Sample Input
4
5 8 7 6
4 1 2 3
3
8 7 6 5
1 2 3 4
-1


Sample Output
2  AB
1  A


���֣�M����N���߸����Ĳ�������ȷ�����ܵ÷֡�

Problem Source

ZSUACM Team Member

˼·��
	����Ľⷨ��soj1150��ͬ����ͬ���ǣ�����Ҫ�Ż���
	���Ի��òο�soj1515�ļ�֦�������������ų��Ѿ����ֵ�ħ��

*/
#include <iostream>
#include <memory.h>
#include <queue>
#include <set>
#include <string>


struct qt
{
	int x, y;
	char op;
	std::string pre;
	qt(int xx, int yy, char opop, std::string prepre) {
		x = xx;
		y = yy;
		op = opop;
		pre = prepre;
	}
	qt() {
		x = 0;
		y = 0;
		op = 0;
		pre = "";
	}
}; // ���нڵ�

std::queue<qt> qm;
std::set<int> xy;
int  xx, yy, m, n, fp, rp;
bool flag;

void Add(char opx) {
	qm.push(qt(m, n, opx, qm.front().pre + opx));
	if (m == xx && n == yy)
	{
		flag = false;
	}
}

void A() {
	if (!flag)
	{
		return;
	}


	m = qm.front().y;
	n = qm.front().x;

	//	m = (qm.front().x % 100) * 100 + (qm.front().x / 100);
	//	n = (qm.front().y % 100) * 100 + (qm.front().y / 100);
	if (xy.insert(m * 10000 + n).second)
	{
		Add('A');
	}
}

void B() {
	if (!flag)
	{
		return;
	}
	m = (qm.front().x % 10) * 1000 + (qm.front().x / 10);
	n = (qm.front().y % 10) * 1000 + (qm.front().y / 10);

	//	m = (qm.front().x % 1000) * 10 + (qm.front().x / 1000);
	//	n = (qm.front().y % 1000) * 10 + (qm.front().y / 1000);
	if (xy.insert(m * 10000 + n).second)
	{
		Add('B');
	}
}

void C() {
	if (!flag)
	{
		return;
	}
	int i = (qm.front().x / 1000) * 1000;
	int j = qm.front().x - i;
	int a = j / 100;
	int b = (j - a * 100) / 10;
	int i1 = (qm.front().y / 1000) * 1000;
	int j1 = qm.front().y - i1;
	int c = j1 / 100;
	int d = (j1 - c * 100) / 10;
	m = i + c * 100 + a * 10 + (qm.front().x % 10);
	n = i1 + d * 100 + b * 10 + (qm.front().y % 10);

/*	int i = qm.front().x / 1000; // ǧλ
	int j = qm.front().x - i * 1000;
	int a = j / 100; // ��λ
	int b = (j - a * 100) / 10; // ʮλ
	int i1 = qm.front().y / 1000; // ǧλ
	int j1 = qm.front().y - i1 * 1000;
	int a1 = j1 / 100; // ��λ
	int b1 = (j1 - a1 * 100) / 10; // ʮλ
	m = i * 1000 + b * 100 + b1 * 10 + (qm.front().x % 10);
	n = i1 * 1000 + a * 100 + a1 * 10 + (qm.front().y % 10);*/

	if (xy.insert(m * 10000 + n).second)
	{
		Add('C');
	}
}

int main() {
	int N;
	std::cin >> N;
	//N = 4;
	while (N != -1)
	{
		while (!qm.empty())
		{
			qm.pop();
		}
		xy.clear();

		int a, b, c, d;
		std::cin >> a >> b >> c >> d;
		xx = a * 1000 + b * 100 + c * 10 + d;
		//xx = 4123;
		std::cin >> a >> b >> c >> d;
		yy = a * 1000 + b * 100 + c * 10 + d;
		//yy = 8567;

		m = 0;
		n = 0;

		// �����ʼ״̬���ǽ⣬���߲���Ϊ0
		if (xx == 1234 && yy == 5678 || N == 0)
		{
			flag = false;
		}
		else
		{
			flag = true;
		}

		qm.push(qt(1234, 8765, 'x', ""));
		xy.insert(1234 * 10000 + 8765);

		while (flag && !qm.empty())
		{
			A();
			B();
			C();
			qm.pop();
			// ������������
			if (qm.back().pre.size() > N)
			{
				flag = false;
				break;
			}
		}

		if (qm.back().x == xx && qm.back().y == yy)
		{
			if (qm.back().pre.size() > 0)
			{
				std::cout << qm.back().pre.size() << " " << qm.back().pre << "\n";
			}
			else
			{
				std::cout << "0\n";
			}
		}
		else
		{
			std::cout << "-1\n";
		}

		std::cin >> N;
	}

	return 0;
}

/*
��ǣ�
    ����һ�ι���
	����д���ⱨ���ˡ�
*/