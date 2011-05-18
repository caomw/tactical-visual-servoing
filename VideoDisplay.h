#ifndef VIDEODISPLAY_H
#define VIDEODISPLAY_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>

#include <stdio.h>
#include <stdlib.h>

class VideoDisplay : public QGraphicsView
{
    Q_OBJECT

    public:

        VideoDisplay();
        ~VideoDisplay();

        QGraphicsView _display;

    protected:

        //virtual void mouseMoveEvent(QMouseEvent *event);
        //virtual void mouseMoveEvent(QDragDropEvent *event);
        //virtual void mousePressEvent(QGraphicsSceneMouseEvent * event);
        virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
        //virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // VIDEODISPLAY_H
