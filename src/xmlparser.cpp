#include "xmlparser.h"

#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QDebug>

XMLParser::XMLParser() {

}

XMLParser::~XMLParser() {

}

QVector<int> XMLParser::parse(const QString &filePath) {
    QVector<int> result;

    QFile *file = new QFile(filePath);
    if(!file->open(QIODevice::ReadOnly | QIODevice::Text)) {

    }
    QXmlStreamReader xml(file);
    while(!xml.atEnd() && !xml.hasError()) {
        QXmlStreamReader::TokenType token = xml.readNext();
        if(token == QXmlStreamReader::StartDocument) {
            continue;
        }
        if(token == QXmlStreamReader::StartElement) {
            if(xml.name() == "request") {
                continue;
            }
            if(xml.name() == "sum") {
                QXmlStreamAttributes attributes = xml.attributes();
                if(attributes.hasAttribute("arg1") && attributes.hasAttribute("arg2")) {

                    result.push_back(attributes.value("arg1").toInt());
                    result.push_back(0);
                    result.push_back(attributes.value("arg2").toInt());
                    result.push_back(sum(attributes.value("arg1").toInt(), attributes.value("arg2").toInt()));
                }

            }
            if(xml.name() == "diff") {
                QXmlStreamAttributes attributes = xml.attributes();
                if(attributes.hasAttribute("arg1") && attributes.hasAttribute("arg2")) {

                    result.push_back(attributes.value("arg1").toInt());
                    result.push_back(1);
                    result.push_back(attributes.value("arg2").toInt());
                    result.push_back(diff(attributes.value("arg1").toInt(), attributes.value("arg2").toInt()));

                }
            }
            if(xml.name() == "mult") {
                QXmlStreamAttributes attributes = xml.attributes();
                if(attributes.hasAttribute("arg1") && attributes.hasAttribute("arg2")) {

                    result.push_back(attributes.value("arg1").toInt());
                    result.push_back(2);
                    result.push_back(attributes.value("arg2").toInt());
                    result.push_back(mult(attributes.value("arg1").toInt(), attributes.value("arg2").toInt()));

                }
            }
            if(xml.name() == "div") {
                QXmlStreamAttributes attributes = xml.attributes();
                if(attributes.hasAttribute("arg1") && attributes.hasAttribute("arg2")) {

                    result.push_back(attributes.value("arg1").toInt());
                    result.push_back(3);
                    result.push_back(attributes.value("arg2").toInt());
                    result.push_back(div(attributes.value("arg1").toInt(), attributes.value("arg2").toInt()));
                }
            }
        }
    }

    file->close();

    return result;
}

void XMLParser::write(const QString &savePath, QVector<int> result) {
    QFile *file = new QFile(savePath);
    if(!file->open(QIODevice::WriteOnly | QIODevice::Text)) {

    }
    QXmlStreamWriter xml(file);
    xml.setAutoFormatting(true);

    xml.writeStartDocument();
    xml.writeStartElement("response");

    for(int i = 0; i < result.size(); i+=4) {

        xml.writeAttribute("arg1", QString::number(result[i]));
        switch (result[i+1]) {
            case 0:
                xml.writeStartElement("sum");
                break;
            case 1:
                xml.writeStartElement("diff");
                break;
            case 2:
                xml.writeStartElement("mult");
                break;
            case 3:
                xml.writeStartElement("div");
                break;

        }
        xml.writeAttribute("arg2", QString::number(result[i+2]));
        xml.writeAttribute("result", QString::number(result[i+3]));
        xml.writeEndElement();
    }
    xml.writeEndElement();
    file->close();
}
