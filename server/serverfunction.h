#ifndef serverfunction_h
#define serverfunction_h

#include <QCoreApplication>
#include <QString>

/*
parsing — функция, которая обрабатывает сообщения клиента: выделяет команду и аргументы, а затем вызывает соответствующую функцию
Аргумент data — сообщение, пришедшее от клиента
Возвращаемое значение — ответ соответствующей функции
*/
QByteArray parse(QByteArray request);
QByteArray auth(QJsonObject request);
QByteArray reg(QJsonObject request);
QByteArray getStat(QJsonObject request);
QByteArray getTask(QJsonObject request);
QByteArray checkTask(QJsonObject request);
#endif
