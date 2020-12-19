#ifndef ENUMERROR_H
#define ENUMERROR_H

#include"qnetwork.h"
#include "QMetaEnum"
#include <qerrormessage.h>
#include <QtNetwork/qnetworkreply.h>
class enumerror
{
public:

    enumerror();
    QNetworkReply::NetworkError error;

       enumerror == fetchStuff();

    if (enumerror != QNetworkReply::NoError) {

        QString enumerrorValue;

        QMetaObject meta = QNetworkReply::staticMetaObject;

        for (int i=0; i < meta.enumeratorCount(); ++i) {

            QMetaEnum m = meta.enumerator(i);

            if (m.name() == QLatin1String("NetworkError")) {

                errorValue = QLatin1String(m.valueToKey(error));

                break;

            }

        }


        QMessageBox box(QMessageBox::Information, "Failed to fetch",

                    "Fetching stuff failed with error '%1`").arg(errorValue),

                    QMessageBox::Ok);

        box.exec();

        return 1;

    }
};
};

#endif // ENUMERROR_H
