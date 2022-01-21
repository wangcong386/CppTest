#include <QApplication>
#include <QDebug>
#include <QRandomGenerator>
#include <QVector>
#include <algorithm>

#include "mainwindow.h"

void func_x(int& i) {
  int* a;
  a = &i;
  qDebug() << "a = " << a;
  qDebug() << "a_val = " << *a;
}

bool func_compare(int a, int b) { return a > b; }

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  /* 数据类型测试
  //  char cTest[10];
  //  int iTest = 11;
  //  long long int lliTest = 18;
  //  uint uTest = 12;
  //  uint8_t u8Test = 99;
  //  uint16_t u16Test = 13;
  //  uint32_t u32Test = 14;
  //  uint64_t u64Test = 15;
  //  double dTest[10];

  //  float fTest = 1.2;
  //  int* i = new int(10);
  //  qDebug() << "&i: " << &i;
  //  qDebug() << "i: " << i;
  //  qDebug() << "*i: " << *i;
  //  qDebug() << "size of i: " << sizeof(i);
  //  qDebug() << "size of *i: " << sizeof(*i);

  //  qDebug() << "size of iTest: " << sizeof(iTest);
  //  qDebug() << "size of &iTest: " << sizeof(&iTest);

  //  qDebug() << "size of cTest: " << sizeof(cTest);
  //  qDebug() << "size of &cTest: " << sizeof(&cTest);

  //  qDebug() << "size of uTest: " << sizeof(uTest);
  //  qDebug() << "size of &uTest: " << sizeof(&uTest);

  //  qDebug() << "size of u8Test: " << sizeof(u8Test);
  //  qDebug() << "size of &u8Test: " << sizeof(&u8Test);

  //  qDebug() << "size of u16Test: " << sizeof(u16Test);
  //  qDebug() << "size of &u16Test: " << sizeof(&u16Test);

  //  qDebug() << "size of u32Test: " << sizeof(u32Test);
  //  qDebug() << "size of &u32Test: " << sizeof(&u32Test);

  //  qDebug() << "size of u64Test: " << sizeof(u64Test);
  //  qDebug() << "size of &u64Test: " << sizeof(&u64Test);

  //  qDebug() << "size of lliTest: " << sizeof(lliTest);
  //  qDebug() << "size of &lliTest: " << sizeof(&lliTest);

  //  qDebug() << "size of dTest: " << sizeof(dTest);
  //  qDebug() << "size of &dTest: " << sizeof(&dTest);

  //  qDebug() << "size of fTest: " << sizeof(fTest);
  //  qDebug() << "size of &fTest: " << sizeof(&fTest);
  */

  //  int* x = new int(10);
  //  int m = 10;
  //  qDebug() << "m_addr = " << &m;
  //  func_x(m);
  QVector<int> vec;
  QMap<int, QPair<int, int>> map;
  for (int i = 10; i > 0; i--) {
    //    vec.push_back(QRandomGenerator::global()->bounded(10));
    map[i] = QPair<int, int>(QRandomGenerator::global()->bounded(10),
                             QRandomGenerator::global()->bounded(10));
  }
  qDebug() << map;
  //  std::sort(map.begin(), map.end(), func_compare);
  qDebug() << vec;
  w.show();
  return a.exec();
}
