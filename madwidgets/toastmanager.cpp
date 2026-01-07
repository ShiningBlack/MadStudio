#include "toastmanager.h"
#include <QApplication>
#include <QScreen>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QVBoxLayout>
#include <QDebug>

namespace Mad {

ToastManager::ToastManager(QObject *parent)
    : QObject(parent)
{
}

ToastManager::~ToastManager()
{
    qDeleteAll(m_activeToasts);
    m_activeToasts.clear();
}

ToastManager *ToastManager::instance()
{
    static ToastManager manager;
    return &manager;
}

void ToastManager::show(QWidget *parent, const QString &message, ToastType type, int duration)
{
    createToast(parent, message, type, duration);
}

void ToastManager::showInfo(QWidget *parent, const QString &message, int duration)
{
    show(parent, message, ToastType::Info, duration);
}

void ToastManager::showSuccess(QWidget *parent, const QString &message, int duration)
{
    show(parent, message, ToastType::Success, duration);
}

void ToastManager::showWarning(QWidget *parent, const QString &message, int duration)
{
    show(parent, message, ToastType::Warning, duration);
}

void ToastManager::showError(QWidget *parent, const QString &message, int duration)
{
    show(parent, message, ToastType::Error, duration);
}

void ToastManager::createToast(QWidget *parent, const QString &message, ToastType type, int duration)
{
    // 创建 Toast 容器
    QWidget *toast = new QWidget();
    toast->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
    toast->setAttribute(Qt::WA_TranslucentBackground);
    toast->setStyleSheet(getStyleSheet(type));

    // 创建布局
    QVBoxLayout *layout = new QVBoxLayout(toast);
    layout->setContentsMargins(20, 15, 20, 15);

    // 创建消息标签
    QLabel *label = new QLabel(message, toast);
    label->setWordWrap(true);
    label->setStyleSheet("color: white; font-size: 15px; font-weight: 500;");
    layout->addWidget(label);

    // 计算尺寸 - 增大卡片尺寸
    toast->adjustSize();
    int maxWidth = 500;
    if (toast->width() > maxWidth) {
        toast->setFixedWidth(maxWidth);
        toast->adjustSize();
    }
    // 设置最小高度
    if (toast->height() < 100) {
        toast->setFixedHeight(100);
    }

    // 添加到活动列表
    m_activeToasts.append(toast);

    // 定位 Toast
    positionToast(toast, parent);

    // 显示动画
    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(toast);
    toast->setGraphicsEffect(effect);
    
    QPropertyAnimation *fadeIn = new QPropertyAnimation(effect, "opacity");
    fadeIn->setDuration(300);
    fadeIn->setStartValue(0.0);
    fadeIn->setEndValue(1.0);
    fadeIn->start(QPropertyAnimation::DeleteWhenStopped);

    // 显示
    toast->show();

    // 自动消失
    QTimer::singleShot(duration, this, [this, toast, effect]() {
        // 淡出动画
        QPropertyAnimation *fadeOut = new QPropertyAnimation(effect, "opacity");
        fadeOut->setDuration(300);
        fadeOut->setStartValue(1.0);
        fadeOut->setEndValue(0.0);
        
        connect(fadeOut, &QPropertyAnimation::finished, this, [this, toast]() {
            m_activeToasts.removeAll(toast);
            toast->deleteLater();
            // 重新定位剩余的 Toast
            for (QWidget *t : m_activeToasts) {
                positionToast(t, nullptr);
            }
        });
        
        fadeOut->start(QPropertyAnimation::DeleteWhenStopped);
    });
}

QString ToastManager::getStyleSheet(ToastType type)
{
    QString backgroundColor;
    QString borderColor;
    
    switch (type) {
    case ToastType::Info:
        backgroundColor = "#2196F3";
        borderColor = "#1976D2";
        break;
    case ToastType::Success:
        backgroundColor = "#4CAF50";
        borderColor = "#388E3C";
        break;
    case ToastType::Warning:
        backgroundColor = "#FF9800";
        borderColor = "#F57C00";
        break;
    case ToastType::Error:
        backgroundColor = "#F44336";
        borderColor = "#D32F2F";
        break;
    }
    
    return QString(
        "QWidget {"
        "    background-color: %1;"
        "    border: 2px solid %2;"
        "    border-radius: 10px;"
        "}"
    ).arg(backgroundColor, borderColor);
}

void ToastManager::positionToast(QWidget *toast, QWidget *parent)
{
    if (!toast) return;

    // 获取父窗口或屏幕
    QScreen *screen;
    QRect geometry;
    
    if (parent) {
        // 定位到父窗口的右上角
        screen = parent->screen();
        geometry = parent->geometry();
    } else {
        // 没有父窗口，使用屏幕
        screen = QGuiApplication::primaryScreen();
        geometry = screen->availableGeometry();
    }

    if (!screen) {
        screen = QGuiApplication::primaryScreen();
    }
    
    QRect screenGeometry = screen->availableGeometry();

    // 计算位置（右上角）
    int x = geometry.right() - toast->width() - 20;
    
    // 计算垂直位置（考虑多个 Toast 堆叠）
    int y = geometry.top() + 20;
    int spacing = 10;
    
    // 查找这个 Toast 在列表中的位置
    int index = m_activeToasts.indexOf(toast);
    if (index > 0) {
        for (int i = 0; i < index; ++i) {
            y += m_activeToasts[i]->height() + spacing;
        }
    }

    toast->move(x, y);
}

} // namespace Mad