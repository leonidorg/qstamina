#include "sounds.h"




Sounds::Sounds(Config *config, QObject *parent) : QObject(parent),
    m_config( config )

{   players.clear();
    setVolume(m_config->volume());

    m_sounds[ "metronome" ] = ":/resources/sounds/Metronome.wav";//(c)VerseQ

    m_sounds[ "backspace" ] = ":/resources/sounds/Switch.wav";//(c) Xneur
    m_sounds[ "item" ] = ":/resources/sounds/itemback.wav";//(c) Xneur
    m_sounds[ "owFemale" ] = ":/resources/sounds/Ow_Female.wav";//(с)Stamina
    m_sounds[ "owVinni" ] = ":/resources/sounds/Ow_Vinni.wav";//(с)Stamina
    m_sounds[ "click" ] = ":/resources/sounds/Click.wav";//(c) VerseQ
    m_sounds[ "type" ] = ":/resources/sounds/type.wav";
    m_sounds[ "error" ] = ":/resources/sounds/Error.wav";//VerseQ
    m_sounds[ "Success" ] = ":/resources/sounds/Success.wav";//VerseQ
}

Sounds::~Sounds()
{
    while (!players.isEmpty())
     players.dequeue()->deleteLater();
}
void Sounds::setVolume(double vol)
{

    _volume=vol;
}



void Sounds::play( const QString &sound )
{

 if (  m_sounds.contains( sound ) && m_config->enableSound())
 {

   QSoundEffect *currentPlayer=new QSoundEffect();
   players.enqueue(currentPlayer);


    //Исполним трек с помощью найденного свободного плейера.

       if(currentPlayer->isPlaying()) currentPlayer->stop();
        currentPlayer->setLoopCount(1);
        currentPlayer->setSource(QUrl::fromLocalFile(m_sounds[ sound ]));
        currentPlayer->setVolume(_volume);
        currentPlayer->play();
//освободим память.
        while(!players.head()->isPlaying())
            players.dequeue()->deleteLater();
        //qDebug()<<"плейеров всего:"<<players.count();

 }


}

