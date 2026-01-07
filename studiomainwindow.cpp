#include "studiomainwindow.h"
#include "ui_studiomainwindow.h"
#include "demowindow.h"

MadStudioMainWindow::MadStudioMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StudioMainWindow)
    , m_demoWindow(nullptr)
{
    ui->setupUi(this);
    setupStyles();

    // 连接打开演示窗口的信号
    connect(ui->action, &QAction::triggered, this, &MadStudioMainWindow::onOpenDemoWindow);
}

MadStudioMainWindow::~MadStudioMainWindow()
{
    delete ui;
}

void MadStudioMainWindow::setupStyles()
{
    // 设置主窗口样式
    // ui->centralwidget->setStyleSheet(
    //     "QWidget {"
    //     "    background-color: #f0f0f0;"
    //     "}"
    // );
}

void MadStudioMainWindow::onOpenDemoWindow()
{
    if (!m_demoWindow) {
        m_demoWindow = new DemoWindow(this);
    }
    
    m_demoWindow->show();
    m_demoWindow->raise();
    m_demoWindow->activateWindow();
}
