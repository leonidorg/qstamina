#ifndef MARKCHAIN_H
#define MARKCHAIN_H

#include <QObject>
#include <QObject>
#include <QMap>
#include <QStringList>
#include <QTime>
#include <QDebug>
#include <QSettings>
//#include "interval.h"
//#include<intlist.h>
#include<QList>
#include<QString>
#include<QForeachContainer>
#include"config.h"
#include <QObject>
#include <QDebug>
#include "intlist.h"

class Markchain : public QObject
{
    Q_OBJECT
public:
    explicit Markchain(QObject *parent = 0);
    void load(QString layout);
    bool isEmpty() const{ return m_chain.isEmpty();}
    void append(QString str, int count);//public enabled correcct for other modules
    QString chapper(QChar start, int length,bool isAdvanced);
    void clear();

signals:

public slots:
private:
   QString lower(QString ch, bool isAdvance);
   void rand();
   int getRandomNo(int low, int high);
   bool needDrop(QChar ch);
   QMap <QChar, IntList> m_chain;
   QMap<QChar, QStringList> m_store;//для хранения элементов марковской цепи
};

#endif // MARKCHAIN_H
