#include "demowindow.h"
#include "ui_demowindow.h"
#include "pages/flowlayoutpage.h"
#include "pages/cardpage.h"
#include "pages/toastpage.h"
#include "pages/searchboxpage.h"
#include "pages/buttonpage.h"
#include <QStackedWidget>
#include <QLabel>

DemoWindow::DemoWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DemoWindow)
{
    ui->setupUi(this);

    // 设置左侧导航栏样式
    ui->navigationList->setStyleSheet(
        // "QListWidget {"
        // "    background-color: #f5f5f5;"
        // "    border: none;"
        // "}"
        "QListWidget::item {"
        "    padding: 12px 16px;"
        // "    border-bottom: 1px solid #e0e0e0;"
        "}"
    //     "QListWidget::item:hover {"
    //     "    background-color: #e8e8e8;"
    //     "}"
    //     "QListWidget::item:selected {"
    //     "    background-color: #0078d4;"
    //     "    color: white;"
    //     "}"
    );

    // 创建页面堆栈
    QStackedWidget *stackedWidget = new QStackedWidget(this);
    
    // 创建 FlowLayout 演示页面
    FlowLayoutPage *flowLayoutPage = new FlowLayoutPage(this);
    stackedWidget->addWidget(flowLayoutPage);
    
    // 创建 CardPage 演示页面
    CardPage *cardPage = new CardPage(this);
    stackedWidget->addWidget(cardPage);
    
    // 创建 ToastPage 演示页面
    ToastPage *toastPage = new ToastPage(this);
    stackedWidget->addWidget(toastPage);
    
    // 创建 SearchBox 演示页面
    SearchBoxPage *searchBoxPage = new SearchBoxPage(this);
    stackedWidget->addWidget(searchBoxPage);
    
    // 创建 Button 演示页面
    Mad::ButtonPage *buttonPage = new Mad::ButtonPage(this);
    stackedWidget->addWidget(buttonPage);
    
    // 将堆栈widget添加到内容区域
    ui->contentLayout->addWidget(stackedWidget);
    
    // 设置堆栈widget的对象名称，方便后续访问
    stackedWidget->setObjectName("pageStackedWidget");

    // 连接导航信号
    connect(ui->navigationList, &QListWidget::currentRowChanged, this, [this](int index) {
        QStackedWidget *stackedWidget = ui->contentFrame->findChild<QStackedWidget*>("pageStackedWidget");
        if (stackedWidget) {
            stackedWidget->setCurrentIndex(index);
        }
    });

    // 连接关闭动作
    connect(ui->actionClose, &QAction::triggered, this, &DemoWindow::close);

    // 设置默认选中第一项
    ui->navigationList->setCurrentRow(0);
}

DemoWindow::~DemoWindow()
{
    delete ui;
}
