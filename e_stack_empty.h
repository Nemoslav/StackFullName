#ifndef ESTACKEMPTY_H
#define ESTACKEMPTY_H

#include "e_stack_exception.h"

class EStackEmpty : public EStackException
{
public:
	// конструктор по умолчанию
	EStackEmpty()
		: EStackException("A stack is empty.") // инициализируем базовый класс сообщением об ошибке
	{

	}

	// конструктор копирования
	EStackEmpty(const EStackEmpty &obj)
		: EStackException(obj) // инициализируем базовый класс переденным обьектом
	{

	}
};

#endif // ESTACKEMPTY_H
