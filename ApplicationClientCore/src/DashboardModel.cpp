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

DashboardModel::DashboardModel(QObject *parent) : QAbstractListModel(parent)
{

}
