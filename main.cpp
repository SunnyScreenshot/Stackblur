#include "widget.h"
#include <QApplication>
#include <QDebug>
#include <QImage>
#include <QPainter>
#include <QColor>
#include <QDebug>
#include "./stackblur/master/imagefilter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // QImage image("C:/Users/Venn/Downloads/wiki定义图像.png");
    // float radius = 10.0f; // 阴影模糊的半径
    // QColor shadowColor(0, 0, 0, 0.1 * 255); // 半透明黑色阴影
    // ImageFilter::shadowBlur(image, radius, shadowColor);

    // 创建一个 200x200 像素的图像，格式为 ARGB32
    QImage image(200, 200, QImage::Format_ARGB32);
    image.fill(Qt::transparent); // 填充透明背景

    // 使用 QPainter 绘制自定义图形
    QPainter painter(&image);
    painter.setPen(QPen(QColor(0, 255, 0, 255), 2));
    painter.setBrush(QColor(255, 0, 0, 255)); // 红色填充
    painter.drawRect(50, 50, 100, 100); // 绘制一个 100x100 像素的红色矩形
    painter.end();

    // 设置阴影模糊的半径和颜色
    float radius = 1.0f; // 阴影模糊的半径
    QColor shadowColor(255, 255, 255, 0.3 * 255);

    // 对图像应用阴影模糊效果
    ImageFilter::shadowBlur(image, radius, shadowColor);

    image.save("D:/output_image.png");
    qDebug() << "D:/output_image.png";


    return a.exec();
}
