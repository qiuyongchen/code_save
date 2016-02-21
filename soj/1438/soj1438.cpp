/*

1438. Shopaholic

Constraints

Time Limit: 1 secs, Memory Limit: 32 MB

Description

Lindsay is a shopaholic. Whenever there is a discount of the kind where you can buy three items and only pay for two,
she goes completely mad and feels a need to buy all items in the store. You have given up on curing her for this disease,
but try to limit its effect on her wallet. You have realized that the stores coming with these offers are quite selective
when it comes to which items you get for free; it is always the cheapest ones. As an example,
when your friend comes to the counter with seven items, costing 400, 350, 300, 250, 200, 150, and 100 dollars,
she will have to pay 1500 dollars. In this case she got a discount of 250 dollars.
You realize that if she goes to the counter three times,
she might get a bigger discount. E.g. if she goes with the items that costs 400, 300 and 250,
she will get a discount of 250 the first round.
The next round she brings the item that costs 150 giving no extra discount, but the third round she takes the last items that costs 350,
200 and 100 giving a discount of an additional 100 dollars, adding up to a total discount of 350.
Your job is to find the maximum discount Lindsay can get.

Input

The first line of input gives the number of test scenarios, 1 �� t �� 20. Each scenario consists of two lines of input.
The first gives the number of items Lindsay is buying, 1 �� n �� 20000. The next line gives the prices of these items, 1 �� pi �� 20000.

Output

For each scenario, output one line giving the maximum discount Lindsay can get by selectively
choosing which items she brings to the counter at the same time.

Sample Input
1
6
400 100 200 350 300 250

Sample Output
400

˼·��
	ֻҪ�Ӵ�С����ÿ��3����ȡ3������С�Ǹ�����ȡ������������������㼴�ɡ�
*/

#include <iostream>
#include <vector>
#include <algorithm>

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int n;
	std::cin >> n;

	while (n--)
	{
		int c;
		int item;
		std::vector<int> items;

		std::cin >> c;
		for (int i = 0; i < c; i++)
		{
			std::cin >> item;
			items.push_back(item);
		}

		std::sort(items.begin(), items.end(), cmp);

		int i = 0;
		int sum = 0;
		while (!items.empty())
		{
			if (i == 2) {
				i = 0;
				sum += items[0];
			}
			else
			{
				i++;
			}
			items.erase(items.begin());
		}

		std::cout << sum << "\n";
	}

	return 0;
}

/*
��ǣ�
    ���Ƿǳ��򵥵�һ�������⡣
*/