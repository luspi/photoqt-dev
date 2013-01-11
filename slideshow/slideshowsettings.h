#ifndef SLIDESHOWSETTINGS_H
#define SLIDESHOWSETTINGS_H

#include "../customelements/customscrollbar.h"
#include "../customelements/customslider.h"
#include "../customelements/customspinbox.h"
#include "../customelements/customcheckbox.h"
#include "../customelements/customlineedit.h"
#include "../customelements/custompushbutton.h"

#include <QWidget>
#include <QPropertyAnimation>
#include <QTimeLine>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QLabel>
#include <QDir>
#include <QFileDialog>

class SlideShow : public QWidget {

	Q_OBJECT

public:
	SlideShow(QMap<QString,QVariant> set, QWidget *parent = 0);
	~SlideShow();

	QMap<QString,QVariant> globSet;

	// The animation for the content widget
	QPropertyAnimation *ani;

	// Boolean about current geometry/position
	bool isShown;

	// The different QRects
	QRect rectShown;
	QRect rectHidden;
	QRect rectAni;

	// The fade parameters for the background
	int backAlphaShow;
	int backAlphaCur;
	QTimeLine *fadeBack;
	bool fadeBackIN;

	// Central widget
	QWidget *center;

	// Adjust time
	CustomSlider *timeSlider;
	// Adjust transition
	CustomSlider *trans;
	// Adjust quickinfo labels
	CustomCheckBox *hideQuickInfo;
	// Adjust music
	CustomCheckBox *musicEnable;
	CustomLineEdit *musicPath;

	// Adjust geometries
	void adjustGeometries();

public slots:
	// The animation functions
	void animate();
	void aniFinished();

	// Each fade step calls this function
	void fadeStep();

	// Browse filesystem for music file
	void browseForMusic();

	// Start slideshow
	void andStart();

signals:
	// Block all function in mainwindow and activate system keys
	void blockFunc(bool block);

	// Start the slideshow
	void startSlideShow();

protected:
	// Overriding the paint event to make widget styleable
	void paintEvent(QPaintEvent *);

	void mouseReleaseEvent(QMouseEvent *);
};

#endif // SLIDESHOWSETTINGS_H
