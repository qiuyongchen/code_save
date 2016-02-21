/*************************************************************************************************
1036. Crypto Columns

Constraints

Time Limit : 1 secs, Memory Limit : 32 MB


Description

The columnar encryption scheme scrambles the letters in a message(or plaintext) using a keyword as illustrated in the following example : Suppose BATBOY is the keyword and our message is MEET ME BY THE OLD OAK TREE.Since the keyword has 6 letters, we write the message(ignoring spacing and punctuation) in a grid with 6 columns, padding with random extra letters as needed :

MEETME
BYTHEO
LDOAKT
REENTH

Here, we've padded the message with NTH. Now the message is printed out by columns, but the columns are printed in the order determined by the letters in the keyword. Since A is the letter of the keyword that comes first in the alphabet, column 2 is printed first. The next letter, B, occurs twice. In the case of a tie like this we print the columns leftmost first, so we print column 1, then column 4. This continues, printing the remaining columns in order 5, 3 and finally 6. So, the order the columns of the grid are printed would be 2, 1, 4, 5, 3, 6, in this case. This output is called the ciphertext, which in this example would be EYDEMBLRTHANMEKTETOEEOTH. Your job will be to recover the plaintext when given the keyword and the ciphertext.


Input


There will be multiple input sets.Each set will be 2 input lines.The first input line will hold the keyword, which will be no longer than 10 characters and will consist of all uppercase letters.The second line will be the ciphertext, which will be no longer than 100 characters and will consist of all uppercase letters.The keyword THEEND indicates end of input, in which case there will be no ciphertext to follow.


Output

For each input set, output one line that contains the plaintext(with any characters that were added for padding).This line should contain no spacing and should be all uppercase letters.


Sample Input
BATBOY
EYDEMBLRTHANMEKTETOEEOTH
HUMDING
EIAAHEBXOIFWEHRXONNAALRSUMNREDEXCTLFTVEXPEDARTAXNAARYIEX
THEEND


Sample Output
MEETMEBYTHEOLDOAKTREENTH
ONCEUPONATIMEINALANDFARFARAWAYTHERELIVEDTHREEBEARSXXXXXX

˼·��������1007�е����ƣ����Ǹ��ݶ�ά�������
      �ؼ����ڣ�

**********************************************************************/
#include <iostream>
#include <string>


int main() {
	int row, column;
	std::string str = "";
	std::string keyword = "";
	char a[200][20] = { 0 };
	int index;

	std::cin >> keyword;
	while (keyword != "THEEND")
	{
		std::cin >> str;

		column = keyword.length();
		row = str.length() / column;

		// ÿ�ζ�����һ��,�ؼ����ҳ�����һ��
		for (int i = 0, ii = 0; i < str.length(); i += row)
		{
			    // ����
				index = 0;
				for (int k = 0; k < column; k++)
				{
					if (keyword[k] < keyword[index])
					{
						index = k;
					}
				}
				keyword[index] = 'Z' + 1;

				// ������
				for (int j = 0; j < row; j++)
				{
					a[j][index] = str[ii++];
				}
			
		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				std::cout << a[i][j];
			}
		}

		std::cout << "\n";

		std::cin >> keyword;
	}
	return 0;
}

/**************************************************************************************
��ǣ�
    ��ξͿ���ˣ�ֱ�Ӹ���soj1007�Ĵ�������������޸ģ����ɡ�

	���������һ�����ɣ���ͬһ��forѭ����ߵ�����������������һ����������һ����������һ�������Ǵ��Խʽ����
	֮��������������Ϊ��forѭ���ﻹ��һ��forѭ������һ�������Ǹ�����������forѭ������Խʽ�������Ǹ�����
	������ĸforѭ���

**************************************************************************************/