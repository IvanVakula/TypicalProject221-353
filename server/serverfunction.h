#ifndef serverfunction_h
#define serverfunction_h

#include <QCoreApplication>
#include <QString>

/*
parsing — функция, которая обрабатывает сообщения клиента: выделяет команду и аргументы, а затем вызывает соответствующую функцию
Аргумент data — сообщение, пришедшее от клиента
Возвращаемое значение — ответ соответствующей функции
*/
QByteArray parse(QString request);
QString auth(QString login,QString password);
QString reg(QString login,QString password);
QString getStat();
QString getTask(int taskType);
QString checkTask(int taskId, int answer);
#endif
