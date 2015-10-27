/*
  graphMatrix.h
  
*/
#include <iostream>
#include <array>
#include <set>
#include <vector>
#define MAXSIZE 100
#define MINSIZE 0
using namespace std;

class graphMatrix {
 public:
     friend ostream& operator<<(ostream& out, const graphMatrix& g);
     friend istream& operator>>(istream& in, graphMatrix& g);
     graphMatrix();
     ~graphMatrix();
     int size() const;
     bool empty() const;
     int smallestEntryRow() const;
     int smallestEntryColumn() const;
     void mergeAB(int a, int b);
     void swap(int *a, int *b);
     void replaceRow(int rowI, int rowJ);
     void replaceColumn(int columnI, int columnJ);
     void replaceTheDiaGonal();
     void updateSuperVertext();
     void selectEdge();
     void showEdge();
     void repeat();
 private:
     // ��¼������Ϣ������������ϲ�����������sizoOfMatrix�Ĵ�С���С1.
     int matrix[MAXSIZE][MAXSIZE];

     // matrixForConstructTree,ͬ����¼������Ϣ����������Զ���䣬��Ϊ����
     // Ҫ����������ԭʼ�����㡯֮���Ȩ�أ�
     // �Ա��ؽ�spanning tree.
     int matrixFCT[MAXSIZE][MAXSIZE];

     // matrix��size.
     int sizeOfMatrix;

     // matirxFCT��size.
     int sizeOfMatrixFCT;
     
     /********************************************************************
     /* ����֪�����������ڵ�ϲ������Ǿͻ��γ�һ���µĽڵ㣬����µĽڵ������
     /* һ��set����������ǽ�֮��Ϊ�����޵г�����ڵ㣬����ν��superVertext.
     /* ���裡���������������������¼���仯��ľ��󡰣�������������������������
     /*******************************************************************/

     // if setOrEntry[i] == 1, then vertext represented by column i or column i
     // is a set, which is named 'superVertext'.
     // ����������鱻������ʾ ���仯��ľ��󡱵ĸ����Ƿ�Ϊset.
     int setOrEntry[MAXSIZE];

     // �ڵ�ϲ����γ�set���������set���鱻������ʾ ���仯��ľ��󡱵ĸ����������set.
     array<set<int>, MAXSIZE> superVertext;

     // �����ڵ�ϲ�֮�󣬾����е�Ԫ��λ�÷����仯�������һ�к͵ڶ��кϲ���ԭ�ȵ�
     // ��3�У������Žڵ�C)�����ڱ��ȳ�Ϊ�ڶ��У������Žڵ�B), ���ڵ��λ�ˡ�

     // Ϊ�˷�ֹ�ڵ��λ���������������������������
     // һ��ʼʱstoreVertext[i] == i,����storeVertext[3] == 3, ���ʾ����ĵ�����
     // ����D, �����ڵ��ϲ���storeVertext[3]��ֵ��ǰ�Ƶ�storeVertext[2]�У�
     // storeVertext[2] == 3�����ʾ����ĵ����д���D��

     // ����һ��������ڵ�ϲ��ˣ��������ɿ���֪��"�仯��ľ���"���д����ĸ��ڵ㡣
     int storeVertext[MAXSIZE];

     // ��¼edge��ֵ��ע����ǣ������㱻�ϲ�֮��ԭʼgraph��edge��Ϣ
     // �Ͷ�ʧ�ˡ��������ǹ��������matrixFCT����ӡԭgraph�������������ı䡣
     set< pair<int, int> > edge;
};
