/*************************

1050. Numbers & Letters


Constraints

Time Limit: 3 secs, Memory Limit: 32 MB


Description

In the early 80��s, a popular TV show on Dutch television was ��Cijfers en Letters�� (Numbers and Letters). This game consisted of two game elements, in which the main goal was to outclass your opponent. Letters is a game in which you are given a number of letters with which you should form the longest Dutch word possible. Since Dutch is a very hard language to learn we will postpone implementation of this game element until after the contest.
For the second game element ��Numbers�� 5 different numbers are chosen, together with a target number. The aim is to use some arithmetic on (some of) the five numbers to form the target number. Each number can be used only once. It might not be possible to form the target number given the input numbers, in that case the largest number smaller than the target number that can be calculated should be given. The only mathematical operations allowed are: +, -, *, /.  All intermediate results should be integers, so division is not always allowed (e.g. (2*2)/4 is OK, but 2*(2/4) is not).
Examples:
- If the 5 numbers are 1, 2, 3, 7 and 100 and the target number is 573, the target number can be reached as follows: (((100-1)*2)-7)*3. -If the 5 numbers are 3, 26, 78, 12 and 17, and the target number is 30, the target number can be reached as follows: (78*3)-(12*17).
- If the 5 numbers are 67, 69, 58, 22, 2, and the target number is 929, the target number cannot be reached, but the largest number smaller than the target number that can be reached is 923 = (22-(67-58))*(69+2).
Your assignment is to write a program that calculates the best approximation from below of the target number using arithmetic on the 5 given numbers. Note that if it is not possible to reach the exact number, you should give the largest reachable number below the target number.


Input

The first line contains the number of runs, N. The next N lines consist of six numbers separated by a space. The first 5 numbers Mi, 1��Mi��100, are the numbers you can use to calculate the target number. The sixth number is the target number T, 0��T��1000.


Output

The output consists of N rows, each containing the best approximation of the target number using the 5 given numbers.


Sample Input
3
1 2 3 7 100 573
3 26 78 12 17 30
67 69 58 22 2 929


Sample Output
573
30
923

˼·��
    �ƺ���ȫû��������ʾ�ǻ���
	��λ��ݣ�
	Ҫ����5���������ϣ���Ϸ�ʽҲ������������
	����������ô�

	��ʵ�������ɣ���5������
	������һ��������������4���ӽڵ㣬ÿ���ӽڵ���3
	�����ӽڵ㣬ÿ�����ӽڵ�����2��...
	�Դ����ƣ��޴�������ò�����Ҫ�������ɡ�

	Ӧ�ò��ᣬ��ֻ�ǿó���������һ�������������ݽṹ
	�����õݹ�ʵ�ֵİ�

	�����㷨�������ģ��ȴ�5��������ʼ��ÿһ����
	������4���ӽڵ㣬��4���ӽڵ�Ĵ�����������
	һ�����������һ��ֻ��һ���ӽڵ㣬ֱ�ӷ��ظ��ӽڵ�

	�ţ����ֿ��������᣿�ƺ������ԣ��ðɡ�
	���������ʵ�֣���ô��Ҫһ��flag���飬���ڱ���ĸ�
	�����Ѿ���ʹ�õ���

	ÿ�ݹ�һ�Σ�������һ��������������ţ���
	ֱ�ӷ�����

	������Ҫ�ݹ�5�㡣

	�Ǽ���Ľ�����������أ�
	�����Ҫ����the best approximation from below of the target number using arithmetic on the 5 given numbers. Note that if it is not possible to reach the exact number, you should give the largest reachable number below the target number.
	������Ŀ��ֵ��ͬ������ﲻ����Ҳ����Ǳ�Ŀ��С�����ֵ

	�����Ļ���������Ҫ����ĳ��·�������еĽ��������һ�����飿
	��Ϊ�ǻ��ݣ����ԴӸ�������֮�󣬱����޸��������һ��һ����Чֵ��
	��Ӧ��ĳ��·�������һ���ӽڵ��Ҷ�ӽڵ㡣

	�ݹ������ˣ���ô�߽�������ʲô��
	��������һ�㣨����㣩���ǿ϶�Ҫ��ͷ��
	����һ������5���������Ի�������ı߽�������
	���Ŀǰ����õ��Ľ���У��Ѿ���ֵ�ﵽ��Ŀ��ֵ��
	��ҲҪ���ء�

	�Ƿ��صĽ����ʲô��
	�����Ŀ��ֵ����ȻҲ�����ܴ������������ֵ
	��Ҫʵʱ���µģ�ÿ����չҶ��ǰ��������һ�·���ֵ
	����ֵ�ķ�Χ�޶���Ŀ��ֵ�����ֵ���͡����з���ֵ��֮�䣬
	�����Ļ�������ֵ��Խ�ݹ�Խ�󣬾�������·���������ˣ�
	�������õ��ķ���ֵ������Ӱ�죬�Ͼ��Ǹ�����ֵ����������

	�������ݽṹ�ǣ�
	    int number[5] �û������5����
		bool flag[5] ���ĳ�����Ƿ�ʹ��
		int result[5]��Ҳ����·���ϵ����н����
	    int target Ŀ��ֵ
		int fakeTarget �Ѿ����������ֵ���������յ����
	���������У�
	    DD(int remain) �ݹ麯����������ʾ�����ж��ٸ���δ����
		               ���㡱

*/

