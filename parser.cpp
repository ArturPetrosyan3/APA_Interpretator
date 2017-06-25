#include "parser.h"
#include <iostream>
#include <bitset>
#include <string>
Parser::Parser()
{

}

int Parser::GetCommandEnum(QString CommandName) {
    if (CommandName == "mov")
        return 0;
    else if (CommandName == "add")
        return 1;
    else if (CommandName == "clr")
        return 2;
    else if (CommandName == "input")
        return 3;
    else
        return -1;
}

QMap<QString, QString> Parser::ParseToken(QQueue<QString> &Token) {
    QTextStream ParsedToken;
    QString InputVariable;
    QString FirstVariable;
    QString SecondVariable;
    QMap <QString, QString> VariableMap;

    switch (GetCommandEnum(Token.front())) {
        case MOV:
            Token.pop_front();
            FirstVariable = Token.front();
            Token.pop_front();
            SecondVariable = Token.front();

            //InputBinaryString = GetBinFormatInt(32,SecondVariable.toInt());
            break;
        case ADD:
            //to do
            break;
        case CLR:
            break;
        case INPUT:
             Token.pop_front();
             InputVariable = Token.front();
             VariableMap.insert(InputVariable,GetBinFormatInt(32,0));

            break;

        default:
        break;
    }
    return VariableMap;
}

QString Parser::QBitArray2QString( QBitArray& array )
{
    QByteArray bytes;
        bytes.resize(array.size()/8);

        for(int b = 0; b < array.count(); ++b)
            bytes[b/8] = (bytes.at(std::floor(b/8)) | ((array[b]?1:0)<<(b%8)));
        QString aa= bytes;

        return aa;
}
QString Parser::GetBinFormatInt(const int Width, int Num){
    std::bitset<32> BitStr(Num);
    std::string mystr=  BitStr.to_string();
    QString str = QString::fromUtf8(mystr.c_str());
    return str;
}
