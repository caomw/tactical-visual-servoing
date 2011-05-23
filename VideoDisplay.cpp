
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

/**

//void VideoDisplay::mousePressEvent(QGraphicsSceneMouseEvent *event)
void VideoDisplay::mousePressEvent(QMouseEvent *event)
{

    printf("Clicked...");
}
**/

/**
void VideoDisplay::mousePressEvent(QGraphicsSceneMouseEvent *event)

{
 //   QGraphicsSceneMouseEvent::mousePressEvent(event);
//    QGraphicsScene::mousePressEvent(event);
//    if (event->isAccepted())
//        return;

    //m_mouseEventTime = m_time.elapsed();
    //m_angularMomentum = m_accumulatedMomentum = Point3d();
//    event->accept();
    printf("clicked...\n");
}
**/


void VideoDisplay::mousePressEvent(QMouseEvent *event)
{
    //QGraphicsView::mousePressEvent(event);

    //QGraphicsScene::mousePressEvent(event);
    //if (event->isAccepted())
    //    return;
    //event->accept();
    printf("yay...\n");
}
