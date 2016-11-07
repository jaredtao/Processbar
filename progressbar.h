#ifndef PROCESSBAR_H
#define PROCESSBAR_H

#include <QObject>
#include <QProgressBar>
#include <QList>
#include <QColor>
class ProgressBar : public QProgressBar
{
    Q_OBJECT
public:
    ProgressBar(QWidget *parent = 0);
    void setCurrent(qreal v);
    qreal current() const;
protected:
    void paintEvent(QPaintEvent *) override;
signals:

public slots:
private:
    void paintSlider(QPainter &);
    void paintSlider2(QPainter &);
    void paintSlider3(QPainter &);
    void paintSlider4(QPainter &);
    void paintSlider5(QPainter &);
    void paintSlider6(QPainter &);
    void paintSlider7(QPainter &);
    void paintSlider8(QPainter &);


    QList<QColor> colors;
    qreal m_current;
};

#endif // PROCESSBAR_H
