#include "cardpage.h"
#include "ui_cardpage.h"
#include "../madwidgets/card.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

CardPage::CardPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CardPage)
{
    ui->setupUi(this);

    // 设置滚动区域样式
    ui->scrollArea->setFrameShape(QFrame::NoFrame);

    // 创建卡片容器布局
    QVBoxLayout *cardsLayout = new QVBoxLayout(ui->cardsContainer);
    cardsLayout->setSpacing(16);
    cardsLayout->setContentsMargins(0, 0, 0, 0);

    // 基础卡片
    Mad::Card *basicCard = new Mad::Card(this);
    basicCard->setTitle("基础卡片");
    basicCard->setContent("这是一个基础的卡片组件，带有阴影和圆角效果。");
    basicCard->setBorderRadius(8);
    cardsLayout->addWidget(basicCard);

    // 可点击卡片
    Mad::Card *clickableCard = new Mad::Card(this);
    clickableCard->setTitle("可点击卡片");
    clickableCard->setContent("这个卡片可以点击，悬停时会有高亮效果。");
    clickableCard->setClickable(true);
    clickableCard->setBorderRadius(12);
    connect(clickableCard, &Mad::Card::clicked, []() {
        qDebug() << "卡片被点击了！";
    });
    cardsLayout->addWidget(clickableCard);

    // 带按钮的卡片
    Mad::Card *buttonCard = new Mad::Card(this);
    buttonCard->setTitle("带按钮的卡片");
    buttonCard->setContent("卡片中可以添加自定义控件。");
    
    QPushButton *actionButton = new QPushButton("点击我");
    actionButton->setStyleSheet(
        "QPushButton {"
        "    background-color: #0078d4;"
        "    color: white;"
        "    border: none;"
        "    border-radius: 4px;"
        "    padding: 8px 16px;"
        "}"
        "QPushButton:hover {"
        "    background-color: #106ebe;"
        "}"
    );
    connect(actionButton, &QPushButton::clicked, []() {
        qDebug() << "按钮被点击了！";
    });
    buttonCard->addWidget(actionButton);
    cardsLayout->addWidget(buttonCard);

    // 带多个控件的卡片
    Mad::Card *multiWidgetCard = new Mad::Card(this);
    multiWidgetCard->setTitle("多控件卡片");
    multiWidgetCard->setContent("卡片中可以添加多个控件。");
    
    QPushButton *btn1 = new QPushButton("按钮 1");
    QPushButton *btn2 = new QPushButton("按钮 2");
    QPushButton *btn3 = new QPushButton("按钮 3");
    
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(btn1);
    buttonLayout->addWidget(btn2);
    buttonLayout->addWidget(btn3);
    
    // multiWidgetCard->setLayout(buttonLayout);
    // multiWidgetCard->addWidget(buttonLayout);
    cardsLayout->addWidget(multiWidgetCard);

    // 添加弹簧，使卡片靠上
    cardsLayout->addStretch();
}

CardPage::~CardPage()
{
    delete ui;
}
