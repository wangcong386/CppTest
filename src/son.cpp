#include "son.h"
#include <QDebug>

Son::Son(QObject *parent) {}

void Son::FuncTest3() { qDebug() << __func__ << "from Son"; }

void Son::FuncTest4(int nVal) { qDebug() << __func__ << "from Son"; }

void Son::FuncTest1(const double dVal, const std::string sVal) {
  qDebug() << __func__ << "from Son";
}

// void Son::FuncTest11(int nVal1, int nVal2) {
//  qDebug() << __func__ << "from Son" << nVal1 << nVal2;
//}

void Son::FuncTest11(double dVal, double dVal1) {
  qDebug() << __func__ << "from Son";
}

void Son::FuncTest2() { qDebug() << __func__ << "from Son"; }
