#ifndef QTCHECK_BACKEND_H
#define QTCHECK_BACKEND_H

#include <QMainWindow>
#include <QObject> 
#include <QWaitCondition>
#include "MarSystemManager.h"
#include "MarSystemQtWrapper.h"
using namespace Marsyas;
using namespace MarsyasQt;

// temp for debugging
using namespace std;
#include <iostream>

class MarBackend: public QObject
{
	Q_OBJECT
public:
	MarBackend(string infile, string outfile);
	~MarBackend();
	void waitUntilFinished();

public slots:
	void ctrlChanged(MarControlPtr changed);

private:
	void stop();
	MarSystemManager mng;
	MarSystemQtWrapper *mrsWrapper;
	MarSystem *pnet;
	MarControlPtr isEmptyPtr;
	MarControlPtr posPtr;
	bool isRunning;


	QWaitCondition wait;
	QMutex mutex;
};
#endif

