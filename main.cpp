#include <QtCharts/QBarCategoryAxis>
// #include <QtCharts/QCategoryAxis>
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QCandlestickSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
#include <QtCore/QDateTime>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QLineSeries>

#include <iostream>

#include "candlestickdatareader.h"
#include "analysis.h"
QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QCandlestickSeries *acmeSeries = new QCandlestickSeries();
	acmeSeries->setName("Acme Ltd");
	acmeSeries->setIncreasingColor(QColor(Qt::green));
	acmeSeries->setDecreasingColor(QColor(Qt::red));

	QFile acmeData("./acme_data.txt");
	if (!acmeData.open(QIODevice::ReadOnly | QIODevice::Text))
		return 1;

	QStringList categories;

	CandlestickDataReader dataReader(&acmeData);
	while (!dataReader.atEnd())
	{
		QCandlestickSet *set = dataReader.readCandlestickSet();
		std::cout << set << std::endl;
		if (set) {
			acmeSeries->append(set);
			categories << QDateTime::fromMSecsSinceEpoch(set->timestamp()).toString("yyyy-MM-dd HH:mm");
		}
	}

	// QList<QCandlestickSet *>::iterator it;
	// for (it = acmeSeries->sets().begin(); it != acmeSeries->sets().end(); it++)
	// {
	// 	std::cout << (*it)->open() << std::endl;
	// }

	QChart *chart = new QChart();
	chart->addSeries(acmeSeries);
	chart->setTitle("Acme Ltd Historical Data (July 2015)");

	AnalysisLine(1436313600000, 124.0, 20.);
	// Find the first and last timestamp
	QList<QCandlestickSet *>::iterator it_begin, it_end;

	QLineSeries *seriesL = new QLineSeries();
	seriesL->append(0., 126.94);
	seriesL->append(20., 122.64);
	chart->addSeries(seriesL);

	chart->createDefaultAxes();
	// QDateTimeAxis *axisX = qobject_cast<QDateTimeAxis *>(chart->axes(Qt::Horizontal).at(0));
	QBarCategoryAxis *axisX = qobject_cast<QBarCategoryAxis *>(chart->axes(Qt::Horizontal).at(0));
	axisX->setCategories(categories);
	std::cout << axisX->count() << std::endl;
	// axisX->setMax("07/17");
	// axisX->setMin("07/06");
	seriesL->attachAxis(axisX);

	QValueAxis *axisY = qobject_cast<QValueAxis *>(chart->axes(Qt::Vertical).at(0));
	axisY->setMax(axisY->max() * 1.01);
	axisY->setMin(axisY->min() * 0.99);
	// chart->axisX(seriesL)->setVisible(false);
	seriesL->attachAxis(axisY);

	chart->legend()->setVisible(true);
	chart->legend()->setAlignment(Qt::AlignBottom);

	QChartView *chartView = new QChartView(chart);
	chartView->setRenderHint(QPainter::Antialiasing);

	QMainWindow window;
	window.setCentralWidget(chartView);
	window.resize(800, 600);
	window.show();

	return a.exec();
}
