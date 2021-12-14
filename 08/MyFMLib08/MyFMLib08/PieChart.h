#pragma once

#include "stdafx.h"

class PieChart
{
public:
	void setTitle(const std::string& title);
	void addEntry(const std::string& label, double value);
	void writeAsHTML(std::ostream& out) const;
	void writeAsHTML(std::string& file) const;

private:
	std::string title;
	std::vector<std::string> labels;
	std::vector<double> values;
};

static void writeTopBoilerPlateOfPieChart(std::ostream& out, const std::string& title);
static void writeDataOfPieChart(std::ostream& out, const std::vector<std::string>& labels, const std::vector<double>& values);
static void writeBottomBoilerPlateOfPieChart(std::ostream& out, std::string title);
