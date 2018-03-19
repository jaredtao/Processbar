#include "progressbar.h"
#include <QPainter>
#include <QtMath>
#include <QDebug>
#include <QPointer>

class PainterUser {
public:
    PainterUser(QPainter *painter):m_painter(painter) {
        m_painter->save();
    }
    ~PainterUser() {
        m_painter->restore();
    }
private:
    Q_DISABLE_COPY(PainterUser)
    QPainter* m_painter;
};
ProgressBar::ProgressBar(QWidget *parent) : QProgressBar(parent) {
    mCurrent = 0;
    resize(parent->size());
    mColorList << QColor(51, 52, 54)
               << QColor(75, 85, 86)
               << QColor(87, 103, 103)
               << QColor(95, 119, 121)
               << QColor(101, 132, 134)
               << QColor(104, 146, 145)
               << QColor(104, 158, 158)
               << QColor(101, 169, 168)
               << QColor(92, 182, 180)
               << QColor(79, 194, 191);
}
void ProgressBar::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event)

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing|QPainter::TextAntialiasing);

    paintSlider(painter);
    paintSlider2(painter);
    paintSlider3(painter);
    paintSlider4(painter);
    paintSlider5(painter);
    paintSlider6(painter);
    paintSlider7(painter);
    paintSlider8(painter);

}
void ProgressBar::paintSlider(QPainter &painter) {
    PainterUser user(&painter);
    //原点x坐标
    qreal a = 100;
    //原点y坐标
    qreal b = 100;
    //半径
    qreal r = 80;
    //每个小圆的半径递增值
    qreal roffset = 2;
    //每个小圆的角度递增值
    qreal angleOffset = 30;

    qreal currentangle = mCurrent ;

    for (int i = 0; i < mColorList.length(); i++) {
        qreal r0 = i * roffset;
        qreal angle = currentangle + i * angleOffset;

        qreal x0 = r * cos(qDegreesToRadians(angle)) + a;
        qreal y0 = r * sin(qDegreesToRadians(angle)) + b;
        painter.setPen(mColorList[i]);
        painter.setBrush(QBrush(mColorList[i]));
        painter.drawEllipse(x0  - r0, y0 - r0, 2 * r0, 2 * r0);
    }
}
void ProgressBar::paintSlider2(QPainter &painter) {
    PainterUser user(&painter);
    qreal a = 300;
    qreal b = 100;
    qreal r = 75;

    qreal currentangle = mCurrent ;
    qreal sweepangle = 60 ;
    qreal inr  = r;
    qreal outr = r + 20;
    QConicalGradient gradiant(a, b, currentangle);
    //    gradiant.setCenter(0.5, 0.5);
    gradiant.setColorAt(0, QColor(100, 170, 169));
    //    gradiant.setColorAt(1 / 6 * 0.7, QColor(100, 172, 169));
    //    gradiant.setColorAt(1 / 6, QColor(23, 23, 23));

    painter.setBrush(QBrush(gradiant));

    QPainterPath path(QPointF(a + inr * cos(qDegreesToRadians(180 -  currentangle)), b + inr * sin(qDegreesToRadians(180 - currentangle ))));
    path.arcTo(QRect(a - inr, b - inr, inr * 2, inr * 2), currentangle, sweepangle);
    path.arcTo(QRect(a - outr, b - outr, outr * 2, outr * 2), currentangle + sweepangle, -sweepangle);
    path.closeSubpath();

    painter.drawPath(path);
}
void ProgressBar::paintSlider3(QPainter &painter) {
    PainterUser user(&painter);
    //原点x坐标
    qreal a = 500;
    //原点y坐标
    qreal b = 100;
    //半径
    qreal r = 80;

    qreal r1 = r / 2;
    qreal r2 = r / 6;
    qreal currentangle = mCurrent;
    //red 部分
    {
        painter.setBrush(QBrush(QColor(128, 1, 1)));

        QPainterPath path(QPointF(a + r * cos(qDegreesToRadians( currentangle )), b - r * sin(qDegreesToRadians(currentangle ))));
        path.arcTo(a - r, b - r,
                   r * 2, r * 2,
                   currentangle, 180);
        path.arcTo(a + r1 * cos(qDegreesToRadians(currentangle + 180)) - r1, b - r1 * sin(qDegreesToRadians(currentangle + 180)) - r1,
                   r1 * 2, r1 * 2,
                   currentangle + 180, 180);
        path.arcTo(a + r1*cos(qDegreesToRadians(currentangle)) - r1, b - r1 * sin(qDegreesToRadians(currentangle)) - r1,
                   r1 * 2, r1 * 2,
                   currentangle + 180, -180
                   );

        painter.drawPath(path);
    }

    //blue 部分
    {
        painter.setBrush(QBrush(QColor(1, 1, 128)));
        QPainterPath path(QPointF(a + r * cos(qDegreesToRadians( currentangle )), b - r * sin(qDegreesToRadians(currentangle ))));
        path.arcTo(a - r, b - r,
                   r * 2, r * 2,
                   currentangle, -180);
        path.arcTo(a + r1 * cos(qDegreesToRadians(currentangle + 180)) - r1, b - r1 * sin(qDegreesToRadians(currentangle + 180)) - r1,
                   r1 * 2, r1 * 2,
                   currentangle + 180, 180);
        path.arcTo(a + r1*cos(qDegreesToRadians(currentangle)) - r1, b - r1 * sin(qDegreesToRadians(currentangle)) - r1,
                   r1 * 2, r1 * 2,
                   currentangle + 180, -180
                   );

        painter.drawPath(path);
    }
    {
        // red 小圆
        painter.setBrush(QBrush(QColor(128, 1, 1)));
        QPainterPath path;
        path.addEllipse(a + r1 * cos(qDegreesToRadians(currentangle)) - r2, b - r1 * sin(qDegreesToRadians(currentangle )) - r2,
                        r2 * 2, r2 * 2);
        painter.drawPath(path);
    }
    {
        //blue 小圆
        painter.setBrush(QBrush(QColor(1, 1, 128)));
        QPainterPath path;
        path.addEllipse(a + r1 * cos(qDegreesToRadians(180 + currentangle)) - r2, b - r1 * sin(qDegreesToRadians(180 + currentangle)) - r2,
                        r2 * 2, r2 * 2);
        painter.drawPath(path);
    }

}
void ProgressBar::paintSlider4(QPainter &painter) {
    PainterUser user(&painter);
    qreal a = 800;
    qreal b = 100;
    qreal r = 80;

    qreal currentangle = mCurrent;
    qreal angleOffset = 360 / mColorList.length();
    qreal r0 = 16;
    for (int i = 0; i < mColorList.length(); i++) {
        qreal angle = currentangle + i * angleOffset;

        qreal x0 = r * cos(qDegreesToRadians(angle)) + a;
        qreal y0 = r * sin(qDegreesToRadians(angle)) + b;
        painter.setPen(mColorList[i]);
        painter.setBrush(QBrush(mColorList[i]));
        painter.drawEllipse(x0 - r0, y0 - r0, 2 * r0, 2 * r0);
    }
}
void ProgressBar::paintSlider5(QPainter &painter) {
    PainterUser user(&painter);
    qreal a = 100;
    qreal b = 400;
    qreal r = 80;
    qreal currentangle = mCurrent * 16;
    qreal sweepangle = 60 * 16;
    painter.setPen(QColor(97, 117, 118));
    painter.setBrush(QBrush(QColor(97, 117, 118)));
    painter.drawEllipse(a - r, b - r, r * 2, r * 2);

    painter.setPen(QColor(79, 194, 191));
    painter.setBrush(QColor(79, 194, 191));
    painter.drawPie(a - r, b - r, r * 2, r * 2, currentangle, sweepangle);
}
void ProgressBar::paintSlider6(QPainter &painter) {
    PainterUser user(&painter);
    //    qreal a = 300;
    //    qreal b = 400;
    //    qreal r = 80;

}
void ProgressBar::paintSlider7(QPainter &painter) {
    PainterUser user(&painter);
    //    qreal a = 100;
    //    qreal b = 300;
    //    qreal r = 80;
}
void ProgressBar::paintSlider8(QPainter &painter) {
    PainterUser user(&painter);
    //    qreal a = 100;
    //    qreal b = 300;
    //    qreal r = 80;
}
void ProgressBar::setCurrent(qreal v) {
    mCurrent = v;
}
qreal ProgressBar::current() const {
    return mCurrent;
}
