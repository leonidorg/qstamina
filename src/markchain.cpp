#include "markchain.h"

Markchain::Markchain(QObject *parent) :
    QObject(parent)
{
rand();
clear();
}

void Markchain::clear()
{
    m_chain.clear();
    m_store.clear();
}
void Markchain::rand()
{
    // Seed the random generator with current time
      QTime time = QTime::currentTime();
      qsrand((uint)time.msec());
}
int Markchain::getRandomNo(int low, int high)
{
     return qrand() % ((high + 1) - low) + low;
}
void Markchain::load(QString layout)
{
    this->clear();
    QSettings *readData;
    //readData=new QSettings(qApp->applicationName(),layout);
    readData=new QSettings(":/resources/generatorRules/"+layout+".rnd", QSettings::IniFormat);
     qDebug()<<"loading: readdata from:"<<readData->fileName();
    QStringList keys = readData->allKeys();

    foreach(QString key, keys)
       {

        int count=QVariant(readData->value(key)).toInt();
        this->append(key,count);
      };
    qDebug()<<" Загружен чистый  Random";

  }
void Markchain::append(QString str, int count)
{

    QChar key=str.at(0);
    QString value=str.right(str.size()-1);
    m_store[key].append(value);
    int ref=m_store[key].size()-1;
    //несколько раз...
   for(int i=0;i<count;i++)
   {
       m_chain[key].append(ref);
   }

}
bool Markchain::needDrop(QChar ch)
{
    QString  dropString=";.,:(){}[]/\?!-*@";

   bool result=false;
       if (ch=='"')result=true;
           else
       if (dropString.indexOf(ch)!=-1)result=true;
            else
           if(!ch.isSpace()&&!ch.isLetter())result=true;
           else
               if(ch.isNumber())result=true;
               else
                 result=false;
   return result;
}
QString Markchain::lower(QString ch,bool isAdvance)
{
   if(isAdvance) return ch;
   QChar qch;
   QString result;
   result.clear();
   for(int kk=0;(kk<ch.size());kk++)
   {
       qch=ch.at(kk);
       if(!needDrop(qch)) result.append(qch.toLower());
    }
return result;
}

QString Markchain::chapper(QString start, int length,bool isAdvanced)
{
        QChar key;
        if(!start.isEmpty()) key=start.at(0);
        else
        key=' ';
        QString sKey, sNum;
        sKey.clear();
        sKey.append(key);
        QString next;
        int last=0;

        QString result;
        result.clear();
         QMap<QChar, QStringList>::const_iterator it ;
        qDebug()<<"первый элем="<<start<<"vs"<<key;
        do
        {   it = m_store.find(key);
            if (it== m_store.end())
            {//нет соответсвующего символа! выберем случайно.
                qDebug()<<"OOps!!!";
                //for(int j=0;j<m_store.size();j++)
                   // qDebug()<<(m_store.begin()+j).key();
                int j=getRandomNo(0, m_store.size()-1);
                key=(m_store.begin() +j).key();
                next=key;
                if(!next.isEmpty())
                {
                    result.append(lower(next, isAdvanced));

                }


            }
            else
            {
            int len=m_chain[key].size();
            sNum.setNum(len);
            last=getRandomNo(0, m_chain[key].count()-1);
            //qDebug()<<"last["<<key<<"]="<<last;

            next=m_store[key].at(m_chain[key].at(last));
            //qDebug()<<"verseQ"<<result.size()<<"count="<<m_chain[key].count()<<"last="<<last<<"next="<<next;
            key=next.at(next.size()-1);
            if(!next.isEmpty())
            {
                result.append(lower(next,isAdvanced));

            }

            }//end if

        } while((result.size()<length)&&(!result.isEmpty()));
        qDebug()<<"RandomString: "<<result;
        return result.simplified();
}
