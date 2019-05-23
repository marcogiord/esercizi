#ifndef TASKHANDLER_H
#define TASKHANDLER_H

#include <QtConcurrent>
#include <QDebug>
#include <QThread>
#include <QFutureWatcher>
#include <QObject>
#include "imagecreator.h"
#include "workerthread.h"


class Controller : public QObject
{
    Q_OBJECT
    QThread workerThread;
public:
    Controller(const ImageProperty& property, QObject * parent = 0): QObject(parent), m_imageproperty(property)
    {
        Worker *worker = new Worker(NULL);
        worker->SetProperty(property);
        worker->moveToThread(&workerThread);
        connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
        connect(this, &Controller::operate, worker, &Worker::doWork);
        connect(worker, &Worker::resultReady, this, &Controller::handleResults);
        workerThread.start();
    }
    ~Controller() {
        workerThread.quit();
        workerThread.wait();
    }
public slots:
    void handleResults(const QString &);
signals:
    void operate(const QString &);
private:
    ImageProperty m_imageproperty;
};

//class TaskHandler : public QObject
//{
//  Q_OBJECT
//public:

//  TaskHandler();
//  void startWorkInAThread()
//  {
//    WorkerThread *workerThread = new WorkerThread;
//    connect(workerThread, &WorkerThread::resultReady, this, &TaskHandler::handleResults);
//    connect(workerThread, &WorkerThread::finished, workerThread, &QObject::deleteLater);
//    workerThread->start();
//  }
//signals:
//  void handleResults();

//}


#endif // TASKHANDLER_H
