#include "cardwidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGraphicsDropShadowEffect>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QPainterPath>

namespace Mad {

CardWidget::CardWidget(QWidget *parent)
    : QFrame(parent)
    , m_titleLabel(nullptr)
    , m_contentLabel(nullptr)
    , m_contentLayout(nullptr)
    , m_borderRadius(8)
    , m_shadowRadius(15)
    , m_clickable(false)
    , m_isHovered(false)
{
    setupUI();
    updateShadow();
}

CardWidget::~CardWidget()
{
}

void CardWidget::setupUI()
{
    setMouseTracking(true);
    setMinimumWidth(200);
    setMaximumWidth(400);

    // 主布局
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(16, 16, 16, 16);
    mainLayout->setSpacing(8);

    // 标题标签
    m_titleLabel = new QLabel(this);
    m_titleLabel->setWordWrap(true);
    m_titleLabel->setStyleSheet(
        "QLabel {"
        "    font-size: 16px;"
        "    font-weight: bold;"
        "    color: #333333;"
        "}"
    );
    m_titleLabel->hide();
    mainLayout->addWidget(m_titleLabel);

    // 内容标签
    m_contentLabel = new QLabel(this);
    m_contentLabel->setWordWrap(true);
    m_contentLabel->setStyleSheet(
        "QLabel {"
        "    font-size: 14px;"
        "    color: #666666;"
        "}"
    );
    m_contentLabel->hide();
    mainLayout->addWidget(m_contentLabel);

    // 自定义内容布局
    m_contentLayout = new QVBoxLayout();
    m_contentLayout->setSpacing(8);
    mainLayout->addLayout(m_contentLayout);

    // 设置基础样式
    setStyleSheet(
        "CardWidget {"
        "    background-color: white;"
        "    border: 1px solid #e0e0e0;"
        "}"
    );
}

void CardWidget::updateShadow()
{
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setBlurRadius(m_shadowRadius);
    shadow->setColor(QColor(0, 0, 0, 30));
    shadow->setOffset(0, 2);
    setGraphicsEffect(shadow);
}

void CardWidget::setTitle(const QString &title)
{
    m_titleLabel->setText(title);
    m_titleLabel->setVisible(!title.isEmpty());
}

QString CardWidget::title() const
{
    return m_titleLabel->text();
}

void CardWidget::setContent(const QString &content)
{
    m_contentLabel->setText(content);
    m_contentLabel->setVisible(!content.isEmpty());
}

QString CardWidget::content() const
{
    return m_contentLabel->text();
}

int CardWidget::borderRadius() const
{
    return m_borderRadius;
}

void CardWidget::setBorderRadius(int radius)
{
    if (m_borderRadius != radius) {
        m_borderRadius = radius;
        update();
        emit borderRadiusChanged(radius);
    }
}

int CardWidget::shadowRadius() const
{
    return m_shadowRadius;
}

void CardWidget::setShadowRadius(int radius)
{
    if (m_shadowRadius != radius) {
        m_shadowRadius = radius;
        updateShadow();
        emit shadowRadiusChanged(radius);
    }
}

bool CardWidget::isClickable() const
{
    return m_clickable;
}

void CardWidget::setClickable(bool clickable)
{
    if (m_clickable != clickable) {
        m_clickable = clickable;
        setCursor(m_clickable ? Qt::PointingHandCursor : Qt::ArrowCursor);
        emit clickableChanged(clickable);
    }
}

void CardWidget::addWidget(QWidget *widget)
{
    if (widget) {
        m_contentLayout->addWidget(widget);
    }
}

void CardWidget::clearWidgets()
{
    while (QLayoutItem *item = m_contentLayout->takeAt(0)) {
        if (QWidget *widget = item->widget()) {
            widget->deleteLater();
        }
        delete item;
    }
}

void CardWidget::enterEvent(QEnterEvent *event)
{
    QFrame::enterEvent(event);
    m_isHovered = true;
    update();
}

void CardWidget::leaveEvent(QEvent *event)
{
    QFrame::leaveEvent(event);
    m_isHovered = false;
    update();
}

void CardWidget::mousePressEvent(QMouseEvent *event)
{
    QFrame::mousePressEvent(event);
    if (m_clickable && event->button() == Qt::LeftButton) {
        emit clicked();
    }
}

void CardWidget::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // 绘制圆角矩形
    QPainterPath path;
    path.addRoundedRect(rect(), m_borderRadius, m_borderRadius);
    painter.setClipPath(path);

    // 悬停效果
    if (m_isHovered) {
        painter.fillRect(rect(), QColor(0, 0, 0, 5));
    }
}

} // namespace Mad
