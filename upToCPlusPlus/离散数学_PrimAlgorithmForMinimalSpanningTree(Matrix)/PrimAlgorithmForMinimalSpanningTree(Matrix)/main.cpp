/*
  main.cpp

  PRIM'S ALGORITHM

  Implemented by SomebodyWho

  For �ҿɰ���С��Ҷ.

  (�������ĵ�һ������400�еĳ���

*/
#include "graphMatrix.h"
#include <iostream>
using namespace std;

int main() {
    graphMatrix matrixForPrim;
    cin >> matrixForPrim;
    cout << matrixForPrim;
    matrixForPrim.repeat();
    matrixForPrim.showEdge();
    return 0;
}