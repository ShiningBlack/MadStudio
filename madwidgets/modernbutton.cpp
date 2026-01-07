#include "modernbutton.h"
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>

namespace Mad {

ModernButton::ModernButton(const QString &text, QWidget *parent)
    : QPushButton(text, parent)
    , m_buttonType(ButtonType::Primary)
    , m_borderRadius(6)
    , m_isLoading(false)
{
    setCursor(Qt::PointingHandCursor);
    setMinimumHeight(36);
    updateStyle();
}

ModernButton::~ModernButton()
{
}

ButtonType ModernButton::buttonType() const
{
    return m_buttonType;
}

void ModernButton::setButtonType(ButtonType type)
{
    if (m_buttonType != type) {
        m_buttonType = type;
        updateStyle();
        emit buttonTypeChanged(type);
    }
}

int ModernButton::borderRadius() const
{
    return m_borderRadius;
}

void ModernButton::setBorderRadius(int radius)
{
    if (m_borderRadius != radius) {
        m_borderRadius = radius;
        updateStyle();
        emit borderRadiusChanged(radius);
    }
}

bool ModernButton::isLoading() const
{
    return m_isLoading;
}

void ModernButton::setIsLoading(bool loading)
{
    if (m_isLoading != loading) {
        m_isLoading = loading;
        setEnabled(!loading);
        updateStyle();
        emit isLoadingChanged(loading);
    }
}

void ModernButton::setIconText(const QString &icon)
{
    m_iconText = icon;
    update();
}

void ModernButton::updateStyle()
{
    setStyleSheet(getButtonStyle());
}

QString ModernButton::getButtonStyle()
{
    QString backgroundColor;
    QString hoverColor;
    QString pressedColor;
    QString textColor;
    QString borderColor;

    switch (m_buttonType) {
        case ButtonType::Primary:
            backgroundColor = "#2196F3";
            hoverColor = "#1976D2";
            pressedColor = "#0D47A1";
            textColor = "white";
            borderColor = "#1976D2";
            break;
        case ButtonType::Secondary:
            backgroundColor = "#F5F5F5";
            hoverColor = "#E0E0E0";
            pressedColor = "#BDBDBD";
            textColor = "#333333";
            borderColor = "#E0E0E0";
            break;
        case ButtonType::Success:
            backgroundColor = "#4CAF50";
            hoverColor = "#388E3C";
            pressedColor = "#1B5E20";
            textColor = "white";
            borderColor = "#388E3C";
            break;
        case ButtonType::Warning:
            backgroundColor = "#FF9800";
            hoverColor = "#F57C00";
            pressedColor = "#E65100";
            textColor = "white";
            borderColor = "#F57C00";
            break;
        case ButtonType::Danger:
            backgroundColor = "#F44336";
            hoverColor = "#D32F2F";
            pressedColor = "#B71C1C";
            textColor = "white";
            borderColor = "#D32F2F";
            break;
        case ButtonType::Ghost:
            backgroundColor = "transparent";
            hoverColor = "rgba(33, 150, 243, 0.1)";
            pressedColor = "rgba(33, 150, 243, 0.2)";
            textColor = "#2196F3";
            borderColor = "#2196F3";
            break;
        case ButtonType::Gradient:
            backgroundColor = "qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #2196F3, stop:1 #9C27B0)";
            hoverColor = "qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #1976D2, stop:1 #7B1FA2)";
            pressedColor = "qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #0D47A1, stop:1 #4A148C)";
            textColor = "white";
            borderColor = "transparent";
            break;
    }

    QString disabledStyle;
    if (!isEnabled() || m_isLoading) {
        disabledStyle = QString(
            "ModernButton:disabled {"
            "  background-color: #E0E0E0;"
            "  color: #999999;"
            "  border: 1px solid #E0E0E0;"
            "}"
        );
    }

    QString loadingText = m_isLoading ? "⏳ " : (m_iconText.isEmpty() ? "" : m_iconText + " ");

    return QString(
        "ModernButton {"
        "  background-color: %1;"
        "  color: %2;"
        "  border: 1px solid %3;"
        "  border-radius: %4px;"
        "  padding: 8px 16px;"
        "  font-size: 14px;"
        "  font-weight: 500;"
        "  text-align: center;"
        "}"
        "ModernButton:hover {"
        "  background-color: %5;"
        "}"
        "ModernButton:pressed {"
        "  background-color: %6;"
        "}"
        "%7"
    ).arg(backgroundColor, textColor, borderColor)
     .arg(m_borderRadius)
     .arg(hoverColor, pressedColor, disabledStyle);
}

void ModernButton::paintEvent(QPaintEvent *event)
{
    QPushButton::paintEvent(event);
}

} // namespace Mad