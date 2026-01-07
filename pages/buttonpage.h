#ifndef BUTTONPAGE_H
#define BUTTONPAGE_H

#include <QWidget>

namespace Mad {

namespace Ui {
class ButtonPage;
}

class ButtonPage : public QWidget
{
    Q_OBJECT

public:
    explicit ButtonPage(QWidget *parent = nullptr);
    ~ButtonPage();

private slots:
    void onButtonClick();

private:
    Ui::ButtonPage *ui;
};

} // namespace Mad

#endif // BUTTONPAGE_H