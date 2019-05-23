#include "imageproperty.h"

ImageProperty::ImageProperty(const ImagePropertyData& data ) :
  m_properties(data)
{

}

void ImageProperty::GetProperties(ImagePropertyData& data)
{
  data = m_properties;
}
