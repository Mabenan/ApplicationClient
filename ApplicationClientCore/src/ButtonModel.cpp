#include <ButtonModel.h>
ButtonModel::ButtonModel(QObject *parent) : QAbstractListModel(parent)
{

}

void ButtonModel::AddButton(Button *button)
{
    this->buttons.append(button);
}

void ButtonModel::RemoveButton(Button *button)
{
    int index = this->buttons.indexOf(button);
    beginRemoveRows(QModelIndex(), index, index);
    this->buttons.removeOne(button);
    emit endRemoveRows();
}

int ButtonModel::rowCount(const QModelIndex &parent) const { return this->buttons.size(); }

QVariant ButtonModel::data(const QModelIndex &index, int role) const {
  if(index.isValid()){
      Button * button = this->buttons.at(index.row());
      return QVariant::fromValue(button);
  }else{
      return NULL;
  }
}
