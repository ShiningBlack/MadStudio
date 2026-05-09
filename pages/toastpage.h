#ifndef TOASTPAGE_H
#define TOASTPAGE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class ToastPage;
}
QT_END_NAMESPACE

/**
 * @brief 通知消息演示页面
 */
class ToastPage : public QWidget
{
    Q_OBJECT
public:
    explicit ToastPage(QWidget *parent = nullptr);
    ~ToastPage();

private slots:
    void onShowInfoClicked();
    void onShowSuccessClicked();
    void onShowWarningClicked();
    void onShowErrorClicked();
    void onShowMultipleClicked();

private:
    Ui::ToastPage *ui;
};

#endif // TOASTPAGE_H