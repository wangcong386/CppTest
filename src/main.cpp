#include <QApplication>
#include <QDebug>
#include <QDir>
#include <QRandomGenerator>
#include <QRegExp>
#include <QVector>
#include <QtEndian>
#include <algorithm>
#include <iostream>
#include <vector>

#include "father.h"
#include "testwindow.h"
#include "son.h"
struct Test
{
  bool operator==(const Test &test)
  {
    bool bRet = true;
    bRet &= test.m_nVal1 == this->m_nVal1 ? true : false;
    bRet &= test.m_nVal2 == this->m_nVal2 ? true : false;
    return bRet;
  }
  int m_nVal1;
  int m_nVal2;
};

int StringToU16Array(const QString &str, QVector<uint16_t> &u16Array)
{
  u16Array.clear();
  int nArrSize = str.toLatin1().size() / sizeof(uint16_t);
  int nRestByteCnt = str.toLatin1().size() % sizeof(uint16_t);
  if (nRestByteCnt != 0)
  {
    u16Array.resize(nArrSize + 1);
  }
  else
  {
    u16Array.resize(nArrSize);
  }
  qDebug() << "str.toLatin1().size()" << str.toLatin1().size();
  const uint16_t *pU16Array =
      reinterpret_cast<const uint16_t *>(str.toLatin1().data());
  for (int nArrIdx = 0; nArrIdx < nArrSize; nArrIdx++)
  {
    u16Array[nArrIdx] = *pU16Array;
    pU16Array++;
  }
  if (nRestByteCnt != 0)
  {
    const uint8_t *pU8RestByte = reinterpret_cast<const uint8_t *>(pU16Array);
    u16Array.last() = static_cast<uint16_t>(*pU8RestByte);
  }
  return 0;
}

QString U16ArrayToString(const QVector<uint16_t> &u16Array)
{
  const char *pChar = reinterpret_cast<const char *>(u16Array.data());
  QString ret = QString::fromLatin1(pChar, u16Array.size() * sizeof(uint16_t));
  return ret;
}

void *TestVoid(int &nVal)
{
  return &nVal;
}

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  TestWindow w;
#pragma region 数据类型大小 {
  int n0;
  short int n1;
  long int n2;
  long long int n3;
  char c0;
  bool b0;
  float f0;
  double d0;
  std::cout << "size of int " << sizeof(n0) << std::endl;
  std::cout << "size of short int " << sizeof(n1) << std::endl;
  std::cout << "size of long int " << sizeof(n2) << std::endl;
  std::cout << "size of long long int " << sizeof(n3) << std::endl;
  std::cout << "size of char " << sizeof(c0) << std::endl;
  std::cout << "size of bool " << sizeof(b0) << std::endl;
  std::cout << "size of float " << sizeof(f0) << std::endl;
  std::cout << "size of double " << sizeof(d0) << std::endl;
#pragma endregion }

#pragma region 继承 {
  if (false)
  {
    Father *pFatherObj = new Son;

    pFatherObj->FuncTest1(1, "good");
    pFatherObj->FuncTest11(1, 1);

    delete pFatherObj;
    pFatherObj = nullptr;
  }
#pragma endregion }

#pragma region 大小端 {
  if (false)
  {
    int nTest1 = 0x10495;
    int nRes1 = qFromBigEndian(nTest1);
    qDebug() << nRes1;
  }
#pragma endregion }

#pragma region 字符串分段 {
  if (false)
  {
    QString sTest1 = "wang\rcong\r";
    QStringList sList1 = sTest1.split('\r');
    QString sTest2 = "wangcong\r";
    QStringList sList2 = sTest2.split('\r');
    qDebug() << sList1;
    qDebug() << sList2;
  }
#pragma endregion }

#pragma region 字符串指针 {
  if (false)
  {
    QString sTest1 = "wangcong";
    uint8_t *u8Test1 = reinterpret_cast<uint8_t *>(sTest1.data());
    qDebug() << (char *)u8Test1;
  }
#pragma endregion }

