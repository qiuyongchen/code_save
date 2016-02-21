/*

1029. Rabbit

Constraints

Time Limit: 1 secs, Memory Limit: 32 MB

Description


The rabbits have powerful reproduction ability. One pair of adult rabbits can give birth to one pair of 
kid rabbits every month. And after m months, the kid rabbits can become adult rabbits.
As we all know, when m=2, the sequence of the number of pairs of rabbits in each month is called 
Fibonacci sequence. But when m<>2, the problem seems not so simple. You job is to calculate after d 
months, how many pairs of the rabbits are there if there is exactly one pair of adult rabbits initially. 
You may assume that none of the rabbits dies in this period.

Input

The input may have multiple test cases. In each test case, there is one line having two integers m
(1<=m<=10), d(1<=d<=100), m is the number of months after which kid rabbits can become adult rabbits, 
and d is the number of months after which you should calculate the number of pairs of rabbits. 
The input will be terminated by m=d=0.

Output

You must print the number of pairs of rabbits after d months, one integer per line.

Sample Input
2 3
3 5
1 100
0 0


Sample Output
5
9
1267650600228229401496703205376

Problem Source

ZSUACM Team Member

˼·��
    ���������ӣ��ѵ������Ӳ�����ô��
	�����������������ӣ��ټ���δ��������̡��������ж��ٳ����ã����ж������̱�����������

	���ǿ��ǵ������д��������̣�������Ҫ�ø߾��ȼӷ��������ÿ���ѧϰһ�¸߾��ȼӷ���
*/

#include <iostream>
#include <string>

// �߾��ȼӷ�
std::string bigAdd(std::string a, std::string b) {
	while (a.length() < b.length())
	{
		a = '0' + a;
	}
	while (a.length() > b.length())
	{
		b = '0' + b;
	}

	std::string sum = '0' + a;
	for (int i = 0; i < sum.length(); i++)
	{
		sum[i] = '0';
	}

	for (int i = a.length() - 1; i >= 0; i--)
	{
		sum[i + 1] += a[i] - '0' + b[i] - '0';
		if (sum[i + 1] > '9')
		{
			sum[i + 1] -= 10;
			sum[i] += 1;
		}
	}

	for (int i = 0; i < sum.length(); i++)
	{
		if (sum[i] == '0')
		{
			sum.erase(0, 1);
			i = -1;
		}
		else
		{
			break;
		}
	}

	if (sum.length() == 0)
	{
		sum = "0";
	}
	return sum;
}

int main() {
	int m, d;
	std::string sum;
	std::string a[102];
	while (std::cin >> m >> d && m != 0 && d != 0)
	{
		a[1] = "1";
		for (int i = 2; i <= d; i++)
		{
			a[i] = (i > m) ? bigAdd(a[i - m], a[i - 1]) : a[i - 1];
		}
		sum = a[d];

		// ���m��d���˺ܶ�ܶ�
		int i = d - m + 1;
		if (i < 1)
		{
			i = 1;
		}

		for (i; i <= d; i++)
		{
			sum = bigAdd(sum, a[i]);
		}

		std::cout << sum << "\n";
	}

	return 0;
}

/*
��ǣ�
    �߾��ȼӷ�������򵥡�
	�ύ��ʱ��������Runtime Error����һ㶣����룺���ѵ�������̫���ˣ���
	���Ǿ����ĵذ������С��СһЩ���ź��������������ڡ�

	������ȥ����VS2015�ϴ�������������У�������ȴû�������ҵĴ��룿
	Ī����������汾���̫�࣬��ĳЩ�ٷ�������֧�֣�
	��������ȥ��Ҳû�ҵ�ʲô�ر�ĺ�����

	����Ҳ����𣬿�����ĳЩ��������������Խ�磡
	����m = 10����d = 1����Ȼ�����⣬�����޸ģ�˳��accept��

	�������ϱߵĴ�����ʱͦ���˵�
*/