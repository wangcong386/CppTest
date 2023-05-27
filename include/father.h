#ifndef FATHER_H
#define FATHER_H

#include <QObject>
#include <QDebug>

class Father : public QObject
{
  Q_OBJECT
public:
  explicit Father(QObject *parent = nullptr);
  virtual ~Father() { qDebug() << "析构函数"; }
  virtual void FuncTest1(double dVal, std::string sVal);
  virtual void FuncTest11(double dVal, int nVal);
  virtual void FuncTest4(int nVal);

protected:
  virtual void FuncTest2();
  static const uint32_t kTestVal1 = 100;
};

#endif // FATHER_H
