#include "workerthread.h"


Worker::Worker(QObject * parent) : QObject(parent)
{
  doWork(QString("i am starting to work"));
}

Worker::~Worker()
{

}

void Worker::SetProperty(const ImageProperty& property)
{
    m_imageproperty = property;
}


void Worker::doWork(const QString &parameter) {

    QString result;
    qDebug() << "We are in the do work code" ;
    ImageCreator creator(m_imageproperty);
    creator.RunCreator();


    /* ... here is the expensive or blocking operation ... */
    emit resultReady(result);
}


//void Worker::OnSetImagePropoerty(const ImageProperty& p)
//{
//  m_imageproperty = p;

//}
