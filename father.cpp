#include "father.h"
#include <QDebug>

Father::Father(QObject *parent) : QObject(parent) {}

void Father::FuncTest1(double dVal, std::string sVal) {
  qDebug() << __func__ << "from Father";
}

void Father::FuncTest11(double dVal, int nVal) {
  qDebug() << __func__ << "from Father" << dVal << nVal;
}

void Father::FuncTest4(int nVal) { qDebug() << __func__ << "from Father"; }

void Father::FuncTest2() {
  FuncTest4(kTestVal1);
  qDebug() << __func__ << "from Father";
}
