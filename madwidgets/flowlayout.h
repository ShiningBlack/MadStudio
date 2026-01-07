#ifndef FLOWLAYOUT_H
#define FLOWLAYOUT_H

#include <QLayout>
#include <QRect>
#include <QStyle>

namespace Mad {

/**
 * @brief FlowLayout 流式布局管理器
 * 
 * 实现一个能够自动换行的流式布局，子控件会按照添加顺序从左到右排列，
 * 当一行放不下时自动换行。支持自定义水平和垂直间距。
 * 
 * 特性：
 * - 自动换行布局
 * - 支持动态调整间距
 * - 支持高度随宽度变化（hasHeightForWidth）
 * - 智能间距计算（基于样式）
 * - 完整的内存管理
 */
class FlowLayout : public QLayout
{
public:
    /**
     * @brief 构造函数（带父窗口）
     * @param parent 父窗口
     * @param margin 边距，-1 表示使用样式默认值
     * @param hSpacing 水平间距，-1 表示使用样式默认值
     * @param vSpacing 垂直间距，-1 表示使用样式默认值
     */
    explicit FlowLayout(QWidget *parent = nullptr, int margin = -1, int hSpacing = -1, int vSpacing = -1);

    /**
     * @brief 构造函数（无父窗口）
     * @param margin 边距，-1 表示使用样式默认值
     * @param hSpacing 水平间距，-1 表示使用样式默认值
     * @param vSpacing 垂直间距，-1 表示使用样式默认值
     */
    explicit FlowLayout(int margin = -1, int hSpacing = -1, int vSpacing = -1);

    /**
     * @brief 析构函数，清理所有布局项
     */
    ~FlowLayout() override;

    // QLayout 纯虚函数实现
    void addItem(QLayoutItem *item) override;
    int count() const override;
    QLayoutItem *itemAt(int index) const override;
    QLayoutItem *takeAt(int index) override;
    Qt::Orientations expandingDirections() const override;
    bool hasHeightForWidth() const override;
    int heightForWidth(int width) const override;
    void setGeometry(const QRect &rect) override;
    QSize sizeHint() const override;
    QSize minimumSize() const override;

    // 间距相关方法
    /**
     * @brief 获取水平间距
     * @return 水平间距值
     */
    int horizontalSpacing() const;

    /**
     * @brief 获取垂直间距
     * @return 垂直间距值
     */
    int verticalSpacing() const;

    /**
     * @brief 设置水平间距
     * @param hSpacing 水平间距值，-1 表示使用样式默认值
     */
    void setHorizontalSpacing(int hSpacing);

    /**
     * @brief 设置垂直间距
     * @param vSpacing 垂直间距值，-1 表示使用样式默认值
     */
    void setVerticalSpacing(int vSpacing);

    /**
     * @brief 刷新布局
     * 在修改间距后调用此方法以立即应用更改
     */
    void refreshLayout();

    /**
     * @brief 获取布局项数量
     * @return 布局项数量
     */
    int itemCount() const { return itemList.size(); }

    /**
     * @brief 清空所有布局项
     */
    void clear();

private:
    /**
     * @brief 执行布局计算
     * @param rect 布局区域
     * @param testOnly 是否仅测试（不实际设置几何形状）
     * @return 布局所需的总高度
     */
    int doLayout(const QRect &rect, bool testOnly) const;

    /**
     * @brief 智能间距计算
     * @param pm 样式像素度量
     * @return 计算出的间距值
     */
    int smartSpacing(QStyle::PixelMetric pm) const;

    QList<QLayoutItem *> itemList;  ///< 布局项列表
    int m_hSpace;                   ///< 水平间距
    int m_vSpace;                   ///< 垂直间距
};

} // namespace Mad

#endif // FLOWLAYOUT_H
