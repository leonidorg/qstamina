/*
*  This file is freqbased random text generator
*   Created for Qstamina and testing here
*
*  Copyright (C) 2015 Leonidorg <leonidorg@gmail.com>
*
*  This is free software: you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation, either version 2 or (at your option)
*  version 3 of the License.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
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
    QString chapper(QString start, int length,bool isAdvanced);
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
