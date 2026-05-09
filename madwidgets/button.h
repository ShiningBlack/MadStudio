#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>

namespace Mad {

enum class ButtonType {
    Primary,        // 主要按钮（蓝色）
    Secondary,      // 次要按钮（灰色）
    Success,        // 成功按钮（绿色）
    Warning,        // 警告按钮（橙色）
    Danger,         // 危险按钮（红色）
    Ghost,          // 幽灵按钮（透明背景）
    Gradient        // 渐变按钮
};

/**
 * @brief 现代化按钮组件
 * 
 * 提供多种样式的现代化按钮，支持悬停、禁用和加载状态
 */
class Button : public QPushButton
{
    Q_OBJECT
    Q_PROPERTY(ButtonType buttonType READ buttonType WRITE setButtonType NOTIFY buttonTypeChanged)
    Q_PROPERTY(int borderRadius READ borderRadius WRITE setBorderRadius NOTIFY borderRadiusChanged)
    Q_PROPERTY(bool isLoading READ isLoading WRITE setIsLoading NOTIFY isLoadingChanged)
public:
    explicit Button(const QString &text = QString(), QWidget *parent = nullptr);
    ~Button();

    // 按钮类型
    ButtonType buttonType() const;
    void setButtonType(ButtonType type);

    // 样式属性
    int borderRadius() const;
    void setBorderRadius(int radius);

    // 加载状态
    bool isLoading() const;
    void setIsLoading(bool loading);

    // 图标
    void setIconText(const QString &icon);

protected:
    void paintEvent(QPaintEvent *event) override;

signals:
    void buttonTypeChanged(ButtonType type);
    void borderRadiusChanged(int radius);
    void isLoadingChanged(bool loading);

private:
    void updateStyle();
    QString getButtonStyle();

private:
    ButtonType m_buttonType;
    int m_borderRadius;
    bool m_isLoading;
    QString m_iconText;
};

} // namespace Mad

#endif // BUTTON_H
