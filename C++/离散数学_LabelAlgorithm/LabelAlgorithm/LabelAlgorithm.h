#ifndef LABELALGORITHM
#define LABELALGORITHM

#define MAXSIZE 100
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct vertice {
    int E;  // Ek is the minimum of Ej and the excess capacity ejk of
            // edge(j, k)............................................
            // Ej is the excess capacity e1j of edge(1, j)...........
            // E�������������ýڵ���������
    int reverseConnect;  // reverseConnect��¼�Ÿ�flow����һ���ڵ㡣
    bool haveBeenCollectedIn;  // true���ʾ�ýڵ��Ѿ������뼯��Ni֮�С�

    // default constructor.
    vertice(int e = 0, int r = 0, bool l = false) {
        E = e;
        reverseConnect = r;
        haveBeenCollectedIn = l;
    }
};

class LabelAlgorithm {
public:

    // ��������������
    friend ostream& operator<<(ostream& out, LabelAlgorithm& a);

    // ���������������
    friend istream& operator>>(istream& in, LabelAlgorithm& a);

    // constructor.
    LabelAlgorithm() {
        for (int i = 0; i < MAXSIZE; i++) {
            for (int j = 0; j < MAXSIZE; j++) {
                excessCapacity[i][j] = 0;
            }
            size_ = 0;
            verticeLabeled[i] = false;
        }
        NN = 1;


        /////////////////////////////////////////////
        size_ = 6;
        excessCapacity[0][1] = 5;
        excessCapacity[0][3] = 4;
        excessCapacity[1][2] = 3;
        excessCapacity[1][3] = excessCapacity[1][4] = 2;
        excessCapacity[2][5] = 3;
        excessCapacity[3][4] = 3;
        excessCapacity[4][5] = 4;
        ////////////////////////////////////////////
    }

    // �ж�ĳ�ڵ��Ƿ��Ѿ�����ǡ�
    bool itIsLabeled(int verticeI);

    // Step1: Let N1 be the set of all nodes connected to the source
    //        by an edge with positive excess capacity. Label each j
    //        in N1 with [Ej, 1], where Ej is the excess capacity e1j
    //        of edge(1, j). The 1 in the label indicates that j is
    //        connected to the source, node 1.
    //        ����������þ���V�ĵ�һ�����洢N1��
    void dealWithN1();

    // Step2: Let node j in N1 be the node with smallest node number
    //        and let N2(j) be the set of all unlabeled nodes, other
    //        than the source, that are joined to node j and have
    //        positive excess capacity. Suppose that node k is in N2(j)
    //        and (j, k) is the edge with positive excess capacity.
    //        Label node k with [Ek, j], where Ek is the minimum of Ej
    //        and the excess capacity ejk of edge (j, k). When all the
    //        nodes in N2(j) are labeled in this way, repeat this process
    //        for the other nodes in N1. Let N2 = new N2(j) U old N2(j).
    //        ���N1�е�����Ԫ�ص����������������ɿ�
    // Step3: Repeat Step2, labeling all previously unlabeled nodes N3
    //        that can be reached from a node in N2 by an edge having
    //        positive excess capacity. Continue this process forming
    //        sets N4, N5,...until after a finite number of steps either
    //    (i) the sink has not been labeled and no other nodes can be
    //        labeled. It can happen that no nodes have been labeled;
    //        remember that the source is not labeled.
    //        or
    //    (ii)the sink has been labeled.
    void dealWithNi(int Ni);

    // �ð����ơ��㡱�Ƿ��Ѿ�����ǣ���������ǣ����͵�ˢ�¾����ˡ�
    bool sinkHaveBeenLabeled();

    // �жϻ���ľ���µĽڵ���Ա���ǡ�
    bool noFurtherLabeling(int Ni);

    // ˢ��ͼ��Ӧ�ľ��󣨶ʵ����ֻ�ǻ�������������·�������ˣ��Ǻǣ�
    // �������ǻ���Ҫ����Щ��ǵ���Ϣȫ��Ĩȥ���������뿪���ʹ�������
    // �ɣ�������������
    void updateGraph();

    //  �����Ϸ����ǲ��µ�����˭�µ�����ȥ�ɡ�
    // Ĩ�����еı����Ϣ��
    void removeLabeling();

    // ��repeat, repeat����һ����������������ͷ������
    void repeat();

    // ��ֹ��repeat, �ڿ�����ֻأ��յ�������
    bool ifTerminate();

    // ��ʾ����·������������
    void showCapacityAndPath();
private:

    // ��¼ÿ���ߵ�ʣ��������excessCapacity[i][j]��¼�ӽڵ�i���ڵ�j��
    // ʣ��������excessCapacity[j][i]���¼�ӽڵ�i���ڵ�j������������
    int excessCapacity[MAXSIZE][MAXSIZE];

    // ��¼����Ĵ�С��Ҳ���ǽڵ�ĸ�����
    int size_;

    // ����ĵ�һ�м�¼N1�ı����Ϣ���ڶ��м�¼N2�ı����Ϣ,�Դ����ơ�
    vertice V[MAXSIZE][MAXSIZE];

    // ��¼ĳ�ڵ��Ƿ��ѱ���ǣ������Ѿ�����������ٶ�����
    bool verticeLabeled[MAXSIZE];

    // �ڱ��㷨�У�˼���Ǳ�ǡ�
    // ���Ǵ�N1��ǵ�N2��N3��Ni�����������NN��ʾ�����Ǽ���Ҫ��ǵ�Ni����
    int NN;

    // ���multimap�������洢·����·����Ӧ������������Ϊkey��·��Ϊvector<int>��
    unordered_multimap< int, vector<int> > capAndPath;
};

#endif
