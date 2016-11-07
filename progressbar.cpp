#include "progressbar.h"
#include <QPainter>
#include <QtMath>
#include <QDebug>
#include <QPointer>
class Ellipse{
public:
    Ellipse(qreal a, qreal b, qreal r)
    {
    }
    void getXByY(qreal y, qreal & x1, qreal & x2)
    {
        qreal sq = sqrt(r * r - (y - b) * (y - b));
        x1 =  sq + a;
        x2 = -sq + a;
    }
    void getYByX(qreal x, qreal & y1, qreal & y2)
    {
        qreal sq = sqrt(r * r - (x - a) * (x - a));
        y1 =  sq + b;
        y2 = -sq + b;
    }
private:
    qreal a, b, r;
};
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
ProgressBar::ProgressBar(QWidget *parent) : QProgressBar(parent)
{
    m_current = 0;
    resize(parent->size());
    colors << QColor(51, 52, 54)
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
void ProgressBar::paintEvent(QPaintEvent *event)
{
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
void ProgressBar::paintSlider(QPainter &painter)
{
    PainterUser user(&painter);

    qreal a = 100;
    qreal b = 100;
    qreal r = 80;
    qreal roffset = 1.0;
    qreal angleOffset = 15;
    qreal currentangle = m_current ;
    for (int i = 0; i < colors.length(); i++) {
        qreal r0 = i * roffset;
        qreal angle = currentangle + i * angleOffset;

        qreal x0 = r * cos(qDegreesToRadians(angle)) + a;
        qreal y0 = r * sin(qDegreesToRadians(angle)) + b;
        painter.setPen(colors[i]);
        painter.setBrush(QBrush(colors[i]));
        painter.drawEllipse(x0  - r0, y0 - r0, 2 * r0, 2 * r0);
    }
}
void ProgressBar::paintSlider2(QPainter &painter)
{
    PainterUser user(&painter);
    qreal a = 300;
    qreal b = 100;
    qreal r = 75;

    qreal currentangle = m_current ;
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
void ProgressBar::paintSlider3(QPainter &painter)
{

}
void ProgressBar::paintSlider4(QPainter &painter)
{
    PainterUser user(&painter);
    qreal a = 700;
    qreal b = 100;
    qreal r = 80;

    qreal currentangle = m_current;
    qreal angleOffset = 360 / colors.length();
    qreal r0 = 16;
    for (int i = 0; i < colors.length(); i++) {
        qreal angle = currentangle + i * angleOffset;

        qreal x0 = r * cos(qDegreesToRadians(angle)) + a;
        qreal y0 = r * sin(qDegreesToRadians(angle)) + b;
        painter.setPen(colors[i]);
        painter.setBrush(QBrush(colors[i]));
        painter.drawEllipse(x0 - r0, y0 - r0, 2 * r0, 2 * r0);
    }
}
void ProgressBar::paintSlider5(QPainter &)
{
    PainterUser user(&painter);
    qreal a = 100;
    qreal b = 300;
    qreal r = 80;



}
void ProgressBar::paintSlider6(QPainter &)
{
    PainterUser user(&painter);
    qreal a = 100;
    qreal b = 300;
    qreal r = 80;

}
void ProgressBar::paintSlider7(QPainter &)
{
    PainterUser user(&painter);
    qreal a = 100;
    qreal b = 300;
    qreal r = 80;
}
void ProgressBar::paintSlider8(QPainter &)
{
    PainterUser user(&painter);
    qreal a = 100;
    qreal b = 300;
    qreal r = 80;
}
void ProgressBar::setCurrent(qreal v)
{
    m_current = v;
}
qreal ProgressBar::current() const
{
    return m_current;
}