#pragma region 正则表达式 {
  if (false)
  {
    QRegExp regExp(QString("^\\[\\w*\\]$"));
    QString sTest1("[wang]");
    if (regExp.exactMatch(sTest1))
    {
      sTest1 = sTest1.left(2);
      sTest1.chop(1);
      qDebug() << sTest1;
    }
    else
    {
      qWarning() << sTest1 << "不符合正则表达";
    }
  }
#pragma endregion }

#pragma region QVector转字符串 {
  if (false)
  {
    QVector<uint16_t> vU16Input;
    // 初始化数组
    for (uint16_t u16Idx = 100; u16Idx < 120; u16Idx++)
    {
      vU16Input.push_back(u16Idx);
    }
    // 数组转换为QString
    const QChar *pCharTest1 = reinterpret_cast<QChar *>(vU16Input.data());
    QString sTest(pCharTest1, vU16Input.size() * sizeof(uint16_t));
    qDebug() << "sTest" << sTest;
    qDebug() << "size of sTest" << sTest.length();

    // QString重新转换为数组
    QVector<uint16_t> vU16Output;
    uint16_t *pU16Val = reinterpret_cast<uint16_t *>(sTest.data());
    for (int nIdx = 0; nIdx < sTest.length() / sizeof(uint16_t); nIdx++)
    {
      vU16Output.push_back(*pU16Val);
      pU16Val++;
    }
    qDebug() << "vU16Output" << vU16Output;
  }
#pragma endregion }

#pragma region QVector删除元素 {
  if (false)
  {
    QVector<Test> vTest;
    for (int nIdx = 0; nIdx < 3; nIdx++)
    {
      Test test = {.m_nVal1 = nIdx, .m_nVal2 = nIdx};
      vTest.push_back(test);
    }

    qDebug() << vTest.size();
  }
#pragma endregion }

#pragma region QVector字节数 / 大小 {
  if (false)
  {
    QVector<int> vTest;
    for (int nIdx = 0; nIdx < 3; nIdx++)
    {
      vTest.push_back(nIdx);
    }
    qDebug() << vTest;
    qDebug() << vTest.size();
    qDebug() << vTest.length() * sizeof(int);

    vTest.resize(10);
    qDebug() << vTest;
    qDebug() << vTest.size();
    qDebug() << vTest.length() * sizeof(int);
  }
#pragma endregion }

#pragma region QString字节数 / 大小 {
  if (false)
  {
    QString sTest("12345");

    qDebug() << sTest;
    qDebug() << sTest.size();
    qDebug() << sTest.length();
    qDebug() << sTest.toLocal8Bit().size();
    qDebug() << sizeof(sTest);

    sTest = QString("abcd");
    qDebug() << sTest;
    qDebug() << sTest.size();
    qDebug() << sTest.length();
    qDebug() << sTest.toLocal8Bit().size();
    qDebug() << sizeof(sTest);

    sTest = QString("王淙正在编程王淙正在睡觉");
    qDebug() << sTest;
    qDebug() << sTest.size();
    qDebug() << sTest.length();
    qDebug() << sTest.toLocal8Bit().size();
    qDebug() << sizeof(sTest);
  }
#pragma endregion }

#pragma region StringToU16Array测试 {
  if (false)
  {
    QString sTest("123456712312421353256456746");
    qDebug() << sTest.toLocal8Bit().size();
    qDebug() << sTest.toLocal8Bit();
    QVector<uint16_t> vU16Test;
    StringToU16Array(sTest, vU16Test);
    qDebug() << "vU16Test" << vU16Test;
    qDebug() << "vU16Test.size()" << vU16Test.size();
  }
#pragma endregion }

#pragma region U16ArrayToString测试 {
  if (false)
  {
    QVector<uint16_t> vTest;
    for (uint16_t u16Idx = 0; u16Idx < 10; u16Idx++)
    {
      vTest.push_back(u16Idx);
    }
    qDebug() << vTest;
    QString sTest = U16ArrayToString(vTest);
    qDebug() << sTest;
  }
#pragma endregion }

