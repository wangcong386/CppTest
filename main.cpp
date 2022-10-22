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

#pragma region QVector转字符串 {
  if (true) {
    QVector<uint16_t> vU16Input;
    // 初始化数组
    for (uint16_t u16Idx = 100; u16Idx < 120; u16Idx++) {
      vU16Input.push_back(u16Idx);
    }
    // 数组转换为QString
    const QChar* pCharTest1 = reinterpret_cast<QChar*>(vU16Input.data());
    QString sTest(pCharTest1, vU16Input.size() * sizeof(uint16_t));
    qDebug() << "sTest" << sTest;
    qDebug() << "size of sTest" << sTest.length();

    // QString重新转换为数组
    QVector<uint16_t> vU16Output;
    uint16_t* pU16Val = reinterpret_cast<uint16_t*>(sTest.data());
    for (int nIdx = 0; nIdx < sTest.length() / sizeof(uint16_t); nIdx++) {
      vU16Output.push_back(*pU16Val);
      pU16Val++;
    }
    qDebug() << "vU16Output" << vU16Output;
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
  if (false) {
    const char* charTest[] = {"X", "Y"};

    qDebug() << sizeof(charTest) / sizeof(char*);
  }
#pragma endregion }

#pragma region char* 数组指针测试 {
  if (false) {
    struct testStruct {
      testStruct() {
        a = 1;
        b = 2;
      }
      int a;
      int b;
    };
    QVector<testStruct*> vPtrTestStruct;
    vPtrTestStruct.resize(2);
    //    qDebug() << vPtrTestStruct[0]->a;
    // 以上测试表明无法通过resize为数组指针构造相应的实体对象

    qDebug() << vPtrTestStruct.size();
    vPtrTestStruct[0] = new testStruct;
    qDebug() << vPtrTestStruct[0]->a;
    //    qDebug() << vPtrTestStruct[1]->a;
    // 以上测试表明为数组指针构造相应的实体对象需要new
  }
#pragma endregion }

#pragma region 数字转字符串大小是否改变 {
  if (false) {
    QString sTest1;
    int nVal1 = 10;
    double dVal1 = 10.000000001;
    int nVal2 = 1000000;
    uint8_t u8Val = 10;
    uint16_t u16Val = 1000;
    uint32_t u32Val = 10;
    sTest1 = QString::number(nVal1);
    qDebug() << sTest1.length();

    sTest1 = QString::number(nVal2);
    qDebug() << sTest1.length();

    sTest1 = QString ::number(dVal1);
    qDebug() << sTest1.length();

    sTest1 = QString::number(u8Val);
    qDebug() << sTest1.length();

    sTest1 = QString::number(u16Val);
    qDebug() << sTest1.length();

    sTest1 = QString::number(u32Val);
    qDebug() << sTest1.length();
  }
#pragma endregion }

#pragma region 操作符测试 {
  if (false) {
    int nVal1 = 10;
    qDebug() << nVal1 % 256;
    qDebug() << nVal1 % 3;
  }
#pragma endregion }

#pragma region QByteArray测试 {
  if (false) {
    // uint16_t数组转换成QByteArray
    QVector<uint16_t> vTest;
    for (uint16_t u16Idx = 0; u16Idx < 10; u16Idx++) {
      vTest.push_back(u16Idx);
    }
    char* pTest = reinterpret_cast<char*>(vTest.data());
    QByteArray arrTest(
        QByteArray::fromRawData(pTest, sizeof(uint16_t) * vTest.size()));
    qDebug() << "arrTest size" << arrTest.size();

    // QByteArray转换成uint16_t数组
    QVector<uint16_t> vOutput;
    uint16_t* p16Output = reinterpret_cast<uint16_t*>(arrTest.data());
    for (int nIdx = 0; nIdx < arrTest.size() / sizeof(uint16_t); nIdx++) {
      vOutput.push_back(*p16Output);
      p16Output++;
    }
    qDebug() << "vOutput" << vOutput;
  }
#pragma endregion }
  w.show();
  return a.exec();
}
