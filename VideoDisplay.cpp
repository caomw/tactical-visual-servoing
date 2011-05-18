
#include "VideoDisplay.h"

VideoDisplay::VideoDisplay()
{

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

void VideoDisplay::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    printf("Clicked...");
}
