#include "main_window.h"

#include <QApplication>

// имеющиеся файлы
// input_1.txt - большой список имен, разделенных пробелами
// input_2.txt - небольшой список имен, имеющих лишние пробелы в начале и между словами, также присутствуют пустые строки

// автоматически сгенерированный файл, без изменений
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	return a.exec();
}
