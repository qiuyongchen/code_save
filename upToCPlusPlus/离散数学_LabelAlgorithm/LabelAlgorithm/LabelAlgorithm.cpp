#include "LabelAlgorithm.h"

// ��������������
ostream& operator<<(ostream& out, LabelAlgorithm& a) {
    out << "[\n";
    for (int i = 0; i < a.size_; i++) {
        for (int j = 0; j < a.size_; j++) {
            out << a.excessCapacity[i][j] << " ";
        }
        out << endl;
    }
    out << "]" << endl;
    return out;
}

// ���������������
istream& operator>>(istream& in, LabelAlgorithm& a) {
    cout << "��������ľ���Ĵ�С:";
    in >> a.size_;
    cout << "��������ľ���:" << endl;
    for (int i = 0; i < a.size_; i++) {
        for (int j = 0; j < a.size_; j++) {
            in >> a.excessCapacity[i][j];
        }
    }
    return in;
}

// �ж�ĳ�ڵ��Ƿ��Ѿ�����ǡ�
bool LabelAlgorithm::itIsLabeled(int verticeI) {
    return verticeLabeled[verticeI];
}

// Step1: Let N1 be the set of all nodes connected to the source
//        by an edge with positive excess capacity. Label each j
//        in N1 with [Ej, 1], where Ej is the excess capacity e1j
//        of edge(1, j). The 1 in the label indicates that j is
//        connected to the source, node 1.
//        ����������þ���V�ĵ�һ�����洢N1��
void LabelAlgorithm::dealWithN1() {

    for (int i = 0; i < size_; i++) {
        // ����Щ��"Դ���м���ļһ�ȫ����ǣ����ɳ�����
        if (excessCapacity[0][i] > 0 && !verticeLabeled[i]) {
            verticeLabeled[i] = true;
            V[0][i].E = excessCapacity[0][i];
            V[0][i].reverseConnect = 0;
            V[0][i].haveBeenCollectedIn = true;
        }
    }
}

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
void LabelAlgorithm::dealWithNi(int Ni) {
    // ����Ni-1,����Щ�Ѿ�������Ni-1�еĽڵ����һ���ӡ��ϸ񡰽ڵ�ȫ����ǡ�
    for (int i = 0; i < size_; i++) {
        // �ҳ�������Ni-1�еĽڵ㡣
        if (V[Ni - 1][i].haveBeenCollectedIn) {
            // ���������Щ������Ni-1�Ľڵ���ӽڵ㣬��ͼ������ǡ�
            for (int j = 0; j < size_; j++) {
                // ����ýڵ�����һ���С�������������������һ���ӽڵ�û����ǣ�
                // ������Ϊ������ĺ�ƽ��������........
                if (excessCapacity[i][j] > 0 && !itIsLabeled(j)) {
                    verticeLabeled[j] = true;
                    V[Ni][j].E = (excessCapacity[i][j] < V[Ni - 1][i].E) ?
                        excessCapacity[i][j] : V[Ni - 1][i].E;
                    V[Ni][j].reverseConnect = i;
                    V[Ni][j].haveBeenCollectedIn = true;
                }
            }
        }
    }
}

// �ð����ơ��㡱�Ƿ��Ѿ�����ǣ���������ǣ����͵�ˢ�¾����ˡ�
bool LabelAlgorithm::sinkHaveBeenLabeled() {
    return verticeLabeled[size_ - 1];
}

// �жϻ���ľ���µĽڵ���Ա���ǲ�����Ni�С�
bool LabelAlgorithm::noFurtherLabeling(int Ni) {
    for (int i = 0; i < size_; i++) {
        if (V[Ni - 1][i].haveBeenCollectedIn) {
            for (int j = 0; j < size_; j++) {
                if (excessCapacity[i][j] > 0 && !itIsLabeled(j))
                    return false;
            }
        }
    }
    return true;
}

