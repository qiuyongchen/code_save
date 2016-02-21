/************************************************************************************

1006. Team Rankings

Constraints

Time Limit: 1 secs, Memory Limit: 32 MB


Description

It's preseason and the local newspaper wants to publish a preseason ranking of the teams in the local amateur basketball league. The teams are the Ants, the Buckets, the Cats, the Dribblers, and the Elephants. When Scoop McGee, sports editor of the paper, gets the rankings from the selected local experts down at the hardware store, he's dismayed to find that there doesn't appear to be total agreement and so he's wondering what ranking to publish that would most accurately reflect the rankings he got from the experts. He��s found that finding the median ranking from among all possible rankings is one way to go.

The median ranking is computed as follows: Given any two rankings, for instance ACDBE and ABCDE, the distance between the two rankings is defined as the total number of pairs of teams that are given different relative orderings. In our example, the pair B, C is given a different ordering by the two rankings. (The first ranking has C above B while the second ranking has the opposite.) The only other pair that the two rankings disagree on is B, D; thus, the distance between these two rankings is 2. The median ranking of a set of rankings is that ranking whose sum of distances to all the given rankings is minimal. (Note we could have more than one median ranking.) The median ranking may or may not be one of the given rankings.

Suppose there are 4 voters that have given the rankings: ABDCE, BACDE, ABCED and ACBDE. Consider two candidate median rankings ABCDE and CDEAB. The sum of distances from the ranking ABCDE to the four voted rankings is 1 + 1 + 1 + 1 = 4. We'll call this sum the value of the ranking ABCDE. The value of the ranking CDEAB is 7 + 7 + 7 + 5 = 26.

It turns out that ABCDE is in fact the median ranking with a value of 4.


Input

There will be multiple input sets. Input for each set is a positive integer n on a line by itself, followed by n lines (n no more than 100), each containing a permutation of the letters A, B, C, D and E, left-justified with no spaces. The final input set is followed by a line containing a 0, indicating end of input.


Output

Output for each input set should be one line of the form:

ranking is the median ranking with value value.

Of course ranking should be replaced by the correct ranking and value with the correct value. If there is more than one median ranking, you should output the one which comes first alphabetically.


Sample Input
4
ABDCE
BACDE
ABCED
ACBDE
0


Sample Output
ABCDE is the median ranking with value 4.

˼·��
	 �����զһ��ͦ�鷳�ģ���������һ��˼·
	 �����������һ��ѳ���Ϊ5����ABCDE5����ĸ���ַ���
	 ����Ҫ�����ҳ�median ranking
	 Ϊ���ҳ���median ranking�����Ǳ�����ÿ���ַ�����rank sum
	 Ϊ����rank sum�����������ַ�������Ƚ�

	 ����but,���ջ��ʲô��ϵ���������˶����㲻���ס�

	 �Ҳ���һ�´�ţ��˼·���������Ƕ�����ȫ���У�����Ϊʲô������ֻҪ��������ַ�����Ⱦ������᣿
	 ΪʲôҪ�󻨹���ȥ��ȫ���б��أ��ѵ��ǡ�XPϵͳ����

	 ��˵�������ȫ������ȣ��Ʊػ��ĳ...�ȵȣ�������������

	 �ƺ���Ŀ�����ļ����ַ�����һ���������մ�
	 whose sum of distances to all the given rankings....
	 The median ranking may or may not be one of the given rankings.

	 �����Ļ������Ǳ�����ȫ�����ˣ�����𰸲�һ���Ǹ������ַ�����ĳһ���Ļ���

	 ������ȫ���У�5��������ȫ���������е��ַ������ȴ���������ַ�����
	 һ���û�������һ���ַ�����ȫ���������е��ַ��������û��ַ������Ƚϣ�
	 ����û����������ˣ���ô����ȫ���������е��ַ�����˭��sum��С������˭��

	 Ӧ�þ�����ôһ���¶��ˡ�

	 �������ˣ�ȫ������ô���ɣ���5��forѭ��ֱ�����ɣ�������5��5�η��ˣ����ԣ���ĸ���ظ����������5�����ѡ�
	 Ī�����Ҫ��5��Ƕ�׵�ѭ����̫�Ǹ��ˣ���

	 �����ջ����ô�㣿
	 ���ˣ���Ҫջ�ˣ�ֱ��Ƕ��ѭ�����ˣ��ƺ�ջͦ�鷳�ġ�
	 ��ô��������Ū��flag[5]������flag[0]����A��flag[1]����B�����forѭ�����Ѿ�����ĳ����ĸ�Ͳ�����ȥѭ�����ˡ�

	 ���ȹ���ȫ���У����û������������е��ַ�����Ȼ���ٱ�������ȫ���У�ȫ�����е�ÿһ�ַ����������е��û��ַ�����С������
	 Ȼ����ѡ��С����֮������

*************************************************************************************/

