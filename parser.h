#ifndef PARSER_H
#define PARSER_H

#include <QString>
#include <QTextStream>
#include <QQueue>
#include <QBitArray>
#include <QDataStream>
#include <QDebug>
#include <QMap>
//Parser class
class Parser
{
public:
    Parser();
    // Commands
    enum {MOV, ADD, CLR, VAR};

    QMap<QString,QString> ParseToken(QQueue<QString> &Token);
    QString GetBinFormatInt(const int Width, int Num);
    int GetCommandEnum(QString CommandName);
    QString QBitArray2QString( QBitArray& array );

};

#endif // PARSER_H
