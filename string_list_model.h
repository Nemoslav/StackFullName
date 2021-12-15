#ifndef STRINGLISTMODEL_H
#define STRINGLISTMODEL_H

#include <QAbstractListModel>

class StringListModel : public QAbstractListModel
{
public:
	StringListModel(QObject *parent = nullptr);

	void setStringList(const QStringList &string_list); // фукнция, позволяющая изменять данные

	// реализуем минимальный необходимый набор методов, исходя из документации
	int rowCount(const QModelIndex &parent = QModelIndex()) const;

	QVariant data(const QModelIndex &index, int role) const;

private:
	QStringList string_list_;
};

#endif // STRINGLISTMODEL_H
