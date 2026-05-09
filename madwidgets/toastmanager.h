#ifndef TOASTMANAGER_H
#define TOASTMANAGER_H

#include <QObject>
#include <QLabel>
#include <QTimer>

namespace Mad {

/**
 * @brief 通知消息类型
 */
enum class ToastType {
    Info,
    Success,
    Warning,
    Error
};

/**
 * @brief Toast 消息组件
 * 
 * 提供现代化的浮动通知消息，支持不同类型和自动消失
 */
class ToastManager : public QObject
{
    Q_OBJECT
public:
    static ToastManager *instance();
    
    void show(QWidget *parent, const QString &message, ToastType type = ToastType::Info, int duration = 3000);
    void showInfo(QWidget *parent, const QString &message, int duration = 3000);
    void showSuccess(QWidget *parent, const QString &message, int duration = 3000);
    void showWarning(QWidget *parent, const QString &message, int duration = 3000);
    void showError(QWidget *parent, const QString &message, int duration = 3000);

private:
    explicit ToastManager(QObject *parent = nullptr);
    ~ToastManager();

    void createToast(QWidget *parent, const QString &message, ToastType type, int duration);
    QString getStyleSheet(ToastType type);
    void positionToast(QWidget *toast, QWidget *parent);

private:
    QList<QWidget*> m_activeToasts;
};

} // namespace Mad

#endif // TOASTMANAGER_H