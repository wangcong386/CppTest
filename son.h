#ifndef SON_H
#define SON_H

#include <QObject>
#include "father.h"

class Son : public Father {
  Q_OBJECT
 public:
  explicit Son(QObject *parent = nullptr);
  void FuncTest3();

 protected:
  void FuncTest1() override;
  void FuncTest2() override;
};

#endif  // SON_H
