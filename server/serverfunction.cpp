#include <stdio.h>
#include "serverfunction.h"
#include <QDebug>
#include <QCoreApplication>



QByteArray parse(QString request) {
    request.chop(2);
    QString data = QString::fromStdString(request.toStdString());
    // function_name arg1 arg2
    QStringList list = data.split(" ");
    QString response;
    if (list[0] == QString("auth")) {
        response = auth(list[1], list[2]);
    }
    else if (list[0] == QString("reg")) {
        response = reg(list[1], list[2]);
    }
    else if (list[0] == QString("gettask")) {
        response = getTask(list[1].toInt());
    }
    else if (list[0] == QString("checktask")) {
        response = checkTask(list[1].toInt(), list[1].toInt());
    }
    else if (list[0] == QString("getstat")) {
        response = getStat();
    }
    else response = "Wrong syntax";
    return QByteArray((response + "\r\n").toUtf8());
}

QString auth(QString login,QString password){
    return QString("Autherisation with login %1 and password %2").arg(login).arg(password);
}
QString reg(QString login,QString password){
    return QString("Registration with login %1 and password %2").arg(login).arg(password);
}
QString getStat(){
    return QString("Statictins");
}
QString getTask(int taskType){
    return QString("Task type %1").arg(taskType);
}
QString checkTask(int taskId, int answer){
    return QString("Check task number %1 with answer %2").arg(taskId).arg(answer);
}
