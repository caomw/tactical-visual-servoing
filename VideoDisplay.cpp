
#include "VideoDisplay.h"

//VideoDisplay::VideoDisplay(QWidget *parent) : QGraphicsView(parent)
VideoDisplay::VideoDisplay(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(true);
    printf("VideoDisplay constructor....\n");

}

VideoDisplay::~VideoDisplay()
{

}


/**
void VideoDisplay::mousePressEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);
    if (event->isAccepted()) {
        return;
    }
    if (event->buttons() & Qt::LeftButton) {
        printf("Click....\n");
        event->accept();
        update();
    }
}
**/


void VideoDisplay::mousePressEvent(QMouseEvent *event)
{
    QMessageBox msgBox;
    msgBox.setText("Test OK!!");
    msgBox.exec();

    printf("yay...\n");
    event->setAccepted(true);
    //QGraphicsView::mousePressEvent(event);

    //QGraphicsScene::mousePressEvent(event);
    //if (event->isAccepted())
    //    return;
    //event->accept();
    //emit clicked(event->pos());
}
