#ifndef BASE_H
#define BASE_H

#include <QObject>

class Base : public QObject {
  Q_OBJECT
 public:
  explicit Base(QObject *parent = nullptr);

 signals:

  void SigTest();

 private:
  int iTest;
};

#endif  // BASE_H
