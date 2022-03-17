#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPen>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // populate the combo box
     ui->shapeComboBox->addItem("Rectangle");
     ui->shapeComboBox->addItem("Ellipse");

     // put limits on the pen width
    ui->penWidthSpinBox->setRange(0, 20);

    // make a connection to changes in the values to redraw
    connect(ui->shapeComboBox, &QComboBox::currentTextChanged, this, &MainWindow::valuesChanged);
    connect(ui->penWidthSpinBox, &QSpinBox::valueChanged, this,&MainWindow::valuesChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Override the default paintEvent with drawing of the shape
void MainWindow::paintEvent(QPaintEvent *) {
 // Create a painter
 QPainter painter(this);
 QPen pen(Qt::black);
 int penWidth = ui->penWidthSpinBox->value();
 pen.setWidth(penWidth);
 painter.setPen(pen);
 //painter.setBrush(Qt::blue);
pen.setFill(0,0,255);
 QRect rect(10, 20, 80, 60);
 int shapeNum = ui->shapeComboBox->currentIndex();
 switch (shapeNum) {
 case 0:
 painter.drawRect(rect);
 break;
 case 1:
 painter.drawEllipse(rect);
 break;
 }
}

void MainWindow::valuesChanged(){
    update();
}





