#include "analysis.h"

AnalysisLine::AnalysisLine()
{
	oTimeStamp = 0.;
	oValue = 0.;
	slope = 0.;
}

AnalysisLine::AnalysisLine(double _oTime, double _oValue, double _slope)
{
	if (setLine(_oTime, _oValue, _slope) != 0)
	{
		oTimeStamp = 0.;
		oValue = 0.;
		slope = 0.;
	}
}

AnalysisLine::~AnalysisLine()
{

}

int AnalysisLine::setLine(double _oTimeStamp, double _oValue, double _slope)
{
	oTimeStamp  = _oTimeStamp;
	oValue = _oValue;
	slope  = _slope;

	return 0;
}
