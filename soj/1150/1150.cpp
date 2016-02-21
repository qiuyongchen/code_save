#include <iostream>

/*********************************************************************
  ���⿴�����ƺ�ͦ����ģ��㷨Ҳ���ˣ�����һ����ʵ�֡�
  �����ö��������������֮��ģ�����ǰ������û��������

*****************************************************************/

const int MAX = 8100; // ������ĳ���
struct qt
{
	int x, y;
	char op;
	int pre;
	qt(int xx, int yy, char opop, int prepre) {
		x = xx;
		y = yy;
		op = opop;
		pre = prepre;
	}
	qt() {
		x = 0;
		y = 0;
		op = 0;
		pre = 0;
	}
}; // ���нڵ�

struct qt qm[MAX]; // ����
int  xx, yy, m, n, fp, rp;
char sop[300];
bool flag;

void compAndAdd(char opx) {
	bool fg = true;
	for (int i = 1; i <= rp; i++)
	{
		if ((m == qm[i].x) && (n == qm[i].y)) {
			fg = false;
			break;
		}
	}

	if (fg)
	{
		rp++;
		qm[rp].x = m;
		qm[rp].y = n;
		qm[rp].op = opx;
		qm[rp].pre = fp;
		if (m == xx && n == yy)
		{
			flag = false;
		}
	}
}

void A() {
	if (!flag)
	{
		return;
	}
	m = qm[fp].y;
	n = qm[fp].x;
	compAndAdd('A');
}

void B() {
	if (!flag)
	{
		return;
	}
	m = (qm[fp].x % 10) * 1000 + (qm[fp].x / 10);
	n = (qm[fp].y % 10) * 1000 + (qm[fp].y / 10);
	compAndAdd('B');
}

void C() {
	if (!flag)
	{
		return;
	}
	int i = (qm[fp].x / 1000) * 1000;
	int j = qm[fp].x - i; 
	int a = j / 100;
	int b = (j - a * 100)/ 10;
	int i1 = (qm[fp].y / 1000) * 1000;
	int j1  = qm[fp].y - i1;
	int c = j1 / 100;
	int d = (j1 - c * 100)/ 10;
	m = i + c * 100 + a * 10 + (qm[fp].x % 10);
	n = i1 + d * 100 + b * 10 + (qm[fp].y % 10);
	compAndAdd('C');
}

void Printop() {
	int j = 1;
	int i = qm[rp].pre;
	sop[j] = qm[rp].op;
	while (i != 0)
	{
		j++;
		sop[j] = qm[i].op;
		i = qm[i].pre;
	}
	std::cout << j - 1 << " ";
	for (int i = j - 1; i > 0; i--)
	{
		std::cout << sop[i];
	}
	std::cout << "\n";
}

int main() {
	int N;
	std::cin >> N;
	while (N != -1)
	{
		int a, b, c, d;
		std::cin >> a >> b >> c >> d;
		xx = a * 1000 + b * 100 + c * 10 + d;
		std::cin >> a >> b >> c >> d;
		yy = a * 1000 + b * 100 + c * 10 + d;

		m = 0;
		n = 0;
		fp = 1;
		rp = 1;
		flag = true;

		qm[1] = qt(1234, 8765, 'x', 0);
		sop[0] = 'x';

		while (flag)
		{
			A();
			B();
			C();
			fp++;
		}

		Printop();

		std::cin >> N;
	}

	return 0;
}

/** *
    ��ǣ�
	     struct��Ĭ�Ϲ��캯����CLASSһ���������βΡ�
		 �ÿ�����������ʱ�򣬶�����������ܡ�xpϵͳ����֮ǰ��֪��Ϊʲô��vs2015���Ǳ���
		 �쳣������һ�£�����һ������Ī�����������Ī������ĵط������˺�һ�ᣬ
		 �������½���ʾ˵ʲô���ز���***֮��ģ�����һ�£���Ȼ�Ϳ����ˣ��������ˣ�����
		 ������ϸ��һ�µ������������⡣
* */