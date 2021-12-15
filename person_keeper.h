
#ifndef PERSONKEEPER_H
#define PERSONKEEPER_H

#include <QString>
#include <QTextStream>
#include <QFile>

#include "person.h"
#include "stack.h"

// хранитель личностей, Singleton
class PersonKeeper
{
public:
	static PersonKeeper &Instance(); // статическая функция, в которой создается и хранится единственный экземпляр класса

	void ReadPersons(QString path); // записать ФИО из стека в файл
	void WritePersons(QString path) const; // считать ФИО из файла в стек

	QStringList ToQStringList() const; // экспорт стэка имён в список строк

	int Size(); // количество хранимых личностей
	void Clear(); // очистить хранилище личностей

private:
	PersonKeeper(); // конструкторы и оператор присвоения недоступны из вне, то есть класс можно создать только через Instance
	PersonKeeper(const PersonKeeper &); // оставляем конструктор копирования по умолчанию, т. к. все член данные можно скопировать простым присвоением
	~PersonKeeper();

	PersonKeeper &operator=(const PersonKeeper &); // оставляем оператор присовения по умолчанию, по той же причине

	Stack<Person> stack_; // стэк полных имен
};

#endif // PERSONKEEPER_H
