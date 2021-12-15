#include "string_list_model.h"

StringListModel::StringListModel(QObject *parent)
	: QAbstractListModel(parent)
{

}

// функция изменения хранилища данных
void StringListModel::setStringList(const QStringList &string_list)
{
	beginResetModel(); // предупреждение всех видов о том что мы собираемся изменять данные

	string_list_ = string_list; // заменяем старые данные на новые

	endResetModel(); // сообщение о том что новые данные готовы и можно их выводить
}

int StringListModel::rowCount(const QModelIndex &parent) const
{
	if (parent.isValid())
	{
		return 0;
	}

	return string_list_.size();
}

// функция работы с данными имеющимися в модели
QVariant StringListModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid()) // проверка передано ли что-то в качестве индекса модели
	{
		return QVariant(); // если невозможно вернуть какие-то данные, возвращаем пустое значение, как и указано в документации
	}

	if (index.row() >= string_list_.size()) // проверяем есть ли запрошенный индекс в наличии
	{
		return QVariant();
	}

	if (role == Qt::DisplayRole || role == Qt::EditRole) // проверяем для чего запрашиваются данные, принимаются только запросы на отображение и редактирование данных
	{
		return string_list_.at(index.row()); // возвращаем по заданному индексу строку из списка
	}

	return QVariant();
}
