#ifndef FILEFINDER_H
#define FILEFINDER_H

#include <QFileDialog>

class FileFinder : public QObject
{
    Q_OBJECT
public:
    FileFinder();

    QUrl FindOpen();
};

#endif // FILEFINDER_H
