#include "teacherwindow.h"
#include "ui_teacherwindow.h"

TeacherWindow::TeacherWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::TeacherWindow) {
    QStringList header;
    header << QString("Логин")
           << QString("Задание 1")
           << QString("Задание 2")
           << QString("Задание 3");
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setHorizontalHeaderLabels(header);
}

void TeacherWindow::UpdateWindow() {
    return;
}

TeacherWindow::~TeacherWindow()
{
    delete ui;
}

