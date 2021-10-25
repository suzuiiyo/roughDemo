#include "mytablemodel.h"
#include <QColor>
#include <QDebug>

myTableModel::myTableModel(QObject *parent) : QAbstractTableModel(parent)
{

}

void myTableModel::setModelData(const QList<MyModelItem> &datas)
{
    beginResetModel();
    modelData=datas;
    endResetModel();
}

QList<MyModelItem> myTableModel::getModelData() const
{
    return modelData;
}

bool myTableModel::insertModelData(int row, const MyModelItem &datas)
{
    if(row<0 || row>rowCount())
        return false;

    beginInsertRows(QModelIndex(), row, row);
    modelData.insert(row, datas);
    endInsertRows();
    return true;
}

QVariant myTableModel::headerData(int section, Qt::Orientation orientation, int role) const
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
                  return QStringLiteral("突变前一周波采样值");

              if(section == 1)
                  return QStringLiteral("突变后一周波采样值");
          }
      }
      default:
          return QVariant();
      }
      return QVariant();
}

bool myTableModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if(value != headerData(section, orientation, role))
    {
        emit headerDataChanged(orientation, section, section);
        return true;
    }
    return false;
}

int myTableModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    return modelData.count();
}

int myTableModel::columnCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return	0;
    return	2;
}

QVariant myTableModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();
    if(role == Qt::DisplayRole || role == Qt::EditRole)
    {
        const int row = index.row();
        switch(index.column())
        {
            case 0: return modelData.at(row).m_beforeValue;

            case 1: return modelData.at(row).m_afterValue;
        }
    }
    return QVariant();
}

bool myTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid() && role == Qt::EditRole)
    {
        const int row = index.row();
        switch (index.column())
        {
            case 0: modelData[row].m_beforeValue = value.toFloat();	break;

            case 1: modelData[row].m_afterValue = value.toFloat();	break;

        }
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags myTableModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return Qt::NoItemFlags;
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
}

bool myTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    if(row<0 || count<1 || row<rowCount())
        return false;

    beginInsertRows(parent, row, row+count-1);
    for(int i=row; i<row+count; i++)
    {
        modelData.insert(i, MyModelItem());
    }
    endInsertRows();
    return true;
}

bool myTableModel::removeRows(int row, int count, const QModelIndex &parent)
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
