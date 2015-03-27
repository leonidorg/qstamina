#ifndef INTLIST_H
#define INTLIST_H

#include <QObject>
#include <QDebug>

class IntList
{

public:
    IntList();
    void append(const int i);
    bool isEmpty();
    int count();
    void clear();
    int at(int i);
    int size();
private:
    QList<qint64> m_list;
signals:

public slots:

};

#endif // INTLIST_H
