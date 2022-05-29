/* Copyright (C) 2022-2023 Arseniy Movshev <dodoradio@outlook.com>
 * All rights reserved.
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>
 */
#include <QTime>
#include <QDate>
#include <QFile>
#include <QTextStream>
#include <QTimeZone>
#include <QDateTime>

int main(int argc, char *argv[])
{
    //writes the local time into sysfs
    QFile time_file("/sys/devices/sop716/time");
    if(!time_file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qCritical("Unable to open file for write. Check permissions");
        return(-1);
    }
    QTextStream out(&time_file);
    out << QDate::currentDate().toString(Qt::ISODate) << " " << QTime::currentTime().toString(Qt::TextDate);
    time_file.close();
    QTextStream out_time_file(&time_file);
    out_time_file << QDate::currentDate().toString(Qt::ISODate) << " " << QTime::currentTime().toString(Qt::TextDate);
    time_file.close();
    //this code sets the timezone offset. While sop716 operates on local time, when queried it provides the time with the timezone offset. The android kernel uses this to set the system clock.
    qDebug("Synchronised Narwhal hands with system time");
    QFile tzminutes_file("/sys/devices/sop716/tz_minutes");
    if(!tzminutes_file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qCritical("Unable to open file for write. Check permissions");
        return(-1);
    }
    QTextStream out_tzminutes_file(&tzminutes_file);
    out_tzminutes_file << (QTimeZone::systemTimeZone().offsetFromUtc(QDateTime::currentDateTime())/60);
    tzminutes_file.close();
    qDebug("Synchronised Narwhal hands with system time");
}
