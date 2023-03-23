#include <stdio.h>
#include "serverfunction.h"
#include <QDebug>
#include <QCoreApplication>

QByteArray parsing(QByteArray byte_data) {
    byte_data.chop(2);
    QString data = QString::fromStdString(byte_data.toStdString());
    qDebug() << data;
    if (data == QString("lox")) {
        return QByteArray("Sam takoi\r\n");
    }
    else return QByteArray("Wrong syntax\r\n");
}
