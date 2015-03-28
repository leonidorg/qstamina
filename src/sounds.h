#ifndef SOUNDS_H
#define SOUNDS_H

#include <QObject>
#include <QMap>

#include "config.h"
#include <QSoundEffect>
class Sounds : public QObject
{
    Q_OBJECT
public:
    explicit Sounds( Config *config, QObject *parent = 0 );
    void play( const QString & );
    void setVolume(double vol);
    bool isPlaying();
private:
    double _volume;
    Config *m_config;
    QSoundEffect *currentPlayer;
    QMap<QString, QString> m_sounds;
    QList<QSoundEffect*> players;
};

#endif // SOUNDS_H
