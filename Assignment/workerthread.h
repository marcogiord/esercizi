#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QThread>
#include <QObject>
#include <QDebug>
#include "imageproperty.h"
#include "imagecreator.h"

class Worker : public QObject
{
    Q_OBJECT
public:
  Worker (QObject * parent);
  ~Worker();

  void SetProperty(const ImageProperty& property);
public slots:
  void doWork(const QString &parameter);
  //void OnSetImagePropoerty(const ImageProperty& p);
signals:
    void resultReady(const QString &result);
private:
    ImageProperty m_imageproperty;
};

//class WorkerThread : public QThread
//{
//    Q_OBJECT

//    WorkerThread();


//    void run() override {
//        QString result;
//        /* ... here is the expensive or blocking operation ... */
//        qDebug() << " Runnning " ;
//        emit resultReady(result);
//    }
//signals:
//    void resultReady(const QString &s);
//private:
//    ImageProperty *m_property;
//};



#endif // WORKERTHREAD_H
