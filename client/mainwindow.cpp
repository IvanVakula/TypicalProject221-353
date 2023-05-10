#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->update_data();
    tWindow = new TaskForm();
    connect(tWindow, &TaskForm::openWindow, this, &TaskForm::show);
}

bool MainWindow::update_data() {
    if (load_setting("isTeacher") == "true") {
        ui->RoleLabel->setText("Вы преподаватель");
    } else {
        ui->RoleLabel->setText("Вы студент");
    }
    ui->StatLabel->setText(getStat());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openTask(QVariantMap task) {
    int taskId = task["id"].toInt();
    QString taskText = task["text"].toString();
    tWindow->initTask(taskText, taskId);
    tWindow->show();
}


void MainWindow::on_task1_clicked()
{
    QVariantMap task = getTask(1);
    openTask(task);
    ui->StatLabel->setText(getStat());
}



void MainWindow::on_task2_clicked()
{
    QVariantMap task = getTask(2);
    openTask(task);
    ui->StatLabel->setText(getStat());
}


void MainWindow::on_task3_clicked()
{
    QVariantMap task = getTask(3);
    openTask(task);
    ui->StatLabel->setText(getStat());
}


void MainWindow::on_account_exit_triggered() {
    reset_settings();
    // перезапуск приложения
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}

