#pragma once
#include "database.h"
#include <QCoreApplication>
#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
Database::Database()
{
    initDB();
}

void Database::initDB() {
    this->dbInstance = QSqlDatabase::addDatabase("QSQLITE");
    this->dbInstance.setDatabaseName("db1");
    if (!this->dbInstance.open()) {
        qDebug() << this->dbInstance.lastError().text();
    };
};

Database::~Database() {
    this->dbInstance.close();
};

QSqlQuery Database::doSQLQuery(QString stringQuery) {
    QSqlQuery query(this->dbInstance);
    query.exec(stringQuery);

    return query;
}

Database* Database::pInstance = nullptr;
QSqlDatabase Database::dbInstance;
DatabaseDestroyer Database::destroyer;
