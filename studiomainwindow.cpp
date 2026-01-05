#include "studiomainwindow.h"
#include "ui_studiomainwindow.h"
#include "flowlayout.h"

MadStudioMainWindow::MadStudioMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StudioMainWindow)
{
    ui->setupUi(this);

    FlowLayout layout;
    qDebug() << layout.metaObject()->className();
}

MadStudioMainWindow::~MadStudioMainWindow()
{
    delete ui;
}
