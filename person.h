#ifndef PERSON_H
#define PERSON_H

#include <QString>
#include <QRegularExpression>

// класс личности, в данном случае в нем содержится только полное имя, разбитое на поля
class Person
{
public:
	Person();
	Person(QString last_name, QString first_name, QString patronymic);
	Person(QString full_name);

	// функции, с помошью который осуществляется взаимодействие с член данными
	void set_last_name(const QString &last_name) { last_name_ = last_name; }
	void set_first_name(const QString &first_name) { first_name_ = first_name; }
	void set_patronymic(const QString &patronymic) { patronymic_ = patronymic; }

	const QString &last_name() const { return last_name_; }
	const QString &first_name() const { return first_name_; }
	const QString &patronymic() const { return patronymic_; }

private:
	QString last_name_;
	QString first_name_;
	QString patronymic_;
};

#endif // PERSON_H
