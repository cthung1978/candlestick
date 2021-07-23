#ifndef CANDLESTICKDATAREADER_H
#define CANDLESTICKDATAREADER_H

#include <QtCharts/QCandlestickSet>
#include <QtCore/QTextStream>

QT_CHARTS_USE_NAMESPACE

class CandlestickDataReader : public QTextStream
{
public:
	explicit CandlestickDataReader(QIODevice *device);
	~CandlestickDataReader();

	void readFile(QIODevice *device);
	QCandlestickSet *readCandlestickSet();
};

#endif // CANDLESTICKDATAREADER_H
