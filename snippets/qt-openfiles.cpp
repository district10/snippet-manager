QStringList Utils::openMultipleFiles( const QString &filter0, QWidget *widget ) {
    QString filter = filter0;
    if ( filter.isEmpty() ) {
        filter = QObject::tr("images (*.bmp *.png *.jpg *.jpeg *.png *.gif *.tif *.tiff)");
    }
    QStringList fileNames;

    QFileDialog::Options options;
    options |= QFileDialog:: DontUseNativeDialog;

    fileNames = QFileDialog::getOpenFileNames( widget,
                                               QObject::tr( "select multiple image files" ),
                                               DEFAULT_INPUT_IMAGE_DIR,  // entry dir
                                               filter,                   // filter
                                               (QString *)0,             // selected filter
                                               options );
    return fileNames;
}
