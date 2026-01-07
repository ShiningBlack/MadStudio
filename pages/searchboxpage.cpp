#include "searchboxpage.h"
#include "ui_searchboxpage.h"
#include "modernsearchbox.h"

SearchBoxPage::SearchBoxPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SearchBoxPage)
{
    ui->setupUi(this);
    
    // 创建基本搜索框
    Mad::ModernSearchBox *basicSearch = new Mad::ModernSearchBox(this);
    basicSearch->setPlaceholderText("输入关键词搜索...");

    if (!ui->basicSearchWidget) {
        qWarning() << "ui->basicSearchWidget is null!";
        return;
    }

    // 如果已经有布局，不要新建！
    if (ui->basicSearchWidget->layout() == nullptr) {
        auto layout = new QHBoxLayout(ui->basicSearchWidget);
        layout->addWidget(basicSearch);
    } else {
        // 或者直接加到现有布局
        ui->basicSearchWidget->layout()->addWidget(basicSearch);
    }
    
    connect(basicSearch, &Mad::ModernSearchBox::searchRequested, this, [this](const QString &text) {
        ui->resultTextEdit->append(QString("基本搜索: %1").arg(text));
    });
    
    // 创建带自动补全的搜索框
    Mad::ModernSearchBox *completionSearch = new Mad::ModernSearchBox(this);
    completionSearch->setPlaceholderText("输入内容查看自动补全...");
    completionSearch->setCompletionItems({
        "Apple", "Banana", "Cherry", "Date", "Elderberry",
        "Fig", "Grape", "Honeydew", "Kiwi", "Lemon",
        "Mango", "Nectarine", "Orange", "Peach", "Quince"
    });

    // 🔥 关键修复：检查 layout 是否存在！
    if (!ui->completionSearchWidget) {
        qWarning() << "ui->completionSearchWidget is null!";
    } else if (ui->completionSearchWidget->layout() == nullptr) {
        auto layout = new QHBoxLayout(ui->completionSearchWidget);
        layout->addWidget(completionSearch);
        layout->setContentsMargins(0, 0, 0, 0); // 可选：去除边距
    } else {
        ui->completionSearchWidget->layout()->addWidget(completionSearch);
    }
    
    connect(completionSearch, &Mad::ModernSearchBox::searchRequested, this, [this](const QString &text) {
        ui->resultTextEdit->append(QString("自动补全搜索: %1").arg(text));
    });
}

SearchBoxPage::~SearchBoxPage()
{
    delete ui;
}

