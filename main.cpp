#include <QApplication>
#include <QDebug>
#include <QRandomGenerator>
#include <QVector>
#include <algorithm>
#include <iostream>
#include <vector>

#include "father.h"
#include "mainwindow.h"
#include "son.h"

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  MainWindow w;

  Father* pFatherObj = new Son;
  pFatherObj->FuncTest1();

  delete pFatherObj;
  pFatherObj = nullptr;
  w.show();
  return a.exec();
}
