#include "jsontest01.h"
#include <QVariant>
#include <QFile>
#include <QJsonDocument>
#include <QDebug>

JsonTest01::JsonTest01(QQuickItem *parent) :
    QQuickItem(parent)
{
    load();
}

void JsonTest01::setValue(QString name, QVariant value)
{
    switch (value.type()) {
    case QMetaType::Bool:
        m_json[name] = value.toBool();
        break;
    case QMetaType::Double:
    case QMetaType::Int:
        m_json[name] = value.toDouble();
        break;
    default:
        m_json[name] = value.toString();
        break;
    }
}

QVariant JsonTest01::getValue(QString name)
{
    QVariant value;
    switch (m_json[name].type()) {
    case QJsonValue::Bool:
        value = m_json[name].toBool();
        break;
    case QJsonValue::Double:
        value = m_json[name].toDouble();
        break;
    case QJsonValue::Null:
    case QJsonValue::Undefined:
        value.clear();
    default:
        value = m_json[name].toString();
        break;
    }
    return value;
}

bool JsonTest01::save()
{
    QFile saveFile(QStringLiteral("jsontest01.json"));
    if(!saveFile.open(QIODevice::WriteOnly)){
        qWarning("Couldn't open save file.");
        return false;
    }
    qDebug() << "open save file is succeeded.";
    QJsonDocument saveDoc(m_json);
    saveFile.write(saveDoc.toJson());
    return true;
}

bool JsonTest01::load()
{
    QFile loadFile(QStringLiteral("jsontest01.json"));
    if(!loadFile.open(QIODevice::ReadOnly)){
        qWarning("Couldn't open setting file.");
        return false;
    }
    qDebug() << "open setting file is succeeded.";
    QByteArray saveData = loadFile.readAll();
    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));
    m_json = loadDoc.object();
    return true;
}
