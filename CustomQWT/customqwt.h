#ifndef CUSTOMQWT_H
#define CUSTOMQWT_H

#include <QMainWindow>
#include <QString>
#include <QColor>
#include <QPolygonF>

#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_grid.h>

namespace Ui {
class CustomQWT;
}

class CustomQWT : public QMainWindow
{
    Q_OBJECT

public:
    explicit CustomQWT(QWidget *parent = 0);
    ~CustomQWT();

private:
    Ui::CustomQWT *ui;
    QwtPlot *plot;

    QPolygonF calcSine(int phase);
    void setPoints(QString name, QPolygonF points, QColor color);
};

#endif // CUSTOMQWT_H
