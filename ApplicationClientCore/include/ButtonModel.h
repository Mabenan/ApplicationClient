#ifndef BUTTONMODEL_H
#define BUTTONMODEL_H

#include <ApplicationClientCore.Precompiled.h>
#include <QAbstractListModel>
#include <Button.h>
#include <qqml.h>
class APPLICATIONCLIENTCORE_EXPORT ButtonModel : public QAbstractListModel{

private:
    QList<Button *> buttons;
    // QAbstractItemModel interface
public:

    ButtonModel(QObject *parent = nullptr);

    void AddButton(Button *button);
    void RemoveButton(Button *button);

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
};

#endif // BUTTONMODEL_H
