#include "main_window.h"

MainWindow::MainWindow(QWidget *parent)
	: QWidget(parent)
	, person_keeper_(PersonKeeper::Instance()) // получаем ссылку на единственный экземпляр класса PersonKeeper
{
	model_ = new StringListModel(); // создаем модель списка строк

	// настройка интерфейса
	setWindowTitle("Lab01"); // указываем название окна

	view_ = new QListView(); // создаем вид списка
	view_->setModel(model_); // задаем виду списка созданную ранее модель списка строк

	open_button_ = new QPushButton("Open"); // создаем кнопку открытия файла
	save_button_ = new QPushButton("Save As"); // создаем кнопку открытия файла

	horizontal_layout_ = new QHBoxLayout(); // создаем горизонтальную развертку
	horizontal_layout_->addWidget(open_button_); // добавляем на нее кнопки
	horizontal_layout_->addWidget(save_button_); // таким образом они занимают одну строку, и имеют равную ширину

	vertical_layout_ = new QVBoxLayout(this); // создаем вертикальную развертку
	vertical_layout_->addWidget(view_); // в верхнюю ее часть устанавливаем список имен
	vertical_layout_->addLayout(horizontal_layout_); // в нежней части расположатся две кнопки

	// привязываем обработчик события к событию нажатия на кнопку
	connect(open_button_, &QPushButton::clicked, this, &MainWindow::open_button_OnClick);
	connect(save_button_, &QPushButton::clicked, this, &MainWindow::save_button_OnClick);
}

MainWindow::~MainWindow()
{
	// удаляем динамически созданные элементы интерфейса
	delete save_button_;
	delete open_button_;
	delete view_;
	delete horizontal_layout_;
	delete vertical_layout_;

	delete model_;
}

void MainWindow::open_button_OnClick()
{
	QString path = QFileDialog::getOpenFileName(this, "Open", "../", "*.txt"); // открытие диалога открытия файла

	if (path != "")
	{
		try
		{
			person_keeper_.Clear(); // удаляем имеющиеся личности, перед считыванием новых
			person_keeper_.ReadPersons(path); // считываем имена личностей из файла в хранилище личностей

			model_->setStringList(person_keeper_.ToQStringList()); // выводим имена из хранилища в модель в виде списка строк
		}
		catch (EStackException &e)
		{
			QMessageBox::about(this, "Error", e.what());
		}
		catch (const char *str)
		{
			QMessageBox::about(this, "Error", str);
		}
	}

	// если диалог закрыли, ничего не делаем
}

void MainWindow::save_button_OnClick()
{
	QString path = QFileDialog::getSaveFileName(this, "Save As", "../", "*.txt"); // открываем диалог сохранения файла

	if (path != "")
	{
		try
		{
			person_keeper_.WritePersons(path); // записываем имена из храналища личностей в выбранный файл
		}
		catch (EStackException &e)
		{
			QMessageBox::about(this, "Error", e.what());
		}
		catch (const char *str)
		{
			QMessageBox::about(this, "Error", str);
		}
	}

	// если диалог закрыли, ничего не делаем
}