#include <iostream>
#include <string>

std::string onlooker[120]; // ���ȫ���У�5!��

// �������ɴ�A��E��ȫ����
void permutation() {
	bool flag[5] = { false };
	int count = 0;
	std::string c = "ABCDE";

	for (int i = 'A'; i < 'F'; i++)
	{
		flag[i - 'A'] = true;

		for (int j = 'A'; j < 'F'; j++)
		{
			if (flag[j - 'A'])
			{
				continue;
			}
			flag[j - 'A'] = true;

			for (int k = 'A'; k < 'F'; k++)
			{
				if (flag[k - 'A'])
				{
					continue;
				}
				flag[k - 'A'] = true;

				for (int l = 'A'; l < 'F'; l++)
				{
					if (flag[l - 'A'])
					{
						continue;
					}
					flag[l - 'A'] = true;

					for (int m = 'A'; m < 'F'; m++)
					{
						if (flag[m - 'A'])
						{
							continue;
						}
						flag[m - 'A'] = true;
						c[0] = i;
						c[1] = j;
						c[2] = k;
						c[3] = l;
						c[4] = m;
						onlooker[count++] = c;
						flag[m - 'A'] = false;

					}

					flag[l - 'A'] = false;
				}

				flag[k - 'A'] = false;
			}

			flag[j - 'A'] = false;
		}

		flag[i - 'A'] = false;
	}
}

// ���������ַ���֮���difference
int difference(std::string A, std::string B) {
	int n = 0;

	// B[i]��λ�� ��B[j]��ǰ��ģ����B[i]�������ĸ��A���ǿ���ģ���������different����
	for (int i = 0; i < A.length() - 1; i++)
	{
		for (int j = i + 1; j < A.length(); j++)
		{
			if (A.find(B[i]) > A.find(B[j]))
			{
				n++;
			}
		}
	}

	return n;
}

int main() {
	permutation();

	// �û�������ַ���
	std::string participator;
	// �������еĶ�������
	int N;

	std::cin >> N;

	while (N != 0)
	{
		int sum[120] = { 0 };
		int theChosenOne = 0;

		for (int i = 0; i < N; i++)
		{
			std::cin >> participator;
			for (int j = 0; j < 120; j++)
			{
				sum[j] += difference(onlooker[j], participator); // ȫ���е�sum
			}
		}

		for (int j = 0; j < 120; j++)
		{
			if (sum[j] < sum[theChosenOne])
				theChosenOne = j;
		}

		std::cout << onlooker[theChosenOne] << " is the median ranking with value " << sum[theChosenOne] << ".\n";
		std::cin >> N;
	}


	return 0;
}

/**********************************************************
��ǣ�
    ��Ȼ����˯ǰʱ������һ���⡣������
	���⻹�ǱȽϼ򵥵ģ�����Ҳ����һ�أ�
	д�Ǹ�difference������ʱ�����ж��ַ����е��ַ�λ��ʱ��ǰ��Ū���ˡ���������
	if (A.find(B[i]) > A.find(B[j]))
	д��
	if (A.find(B[i]) < A.find(B[j]))

	����ͷ˵�������������ϰջ�ģ�����������һ����ñ������ɡ�
***********************************************************/
