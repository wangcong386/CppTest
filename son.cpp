#include "son.h"
#include <QDebug>

Son::Son(QObject *parent) {}

void Son::FuncTest3() { qDebug() << __func__ << "from Son"; }

void Son::FuncTest1() { qDebug() << __func__ << "from Son"; }

void Son::FuncTest2() { qDebug() << __func__ << "from Son"; }
