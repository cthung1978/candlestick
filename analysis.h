#ifndef ANALYSIS_H
#define ANALYSIS_H

class AnalysisLine
{
public:
	explicit AnalysisLine();
	explicit AnalysisLine(double, double, double);
	~AnalysisLine();

	int setLine(double, double, double); // set the line information with (time, value, slope), where the type of time is qint64(long long)
	int setOririnalPoint(double, double);
	int setSlope(double, double);

private:
	double oTimeStamp;
	double oValue;
	double slope;
};

#endif // CANDLESTICKDATAREADER_H
