#include "filefinder.h"

FileFinder::FileFinder()
{

}

QUrl FileFinder::FindOpen(){
    QString path = QFileDialog::getOpenFileName(nullptr, "Open File", "","Media Files (*.mp4 *.mp3)");
    return QUrl::fromLocalFile(path);
}
