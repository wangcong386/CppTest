#include <QApplication>
#include <QDebug>
#include <QRandomGenerator>
#include <QVector>
#include <QtEndian>
#include <algorithm>
#include <iostream>
#include <vector>

#include "father.h"
#include "mainwindow.h"
#include "son.h"
struct Test {
  bool operator==(const Test& test) {
    bool bRet = true;
    bRet &= test.m_nVal1 == this->m_nVal1 ? true : false;
    bRet &= test.m_nVal2 == this->m_nVal2 ? true : false;
  }
  int m_nVal1;
  int m_nVal2;
};
int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
#pragma region 继承 {
  if (false) {
    Father* pFatherObj = new Son;

    pFatherObj->FuncTest1(1, "good");
    pFatherObj->FuncTest11(1, 1);

    delete pFatherObj;
    pFatherObj = nullptr;
  }
#pragma endregion }

#pragma region 大小端 {
  if (false) {
    int nTest1 = 0x10495;
    int nRes1 = qFromBigEndian(nTest1);
    qDebug() << nRes1;
  }
#pragma endregion }

#pragma region 字符串分段 {
  if (false) {
    QString sTest1 = "wang\rcong\r";
    QStringList sList1 = sTest1.split('\r');
    QString sTest2 = "wangcong\r";
    QStringList sList2 = sTest2.split('\r');
    qDebug() << sList1;
    qDebug() << sList2;
  }
#pragma endregion }

#pragma region 字符串指针 {
  if (false) {
    QString sTest1 = "wangcong";
    uint8_t* u8Test1 = reinterpret_cast<uint8_t*>(sTest1.data());
    qDebug() << (char*)u8Test1;
  }
#pragma endregion }

#pragma region QVector删除元素 {
  if (false) {
    QVector<Test> vTest;
    for (int nIdx = 0; nIdx < 3; nIdx++) {
      Test test = {.m_nVal1 = nIdx, .m_nVal2 = nIdx};
      vTest.push_back(test);
    }

    for (const Test& ele : vTest) {
      if (ele.m_nVal1 == 1) {
        vTest.indexOf(ele);
      }
    }
    qDebug() << vTest.size();
  }
#pragma endregion }

#pragma region 系统时间 {
  if (false) {
    QVector<Test> vTest;
    for (int nIdx = 0; nIdx < 3; nIdx++) {
      Test test = {.m_nVal1 = nIdx, .m_nVal2 = nIdx};
      vTest.push_back(test);
    }

    for (const Test& ele : vTest) {
      if (ele.m_nVal1 == 1) {
        vTest.indexOf(ele);
      }
    }
    qDebug() << vTest.size();
  }
#pragma endregion }

#pragma region++ 赋值 {
  if (false) {
    int nTest = 0;
    int nRes = ++nTest;
    qDebug() << nTest << nRes;
  }
#pragma endregion }

#pragma region u8数组强转char {
  if (false) {
    uint8_t u8Test[] = {100, 101};
    int nStep = 2;
    printf("u8Test %p\n", u8Test);
    std::cout << u8Test << std::endl;
    //    QString sTest = QString(QLatin1String((char*)u8Test));
    //    qDebug() << "sTest" << sTest;
  }
#pragma endregion }

#pragma region char* 数组测试 {
  if (true) {
    const char* charTest[] = {"X", "Y"};

    qDebug() << sizeof(charTest) / sizeof(char*);
  }
#pragma endregion }
  w.show();
  return a.exec();
}
