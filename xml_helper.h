#pragma once

#include <QObject>
#include <QString>



class XmlHelper : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString ip READ getIP WRITE setIP NOTIFY ipChanged)
public:
    explicit XmlHelper(QObject *parent = nullptr);

    QString getIP() const;
    void setIP(const QString &ip);
signals:
    void ipChanged(const QString ip);
public slots:
    void readXml();

private:
    QString m_ip;

};


