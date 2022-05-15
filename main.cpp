#include <Python.h>
#include <QApplication>
#include <QDebug>
#include <QRandomGenerator>
#include <QVector>
#include <algorithm>
#include <armadillo>
#include <iostream>
#include <vector>

#include "mainwindow.h"

uint32_t m_u32AngleLoopNum = 2;
uint32_t m_u32SeqCntCeil = 4;
uint32_t m_u32SeqByteNum = 16;

void func_x(int& i) {
  int* a;
  a = &i;
  qDebug() << "a = " << a;
  qDebug() << "a_val = " << *a;
}

int ConvertSeqRamData(QVector<QVector<QVector<uint8_t>>> vSeqRamData,
                      QVector<uint64_t>& vSeqRamDataRaw) {
  if (vSeqRamData.size() * vSeqRamData.last().size() *
          vSeqRamData.last().last().size() !=
      m_u32AngleLoopNum * m_u32SeqCntCeil * m_u32SeqByteNum) {
    qDebug() << __FUNCTION__ << "SeqRam源数据长度非法，源数据总长度:"
             << vSeqRamData.size() * vSeqRamData.last().size() *
                    vSeqRamData.last().last().size()
             << " 合法长度:"
             << m_u32AngleLoopNum * m_u32SeqCntCeil * m_u32SeqByteNum / 4;
    return -1;
  }

  for (uint32_t u32AngleLoopIdx = 0; u32AngleLoopIdx < m_u32AngleLoopNum;
       u32AngleLoopIdx++) {
    for (uint32_t u32SeqCntCeilIdx = 0; u32SeqCntCeilIdx < m_u32SeqCntCeil;
         u32SeqCntCeilIdx++) {
      for (uint32_t u32SeqMultiByteIdx = 0;
           u32SeqMultiByteIdx < m_u32SeqByteNum / 4; u32SeqMultiByteIdx++) {
        uint64_t u64MultiByte = 0;

        for (uint32_t u32SingleByteIdx = 0; u32SingleByteIdx < 4;
             u32SingleByteIdx++) {
          uint8_t u8SingleByte =
              vSeqRamData.at(u32AngleLoopIdx).at(u32SeqCntCeilIdx).first();
          u64MultiByte |= (u8SingleByte << (8 * (3 - u32SingleByteIdx)));
          vSeqRamData[u32AngleLoopIdx][u32SeqCntCeilIdx].pop_front();
        }
        vSeqRamDataRaw.push_back(u64MultiByte);
      }
    }
  }
  return 0;
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

#pragma region 测试armadillo {
//  QVector<double> vQt = {0.1, 0.2, 0.3, 0.4, 0.5};
//  std::vector<double> vStd = vQt.toStdVector();
//  arma::rowvec vArma(vStd);
//  qDebug() << "均值:" << arma::mean(vArma);
//  qDebug() << "标准差:" << arma::stddev(vArma);

//  arma::rowvec vArmaFlip = arma::fliplr(vArma);
//  std::cout << "vArmaFlip:" << vArmaFlip << std::endl;

#pragma endregion }

  std::vector<double> vTest;
  vTest.size();
  w.show();
  return a.exec();
}
