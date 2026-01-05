#ifndef STUDIOMAINWINDOW_H
#define STUDIOMAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class StudioMainWindow;
}
QT_END_NAMESPACE

class MadStudioMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MadStudioMainWindow(QWidget *parent = nullptr);
    ~MadStudioMainWindow();

private:
    Ui::StudioMainWindow *ui;
};
#endif // STUDIOMAINWINDOW_H
