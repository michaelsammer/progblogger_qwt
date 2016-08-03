#ifndef HELLOQWT_H
#define HELLOQWT_H

#include <QMainWindow>
#include <QString>
#include <QColor>
#include <QPolygonF>

#include <qwt_plot.h>
#include <qwt_plot_curve.h>

namespace Ui {
class HelloQWT;
}

class HelloQWT : public QMainWindow
{
    Q_OBJECT

public:
    explicit HelloQWT(QWidget *parent = 0);
    ~HelloQWT();

private:
    Ui::HelloQWT *ui;
    QwtPlot *plot;

    QPolygonF calcSine(int phase);
    void setPoints(QString name, QPolygonF points, QColor color);
};

#endif // HELLOQWT_H
