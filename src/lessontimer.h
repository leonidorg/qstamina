/*   Created for Qstamina and testing here
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
#ifndef LESSONTIMER_H
#define LESSONTIMER_H

#include <QObject>
#include <QTime>

class LessonTimer : public QObject
{
    Q_OBJECT
public:
    explicit LessonTimer(int interval, QObject *parent = 0);
    ~LessonTimer();

signals:

public slots:
    void start();
    int clearTime();
private:
   int interval;
   QTime astroTime;
   QTime intervalTime;
   int pauseTime;


};

#endif // LESSONTIMER_H
