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
     void selectEdgeOfLeastWeight(int verA, int verB);
     void replaceSetOfEdges(int verA, int verB);
     bool itMakesACycle(int verA, int verB);
     void initEdgeMatrix();
     void constructEdgeMatrix(int verA, int verB);
     void findConnectComponents();
     bool scanAllRow();
     bool Cycle();
     void showEdge();
     void repeat();
     void showstep();
 private:
     // ��¼ͼ��Ӧ�ľ�����Ϣ
     int matrix[MAXSIZE][MAXSIZE];
     int sizeOfMatrix;

     // ��¼�Ѿ���ѡ������edge
     set< pair<int, int> > edge;

     // �ڲ�֪��ĳ�����Ƿ���γɻ�������£����ǰ�����֮ǰѡ�����ı߷���
     // ������������У������ҳ�����������ߡ�֮���γɵ���ͨ����
     int edgeMatrix[MAXSIZE][MAXSIZE];

     // ��������ɨ��ķ�ʽ������������ͬ����ͨ���֡�
     bool hasScanRow[MAXSIZE];

     // ������һ���Լ���ΪԪ�ص����飬һ��Ԫ�ش�����һ����ͨ����
     array< set<int>, MAXSIZE> connectGraph;
};
