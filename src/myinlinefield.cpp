#include "myinlinefield.h"
#include "textfield.h"


MyInlineField::MyInlineField(Sounds *sounds, QWidget *parent)  :
    InlineField(sounds, parent)
{

}

MyInlineField::~MyInlineField()
{

}

 QString MyInlineField::lastSymbol()
 {
    if(!m_oldText->text().isEmpty())
        return m_oldText->text().at(m_oldText->text().size()-1);
    else
        return " ";
 }
 void MyInlineField::start()
 {
     m_rightSymbols = 0;
     m_wrongSymbols = 0;
 }

 void MyInlineField::stop()
 {

 }

 void MyInlineField::reset()
 {  qDebug()<<"reset()"<<m_newText->text();
     m_oldText->setText(m_oldText->text().right(40));
     m_newText->setText(m_text);
     m_countSymbols = m_text.size();
 }
