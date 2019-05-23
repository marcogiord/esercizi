

#include "ARWorker.h"

AR::ARWorker::ARWorker (QObject * parent)
  : QObject (parent)
{
}

AR::ARWorker::~ARWorker ()
{
}

void AR::ARWorker::process ()
{
  // implemented in derived class
  Execute ();

  emit finished ();
}

void AR::ARWorker::Execute ()
{
  // should be implemented in derived class
}

#include <QThread>

#include "ARWorkStarter.h"

AR::ARWorkStarter::ARWorkStarter (AR::ARWorker * worker)
  : QObject (NULL)
{
  // Start the work in its own thread and destruct QThread and worker when finished
  // See https://mayaposch.wordpress.com/2011/11/01/how-to-really-truly-use-qthreads-the-full-explanation/ 

  QThread* thread = new QThread;
  worker->moveToThread (thread);
  //connect (worker, SIGNAL (error (QString)), this, SLOT (errorString (QString)));
  connect (thread, SIGNAL (started ()), worker, SLOT (process ()));
  connect (worker, SIGNAL (finished ()), thread, SLOT (quit ()));
  connect (worker, SIGNAL (finished ()), worker, SLOT (deleteLater ()));
  connect (thread, SIGNAL (finished ()), thread, SLOT (deleteLater ()));
  thread->start ();
}

AR::ARWorkStarter::~ARWorkStarter ()
{
}



#include <QObject>

#include "arlogic_export.h"

namespace AR
{
  class ARLOGIC_EXPORT ARWorker : public QObject
  {
    Q_OBJECT

  public:
    ARWorker (QObject * parent);
    ~ARWorker ();

    public slots:
    void process ();

  signals:
    void finished ();

  private:
    virtual void Execute ();
  };
}

#endif // 

