#ifndef RESULTMODEL_H
#define RESULTMODEL_H

#include <QAbstractTableModel>

struct resultModelItem
{
    int beforeCompareFirSeqNum;
    int beforeCompareSecSeqNum;
    float beforeComparisionResult;
    int afterCompareFirSeqNum;
    int afterCompareSecSeqNum;
    float afterComparisionResult;
};

class resultModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit resultModel(QObject *parent = nullptr);

    void setModelData(const QList<resultModelItem> &datas);
    QList<resultModelItem> getModelData() const;
    bool insertModelData(int row, const resultModelItem &datas);

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
    QList<resultModelItem> modelData;
};

#endif // RESULTMODEL_H
