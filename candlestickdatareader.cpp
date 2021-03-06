// #include <iostream>
#include <QDateTime>
#include "candlestickdatareader.h"

CandlestickDataReader::CandlestickDataReader(QIODevice *device) : QTextStream(device)
{
}

CandlestickDataReader::~CandlestickDataReader()
{
}

void CandlestickDataReader::readFile(QIODevice *device)
{
	QTextStream::setDevice(device);
}

QCandlestickSet *CandlestickDataReader::readCandlestickSet()
{
	QString line = readLine();

	if (line.startsWith("#") || line.isEmpty())
		return 0;

	QStringList strList = line.split(" ", QString::SkipEmptyParts);
	if (strList.count() != 5)
		return 0;

	const qreal timestamp = strList.at(0).toDouble();
	const qreal open = strList.at(1).toDouble();
	const qreal high = strList.at(2).toDouble();
	const qreal low = strList.at(3).toDouble();
	const qreal close = strList.at(4).toDouble();

	QCandlestickSet *candlestickSet = new QCandlestickSet(timestamp);
	candlestickSet->setOpen(open);
	candlestickSet->setHigh(high);
	candlestickSet->setLow(low);
	candlestickSet->setClose(close);

	// std::cout << QDateTime::currentMSecsSinceEpoch() << std::endl;
	// std::cout << QDateTime::currentSecsSinceEpoch() << std::endl;

	return candlestickSet;
}
