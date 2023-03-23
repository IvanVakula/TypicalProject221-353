#include <stdio.h>
#include "serverfunction.h"
#include <QDebug>
#include <QCoreApplication>



QByteArray parse(QString request) {
    request.chop(2);
    QString data = QString::fromStdString(request.toStdString());
    // function_name arg1 arg2
    QStringList list = data.split(" ");
    qDebug() <<  list[0];
    qDebug() << QString("auth");
    qDebug() << (data[0] == QString("auth"));
    QString response;
    if (data[0] == QString("auth")) {
        response = auth(data[1], data[2]);
    }
    else if (data[0] == QString("reg")) {
        response = reg(data[1], data[2]);
    }
    else if (data[0] == QString("gettask")) {
        response = getTask(int(data[1].toLatin1()));
    }
    else if (data[0] == QString("checktask")) {
        response = checkTask(int(data[1].toLatin1()), int(data[1].toLatin1()));
    }
    else if (data[0] == QString("getstat")) {
        response = getStat();
    }
    else response = "Wrong syntax";
    return QByteArray((response + "\r\n").toUtf8());
}

QString auth(QString login,QString password){
}
QString reg(QString login,QString password){
}
QString getStat(){
}
QString getTask(int taskType){
}
QString checkTask(int taskId, int answer){
}
