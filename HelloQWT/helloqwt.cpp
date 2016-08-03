#include "helloqwt.h"
#include "ui_helloqwt.h"


HelloQWT::HelloQWT(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::HelloQWT) {
    ui->setupUi(this);

    plot = new QwtPlot(this);
    plot->setTitle("Hello QWT");

    QPolygonF p1 = calcSine(0);
    setPoints("Sine 1", p1, Qt::magenta);

    QPolygonF p2 = calcSine(90);
    setPoints("Sine 2", p2, Qt::green);

    ui->centralLayout->addWidget(plot, 1);
}

HelloQWT::~HelloQWT() {
    delete ui;
}

QPolygonF HelloQWT::calcSine(int phase) {
    QPolygonF points;

    for (int i = 0; i <= 360; i++) {
        int deg = i;
        // add phase
        deg += phase;

        if (deg > 360)
            deg -= 360;

        // main calculation
        float x = deg * M_PI / 180;
        float sinY = sinf(x);

        // set amplidude
        sinY *= 5.0f;

        points << QPointF(i, sinY);
    }

    return points;
}

void HelloQWT::setPoints(QString name, QPolygonF points, QColor color) {
    QwtPlotCurve *curve = new QwtPlotCurve(name);

    curve->setPen(color, 3.0);

    curve->setSamples(points);

    curve->attach(plot);
}
