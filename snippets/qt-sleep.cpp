void Utils::sleep( const quint16 &t ) {
    QTime dieTime = QTime::currentTime().addMSecs(t);
    while( QTime::currentTime() < dieTime ) {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}

// usleep - suspend execution for microsecond intervals
//          #include <unistd.h>
//          int usleep(useconds_t usec);
while(!mpLocalMapper->isStopped()) {
    usleep(1000);
}
