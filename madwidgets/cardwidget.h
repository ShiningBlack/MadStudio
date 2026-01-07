#ifndef CARDWIDGET_H
#define CARDWIDGET_H

#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QEvent>
#include <QPaintEvent>

namespace Mad {

/**
 * @brief 卡片式布局组件
 * 
 * 提供现代化的卡片样式，支持阴影、圆角和悬停效果
 */
class CardWidget : public QFrame
{
    Q_OBJECT
    Q_PROPERTY(int borderRadius READ borderRadius WRITE setBorderRadius NOTIFY borderRadiusChanged)
    Q_PROPERTY(int shadowRadius READ shadowRadius WRITE setShadowRadius NOTIFY shadowRadiusChanged)
    Q_PROPERTY(bool clickable READ isClickable WRITE setClickable NOTIFY clickableChanged)

public:
    explicit CardWidget(QWidget *parent = nullptr);
    ~CardWidget();

    // 标题和内容
    void setTitle(const QString &title);
    QString title() const;
    void setContent(const QString &content);
    QString content() const;

    // 样式属性
    int borderRadius() const;
    void setBorderRadius(int radius);
    int shadowRadius() const;
    void setShadowRadius(int radius);
    bool isClickable() const;
    void setClickable(bool clickable);

    // 添加自定义控件
    void addWidget(QWidget *widget);
    void clearWidgets();

signals:
    void clicked();
    void borderRadiusChanged(int radius);
    void shadowRadiusChanged(int radius);
    void clickableChanged(bool clickable);

protected:
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    void setupUI();
    void updateShadow();

private:
    QLabel *m_titleLabel;
    QLabel *m_contentLabel;
    QVBoxLayout *m_contentLayout;
    int m_borderRadius;
    int m_shadowRadius;
    bool m_clickable;
    bool m_isHovered;
};

} // namespace Mad

#endif // CARDWIDGET_H
