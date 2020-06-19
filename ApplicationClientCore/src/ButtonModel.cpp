#include <ButtonModel.h>
#include "closebutton.h"
ButtonModel::ButtonModel(QObject *parent) : QAbstractListModel(parent)
{

}

void ButtonModel::AddButton(Button *button)
{
    beginInsertRows(QModelIndex(), this->buttons.length(), this->buttons.length());
    this->buttons.append(button);
    emit endInsertRows();
}

void ButtonModel::RemoveButton(Button *button)
{
    int index = this->buttons.indexOf(button);
    beginRemoveRows(QModelIndex(), index, index);
    this->buttons.removeOne(button);
    emit endRemoveRows();
}

int ButtonModel::rowCount(const QModelIndex &parent) const { return this->buttons.size() + 1; }

QVariant ButtonModel::data(const QModelIndex &index, int role) const {
  if(index.isValid()){
      Button * button = nullptr;
      if(index.row() >= this->buttons.length()){
       button = new CloseButton(QStringLiteral("Close"));
      }else{
      button = this->buttons.at(index.row());
      }
      return QVariant::fromValue(button);
  }else{
      return QVariant();
  }
}
