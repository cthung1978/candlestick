#include "analysis.h"

AnalysisLine::AnalysisLine()
{
	oTime = 0;
	oValue = 0.;
	slope = 0.;
}

AnalysisLine::AnalysisLine(long long _oTime, double _oValue, double _slope)
{
	if (setLine(_oTime, _oValue, _slope) != 0)
	{
		oTime = 0;
		oValue = 0.;
		slope = 0.;
	}
}

AnalysisLine::~AnalysisLine()
{

}

int AnalysisLine::setLine(long long _oTime, double _oValue, double _slope)
{
	oTime  = _oTime;
	oValue = _oValue;
	slope  = _slope;

	return 0;
}
