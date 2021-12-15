#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QBoxLayout>
#include <QPushButton>
#include <QListView>
#include <QFileDialog>
#include <QMessageBox>

#include "string_list_model.h"
#include "person_keeper.h"

// главное окно
class MainWindow : public QWidget
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

	// обработчики событий
	void open_button_OnClick();
	void save_button_OnClick();

private:
	// указатели на графические элементы
	StringListModel *model_;
	QListView *view_;
	QPushButton *open_button_;
	QPushButton *save_button_;
	QHBoxLayout *horizontal_layout_;
	QVBoxLayout *vertical_layout_;

	// ссылка на хранитель личностей
	PersonKeeper &person_keeper_;
};

#endif // MAIN_WINDOW_H
