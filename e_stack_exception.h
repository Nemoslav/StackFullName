#ifndef ESTACKEXCEPTION_H
#define ESTACKEXCEPTION_H

#include <cstring>

class EStackException
{
public:
	// конструктор
	EStackException(const char *msg)
	{
		msg_ = new char[strlen(msg) + 1]; // выделяем память под сообщение об ошибке

		strcpy(msg_, msg); // сохраняем сообщение об ошибке
	}

	// конструктор копирования
	EStackException(const EStackException &obj)
	{
		msg_ = new char[strlen(obj.msg_) + 1]; // выделяем память под копию сообщения об ошибке

		strcpy(msg_, obj.msg_); // копируем сообщение об ошибке
	}

	// деструктор
	~EStackException()
	{
		delete msg_; // освобождаем память, выделенную под сообщение
	}

	const char *what() const { return msg_; }

private:
	char *msg_;
};

#endif // ESTACKEXCEPTION_H
