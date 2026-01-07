#ifndef STUDIOMAINWINDOW_H
#define STUDIOMAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class StudioMainWindow;
}
QT_END_NAMESPACE

class DemoWindow;

/**
 * @brief MadStudio 主窗口
 * 
 * 管理应用程序的主界面
 */
class MadStudioMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MadStudioMainWindow(QWidget *parent = nullptr);
    ~MadStudioMainWindow();

private slots:
    void onOpenDemoWindow();

private:
    void setupStyles();

private:
    Ui::StudioMainWindow *ui;
    DemoWindow *m_demoWindow;
};

#endif // STUDIOMAINWINDOW_H
