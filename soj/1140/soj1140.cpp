/*
Constraints

Time Limit: 1 secs, Memory Limit: 32 MB

Description


哈丁国的国王一生善于管理，勤于政务，在国家里聚积了大量的财富。但他众多的孩子都不争气，相互间时常勾心斗角，却没有一个真正能接受国王传位的人。
为了避免将来某儿子一人独揽大权，又出于不能让权力过度分散的考虑，临终前，国王作了一个决定：

国王他将一生的财富打造出了一条很大的金块链，这条金块链的形状比较特别，它由n块大块的黄金组成，国王准备了n-1条链条，
将某些相邻的两块大黄金用链条连接起来，最后构成一条连通的金块链。下图是国王构建的一条金块链：


国王对每块黄金编上号（从1到n），然后立下了遗嘱：

?   儿子们按照年龄大小顺序，在现存的金块链中获得遗产。

?   对于某个儿子，他可以在现存金块链中剪掉某条链条，获得不超过现有金块总数一半的那一部分。

?   某个儿子取得他那部分金块后，剩下的部分由他后面的弟弟们继续操作。

?   最后一个儿子获得剩下的那些金块，国王将保证每个儿子都能获得遗产。

儿子们都是贪婪的，他们都会选取使自己得到最多的金块的那条链条来剪，当然，有时选取的方案不是唯一的，
但是儿子们都会选择使自己获得的“金块组编号”最小的那一条链来剪。“金块组编号”大小定义为：对于长度相同为L的两个有序数组A和B，
A<B当且仅当存在一个整数i(0<i≤L)，使得A[1]=B[1],…,A[i-1]=B[i-1]且A[i]<B[i]。


Input


输入数据第一行为一个整数n（1≤n≤30000）和一个整数k（1≤k≤100），分别表示金块的总数与国王儿子的数量。接下来n-1行，
每行两个整数x和y，表示编号为x的金块与编号为y的金块用链条连接起来。


Output

输出数据只有一行，包含有k个整数，分别表示每个儿子获得金块的数量（由大儿子到最小的儿子）。

Sample Input
6 3
1 2
2 3
3 4
2 5
3 6


Sample Output
3 1 2


样例说明：这里，大儿子取得金块组{1,2,5}，二儿子取得金块组{4}，三儿子取得金块组{3,6}。


Problem Source

ZSUACM Team Member

*/