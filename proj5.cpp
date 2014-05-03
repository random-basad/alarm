#include <QApplication>
#include <QDesktopWidget>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QPushButton>
#include <QLabel>
#include <QDialog>
#include <QtGui>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]){
	QApplication app(argc, argv);
	QWidget *window = new QWidget;
	window->setWindowTitle(" Alarm");
	window->resize(500, 200);
	window->move(500, 300);
	QLabel *label = new QLabel(argv[1]);

window->setStyleSheet("QLabel {background-color:white;font-size:30px; height:50px; color:red;} QLabel:hover {background-color:rgb(200,145,200)} " ) ;

QHBoxLayout *layout = new QHBoxLayout;
layout->addWidget(label);

window->setLayout(layout);
window->show();

return app.exec();
}