#pragma region StringToU16Array / U16ArrayToString联合测试 {
  if (false)
  {
    QVector<uint16_t> vTestInput, vTestOutput;
    for (uint16_t u16Idx = 65322; u16Idx < 65411; u16Idx++)
    {
      vTestInput.push_back(u16Idx);
    }
    qDebug() << "vTestInput" << vTestInput;
    qDebug() << "vTestInput.size()" << vTestInput.size();
    QString sTest = U16ArrayToString(vTestInput);
    qDebug() << "sTest.toLatin1().size()" << sTest.toLatin1().size();
    qDebug() << "sTest.size()" << sTest.size();

    StringToU16Array(sTest, vTestOutput);
    qDebug() << vTestOutput;
  }
#pragma endregion }

#pragma region++ 赋值 {
  if (false)
  {
    int nTest = 0;
    int nRes = ++nTest;
    qDebug() << nTest << nRes;
  }
#pragma endregion }

#pragma region u8数组强转char {
  if (false)
  {
    uint8_t u8Test[] = {100, 101};
    int nStep = 2;
    printf("u8Test %p\n", u8Test);
    std::cout << u8Test << std::endl;
    //    QString sTest = QString(QLatin1String((char*)u8Test));
    //    qDebug() << "sTest" << sTest;
  }
#pragma endregion }

#pragma region char* 数组测试 {
  if (false)
  {
    const char *charTest[] = {"X", "Y"};

    qDebug() << sizeof(charTest) / sizeof(char *);
  }
#pragma endregion }

#pragma region char* 数组指针测试 {
  if (false)
  {
    struct testStruct
    {
      testStruct()
      {
        a = 1;
        b = 2;
      }
      int a;
      int b;
    };
    QVector<testStruct *> vPtrTestStruct;
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
  if (false)
  {
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
  if (false)
  {
    int nVal1 = 10;
    qDebug() << nVal1 % 256;
    qDebug() << nVal1 % 3;
  }
#pragma endregion }

#pragma region QByteArray测试 {
  if (false)
  {
    // uint16_t数组转换成QByteArray
    QVector<uint16_t> vTest;
    for (uint16_t u16Idx = 110; u16Idx < 140; u16Idx++)
    {
      vTest.push_back(u16Idx);
    }
    char *pTest = reinterpret_cast<char *>(vTest.data());
    QByteArray arrTest(
        QByteArray::fromRawData(pTest, sizeof(uint16_t) * vTest.size()));
    qDebug() << "arrTest size" << arrTest.size();

    // QByteArray转换成uint16_t数组
    QVector<uint16_t> vOutput;
    uint16_t *p16Output = reinterpret_cast<uint16_t *>(arrTest.data());
    for (int nIdx = 0; nIdx < arrTest.size() / sizeof(uint16_t); nIdx++)
    {
      vOutput.push_back(*p16Output);
      p16Output++;
    }
    qDebug() << "vOutput" << vOutput;
  }
#pragma endregion }

#pragma region QDir测试 {
  if (false)
  {
    // 空字符串表示文件夹是否会被判定为存在
    QString sTestDir = "";
    QDir dirTest(sTestDir);
    if (dirTest.exists())
    {
      qDebug() << "文件夹" << sTestDir << "存在";
    }
    else
    {
      qDebug() << "文件夹" << sTestDir << "不存在";
    }
    // 结论：空字符串也会被认为文件夹存在，因此需要使用以下方式判断
    QFileInfo fileInfo(sTestDir);
    if (fileInfo.isDir())
    {
      qDebug() << "文件夹" << sTestDir << "存在";
    }
    else
    {
      qDebug() << "文件夹" << sTestDir << "不存在";
    }
  }
#pragma endregion }

#pragma region void*测试 {
  if (true)
  {
    int nVal = 10;
    printf("nVal Addr %p\n", &nVal);
    void *pVal = TestVoid(nVal);
    printf("nVal Addr after func %p\n", pVal);
  }
#pragma endregion }

  w.show();
  return a.exec();
}
