/*

1515. 魔版C

Constraints

Time Limit: 1 secs, Memory Limit: 32 MB , Special Judge

Description

魔板由8个大小相同方块组成，分别用涂上不同颜色，用1到8的数字表示。
其初始状态是
1 2 3 4
5 6 7 8
对魔板可进行三种基本操作：
A操作（左右两列互换）：
3 4 1 2
7 8 5 6
B操作（每次以行循环左移一个）：
2 3 4 1
6 7 8 5
C操作（中间四小块逆时针转一格）：
1 3 7 4
5 2 6 8
用上述三种基本操作，可将任一种状态转换成另一种状态。

Input

输入包括多个要求解的魔板，每个魔板用三行描述。
第一行步数N（N<=100），表示最多容许的步数。
第二、第三行表示目标状态，按照魔板的形状，颜色用1到8的表示。
当N等于-1的时候，表示输入结束。

Output


对于每一个要求解的魔板，输出一行。
首先是一个整数M，表示你找到解答所需要的步数。接着若干个空格之后，从第一步开始按顺序给出M步操作（每一步是A、B或C），相邻两个操作之间没有任何空格。
注意：如果不能达到，则M输出-1即可。


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

思路：
这题与之前的魔板差不多，ABC三个操作改变了一点，其它的都没变
我只是担心会无脑超时。

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
}; // 队列节点

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
	int i = qm.front().x / 1000; // 千位
	int j = qm.front().x - i * 1000;
	int a = j / 100; // 百位
	int b = (j - a * 100) / 10; // 十位
	int i1 = qm.front().y / 1000; // 千位
	int j1 = qm.front().y - i1 * 1000;
	int a1 = j1 / 100; // 百位
	int b1 = (j1 - a1 * 100) / 10; // 十位
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

		// 如果初始状态就是解，或者步数为0
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
			// 步数超出限制
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
后记：
    还是set简单好用，其它的都是浮云
	多个case的时候，还是得注意全局变量的初始化，一个弄不好，所有case就挤在同一个全局变量里
*/