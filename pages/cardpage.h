#ifndef CARDPAGE_H
#define CARDPAGE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class CardPage;
}
QT_END_NAMESPACE

/**
 * @brief 卡片布局演示页面
 */
class CardPage : public QWidget
{
    Q_OBJECT

public:
    explicit CardPage(QWidget *parent = nullptr);
    ~CardPage();

private:
    Ui::CardPage *ui;
};

#endif // CARDPAGE_H