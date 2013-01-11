#ifndef GLOBALVARIABLES_H
#define GLOBALVARIABLES_H

#include <QObject>
#include <QRect>

// Some global variables
class GlobalVariables {

public:
	// The current file
	QString currentfile;

	// Are we ignoring the tray icon and just exit
	bool skipTrayIcon;

	// The current rotation of the image
	int rotation;

	// Is current image zoomed? By Mouse or key combo?
	bool zoomed;
	bool zoomedByMouse;

	// Is a widget opened?
	bool blocked;

	// This list holds all shortcuts that are to be set up as system shortcuts
	QStringList systemSh;

	// Was the current image zoomed in any way
	bool zoomedImgAtLeastOnce;

	// Is the current image flipped?
	bool flipVer;
	bool flipHor;

	// The "read" is in past tense
	bool exifRead;

	// Currently zoomed to actual size
	bool zoomToActualSize;

	// When restoring photo from system tray, it emits a resizeEvent -> ignore it
	uint restoringFromTrayNoResize;

	// Is a slideshow running
	bool slideshowRunning;

	// Used to catch Alt+F4 (well, actually Alt+closeEvent)
	bool altForAltF4;

	// Is the startup message shown (displayed after update/fresh install)
	int startupMessageInstallUpdateShown;


	// Set the default values
	void setVariables() {

		rotation = 0;

		skipTrayIcon = false;

		blocked = false;

		zoomed = false;
		zoomedByMouse = true;
		zoomedImgAtLeastOnce = false;

		systemSh << "Escape" << "Enter" << "Return" << "Ctrl+s" << "Left" << "Right" << "Up" << "Down" << "Alt+Up" << "Alt+Left" << "Alt+Right" << "Alt+F4" << "Alt+1" << "Alt+2" << "Alt+3" << "Alt+4" << "Alt+5" << "Ctrl+Tab" << "Ctrl+Shift+Tab";

		flipVer = false;
		flipHor = false;

		altForAltF4 = false;

		exifRead = false;

		zoomToActualSize = false;

		restoringFromTrayNoResize = 0;

		startupMessageInstallUpdateShown = 0;

	}

};

#endif // GLOBALVARIABLES_H
