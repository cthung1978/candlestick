#ifndef ANALYSIS_H
#define ANALYSIS_H

class AnalysisLine
{
public:
	explicit AnalysisLine();
	explicit AnalysisLine(long long, double, double);
	~AnalysisLine();

	int setLine(long long, double, double); // set the line information with (time, value, slope), where the type of time is qint64(long long)
	int setOririnalPoint(long long, double);
	int setSlope(long long, double);

private:
	long long oTime;
	double oValue;
	double slope;
};

#endif // CANDLESTICKDATAREADER_H
