#include "father.h"
#include <QDebug>

Father::Father(QObject *parent) : QObject(parent) {}

void Father::FuncTest1() { qDebug() << __func__ << "from Father"; }

void Father::FuncTest2() { qDebug() << __func__ << "from Father"; }
