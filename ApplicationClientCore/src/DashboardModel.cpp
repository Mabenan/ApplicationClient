#include <DashboardModel.h>

QVariant DashboardModel::data(const QModelIndex &index, int role) const
{

    if(index.isValid()){
        DashboardItem * item = this->items.at(index.row());
        return QVariant::fromValue(item);
    }else{
        return QVariant();
    }
}

int DashboardModel::rowCount(const QModelIndex &parent) const
{
return this->items.size();
}

void DashboardModel::AddItem(DashboardItem *item)
{
    this->items.append(item);
}

void DashboardModel::RemoveItem(DashboardItem *item)
{
    int index = this->items.indexOf(item);
    beginRemoveRows(QModelIndex(), index, index);
    this->items.removeOne(item);
    emit endRemoveRows();
}

DashboardModel::DashboardModel(QObject *parent) : QAbstractListModel(parent)
{

}
