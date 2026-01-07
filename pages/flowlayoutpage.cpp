#include "flowlayoutpage.h"
#include "ui_flowlayoutpage.h"
#include "../madwidgets/flowlayout.h"
#include <QPushButton>

FlowLayoutPage::FlowLayoutPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FlowLayoutPage)
{
    ui->setupUi(this);
    setupStyles();
    setupDemoButtons();
}

FlowLayoutPage::~FlowLayoutPage()
{
    delete ui;
}

void FlowLayoutPage::setupStyles()
{
    // 设置滚动区域样式
    ui->scrollArea->setFrameShape(QFrame::NoFrame);

    // 设置 FlowLayout 容器样式
    // ui->flowLayoutContainer->setStyleSheet(
    //     "QFrame {"
    //     "    background-color: white;"
    //     "    border: 1px solid #d0d0d0;"
    //     "    border-radius: 4px;"
    //     "}"
    // );
}

void FlowLayoutPage::setupDemoButtons()
{
    // 创建 FlowLayout
    Mad::FlowLayout *flowLayout = new Mad::FlowLayout(ui->flowLayoutContainer, 10, 10, 10);
    ui->flowLayoutContainer->setLayout(flowLayout);

    // 添加不同大小的按钮来演示 FlowLayout 的自动换行效果
    const QStringList buttonTexts = {
        "短按钮",
        "中等长度按钮",
        "这是一个很长的按钮文本",
        "按钮",
        "FlowLayout",
        "自动换行测试",
        "Qt 布局管理器",
        "MadStudio",
        "演示",
        "这是一个非常长的按钮文本，用于测试换行效果",
        "短",
        "中等",
        "长文本按钮",
        "测试",
        "流式布局",
        "自适应",
        "窗口大小",
        "动态调整",
        "按钮1",
        "按钮2",
        "按钮3",
        "按钮4",
        "按钮5",
        "按钮6",
        "按钮7",
        "按钮8",
        "按钮9",
        "按钮10"
    };

    // 为每个按钮设置不同的样式
    QStringList buttonStyles = {
        "background-color: #0078d4; color: white; border-radius: 5px; padding: 8px 16px;",
        "background-color: #107c10; color: white; border-radius: 5px; padding: 8px 16px;",
        "background-color: #d83b01; color: white; border-radius: 5px; padding: 8px 16px;",
        "background-color: #ff8c00; color: white; border-radius: 5px; padding: 8px 16px;",
        "background-color: #5c2d91; color: white; border-radius: 5px; padding: 8px 16px;"
    };

    for (int i = 0; i < buttonTexts.size(); ++i) {
        QPushButton *btn = new QPushButton(buttonTexts[i]);
        btn->setMinimumSize(80, 30);
        btn->setStyleSheet(buttonStyles[i % buttonStyles.size()]);
        flowLayout->addWidget(btn);
    }
}
