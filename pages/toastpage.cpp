#include "toastpage.h"
#include "ui_toastpage.h"
#include "../madwidgets/toastmanager.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

ToastPage::ToastPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ToastPage)
{
    ui->setupUi(this);

    // 设置滚动区域样式
    ui->scrollArea->setFrameShape(QFrame::NoFrame);

    // 创建按钮容器布局
    QVBoxLayout *buttonsLayout = new QVBoxLayout(ui->buttonsContainer);
    buttonsLayout->setSpacing(12);
    buttonsLayout->setContentsMargins(0, 0, 0, 0);

    // 添加说明标签
    QLabel *descriptionLabel = new QLabel("点击下方按钮查看不同类型的通知消息效果：", this);
    descriptionLabel->setStyleSheet("font-size: 14px; color: #666;");
    buttonsLayout->addWidget(descriptionLabel);

    // 信息消息按钮
    QPushButton *infoButton = new QPushButton("显示信息消息", this);
    infoButton->setStyleSheet(
        "QPushButton {"
        "    background-color: #2196F3;"
        "    color: white;"
        "    border: none;"
        "    border-radius: 4px;"
        "    padding: 10px 20px;"
        "    font-size: 14px;"
        "}"
        "QPushButton:hover {"
        "    background-color: #1976D2;"
        "}"
        );
    connect(infoButton, &QPushButton::clicked, this, &ToastPage::onShowInfoClicked);
    buttonsLayout->addWidget(infoButton);

    // 成功消息按钮
    QPushButton *successButton = new QPushButton("显示成功消息", this);
    successButton->setStyleSheet(
        "QPushButton {"
        "    background-color: #4CAF50;"
        "    color: white;"
        "    border: none;"
        "    border-radius: 4px;"
        "    padding: 10px 20px;"
        "    font-size: 14px;"
        "}"
        "QPushButton:hover {"
        "    background-color: #388E3C;"
        "}"
        );
    connect(successButton, &QPushButton::clicked, this, &ToastPage::onShowSuccessClicked);
    buttonsLayout->addWidget(successButton);

    // 警告消息按钮
    QPushButton *warningButton = new QPushButton("显示警告消息", this);
    warningButton->setStyleSheet(
        "QPushButton {"
        "    background-color: #FF9800;"
        "    color: white;"
        "    border: none;"
        "    border-radius: 4px;"
        "    padding: 10px 20px;"
        "    font-size: 14px;"
        "}"
        "QPushButton:hover {"
        "    background-color: #F57C00;"
        "}"
        );
    connect(warningButton, &QPushButton::clicked, this, &ToastPage::onShowWarningClicked);
    buttonsLayout->addWidget(warningButton);

    // 错误消息按钮
    QPushButton *errorButton = new QPushButton("显示错误消息", this);
    errorButton->setStyleSheet(
        "QPushButton {"
        "    background-color: #F44336;"
        "    color: white;"
        "    border: none;"
        "    border-radius: 4px;"
        "    padding: 10px 20px;"
        "    font-size: 14px;"
        "}"
        "QPushButton:hover {"
        "    background-color: #D32F2F;"
        "}"
        );
    connect(errorButton, &QPushButton::clicked, this, &ToastPage::onShowErrorClicked);
    buttonsLayout->addWidget(errorButton);

    // 多个消息按钮
    QPushButton *multipleButton = new QPushButton("显示多个消息", this);
    multipleButton->setStyleSheet(
        "QPushButton {"
        "    background-color: #9C27B0;"
        "    color: white;"
        "    border: none;"
        "    border-radius: 4px;"
        "    padding: 10px 20px;"
        "    font-size: 14px;"
        "}"
        "QPushButton:hover {"
        "    background-color: #7B1FA2;"
        "}"
        );
    connect(multipleButton, &QPushButton::clicked, this, &ToastPage::onShowMultipleClicked);
    buttonsLayout->addWidget(multipleButton);

    // 添加弹簧，使按钮靠上
    buttonsLayout->addStretch();
}

ToastPage::~ToastPage()
{
    delete ui;
}

void ToastPage::onShowInfoClicked()
{
    Mad::ToastManager::instance()->showInfo(this->window(), "这是一条信息消息");
}

void ToastPage::onShowSuccessClicked()
{
    Mad::ToastManager::instance()->showSuccess(this->window(), "操作成功完成！");
}

void ToastPage::onShowWarningClicked()
{
    Mad::ToastManager::instance()->showWarning(this->window(), "请注意：这是一个警告消息");
}

void ToastPage::onShowErrorClicked()
{
    Mad::ToastManager::instance()->showError(this->window(), "发生错误：操作失败");
}

void ToastPage::onShowMultipleClicked()
{
    Mad::ToastManager::instance()->showInfo(this->window(), "第一条消息");
    Mad::ToastManager::instance()->showSuccess(this->window(), "第二条消息");
    Mad::ToastManager::instance()->showWarning(this->window(), "第三条消息");
    Mad::ToastManager::instance()->showError(this->window(), "第四条消息");
}