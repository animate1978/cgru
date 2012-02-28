#pragma once

#include <QtGui/QListView>

class ListItems;

class ItemDelegate : public QAbstractItemDelegate
{
public:
   ItemDelegate( QWidget *parent = 0);

   void paint( QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

   QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

   void emitSizeHintChanged( const QModelIndex &index);
};

class ViewItems: public QListView
{
public:
   ViewItems( QWidget * parent);
   virtual ~ViewItems();

   void emitSizeHintChanged( const QModelIndex &index);

   inline void updateGeometries() { QListView::updateGeometries();}

//   inline void set_mousePressEvent_handler( bool (*handler)( QMouseEvent  *)) { mousePressEvent_handler = handler;}
   inline void setListItems( ListItems * ptr) { listitems = ptr;}

   void repaintViewport();

protected:
    void keyPressEvent( QKeyEvent * event);
    void mousePressEvent( QMouseEvent * event);
    #if QT_VERSION >= 0x040704
    void paintEvent ( QPaintEvent * event );
    #endif

private:
    void loadImage();

private:
//   bool (*mousePressEvent_handler)( QMouseEvent * );
   ItemDelegate * itemDelegate;

   ListItems * listitems;

   QPixmap m_back_pixmap;
   int m_back_offset_x;
   int m_back_offset_y;
};
