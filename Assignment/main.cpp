#include <QCoreApplication>


#include "QString.h"
#include "QDir.h"
#include "QCommandLineParser.h"
#include <iostream>
#include "taskhandler.h"
#include "imageproperty.h"
#include "imagecreator.h"

int main(int argc, char * argv[])
{
  // Verify input arguments
  if (argc < 2)
  {
    std::cout << "Usage: " << argv[0] << " [-start] <nameImage> <width> <height > [-circle] <radius> <centerX> <centerY> [-exit]"
                           << std::endl;
    return EXIT_FAILURE;
  }

  QString commandlineArgument;
  // read in arguments
  for (int ii = 1; ii < argc; ++ii) // argv[0] contains executable name
    commandlineArgument += QString (" ") + argv [ii];
  //  ("commandlineArgument: " + commandlineArgument);
  QStringList commandlineArgumentList = commandlineArgument.split (" -");

  ImagePropertyData props;


  // states evariable
  bool start_mode = false;
  bool circle_mode = false;
  bool exit_mode = false;

  // loop over arguments
  foreach (QString command, commandlineArgumentList)
  {
    if (command.startsWith ("start "))
    {
      QString fullStringStart = command.remove (0, QString ("start ").length ());
      QStringList imageProperties = fullStringStart.split (" ");

      props.m_strNameImage = imageProperties[0];
      props.m_width = imageProperties[1].toInt();
      props.m_height = imageProperties[2].toInt();
      start_mode = true;
    }
    else if (command.startsWith ("circle "))
    {
      QString fullStringCircle = command.remove (0, QString ("circle ").length ());;
      QStringList circleProperties = fullStringCircle.split (" ");
      props.m_radius = circleProperties[0].toInt();
      props.m_centerX = circleProperties[1].toInt();
      props.m_centerY = circleProperties[2].toInt();
      circle_mode = true;
    }
    else if (command.startsWith ("exit "))
    {
      exit_mode = true;
    }
  }

  std::cout << " name file: " << props.m_strNameImage.toStdString() << std::endl;
  std::cout << " height: " << props.m_height << std::endl;
  std::cout << " width: " << props.m_width << std::endl;

  // itntiailize property class
  ImageProperty property(props);

  // check whch action has to be performed
  if (start_mode)
  {
        //creator->CheckProperties(); // this checks if images exists and if so it modifies the file name
        //creator->CreateImage(); // this creates an empty image
    Controller controller(property);

  }

  if (circle_mode)
  {
        //creator->DrawCircleInImage(); // this creates an empty image
  }

  if (exit_mode)
  {
      // not sure what this has to do
  }

  //delete creator;



  return EXIT_SUCCESS;
}
