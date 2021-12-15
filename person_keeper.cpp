#include "person_keeper.h"

PersonKeeper::PersonKeeper()
{

}

PersonKeeper::~PersonKeeper()
{
	// нет динамически созданных обьектов
}

// функция, возвращающая ссылку на единственный обьект класса
PersonKeeper &PersonKeeper::Instance()
{
	static PersonKeeper instance; // static, для того чтобы обьект не создавался каждый раз при вызове функции

	return instance;
}

// функция, считывающая значения из файла находящегося по заданному пути в стек
void PersonKeeper::ReadPersons(QString path)
{
	QFile file(path);

	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) // пытаемся открыть файл на чтение
	{
		throw "Error: readPersons(): Couldn't open a file!"; // если файл не открылся, выбрасываем исключение
	}

	QTextStream stream(&file); // поток текстовых данных файла
	QString line; // буфер в который считываются строки

	while (stream.readLineInto(&line)) // считываем построчно, пока файл не закончится
	{
		stack_.Push(Person(line)); // создаем личность используя конструктор, принимающий одну строку в которой должно содержаться полное имя и добавляем её в стек
	}

	file.close(); // закрываем файл
}

// функция записи информации из хранителя в файл
void PersonKeeper::WritePersons(QString path) const
{
	QFile file(path);

	if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) // пытаемся открыть файл на запись
	{
		throw "Error: writePersons(): Couldn't open a file!"; // если файл не открылся, выбрасываем исключение
	}

	QTextStream stream(&file); // поток текстовых данных файла

	stack_.ForEach([&](const Person &value) // перебираем все значения, находящиеся в хранителе
	{
        stream << value.last_name() << '\t' << value.first_name() << '\t' << value.patronymic() << endl; // записываем значения в файл построчно
	});

	file.close(); // закрываем файл
}

// экспортируем данные в виде списка строк
QStringList PersonKeeper::ToQStringList() const
{
	QStringList string_list; // создаем список строк

	stack_.ForEach([&](const Person &value) // перебираем все личности
	{
		string_list.prepend(value.last_name() + " " + value.first_name() + " " + value.patronymic()); // записываем в начало списка строк новую строку, состоящую из всех частей имени личности
	});

	return string_list;
}

int PersonKeeper::Size()
{
	return stack_.Size();
}

void PersonKeeper::Clear()
{
	return stack_.Clear();
}
