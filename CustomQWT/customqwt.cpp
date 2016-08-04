#include "customqwt.h"
#include "ui_customqwt.h"

CustomQWT::CustomQWT(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::CustomQWT) {
    ui->setupUi(this);

    plot = new QwtPlot(this);
    plot->setTitle("Custom QWT");

    // style the plot view
    QwtPlotCanvas *canvas = new QwtPlotCanvas(plot);
    canvas->setPalette(QColor(Qt::white));
    canvas->setBorderRadius(5);
    plot->setCanvas(canvas);

    // add grid
    QwtPlotGrid *grid = new QwtPlotGrid();
    grid->enableYMin(true);
//    grid->enableX(false);
    grid->setMajorPen(QColor(Qt::gray), 1.0, Qt::DashLine);
    grid->setMinorPen(QColor(Qt::lightGray), 1.0, Qt::DotLine);
    grid->attach(plot);

    // create and set curve points
    QPolygonF p1 = calcSine(0);
    setPoints("Sine 1", p1, Qt::magenta);

    QPolygonF p2 = calcSine(90);
    setPoints("Sine 2", p2, Qt::green);

    // add QwtPlot object to GUI
    ui->centralLayout->addWidget(plot, 1);
}

CustomQWT::~CustomQWT() {
    delete ui;
}

QPolygonF CustomQWT::calcSine(int phase) {
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

void CustomQWT::setPoints(QString name, QPolygonF points, QColor color) {
    QwtPlotCurve *curve = new QwtPlotCurve(name);

    curve->setPen(color, 3.0);

    curve->setSamples(points);

    curve->attach(plot);
}