#include <iostream>
int number[5];
bool flag[5];
int result[5];
int target;
int fakeTarget;

void DD(int remain) {
	
	for (int i = 0; i < remain; i++)
	{
		if (number[i] <= target && number[i] > fakeTarget)
			fakeTarget = number[i];
	}

	if (remain == 1) // ע�⣺���remainΪ0��˵�����������Ѿ��������㣬ֻʣ�����ս��
		return;
	if (fakeTarget == target)
		return;

	if (remain == 5) // ��һ��ĳ�ʼ��
	{
		for (int i = 0; i < 5; i++)
		{
			flag[i] = false;
		}
	}
	
	for (int i = 0; i < remain; i++)
	{
		for (int j = i + 1; j < remain; j++)
		{
			int A = number[i];
			int B = number[j];
			number[j] = number[remain - 1];

			number[i] = A + B;
			DD(remain - 1);
			number[i] = A - B;
			DD(remain - 1);
			number[i] = B - A;
			DD(remain - 1);
			number[i] = A * B;
			DD(remain - 1);

			if (B != 0 && A % B == 0) {
				number[i] = A / B;
				DD(remain - 1);
			}
			if (A != 0 && B % A == 0) {
				number[i] = B / A;
				DD(remain - 1);
			}

			flag[j] = true;

			number[i] = A;
			number[j] = B;
		}
	}
}

int main() {
	int N;
	std::cin >> N;

	while (N--)
	{
		fakeTarget = -999999999;
		for (int i = 0; i < 5; i++)
		{
			std::cin >> number[i];
			flag[i] = false;
			result[i] = 0;
		}
		std::cin >> target;
		DD(5);
		std::cout << fakeTarget << std::endl;
	}
	return 0;
}

/**
��֪���ˣ���������ݹ麯���Ǵ���ģ���Ϊ��ÿ��ֻ��һ�����������㣬
����(67-58)*(69+2)������ʽ������GG�ˡ�

void DD(int remain) {
	if (remain == 0) // ע�⣺���remainΪ0��˵�����������Ѿ��������㣬ֻʣ�����ս��
		return;
	if (fakeTarget == target)
		return;
	for (int i = 0; i < 5; i++)
	{
		if (result[i] <= target && result[i] > fakeTarget)
			fakeTarget = result[i];
	}

	if (remain == 5) // ��һ��ĳ�ʼ��
	{
		for (int i = 0; i < 5; i++)
		{
			if (flag[i]) continue;
			flag[i] = true; // ʹ�ø���
			result[0] = number[i];
			DD(remain - 1);
			flag[i] = false;
		}
	}
	else
	{
		for (int j = 0; j < 5; j++)
		{
			if (flag[j]) continue;
			flag[j] = true; // ʹ�ø���

			result[5 - remain] = result[5 - remain - 1] + number[j];
			DD(remain - 1);
			result[5 - remain] = result[5 - remain - 1] - number[j];
			DD(remain - 1);
			result[5 - remain] = number[j] - result[5 - remain - 1];
			DD(remain - 1);
			result[5 - remain] = result[5 - remain - 1] * number[j];
			DD(remain - 1);

			if (number[j] != 0 && result[5 - remain - 1] % number[j] == 0) {
				result[5 - remain] = result[5 - remain - 1] / number[j];
				DD(remain - 1);
			}
			if (result[5 - remain - 1] != 0 && number[j] % result[5 - remain - 1] == 0) {
				result[5 - remain] = number[j] / result[5 - remain - 1];
				DD(remain - 1);
			}

			flag[j] = false;
		}
	}
}

�ǽ���ķ����ǣ�ÿ�������ѡ2�����������㣬�����ǽ��ϴν�������һ���������㡣
**/

/*******
��ǣ�
    ��Ȼ������������
	����Ҳ�ǹ���
	�������ѡ�������㷨����Ҳ�ǿ�ѧ�Եģ�ȷʵ�
	����һ��������Ǹ�result����Ļ���ָ�������ѶȺ͸��Ӷȶ�����������������
	�����Ҿ���Э�ˡ�

	ֵ��ע����Ǳ߽�
		if (remain == 1) // ע�⣺���remainΪ0��˵�����������Ѿ��������㣬ֻʣ�����ս��
		return;
		if (fakeTarget == target)
		return;
	����
		for (int i = 0; i < remain; i++)
		{
			if (number[i] <= target && number[i] > fakeTarget)
				fakeTarget = number[i];
		}
	�ĺ��棬��Ϊ�ݹ麯���ĵ����Ƿ��ڼ�����·��֮�󣬵���ǰfakeTarget��û�еõ�����
*/