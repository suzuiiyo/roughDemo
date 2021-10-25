#include "resultmodel.h"
#include <QColor>
#include <QDebug>

resultModel::resultModel(QObject *parent) : QAbstractTableModel(parent)
{

}

void resultModel::setModelData(const QList<resultModelItem> &datas)
{
    beginResetModel();
    modelData=datas;
    endResetModel();;
}

QList<resultModelItem> resultModel::getModelData() const
{
    return modelData;
}

bool resultModel::insertModelData(int row, const resultModelItem &datas)
{
    if(row<0 || row>rowCount())
        return false;

    beginInsertRows(QModelIndex(), row, row);
    modelData.insert(row, datas);
    endInsertRows();
    return true;
}

QVariant resultModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    switch (role) {
      case Qt::TextAlignmentRole:
          return QVariant(Qt::AlignCenter);
      case Qt::BackgroundRole:
          return QColor(Qt::darkGreen);
      case Qt::TextColorRole:
          return QColor(Qt::white);
      case Qt::DisplayRole:
      {
          if(orientation == Qt::Horizontal)
          {
              if(section == 0)
                  return QStringLiteral("序列一采样点序号");

              if(section == 1)
                  return QStringLiteral("序列二采样点序号");

              if(section == 2)
                  return QStringLiteral("突变前二周波比对值");

              if(section == 3)
                  return QStringLiteral("序列一采样点序号");

              if(section == 4)
                  return QStringLiteral("序列二采样点序号");

              if(section == 5)
                  return QStringLiteral("突变后突变后五周波比对值");
          }
      }
      default:
          return QVariant();
      }
      return QVariant();
}

bool resultModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if(value != headerData(section, orientation, role))
    {
        emit headerDataChanged(orientation, section, section);
        return true;
    }
    return false;
}

int resultModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    return modelData.count();
}

int resultModel::columnCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return	0;
    return	6;
}

QVariant resultModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();
    if(role == Qt::DisplayRole || role == Qt::EditRole)
    {
        const int row = index.row();
        switch(index.column())
        {
            case 0: return modelData.at(row).beforeCompareFirSeqNum;

            case 1: return modelData.at(row).beforeCompareSecSeqNum;

            case 2: return modelData.at(row).beforeComparisionResult;

            case 3: return modelData.at(row).afterCompareFirSeqNum;

            case 4: return modelData.at(row).afterCompareSecSeqNum;

            case 5: return  modelData.at(row).afterComparisionResult;
        }
    }
    return QVariant();
}

bool resultModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid() && role == Qt::EditRole)
    {
        const int row = index.row();
        switch (index.column())
        {
            case 0: modelData[row].beforeCompareFirSeqNum = value.toInt();break;

            case 1: modelData[row].beforeCompareSecSeqNum = value.toInt();break;

            case 2: modelData[row].beforeComparisionResult = value.toFloat();break;

            case 3: modelData[row].afterCompareFirSeqNum = value.toInt();break;

            case 4: modelData[row].afterCompareSecSeqNum = value.toInt();break;

            case 5: modelData[row].afterComparisionResult = value.toFloat();break;
        }
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags resultModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return Qt::NoItemFlags;
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
}

bool resultModel::insertRows(int row, int count, const QModelIndex &parent)
{
    if(row<0 || count<1 || row<rowCount())
        return false;

    beginInsertRows(parent, row, row+count-1);
    for(int i=row; i<row+count; i++)
    {
        modelData.insert(i, resultModelItem());
    }
    endInsertRows();
    return true;
}

bool resultModel::removeRows(int row, int count, const QModelIndex &parent)
{
    if(row<0 || count<1 || row+count>rowCount())
        return false;
    beginRemoveRows(parent, row, row + count - 1);
    for(int i=row+count-1; i>=row; i--)
    {
        modelData.removeAt(i);
    }
    endRemoveRows();
    return true;

}
