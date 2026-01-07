#ifndef SEARCHBOXPAGE_H
#define SEARCHBOXPAGE_H

#include <QWidget>

namespace Ui {
class SearchBoxPage;
}

class SearchBoxPage : public QWidget
{
    Q_OBJECT

public:
    explicit SearchBoxPage(QWidget *parent = nullptr);
    ~SearchBoxPage();

private:
    Ui::SearchBoxPage *ui;
};

#endif // SEARCHBOXPAGE_H
