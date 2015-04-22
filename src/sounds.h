#ifndef SOUNDS_H
#define SOUNDS_H

#include <QObject>
#include <QMap>
#include <QQueue>

#include "config.h"
#include<QSoundEffect>
#include <QDebug>
class Sounds : public QObject
{
    Q_OBJECT
public:
    explicit Sounds( Config *config, QObject *parent = 0 );
    ~Sounds();
    void play( const QString & );
    void setVolume(double vol);
private:
    double _volume;
    Config *m_config;
    //QSoundEffect *currentPlayer;
    QMap<QString, QString> m_sounds;
    QQueue<QSoundEffect*> players;
};

#endif // SOUNDS_H
