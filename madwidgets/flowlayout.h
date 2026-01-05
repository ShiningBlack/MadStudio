#ifndef FLOWLAYOUT_H
#define FLOWLAYOUT_H

#include <QObject>

class FlowLayout : public QObject
{
    Q_OBJECT
public:
    explicit FlowLayout(QObject *parent = nullptr);

signals:
};

#endif // FLOWLAYOUT_H
