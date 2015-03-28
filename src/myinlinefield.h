#ifndef MYINLINEFIELD_H
#define MYINLINEFIELD_H
# include <QString>
#include "inlinefield.h"
class MyInlineField : public InlineField
{
public:
    MyInlineField(Sounds *sounds, QWidget *parent = 0);
    ~MyInlineField();
    QString lastSymbol();
    void reset();
    void start();
    void stop();
};

#endif // MYINLINEFIELD_H
