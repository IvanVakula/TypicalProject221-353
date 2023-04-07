#pragma once
#include <QSqlDatabase>
#ifndef DATABASE_H
#define DATABASE_H

class Database;

class DatabaseDestroyer
{
    private:
        Database * pInstance;
    public:
        ~DatabaseDestroyer() {
            delete pInstance;
        }
        void initialize(Database * p) {
            pInstance = p;
        }
};


class Database {
    private:
        static Database * pInstance;
        void initDB();
        static QSqlDatabase dbInstance;
    protected:
        Database(){}
        Database(const Database& );
        Database& operator = (Database &);
        ~Database();
        friend class DatabaseDestroyer;
    public:
        static DatabaseDestroyer destroyer;
        static Database* getInstance() {
            if (!pInstance)
            {
                pInstance = new Database();
                destroyer.initialize(pInstance);
            }
            return pInstance;
        }
        QSqlQuery doSQLQuery(QString stringQuery);

};

Database* Database::pInstance = nullptr;
DatabaseDestroyer Database::destroyer;
QSqlDatabase Database::dbInstance;

#endif // DATABASE_H
