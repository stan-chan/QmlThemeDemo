#include "xml_helper.h"
#include "tinyxml2.h"
using namespace tinyxml2;

XmlHelper::XmlHelper(QObject *parent)
    : QObject{parent}
{
    //ReadXml();
}

QString XmlHelper::getIP() const
{
    return m_ip;
}

void XmlHelper::setIP(const QString &ip)
{
    m_ip=ip;
    emit ipChanged(m_ip);
}

void XmlHelper::readXml()
{
    XMLDocument doc;
    doc.LoadFile("Test.xml");
    XMLElement* root = doc.RootElement();
    XMLElement *ip = root->FirstChildElement("ip");
    setIP(ip->GetText());
    printf("ip:%s\n",ip->GetText());
}
