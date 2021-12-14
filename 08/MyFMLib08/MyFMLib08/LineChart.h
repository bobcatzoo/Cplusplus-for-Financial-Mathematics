#pragma once

#include "stdafx.h"

class LineChart
{
public:
	void setTitle(const std::string& title);
	void addEntry(double xvalue, double yvalue);
	void writeAsHTML(std::ostream& out) const;
	void writeAsHTML(std::string& file) const;

private:
	std::string title;
	std::vector<double> xvalues;
	std::vector<double> yvalues;
};

static void writeTopBoilerPlateOfPieChart(std::ostream& out, const std::string& title);
static void writeDataOfPieChart(std::ostream& out, const std::vector<double>& xvalues, const std::vector<double>& yvalues);
static void writeBottomBoilerPlateOfPieChart(std::ostream& out, std::string title);