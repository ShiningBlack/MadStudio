#ifndef FLOWLAYOUTPAGE_H
#define FLOWLAYOUTPAGE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class FlowLayoutPage;
}
QT_END_NAMESPACE

/**
 * @brief FlowLayout 演示页面
 * 
 * 展示 FlowLayout 的自动换行功能
 */
class FlowLayoutPage : public QWidget
{
    Q_OBJECT

public:
    explicit FlowLayoutPage(QWidget *parent = nullptr);
    ~FlowLayoutPage();

private:
    void setupDemoButtons();
    void setupStyles();

private:
    Ui::FlowLayoutPage *ui;
};

#endif // FLOWLAYOUTPAGE_H