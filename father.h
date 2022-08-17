#ifndef FATHER_H
#define FATHER_H

#include <QObject>

class Father : public QObject {
  Q_OBJECT
 public:
  explicit Father(QObject *parent = nullptr);
  virtual void FuncTest1();

 protected:
  virtual void FuncTest2();
};

#endif  // FATHER_H
