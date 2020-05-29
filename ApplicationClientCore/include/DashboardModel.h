#ifndef DASHBOARDMODEL_H
#define DASHBOARDMODEL_H
#include <ApplicationClientCore.Precompiled.h>
#include <QAbstractListModel>
#include <DashboardItem.h>
#include <qqml.h>
class APPLICATIONCLIENTCORE_EXPORT DashboardModel : public QAbstractListModel{

private:
    QList<DashboardItem *> items;
    // QAbstractItemModel interface
public:

    DashboardModel(QObject *parent = nullptr);

    void AddItem(DashboardItem *item);
    void RemoveItem(DashboardItem *item);

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
};


#endif // DASHBOARDMODEL_H