// ˢ��ͼ��Ӧ�ľ��󣨶ʵ����ֻ�ǻ�������������·�������ˣ��Ǻǣ�
// �������ǻ���Ҫ����Щ��ǵ���Ϣȫ��Ĩȥ���������뿪���ʹ�������
// �ɣ�������������
void LabelAlgorithm::updateGraph() {
    int account = 0;
    int rever;
    int current = size_ - 1;  // ��ǰ�ڵ㡣
    int Ni;  // ��¼sink������Ni
    // ��Ȼsink�Ѿ�����ǣ��������ڵ������ǵõ�����sink����������һ���ڵ㡣
    for (int i = 0; i < size_; i++) {
        if (V[i][size_ - 1].haveBeenCollectedIn) {
            account = V[i][size_ - 1].E;  // �õ�������
            rever = V[i][size_ - 1].reverseConnect;  // �õ���һ���ڵ㡣
            Ni = i;  // �õ�Ni�ľ���ֵ��
            break;
        }
    }

    vector<int> temp;
    temp.push_back(current + 1);  // ��·���ϵĽڵ�ȫ�ѽ�vector��
    temp.push_back(rever + 1);  // ��·���ϵĽڵ�ȫ�ѽ�vector��
    cout << "����Ϊ" << account << "��·�������򣩣�";
    cout<< current + 1 << "<-" << rever + 1;

    // ������һ���ڵ�͵�ǰ�ڵ�֮���·��������
    excessCapacity[rever][current] -= account;
    excessCapacity[current][rever] += account;

    // һֱҪ���ݵ���Դ��
    while (rever != 0) {
        // ���ص���һ���ڵ㡣
        for (int i = 0; i < size_; i++) {
            if (V[i][rever].haveBeenCollectedIn) {
                current = rever;
                rever = V[i][rever].reverseConnect;
                cout << "<-" << rever + 1;
                temp.push_back(rever + 1);  // ��·���ϵĽڵ�ȫ�ѽ�vector��

                excessCapacity[rever][current] -= account;
                excessCapacity[current][rever] += account;
                break;
            }
        }
    }
    capAndPath.insert(make_pair(account, temp));
    cout << endl;
    // ����������Է��ĵ�Ĩ�������Ϣ�ˡ�
    removeLabeling();
    cout << "�޳���·����ľ���ͼ��\n";
    cout << *this << endl ;
}

//  �����Ϸ����ǲ��µ�����˭�µ�����ȥ�ɡ�
// Ĩ�����еı����Ϣ��
void LabelAlgorithm::removeLabeling() {
    for (int i = 0; i < size_; i++) {

        for (int j = 0; j < size_; j++) {
            V[i][j].E = 0;
            V[i][j].reverseConnect = 0;
            V[i][j].haveBeenCollectedIn = false;
        }

        verticeLabeled[i] = false;
    }
}

// ��repeat, repeat����һ����������������ͷ������
void LabelAlgorithm::repeat() {
    // �ȱ�ǵ�һ����
    dealWithN1();

    while (!ifTerminate()) {
        NN = 1;

        // һֱ�������ǲ�ͣ��NN�����n�����ɱ�����ߵļ���)��ֱ��sink����ǻ�
        // �㷨����ֹͣ��
        while (!sinkHaveBeenLabeled() && !ifTerminate()) {
            dealWithNi(NN);
            NN++;
        }
        // ����ǹ��̱���ֹͣʱ�������sink������ˣ��Ǿ�ˢ�¾���Ĩ����ǣ��ص�
        // ��һ����
        if (sinkHaveBeenLabeled()) {
            updateGraph();
            // �ȱ�ǵ�һ����
            dealWithN1();
            NN = 1;
            continue;
            // ������㷨ֹͣ��������ѭ�����ɡ�
        } else {
            break;
        }
    }
}

// ��ֹ��repeat, �ڿ�����ֻأ��յ�������
bool LabelAlgorithm::ifTerminate() {
    return (!sinkHaveBeenLabeled() && noFurtherLabeling(NN));
}

// ��ʾ����·������������
void LabelAlgorithm::showCapacityAndPath() {
    int sumOfcapacity = 0;
    int sum = 1;
    for (unordered_multimap< int, vector<int> >::iterator it = capAndPath.begin();
        it != capAndPath.end(); ++it) {
            sumOfcapacity += it->first;
            cout << sum++ <<". ����Ϊ" << it->first << "��·��: ";
            for (vector<int>::reverse_iterator itt = it->second.rbegin();
                itt != it->second.rend(); ++itt) {
                    cout << " -> " << *itt;
            }
            cout << endl;
    }
    cout << "�������Ϊ��" << sumOfcapacity << endl << endl;
}
