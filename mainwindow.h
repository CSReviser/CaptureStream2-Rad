/*
	Copyright (C) 2009-2013 jakago

	This file is part of CaptureStream, the flv downloader for NHK radio
	language courses.

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 2 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMutex>
#include <QCloseEvent>
#include <QObject>
#include <QNetworkAccessManager>
#include <QList>
#include <QNetworkReply>
#include <QUrl>
#include <QEventLoop>
#include <QMutex>
#include <QStringList>
#include "messagewindow.h"

#define INI_FILE "CaptureStream2-Rad.ini"

//ニュースで英会話「音声と動画」「音声のみ」「動画のみ」
#define ENewsSaveBoth	0
#define ENewsSaveAudio	1
#define ENewsSaveMovie	2

class DownloadThread;

namespace Ui {
	class MainWindowClass;
}

class MainWindow : public QMainWindow {
	Q_OBJECT

	enum ReadWriteMode {
		ReadMode, WriteMode
	};

public:
	MainWindow( QWidget *parent = 0 );
	~MainWindow();

	static QString outputDir;
	static QString ini_file_path;
	static QString scramble;
	static QString scrambleUrl1;
	static QString scrambleUrl2;
	static QString customized_title1;
	static QString customized_title2;
	static QString customized_file_name1;
	static QString customized_file_name2;
	static QString SETTING_OPTIONAL[];
	static QString SETTING_OPT_TITLE[]; 
	static QString Program_TITLE[]; 
	static QString OPTIONAL[];
	static QString optional[];
	static QString optional1;
	static QString optional2;
	static QString optional3;
	static QString optional4;
	static QString optional5;
	static QString optional6;
	static QString optional7;
	static QString optional8;
	static QString program_title[];
	static QString program_title1;
	static QString program_title2;
	static QString program_title3;
	static QString program_title4;
	static QString program_title5;
	static QString program_title6;
	static QString program_title7;
	static QString program_title8;
	static QString no_write_ini;
	static QStringList idList;
	static QStringList titleList;
	static QMap<QString, QString> name_map;
	static QMap<QString, QString> id_map;
	static QMap<QString, QString> thumbnail_map;

protected:
	virtual void closeEvent( QCloseEvent *event );

public slots:
	void download();
	void toggled( bool checked );
	void customizeSaveFolder();

private slots:
	void finished();
	void customizeTitle();
	void customizeFileName();
//	void customizeSaveFolder();
//	void customizeScramble();
	void closeEvent2( );

private:
	QStringList getAttribute( QString url, QString attribute );
	Ui::MainWindowClass *ui;
	DownloadThread* downloadThread;
	QMenu* customizeMenu;
	MessageWindow messagewindow;
	QEventLoop eventLoop;
	static QString prefix;
	static QString suffix;
	static QString json_prefix;
	void setmap();
	void settings( enum ReadWriteMode mode );
};

#endif // MAINWINDOW_H
