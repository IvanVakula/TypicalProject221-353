#include <stdio.h>
#include "serverfunction.h"
#include "database.h"
#include <QDebug>
#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>



QByteArray parse(QByteArray request) {
    // {"method": "register", "login": "qwer", "password": "pass"}
    QJsonObject json_request = QJsonDocument::fromJson(request).object();
    qDebug() << json_request;
    QString response;
    QString method = json_request["method"].toString();
    qDebug() << method;
    if (method == QString("authentication")) {
        response = auth(json_request);
    }
    else if (method == QString("register")) {
        response = reg(json_request);
    }
    else if (method == QString("getTask")) {
        response = getTask(json_request);
    }
    else if (method == QString("checkTask")) {
        response = checkTask(json_request);
    }
    else if (method == QString("getStat")) {
        response = getStat(json_request);
    }
    else response = "Wrong syntax";
    return QByteArray((response + "\r\n").toUtf8());
}

QByteArray auth(QJsonObject request){
    Database::getInstance();
    QVariantMap response;
    QString login = request["login"].toString();
    QString password = request["password"].toString();
    response["message"] = QString("Autherisation with login %1 and password %2").arg(login, password);
    return QJsonDocument::fromVariant(response).toJson();
}
QByteArray reg(QJsonObject request){
    QVariantMap response;
    QString login = request["login"].toString();
    QString password = request["password"].toString();
    response["message"] = QString("Registration with login %1 and password %2").arg(login, password);
    return QJsonDocument::fromVariant(response).toJson();
}
QByteArray getStat(QJsonObject request){
    QVariantMap response;
    response["message"] = QString("Statictins");
    return QJsonDocument::fromVariant(response).toJson();
}
QByteArray getTask(QJsonObject request){
    QVariantMap response;
    int taskType = request["login"].toInt();
    response["message"] = QString("Task type %1").arg(taskType);
    return QJsonDocument::fromVariant(response).toJson();
}
QByteArray checkTask(QJsonObject request){
    QVariantMap response;
    int taskId = request["taskId"].toInt();
    QString answer = request["answer"].toString();
    response["message"] = QString("Check task number %1 with answer %2").arg(taskId).arg(answer);
    return QJsonDocument::fromVariant(response).toJson();
}
