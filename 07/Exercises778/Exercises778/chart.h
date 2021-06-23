#pragma once

static void writeTopBoilerPlateOfLineChart(std::ostream& out);

static void writeBottomBoilerPlateOfLineChart(std::ostream& out);

static void writeDataOfLineChart(std::ostream& out, std::vector<double>& labels, std::vector<double>& values);

void lineChart(const std::string& file, std::vector<double>& labels, std::vector<double>& values);