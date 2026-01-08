#include "buttonpage.h"
#include "ui_buttonpage.h"
#include "button.h"
#include <QHBoxLayout>

namespace Mad {

ButtonPage::ButtonPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ButtonPage)
{
    ui->setupUi(this);
    
    // 基本按钮类型
    QHBoxLayout *basicLayout = new QHBoxLayout(ui->basicButtonsWidget);
    basicLayout->setSpacing(10);
    
    Button *primaryBtn = new Button("主要按钮", this);
    primaryBtn->setButtonType(ButtonType::Primary);
    connect(primaryBtn, &Button::clicked, this, &ButtonPage::onButtonClick);
    basicLayout->addWidget(primaryBtn);
    
    Button *secondaryBtn = new Button("次要按钮", this);
    secondaryBtn->setButtonType(ButtonType::Secondary);
    connect(secondaryBtn, &Button::clicked, this, &ButtonPage::onButtonClick);
    basicLayout->addWidget(secondaryBtn);
    
    Button *successBtn = new Button("成功按钮", this);
    successBtn->setButtonType(ButtonType::Success);
    connect(successBtn, &Button::clicked, this, &ButtonPage::onButtonClick);
    basicLayout->addWidget(successBtn);
    
    Button *warningBtn = new Button("警告按钮", this);
    warningBtn->setButtonType(ButtonType::Warning);
    connect(warningBtn, &Button::clicked, this, &ButtonPage::onButtonClick);
    basicLayout->addWidget(warningBtn);
    
    Button *dangerBtn = new Button("危险按钮", this);
    dangerBtn->setButtonType(ButtonType::Danger);
    connect(dangerBtn, &Button::clicked, this, &ButtonPage::onButtonClick);
    basicLayout->addWidget(dangerBtn);
    
    Button *ghostBtn = new Button("幽灵按钮", this);
    ghostBtn->setButtonType(ButtonType::Ghost);
    connect(ghostBtn, &Button::clicked, this, &ButtonPage::onButtonClick);
    basicLayout->addWidget(ghostBtn);
    
    Button *gradientBtn = new Button("渐变按钮", this);
    gradientBtn->setButtonType(ButtonType::Gradient);
    connect(gradientBtn, &Button::clicked, this, &ButtonPage::onButtonClick);
    basicLayout->addWidget(gradientBtn);
    
    basicLayout->addStretch();
    
    // 带图标的按钮
    QHBoxLayout *iconLayout = new QHBoxLayout(ui->iconButtonsWidget);
    iconLayout->setSpacing(10);
    
    Button *iconPrimaryBtn = new Button("主要", this);
    iconPrimaryBtn->setButtonType(ButtonType::Primary);
    iconPrimaryBtn->setIconText("📁");
    connect(iconPrimaryBtn, &Button::clicked, this, &ButtonPage::onButtonClick);
    iconLayout->addWidget(iconPrimaryBtn);
    
    Button *iconSuccessBtn = new Button("成功", this);
    iconSuccessBtn->setButtonType(ButtonType::Success);
    iconSuccessBtn->setIconText("✅");
    connect(iconSuccessBtn, &Button::clicked, this, &ButtonPage::onButtonClick);
    iconLayout->addWidget(iconSuccessBtn);
    
    Button *iconWarningBtn = new Button("警告", this);
    iconWarningBtn->setButtonType(ButtonType::Warning);
    iconWarningBtn->setIconText("⚠️");
    connect(iconWarningBtn, &Button::clicked, this, &ButtonPage::onButtonClick);
    iconLayout->addWidget(iconWarningBtn);
    
    Button *iconDangerBtn = new Button("删除", this);
    iconDangerBtn->setButtonType(ButtonType::Danger);
    iconDangerBtn->setIconText("🗑️");
    connect(iconDangerBtn, &Button::clicked, this, &ButtonPage::onButtonClick);
    iconLayout->addWidget(iconDangerBtn);
    
    iconLayout->addStretch();
    
    // 按钮状态
    QHBoxLayout *stateLayout = new QHBoxLayout(ui->stateButtonsWidget);
    stateLayout->setSpacing(10);
    
    Button *normalBtn = new Button("正常状态", this);
    normalBtn->setButtonType(ButtonType::Primary);
    connect(normalBtn, &Button::clicked, this, &ButtonPage::onButtonClick);
    stateLayout->addWidget(normalBtn);
    
    Button *disabledBtn = new Button("禁用状态", this);
    disabledBtn->setButtonType(ButtonType::Primary);
    disabledBtn->setEnabled(false);
    stateLayout->addWidget(disabledBtn);
    
    Button *loadingBtn = new Button("加载状态", this);
    loadingBtn->setButtonType(ButtonType::Primary);
    loadingBtn->setIsLoading(true);
    stateLayout->addWidget(loadingBtn);
    
    stateLayout->addStretch();
}

ButtonPage::~ButtonPage()
{
    delete ui;
}

void ButtonPage::onButtonClick()
{
    Button *btn = qobject_cast<Button*>(sender());
    if (btn) {
        qDebug() << "按钮点击:" << btn->text();
    }
}

} // namespace Mad
