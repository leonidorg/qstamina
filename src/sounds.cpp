#include "sounds.h"




Sounds::Sounds(Config *config, QObject *parent) : QObject(parent),
    m_config( config )

{   currentPlayer=NULL;
    players.clear();
    setVolume(m_config->volume());

    m_sounds[ "metronome" ] = ":/resources/sounds/Metronome.wav";//(c)VerseQ

    m_sounds[ "backspace" ] = ":/resources/sounds/Switch.wav";//(c) Xneur

    m_sounds[ "owFemale" ] = ":/resources/sounds/Ow_Female.wav";//(с)Stamina
    m_sounds[ "owVinni" ] = ":/resources/sounds/Ow_Vinni.wav";//(с)Stamina
    m_sounds[ "click" ] = ":/resources/sounds/Click.wav";//(c) VerseQ
    m_sounds[ "type" ] = ":/resources/sounds/type.wav";
    m_sounds[ "error" ] = ":/resources/sounds/error.wav";//native
    m_sounds[ "Error" ] = ":/resources/sounds/Error.wav";//VerseQ
    m_sounds[ "Success" ] = ":/resources/sounds/Success.wav";//VerseQ
}
void Sounds::setVolume(double vol)
{

    _volume=vol;
}
bool Sounds::isPlaying()
{
    if(currentPlayer==NULL)
        return false;
    else
        return currentPlayer->isPlaying();
}

void Sounds::play( const QString &sound )
{

    if (  m_sounds.contains( sound ) && m_config->enableSound())
    {

        int i=0; currentPlayer=NULL;
        if(!players.isEmpty())
        while((i<players.size())&& (currentPlayer==NULL))
        {
            if (!players.at(i)->isPlaying())
                currentPlayer=players.at(i);//нашли свободный плейер - будем играть на нем.
            //или поищем другие свободные - пока не выберем крайний снизу.
            i++;
        }


        if (currentPlayer==NULL)
        {   //нет свободного плейера?- добавим еще один.
            QSoundEffect *one_player=new QSoundEffect(this);
            players.append(one_player);
            currentPlayer=players.last();//выберем его, как заведомо свободный.
            //;за сессию может образоваться несколько плейеров, в зависимости от потока звука.
            //есть надежда, что список сможет пополняться тем количеством, которое обеспечит полифоничное звучание: отработку исполнения всех треков.
            qDebug()<<"плейеров всего:"<<players.count();
        }
    //Исполним трек с помощью найденного свободного плейера.
        currentPlayer->setSource(QUrl::fromLocalFile(m_sounds[ sound ]));//используется файл ресурсов (.qrc)
        currentPlayer->setVolume(_volume);
        currentPlayer->play();
//qDebug()<<"плейер №"<<i<<" из "<<players.count();

    }

}

