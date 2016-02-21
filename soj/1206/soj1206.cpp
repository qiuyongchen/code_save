/*
1206. Stacking Cylinders

Constraints

Time Limit: 1 secs, Memory Limit: 32 MB

Description


Problem Cylinders (e.g. oil drums) (of radius 1 foot) are stacked in a rectangular bin.
Each cylinder on an upper row rests on two cylinders in the row below.
The cylinders in the bottom row rest on the floor and do not roll from their original positions.
Each row has one less cylinder than the row below.



\epsfbox{p3498.eps}

This problem is to write a program to compute the location of the center of the top cylinder from
the centers of the cylinders on the bottom row. Computations of intermediate values should use double precision.


Input

The input begins with a line containing the count of problem instances, nProb , as a decimal integer,
(1<=nProb<=1000) . This is followed by nProb input lines. An input line consists of the number, n ,
of cylinders on the bottom row followed by n floating point values giving the x coordinates of
the centers of the cylinders (the y coordinates are all 1.0 since the cylinders are resting on the
floor (y = 0.0 )). The value of n will be between 1 and 10 (inclusive). The distance between
adjacent centers will be at least 2.0 (so the cylinders do not overlap) and at most 3.4
(so cylinders at level k cannot touch cylinders at level k - 2 ).

Output


The output for each data set is a line containing the problem number (1...nProb) ,
a colon, a space, the x coordinate of the topmost cylinder to 4 decimal places, a
space and the y coordinate of the topmost cylinder to 4 decimal places (both x and
y ROUNDED to the nearest digit).

Note: To help you check your work, the x -coordinate of the center of the top cylinder
should be the average of the x -coordinates of the leftmost and rightmost bottom cylinders.



Sample Input
5
4 1.0 4.4 7.8 11.2
1 1.0
6 1.0 3.0 5.0 7.0 9.0 11.0
10 1.0 3.0 5.0 7.0 9.0 11.0 13.0 15.0 17.0 20.4
5 1.0 4.4 7.8 11.2 14.6


Sample Output
1: 6.1000 4.1607
2: 1.0000 1.0000
3: 6.0000 9.6603
4: 10.7000 15.9100
5: 7.8000 5.2143

˼·��
    �ǳ�����ļ���ͼ�Σ�
	�ϲ��Բ���²��ұߵ�һ��Բ֮���γ�ֱ�������Σ�������ױ߾�������ӣ����յó������
*/


#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>

int main() {
	int nProb;
	int n;
	double cylinders[11], temp;
	double height;
	double part;

	std::cin >> nProb;
	for (int i = 1; i <= nProb; i++)
	{
		
		std::cin >> n;
		for (int j = 0; j < n; j++)
		{
			std::cin >> cylinders[j];
		}

		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (cylinders[i] > cylinders[j])
				{
					temp = cylinders[i];
					cylinders[i] = cylinders[j];
					cylinders[j] = temp;
				}
			}
		}

		height = 1.0;
		for (int i = 1; i < n; i++)
		{
			part = sqrt(2 * 2 - ((cylinders[i] - cylinders[i - 1]) / 2) * ((cylinders[i] - cylinders[i - 1]) / 2));
			height += part;
		}

		std::cout << i << ": " << std::fixed << std::setprecision(4) << (cylinders[0] + cylinders[n - 1]) / 2 << " " << height << "\n";
	}
	
	return 0;
}

/**
n��n�У�a[n][n]��b[n]��x[n]��
ע�⣺����a�Ͳ���x����ָ����ʽ����ȥ�ģ����ǵ�ֵ�ᱻ�޸ģ�
*/
bool GaussElimination(int n, double a[], double b[], double *x) {
	int q[100] = { 0 };

	int i, j, k, p;
	double MAX, L;

	// ɨ�������У���������Ԫ
	for (k = 0; k < n; k++) {
		// ѡ����k���о���ֵ����ֵMAX�����ҳ���ֵ���ڵ���p
		p = 0; MAX = 0;
		for (i = 0; i < n; i++)
		{
			if (q[i] == 0 && MAX + pow(10, -10) < abs(a[i * n + k]))
			{
				MAX = abs(a[i * n + k]);
				p = i;
			}
		}

		// ������ֵ��0��˵���޽������������
		if (MAX == 0)
		{
			return false;
		}
		// �Ѿ��������p�����ϱ��
		else
		{
			q[p] = 1;
		}

		// ��p�г���һ���ʵ���ϵ����ӵ��������ϣ�ʹ��k����ֻ��һ����0ֵ
		for (i = 0; i < n; i++)
		{
			if (i != p)
			{
				// �����ϵ��
				L = a[i * n + k] / a[p * n + k];
				for (j = 0; j < n; j++)
				{
					a[i * n + j] = a[i * n + j] - L * a[p * n + j];
				}
				b[i] = b[i] - L * b[p];
			}
		}


	}

	// ���x
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (abs(a[i * n + j] > pow(10, -10)))
			{
				x[j] = b[i] / a[i * n + j];
			}
		}
	}

	return true;
}

/*
��ǣ�
    �ƺ���������ˣ���ʱû���ύ��ȥ��
	�õģ�accept��
*/