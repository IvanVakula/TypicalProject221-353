#pragma once
#ifndef TASKS_H
#define TASKS_H
#include <QVariant>
#include <QRandomGenerator>
#include <QtMath>
/*!
 * \brief Класс заданий
*/

/*!
 * \brief Функция, генерирующее задание на тему поиска СКНФ
 * \return Структуру задания, содержащую поля text и answer
 */
QVariantMap TaskPenkov();
/*!
 * \brief Функция, генерирующее задание на тему поиска СДНФ
 * \return Структуру задания, содержащую поля text и answer
 */
QVariantMap TaskKomolov();
/*!
 * \brief Функция, генерирующее задание на тему составления карты Карно
 * \return Структуру задания, содержащую поля text и answer
 */
QVariantMap TaskVakula();

#endif // TASKS_H
