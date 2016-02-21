// Problem#: 1009
// Submission#: 3909852
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
/***************************************
1009. Mersenne Composite N

Constraints

Time Limit : 1 secs, Memory Limit : 32 MB


Description

One of the world - wide cooperative computing tasks is the "Grand Internet Mersenne Prime Search" --GIMPS -- striving to find ever - larger prime numbers by examining a particular category of such numbers.
A Mersenne number is defined as a number of the form(2p�C1), where p is a prime number -- a number divisible only by one and itself. (A number that can be divided by numbers other than itself and one are called "composite" numbers, and each of these can be uniquely represented by the prime numbers that can be multiplied together to generate the composite number �� referred to as its prime factors.)
Initially it looks as though the Mersenne numbers are all primes.



Prime

Corresponding Mersenne Number

2 4�C1 = 3 --prime
3 8�C1 = 7 --prime
5 32�C1 = 31 --prime
7 128�C1 = 127 --prime

If, however, we are having a "Grand Internet" search, that must not be the case.
Where k is an input parameter, compute all the Mersenne composite numbers less than 2k -- where k <= 63 (that is, it will fit in a 64 - bit signed integer on the computer).In Java, the "long" data type is a signed 64 bit integer.Under gcc and g++ (C and C++ in the programming contest environment), the "long long" data type is a signed 64 bit integer.


Input

Input is from file a.in.It contains a single number, without leading or trailing blanks, giving the value of k.As promised, k <= 63.


Output

One line per Mersenne composite number giving first the prime factors(in increasing order) separate by asterisks, an equal sign, the Mersenne number itself, an equal sign, and then the explicit statement of the Mersenne number, as shown in the sample output.Use exactly this format.Note that all separating white space fields consist of one blank.


Sample Input
31


Sample Output
23 * 89 = 2047 = (2 ^ 11) - 1
47 * 178481 = 8388607 = (2 ^ 23) - 1
233 * 1103 * 2089 = 536870911 = (2 ^ 29) - 1

˼·��
����������ҵ���ʮ���÷ɭ����Ү��Ҫ�Ҽ��������⣿
�������С�ڵ���63����������Ҫ��֤���Ƿ�Ϊprime��
��֤�Ĺ��̣����ƾ������Ա����ɣ�����ܱ�����1���������������ˣ�����������prime��
ֱ�ӹ��ˣ�
Ȼ����ô��֤�ǲ��Ǻ�����
���Ҳ���Ա������ǣ���536870911������������1��536870911��
�����˵İɣ���һ���Ż��ļ��ɣ��Ǿ���������ֻ��2һ��ż��������������2�Ķ���������
��ͺ����ˣ�������2��N�η���1�õ���÷ɭ��������2��������÷ɭ�����������ӣ�
���Դ�3��ʼ����������i += 2���Ͼ�������������⣬һ��÷ɭ�������Ӷ���͵���÷ɭ��
�Ŀ�����i * i <= M����

�����ֱ�ۣ�һ�����ӳ����˿�������һ�������Ʊ�С�ڿ�����
��С�ڿ��������������Ѿ���֤���ˡ�

��ôһ�Ż������Ʋ��ᳬʱ�ɡ�

*/
#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>

void Deal(int M) {
	if (M >= 61)return;
	for (int i = 2; i * i <= M; i++)
	{
		if (M % i == 0)
			return; // M����������
	}

	// ȷ����÷ɭ����������Ѱ�Һ�������
	bool leftMost = false; // �˺ŵı��
	bool composite = false; // �����ı��
	long long Mersenne = pow(2.0, M) - 1;
	long long forOutput = Mersenne;

	for (long long i = 3; i * i <= Mersenne; i += 2)
	{
		if (Mersenne % i == 0)
		{
			composite = true;

			Mersenne /= i; // ÷ɭ���������һ���������ӣ�Ӧ��С
			if (leftMost)
			{
				std::cout << " * " << i;
			}
			else
			{
				std::cout << i;
				leftMost = true;
			}

			i = 3; // ���¿�ʼѰ���º�������
		}
	}

	if (composite)
		std::cout << " * " << Mersenne << " = " << forOutput << " = " << "( 2 ^ " << M << " ) - 1\n";
}

int main() {
	int N;
	std::cin >> N;

	for (int i = 3; i < 61; i += 2)
	{
		Deal(i);
	}
	return 0;
}


/***************************************************************
��ǣ�
    ɵ����ɵ����
	��д�Ĺ����˾�����
	���𽥳����˵ģ���ȻҲ��wrong answer��
	ɵ����ɵ����

	�ţ�
	�Ұ��Ǿ�
	if (M > 53) return;
	��ע�͵����Ȼ�͹��ˣ�
	ɵ�ƣ�
	�⣡��

	�ҿ���һ�£�����wrong answer����Щ���붼����������M�Ĵ�С...
	�⣡��
	����˵M�ǡ���
	�ҿ�����
	As promised, k <= 63
	ȷʵ��˵�����Ҹ�һ�´�С���ĳ�100����
	accept��
	�Ҹĳ�70����
	����accept������
	�ĳ�60����
	����accept������
	�ĳ�53����
	����accept������
	�ĳ�51������
	wrong answer

	�ĳ�53������
	wrong answer����
	�⣡����
	
	�ţ��ĳ�58�͹�����
	�ĳ�59�ͱع���
	�⣬��Ϊʲô...
*/


