#ifndef VIDEODISPLAY_H
#define VIDEODISPLAY_H

/**
#include <QGraphicsItem>
//#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QMessageBox>
**/

#include <QWidget>
#include <QMessageBox>
#include <QtGui>

//#include <QGraphicsSceneMouseEvent>

/**
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneMouseEvent>
#include <QColor>
#include <QPainter>
#include <QPen>
#include <QPointF>
**/

#include <stdio.h>
#include <stdlib.h>

//class VideoDisplay : public QGraphicsView
class VideoDisplay : public QWidget
//class VideoDisplay : public QGraphicsItem
//class VideoDisplay : public QGraphicsScene
{
    Q_OBJECT

    public:

        VideoDisplay(QWidget *parent = 0);
        ~VideoDisplay();

        //QGraphicsView _display;

    protected:

        //virtual void mouseMoveEvent(QMouseEvent *event);
        //virtual void mouseMoveEvent(QDragDropEvent *event);
        //virtual void mousePressEvent(QGraphicsSceneMouseEvent * event);
        //virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
        //virtual void mousePressEvent(QMouseEvent *event);
        //virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

        //void mousePressEvent(QGraphicsSceneMouseEvent *event);

        virtual void mousePressEvent(QMouseEvent *event);
};

#endif // VIDEODISPLAY_H
