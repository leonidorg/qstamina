#ifndef CLONFIG_H
#define CLONFIG_H

#include <QApplication>
#include <QString>
#include <QSettings>
#include <QList>
#include <QFile>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonArray>
#include <QJsonObject>
#include <QStandardPaths>

#include <QDebug>

#ifdef Q_OS_LINUX
#   include <QDir>
#endif

#include "lessonslist.h"

struct Layout {
    QString name;
    QString title;
    QString symbols;
};

class Config
{
public:
    Config();
    ~Config();

    QString lastLayoutFile() const;
    void setLastLayoutFile(const QString &lastLayoutFile);

    int fontSize() const;
    void setFontSize(int fontSize);
    double volume();
    bool separateKeyboard() const;
    bool enableSound() const;
    void setSeparateKeyboard(bool separateKeyboard);
    void setEnableSound(bool enableSound);

    QString resourcesPath();

    QString lastLayout() const;
    void setLastLayout(const QString &lastLayout);

    Layout *currentLayout() const;
    bool setCurrentLayout(const int layoutIndex);
    Lesson * getLastLesson(QString group,int number);
    QString lastGroup() const{return m_lastGroup;}
    int lastNumber() const{return m_lastNumber;}
    void setLastLesson(QString group,int number);
    QList<Layout *> layouts() const;
    LessonsList lessons() const;
    QList<Lesson *> generatedLessons() const;
public slots:
    void lessonsGenerated();
private:
    QSettings *m_settings;
    QString m_lastLayoutFile;
    QString m_lastLayout;
    int m_fontSize;
    bool m_separateKeyboard;
    bool m_enableSound;
    QList<Layout*> m_layouts;
    Layout *m_currentLayout;
    QString m_lastGroup;
    int m_lastNumber;

    LessonsList m_lessons;
    QList<Lesson*> m_generatedLessons;

    void loadLayouts();
    void loadLessons();
    void loadGeneratedLessons();
    void clearLessons();
    void clearGeneratedLessons();
};

#endif // CLONFIG_H