// ���Կ�ʼд�ĳ����������ģ�

/**********************************
// Problem#: 1009
// Submission#: 3909852
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
/***************************************
1009. Mersenne Composite N

Constraints

Time Limit : 1 secs, Memory Limit : 32 MB


Description

One of the world - wide cooperative computing tasks is the "Grand Internet Mersenne Prime Search" --GIMPS -- striving to find ever - larger prime numbers by examining a particular category of such numbers.
A Mersenne number is defined as a number of the form(2p�C1), where p is a prime number -- a number divisible only by one and itself. (A number that can be divided by numbers other than itself and one are called "composite" numbers, and each of these can be uniquely represented by the prime numbers that can be multiplied together to generate the composite number �� referred to as its prime factors.)
Initially it looks as though the Mersenne numbers are all primes.



Prime

Corresponding Mersenne Number

2 4�C1 = 3 --prime
3 8�C1 = 7 --prime
5 32�C1 = 31 --prime
7 128�C1 = 127 --prime

If, however, we are having a "Grand Internet" search, that must not be the case.
Where k is an input parameter, compute all the Mersenne composite numbers less than 2k -- where k <= 63 (that is, it will fit in a 64 - bit signed integer on the computer).In Java, the "long" data type is a signed 64 bit integer.Under gcc and g++ (C and C++ in the programming contest environment), the "long long" data type is a signed 64 bit integer.


Input

Input is from file a.in.It contains a single number, without leading or trailing blanks, giving the value of k.As promised, k <= 63.


Output

One line per Mersenne composite number giving first the prime factors(in increasing order) separate by asterisks, an equal sign, the Mersenne number itself, an equal sign, and then the explicit statement of the Mersenne number, as shown in the sample output.Use exactly this format.Note that all separating white space fields consist of one blank.


Sample Input
31


Sample Output
23 * 89 = 2047 = (2 ^ 11) - 1
47 * 178481 = 8388607 = (2 ^ 23) - 1
233 * 1103 * 2089 = 536870911 = (2 ^ 29) - 1

˼·��
����������ҵ���ʮ���÷ɭ����Ү��Ҫ�Ҽ��������⣿
�������С�ڵ���63����������Ҫ��֤���Ƿ�Ϊprime��
��֤�Ĺ��̣����ƾ������Ա����ɣ�����ܱ�����1���������������ˣ�����������prime��
ֱ�ӹ��ˣ�
Ȼ����ô��֤�ǲ��Ǻ�����
���Ҳ���Ա������ǣ���536870911������������1��536870911��
�����˵İɣ���һ���Ż��ļ��ɣ��Ǿ���������ֻ��2һ��ż��������������2�Ķ���������
��ͺ����ˣ�������2��N�η���1�õ���÷ɭ��������2��������÷ɭ�����������ӣ�
���Դ�3��ʼ����������i += 2���Ͼ�������������⣬һ��÷ɭ�������Ӷ���͵���÷ɭ��
�Ŀ�����i * i <= M����

�����ֱ�ۣ�һ�����ӳ����˿�������һ�������Ʊ�С�ڿ�����
��С�ڿ��������������Ѿ���֤���ˡ�

��ôһ�Ż������Ʋ��ᳬʱ�ɡ�


#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>

void Deal(int M) {
	for (int i = 2; i * i <= M; i++)
	{
		if (M % i == 0)
			return; // M����������
	}

	// ȷ����÷ɭ����������Ѱ�Һ�������
	bool leftMost = false; // �˺ŵı��
	bool composite = false; // �����ı��
	long long Mersenne = pow(2.0, M) - 1;
	long long forOutput = Mersenne;

	for (long long i = 3; i * i <= Mersenne; i += 2)
	{
		if (Mersenne % i == 0)
		{
			composite = true;

			Mersenne /= i; // ÷ɭ���������һ���������ӣ�Ӧ��С
			if (leftMost)
			{
				std::cout << " * " << i;
			}
			else
			{
				std::cout << i;
				leftMost = true;
			}

			i = 3; // ���¿�ʼѰ���º�������
		}
	}

	if (composite)
		std::cout << " * " << Mersenne << " = " << forOutput << " = " << "( 2 ^ " << M << " ) - 1\n";
}

int main() {
	int N;
	std::cin >> N;

	for (int i = 3; i < N; i += 2)
	{
		Deal(i);
	}
	return 0;
}

*/

/*
�ҷ��֣���ʱ����Ϊ
for (int i = 3; i < N; i += 2)
����д����
for (int i = 3; i <= N; i += 2)
�����Ƕ���һ���Ⱥš����������ͳ�ʱ�ˣ���������Կ�
�⵽����Ϊʲô
�ѵ����Ƕ���һ��63�ͺķѴ�����ʱ�䣿
��Ҳ��Ӧ�ð�

�ţ�ȷʵ����63��62��ԭ������Deal��������������ƣ�����63��62��,�����ɳ�ʱ
��ô�����⵽����ʲô�أ�

���˼��������ų���63��59������61��ʱ
����������Ĳ���������61����61�����ǳ�ʱ���Ǹ����Ӱ�
*/
