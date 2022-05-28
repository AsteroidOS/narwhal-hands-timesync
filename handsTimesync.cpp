/* Copyright (C) 2022 Arseniy Movshev <dodoradio@outlook.com>
 * All rights reserved.
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>
 */
#include <QTime>
#include <QDate>
#include <QFile>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QFile time_file("/sys/devices/sop716/time");
    if(!time_file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qCritical("Unable to open file for write. Check permissions");
        return(-1);
    }
    QTextStream out(&time_file);
    out << QDate::currentDate().toString(Qt::ISODate) << " " << QTime::currentTime().toString(Qt::TextDate);
    time_file.close();
    qDebug("Synchronised Narwhal hands with system time");
}
