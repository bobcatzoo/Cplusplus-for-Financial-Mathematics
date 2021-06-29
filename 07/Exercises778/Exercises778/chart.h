#pragma once

static void writeTopBoilerPlateOfLineChart(std::ostream& out);
static void writeBottomBoilerPlateOfLineChart(std::ostream& out);
static void writeDataOfLineChart(std::ostream& out, std::vector<double>& labels, std::vector<double>& values);
void lineChart(const std::string& file, std::vector<double>& labels, std::vector<double>& values);

std::map<double, int> mhist(const std::vector<double>& v, int numberOfBars);
std::vector<int> vhist(const std::vector<double>& v, int numberOfBars);
static void histWriteTopBoilerPlateOfLineChart(std::ostream& out);
static void histWriteBottomBoilerPlateOfLineChart(std::ostream& out);
static void histWriteDataOfLineChart(std::ostream& out, std::vector<double>& values, int numberOfBars);
void histLineChart(const std::string& file, const std::vector<double>& values, int numberOfBars);