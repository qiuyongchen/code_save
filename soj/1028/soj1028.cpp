/*

1028. Hanoi Tower Sequence

Constraints

Time Limit: 1 secs, Memory Limit: 32 MB

Description


Hanoi Tower is a famous game invented by the French mathematician Edourard Lucas in 1883.
We are given a tower of n disks, initially stacked in decreasing size on one of three pegs.
The objective is to transfer the entire tower to one of the other pegs, moving only one
disk at a time and never moving a larger one onto a smaller.

The best way to tackle this problem is well known: We first transfer the n-1 smallest to a
different peg (by recursion), then move the largest, and finally transfer the n-1 smallest
back onto the largest. For example, Fig 1 shows the steps of moving 3 disks from peg 1 to peg 3.


Now we can get a sequence which consists of the red numbers of Fig 1: 1, 2, 1, 3, 1, 2, 1. The
ith element of the sequence means the label of the disk that is moved in the ith step. When n = 4,
we get a longer sequence: 1, 2, 1, 3, 1, 2, 1, 4, 1, 2, 1, 3, 1, 2, 1. Obviously, the larger n is,
the longer this sequence will be.
Given an integer p, your task is to find out the pth element of this sequence.


Input


The first line of the input file is T, the number of test cases.
Each test case contains one integer p (1<=p<10^100).


Output


Output the pth element of the sequence in a single line. See the sample for the output format.
Print a blank line between the test cases.



Sample Input
4
1
4
100
100000000000000

Sample Output
Case 1: 1

Case 2: 3

Case 3: 3

Case 4: 15

Problem Source

ZSUACM Team Member

˼·��
	��ŵ�����⡣
	�ȰѶ���n-1�����Ӱᵽ��ʱ�����ϣ��ٽ����İᵽĿ�����ӣ������ʱ�����ϵ�n-1������Ҳ�ᵽĿ�������ϡ�
	��ν�����n-1�����Ӱᵽ��ʱ���ӣ�ͬ������ʱ���ӿ���Ŀ�����ӣ���Ŀ�����ӿ�����ʱ���ӣ����ϵصݹ顣

	����̫���ˣ����Ⲣ���Ǻ�ŵ�����⣬���Ǹ߾��ȳ�����
*/

#include <iostream>
#include <string.h>

int main() {
	int testCase;
	std::cin >> testCase;

	char p[200];
	long long int ans, n;
	for (int i = 1; i <= testCase; i++)
	{
		ans = 0;
		std::cin >> p;

		int L = strlen(p);
		// �߾��ȵĴ�����
		for (n = 1; ;n++)
		{
			// ����Ǹ�����
			if ((p[L - 1] - '0') % 2 == 1)
			{
				ans = n;
				break;
			}
			// �����ż��
			else
			{
				for (int i = L - 1; i >= 0; i--)
				{
					if ((p[i] - '0') % 2 == 1)
					{
						p[i + 1] = p[i + 1] + 5;
					}
					p[i] = (p[i] - '0') / 2 + '0';

				}
			}
		}

		std::cout << "Case " << i << ": " << ans << "\n";
		if (i != testCase)
		{
			std::cout << "\n";
		}

	}
	return 0;
}

/*
��ǣ�
    ���ι�����һ��û������Ϊ��û����ö���Ŀ��С�
	�߾��ȳ�����Ҳ�����ر���ѡ�
*/