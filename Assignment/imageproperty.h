#ifndef IMAGEPROPERTY_H
#define IMAGEPROPERTY_H

#include <QString>

enum Action
{
  CREATE_IMAGE = 0,
  CREAT_CIRCLE,
  EXIT
};

struct ImagePropertyData {
  QString m_strNameImage;
  int m_width;
  int m_height;
  int m_radius;
  int m_centerX;
  int m_centerY;

  ImagePropertyData(): m_strNameImage(QString("")),
    m_width(0),
    m_height(0),
    m_radius(0),
    m_centerX(0),
    m_centerY(0) {}

 };

class ImageProperty
{
public:
    ImageProperty(){};
    ImageProperty(const ImagePropertyData& data);
    void GetProperties(ImagePropertyData& data);

private:

  ImagePropertyData m_properties;
};

#endif // IMAGEPROPERTY_H
