#ifndef IMAGECREATOR_H
#define IMAGECREATOR_H

#include "imageproperty.h"
//#include <QPixmap>
#include <QFile>

class ImageCreator
{

public:
    //ImageCreator();
    ImageCreator(const ImageProperty& property);
    //void SetProperty(const ImageProperty& property);
    void RunCreator();
private:
    void CreateImage();
    void DrawCircleInImage();
    void SaveImageToFile();

    ImageProperty m_property;
    std::vector<unsigned char> m_image; // 1 byte image

};

#endif // IMAGECREATOR_H
