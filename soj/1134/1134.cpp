/*
Constraints

Time Limit: 10 secs, Memory Limit: 32 MB

Description

����The Pancakes���׶�԰��С������ˣ���������ʱ��С�������Ѿ����Ż�ľ���ˡ�С���Ѷ���Ҫ����Ļ�ľ��һ���Լ�ϲ����ͼ�Σ�
����Ϳ��Ժ�The Pancakes���ա�ͬʱ��The Pancakes���ϻ���һЩ��ľ�������԰����ϵ���Щ��ľȫ����һ��С���ѣ�
Ȼ��ȸ�С���������Ϳ����ջ������Ļ�ľ�͸�С����ԭ�����ϵĻ�ľ��������֪���ܷ������е�С���Ѷ��������գ�
����������԰�������

Input


�������������ݡ�

ÿ�����ݵĵ�һ��������������n��s��1��n��10000��1��s��1000000����ʾһ����nλС���ѣ�The Pancakes������s���ľ��
������n�У�ÿ����������������a��b��1��a��b��10^9����ʾ��i��С����������a���ľ������Ҫb���ľ���ܹ����ꡣ

����n=0ʱ��ʾ������


Output

�������������С���Ѷ���Pancake���գ������YES���������NO��

Sample Input
2 2
1 4
2 1
2 2
1 4
1 1
0 0

Sample Output
YES
NO

Problem Source

ZSUACM Team Member

˼·��
    �������еĻ�ľ���ƺ��٣������ȿ��Ը���Щ�����ٵĺ��Ӻ������Ѻ��ӵĻ�ľƭ����
	֮�������еĻ�ľ��࣬���Ժ������ĺ��Ӻ���...
*/

#include <iostream>
#include <vector>
#include <algorithm>



class KIDS
{
public:
	KIDS(int a, int b) { handed = a; need = b; }
	int handed;
	int need;
};

bool kidsCMP(KIDS a, KIDS b) {
	return a.need < b.need;
}

int main() {
	int num_kid, s;
	int a, b;
	std::vector<KIDS> kids;

	std::cin >> num_kid >> s;

	while (num_kid != 0) {
		while (num_kid--) {
			std::cin >> a >> b;
			kids.push_back(KIDS(a, b));
		}

		sort(kids.begin(), kids.end(), kidsCMP);

		int i = 0;
		while (i < kids.size() && s >= kids[i].need)
		{
			s += kids[i].handed;
			i++;
		}

		if (i == kids.size())
		{
			std::cout << "YES\n";
		}
		else
		{
			std::cout << "NO\n";
		}

		kids.clear();
		std::cin >> num_kid >> s;
	}
	
	return 0;
}

/*
��ǣ�
    �����︴ϰ�˹����㷨sort������������ͷiterator��βiterator�ͱȽ��㷨���ɡ�
*/