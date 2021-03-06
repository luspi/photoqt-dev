/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef CUSTOMLINEEDIT_H
#define CUSTOMLINEEDIT_H

#include <QLineEdit>

class CustomLineEdit : public QLineEdit {

	Q_OBJECT

public:
	CustomLineEdit(QString txt = "", QWidget *parent = 0);
	~CustomLineEdit();

	// Minimum width
	void setMinWidth(int w);
	void setBorder(QString col, int w);
	void setFontSize(int fs) { fontsize = fs; setCSS(); }

public slots:
	void setEnabled(bool);

private:
	int width;
	QString borderColor;
	int borderWidth;
	int fontsize;
	void setCSS();

protected:
	void mouseReleaseEvent(QMouseEvent *);

signals:
	void clicked();

};

#endif // CUSTOMLINEEDIT_H
