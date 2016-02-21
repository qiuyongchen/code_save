/*

1515. ħ��C

Constraints

Time Limit: 1 secs, Memory Limit: 32 MB , Special Judge

Description

ħ����8����С��ͬ������ɣ��ֱ���Ϳ�ϲ�ͬ��ɫ����1��8�����ֱ�ʾ��
���ʼ״̬��
1 2 3 4
5 6 7 8
��ħ��ɽ������ֻ���������
A�������������л�������
3 4 1 2
7 8 5 6
B������ÿ������ѭ������һ������
2 3 4 1
6 7 8 5
C�������м���С����ʱ��תһ�񣩣�
1 3 7 4
5 2 6 8
���������ֻ����������ɽ���һ��״̬ת������һ��״̬��

Input

����������Ҫ����ħ�壬ÿ��ħ��������������
��һ�в���N��N<=100������ʾ�������Ĳ�����
�ڶ��������б�ʾĿ��״̬������ħ�����״����ɫ��1��8�ı�ʾ��
��N����-1��ʱ�򣬱�ʾ���������

Output


����ÿһ��Ҫ����ħ�壬���һ�С�
������һ������M����ʾ���ҵ��������Ҫ�Ĳ������������ɸ��ո�֮�󣬴ӵ�һ����ʼ��˳�����M��������ÿһ����A��B��C����������������֮��û���κοո�
ע�⣺������ܴﵽ����M���-1���ɡ�


Sample Input
4
4 1 2 3
8 5 6 7
2
1 2 3 4
5 6 7 8
0
1 3 7 4
5 2 6 8
-1


Sample Output
2 AB
0
-1

Problem Source

2007???????????

˼·��
������֮ǰ��ħ���࣬ABC���������ı���һ�㣬�����Ķ�û��
��ֻ�ǵ��Ļ����Գ�ʱ��

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
	m = (qm.front().x % 100) * 100 + (qm.front().x / 100);
	n = (qm.front().y % 100) * 100 + (qm.front().y / 100);
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
	m = (qm.front().x % 1000) * 10 + (qm.front().x / 1000);
	n = (qm.front().y % 1000) * 10 + (qm.front().y / 1000);
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
	int i = qm.front().x / 1000; // ǧλ
	int j = qm.front().x - i * 1000;
	int a = j / 100; // ��λ
	int b = (j - a * 100) / 10; // ʮλ
	int i1 = qm.front().y / 1000; // ǧλ
	int j1 = qm.front().y - i1 * 1000;
	int a1 = j1 / 100; // ��λ
	int b1 = (j1 - a1 * 100) / 10; // ʮλ
	m = i * 1000 + b * 100 + b1 * 10 + (qm.front().x % 10);
	n = i1 * 1000 + a * 100 + a1 * 10 + (qm.front().y % 10);
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

		qm.push(qt(1234, 5678, 'x', ""));
		xy.insert(1234 * 10000 + 5678);

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
    ����set�򵥺��ã������Ķ��Ǹ���
	���case��ʱ�򣬻��ǵ�ע��ȫ�ֱ����ĳ�ʼ����һ��Ū���ã�����case�ͼ���ͬһ��ȫ�ֱ�����
*/