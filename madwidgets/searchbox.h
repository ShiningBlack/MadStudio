#ifndef SEARCHBOX_H
#define SEARCHBOX_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QCompleter>
#include <QStringListModel>

namespace Mad {

/**
 * @brief 搜索框组件
 * 
 * 提供现代化的搜索框，支持搜索图标、清除按钮和自动补全
 */
class SearchBox : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString placeholderText READ placeholderText WRITE setPlaceholderText NOTIFY placeholderTextChanged)
    Q_PROPERTY(int borderRadius READ borderRadius WRITE setBorderRadius NOTIFY borderRadiusChanged)

public:
    explicit SearchBox(QWidget *parent = nullptr);
    ~SearchBox();

    // 文本相关
    QString text() const;
    void setText(const QString &text);
    void clear();
    QString placeholderText() const;
    void setPlaceholderText(const QString &text);

    // 样式属性
    int borderRadius() const;
    void setBorderRadius(int radius);

    // 自动补全
    void setCompletionMode(QCompleter::CompletionMode mode);
    void setCompletionItems(const QStringList &items);

signals:
    void textChanged(const QString &text);
    void returnPressed();
    void searchRequested(const QString &text);
    void placeholderTextChanged(const QString &text);
    void borderRadiusChanged(int radius);

protected:
    void resizeEvent(QResizeEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    void setupUI();
    void updateClearButtonVisibility();
    void applyStyle();

private:
    QLineEdit *m_lineEdit;
    QPushButton *m_clearButton;
    QLabel *m_searchIcon;
    QCompleter *m_completer;
    QStringListModel *m_completionModel;
    int m_borderRadius;
    QString m_placeholderText;
};

} // namespace Mad

#endif // SEARCHBOX_H
