#include "person.h"

Person::Person()
{

}

Person::Person(QString last_name, QString first_name, QString patronymic)
	: last_name_(last_name)
	, first_name_(first_name)
	, patronymic_(patronymic)
{

}

Person::Person(QString full_name)
{
    QStringList words = full_name.split(QRegularExpression("\\s+"), QString::SkipEmptyParts); // разбиваем полученную строку на не пустые слова

	if (words.size() != 2 && words.size() != 3) // если в строке недостаточно, или слишком много слов, то это значит что входные данные в неверном формате
	{
		throw "Error: Person(): A string has incorrect format and could not be completely parsed."; // сответствтвенно об этом нужно предупредить пользователя
	}

	last_name_ = words[0]; // используем первое слово в строке в качестве фамилии
	first_name_ = words[1]; // второе в качестве имени

	if (words.size() == 3) // если есть 3-е слово, используем его в качестве отчества
	{
		patronymic_ = words[2];
	}
}
