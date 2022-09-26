#ifndef SON_H
#define SON_H

#include <QObject>
#include "father.h"

class Son : public Father {
  Q_OBJECT
 public:
  explicit Son(QObject* parent = nullptr);
  // 测试：继承父类函数重写时参数不一样到什么程度会无法重写
  // 1.参数类型&数量&名称相同，关键字不同
  // 1.结论：重写生效
  void FuncTest1(const double dVal, const std::string sVal) override;
  // 2.参数数量不同
  // 2.结论：无法重写
  void FuncTest11(double dVal, double dVal1);
  // 3.参数数量相同，类型不同
  // 3.结论：无法重写
  //  void FuncTest11(int nVal1, int nVal2) override;
  // 父类指针指向子类对象时无法直接调用子类才有的函数
  void FuncTest3();

  // 测试：子类同名函数隐藏父类函数时，父类指针指向子类对象时调用的是哪个函数
  // 结论：参数数量或类型不同的同名函数，无法通过指针调用
  void FuncTest4(int nVal) override;

 protected:
  void FuncTest2() override;
};

#endif  // SON_H
