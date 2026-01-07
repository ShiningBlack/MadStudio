#include "buttonpage.h"
#include "ui_buttonpage.h"
#include "modernbutton.h"
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
    
    ModernButton *primaryBtn = new ModernButton("主要按钮", this);
    primaryBtn->setButtonType(ButtonType::Primary);
    connect(primaryBtn, &ModernButton::clicked, this, &ButtonPage::onButtonClick);
    basicLayout->addWidget(primaryBtn);
    
    ModernButton *secondaryBtn = new ModernButton("次要按钮", this);
    secondaryBtn->setButtonType(ButtonType::Secondary);
    connect(secondaryBtn, &ModernButton::clicked, this, &ButtonPage::onButtonClick);
    basicLayout->addWidget(secondaryBtn);
    
    ModernButton *successBtn = new ModernButton("成功按钮", this);
    successBtn->setButtonType(ButtonType::Success);
    connect(successBtn, &ModernButton::clicked, this, &ButtonPage::onButtonClick);
    basicLayout->addWidget(successBtn);
    
    ModernButton *warningBtn = new ModernButton("警告按钮", this);
    warningBtn->setButtonType(ButtonType::Warning);
    connect(warningBtn, &ModernButton::clicked, this, &ButtonPage::onButtonClick);
    basicLayout->addWidget(warningBtn);
    
    ModernButton *dangerBtn = new ModernButton("危险按钮", this);
    dangerBtn->setButtonType(ButtonType::Danger);
    connect(dangerBtn, &ModernButton::clicked, this, &ButtonPage::onButtonClick);
    basicLayout->addWidget(dangerBtn);
    
    ModernButton *ghostBtn = new ModernButton("幽灵按钮", this);
    ghostBtn->setButtonType(ButtonType::Ghost);
    connect(ghostBtn, &ModernButton::clicked, this, &ButtonPage::onButtonClick);
    basicLayout->addWidget(ghostBtn);
    
    ModernButton *gradientBtn = new ModernButton("渐变按钮", this);
    gradientBtn->setButtonType(ButtonType::Gradient);
    connect(gradientBtn, &ModernButton::clicked, this, &ButtonPage::onButtonClick);
    basicLayout->addWidget(gradientBtn);
    
    basicLayout->addStretch();
    
    // 带图标的按钮
    QHBoxLayout *iconLayout = new QHBoxLayout(ui->iconButtonsWidget);
    iconLayout->setSpacing(10);
    
    ModernButton *iconPrimaryBtn = new ModernButton("主要", this);
    iconPrimaryBtn->setButtonType(ButtonType::Primary);
    iconPrimaryBtn->setIconText("📁");
    connect(iconPrimaryBtn, &ModernButton::clicked, this, &ButtonPage::onButtonClick);
    iconLayout->addWidget(iconPrimaryBtn);
    
    ModernButton *iconSuccessBtn = new ModernButton("成功", this);
    iconSuccessBtn->setButtonType(ButtonType::Success);
    iconSuccessBtn->setIconText("✅");
    connect(iconSuccessBtn, &ModernButton::clicked, this, &ButtonPage::onButtonClick);
    iconLayout->addWidget(iconSuccessBtn);
    
    ModernButton *iconWarningBtn = new ModernButton("警告", this);
    iconWarningBtn->setButtonType(ButtonType::Warning);
    iconWarningBtn->setIconText("⚠️");
    connect(iconWarningBtn, &ModernButton::clicked, this, &ButtonPage::onButtonClick);
    iconLayout->addWidget(iconWarningBtn);
    
    ModernButton *iconDangerBtn = new ModernButton("删除", this);
    iconDangerBtn->setButtonType(ButtonType::Danger);
    iconDangerBtn->setIconText("🗑️");
    connect(iconDangerBtn, &ModernButton::clicked, this, &ButtonPage::onButtonClick);
    iconLayout->addWidget(iconDangerBtn);
    
    iconLayout->addStretch();
    
    // 按钮状态
    QHBoxLayout *stateLayout = new QHBoxLayout(ui->stateButtonsWidget);
    stateLayout->setSpacing(10);
    
    ModernButton *normalBtn = new ModernButton("正常状态", this);
    normalBtn->setButtonType(ButtonType::Primary);
    connect(normalBtn, &ModernButton::clicked, this, &ButtonPage::onButtonClick);
    stateLayout->addWidget(normalBtn);
    
    ModernButton *disabledBtn = new ModernButton("禁用状态", this);
    disabledBtn->setButtonType(ButtonType::Primary);
    disabledBtn->setEnabled(false);
    stateLayout->addWidget(disabledBtn);
    
    ModernButton *loadingBtn = new ModernButton("加载状态", this);
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
    ModernButton *btn = qobject_cast<ModernButton*>(sender());
    if (btn) {
        qDebug() << "按钮点击:" << btn->text();
    }
}

} // namespace Mad
