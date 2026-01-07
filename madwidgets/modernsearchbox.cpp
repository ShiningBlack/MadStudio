#include "modernsearchbox.h"
#include <QHBoxLayout>
#include <QPainter>
#include <QEvent>
#include <QResizeEvent>

namespace Mad {

ModernSearchBox::ModernSearchBox(QWidget *parent)
    : QWidget(parent)
    , m_borderRadius(8)
    , m_placeholderText("搜索...")
{
    setupUI();
    applyStyle();
}

ModernSearchBox::~ModernSearchBox()
{
}

void ModernSearchBox::setupUI()
{
    // 创建布局
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(12, 8, 8, 8);
    layout->setSpacing(8);

    // 搜索图标
    m_searchIcon = new QLabel(this);
    m_searchIcon->setFixedSize(20, 20);
    m_searchIcon->setAlignment(Qt::AlignCenter);
    m_searchIcon->setText("🔍");
    m_searchIcon->setStyleSheet("font-size: 16px;");
    layout->addWidget(m_searchIcon);

    // 输入框
    m_lineEdit = new QLineEdit(this);
    m_lineEdit->setFrame(false);
    m_lineEdit->setPlaceholderText(m_placeholderText);
    m_lineEdit->setStyleSheet("background: transparent; border: none; padding: 4px;");
    
    connect(m_lineEdit, &QLineEdit::textChanged, this, [this](const QString &text) {
        emit textChanged(text);
        updateClearButtonVisibility();
    });
    
    connect(m_lineEdit, &QLineEdit::returnPressed, this, [this]() {
        emit returnPressed();
        emit searchRequested(m_lineEdit->text());
    });
    
    layout->addWidget(m_lineEdit, 1);

    // 清除按钮
    m_clearButton = new QPushButton("×", this);
    m_clearButton->setFixedSize(24, 24);
    m_clearButton->setCursor(Qt::PointingHandCursor);
    m_clearButton->setVisible(false);
    
    connect(m_clearButton, &QPushButton::clicked, this, [this]() {
        clear();
    });
    
    layout->addWidget(m_clearButton);

    // 自动补全
    m_completionModel = new QStringListModel(this);
    m_completer = new QCompleter(m_completionModel, this);
    m_completer->setCaseSensitivity(Qt::CaseInsensitive);
    m_completer->setFilterMode(Qt::MatchContains);
    m_lineEdit->setCompleter(m_completer);

    setFocusProxy(m_lineEdit);
    setMinimumHeight(40);
}

void ModernSearchBox::applyStyle()
{
    setStyleSheet(QString(
        "ModernSearchBox {"
        "  background-color: #F5F5F5;"
        "  border: 1px solid #E0E0E0;"
        "  border-radius: %1px;"
        "}"
        "ModernSearchBox:focus {"
        "  border: 2px solid #2196F3;"
        "  background-color: white;"
        "}"
    ).arg(m_borderRadius));
    
    m_clearButton->setStyleSheet(QString(
        "QPushButton {"
        "  border: none;"
        "  color: #999999;"
        "  font-size: 18px;"
        "  font-weight: bold;"
        "  background: transparent;"
        "  border-radius: 12px;"
        "}"
        "QPushButton:hover {"
        "  color: #666666;"
        "  background: #E0E0E0;"
        "}"
    ));
}

QString ModernSearchBox::text() const
{
    return m_lineEdit->text();
}

void ModernSearchBox::setText(const QString &text)
{
    m_lineEdit->setText(text);
    updateClearButtonVisibility();
}

void ModernSearchBox::clear()
{
    m_lineEdit->clear();
    updateClearButtonVisibility();
}

QString ModernSearchBox::placeholderText() const
{
    return m_placeholderText;
}

void ModernSearchBox::setPlaceholderText(const QString &text)
{
    if (m_placeholderText != text) {
        m_placeholderText = text;
        m_lineEdit->setPlaceholderText(text);
        emit placeholderTextChanged(text);
    }
}

int ModernSearchBox::borderRadius() const
{
    return m_borderRadius;
}

void ModernSearchBox::setBorderRadius(int radius)
{
    if (m_borderRadius != radius) {
        m_borderRadius = radius;
        applyStyle();
        emit borderRadiusChanged(radius);
    }
}

void ModernSearchBox::setCompletionMode(QCompleter::CompletionMode mode)
{
    m_completer->setCompletionMode(mode);
}

void ModernSearchBox::setCompletionItems(const QStringList &items)
{
    m_completionModel->setStringList(items);
}

void ModernSearchBox::updateClearButtonVisibility()
{
    m_clearButton->setVisible(!m_lineEdit->text().isEmpty());
}

void ModernSearchBox::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
}

void ModernSearchBox::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
}

} // namespace Mad