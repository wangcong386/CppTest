#include <QApplication>
#include <QDebug>
#include <QRandomGenerator>
#include <QVector>
#include <algorithm>
#include <iostream>
#include <vector>

#include "mainwindow.h"

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  MainWindow w;

#pragma region 引用测试 {
  int ival = 1.01;
  std::cout << "ival=" << ival << std::endl;
  //  int &rval1 =1.01; // 非法
  int& rval2 = ival;  // 关联引用
  rval2 = 3.14;       // 合法

  const int& rval3 = 1.2;  // 初始化const变量
  rval2 = rval3;           // 使用常量改变引用内容
  ival = rval3;            // 使用常量改变引用内容
  //  rval3 = ival;            // 非法

  int i, &ri = i;
  i = 5;
  ri = 10;
  std::cout << i << " " << ri << std::endl;

#pragma endregion }

  w.show();
  return a.exec();
}
