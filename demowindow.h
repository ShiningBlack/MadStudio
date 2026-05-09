#ifndef DEMOWINDOW_H
#define DEMOWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class DemoWindow;
}
QT_END_NAMESPACE

/**
 * @brief 演示窗口
 * 
 * 独立的演示窗口，用于展示各种组件的演示效果
 */
class DemoWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit DemoWindow(QWidget *parent = nullptr);
    ~DemoWindow();

private:
    Ui::DemoWindow *ui;
};

#endif // DEMOWINDOW_H