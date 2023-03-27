#ifndef MYTABLEMODEL_H
#define MYTABLEMODEL_H

#include <QAbstractTableModel>

struct MyModelItem
{
    float m_beforeValue;
    float m_afterValue;
};

class myTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit myTableModel(QObject *parent = nullptr);

    void setModelData(const QList<MyModelItem> &datas);
    QList<MyModelItem> getModelData() const;
    bool insertModelData(int row, const MyModelItem &datas);

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole) override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    bool insertRows(int Row, int count, const QModelIndex &parent = QModelIndex()) override;

    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

private:
    QList<MyModelItem> modelData;
};

#endif // MYTABLEMODEL_H
