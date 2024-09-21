#ifndef IMAGEFILTER_H
#define IMAGEFILTER_H

class QImage;
class QColor;

class ImageFilter
{
public:
    // Blurs the alpha channel of the image and recolors it to the specified color.
    // The image must have transparent padding on all sides, or the shadow will be clipped.
    static void shadowBlur(QImage &image, float radius, const QColor &color);
};

#endif
