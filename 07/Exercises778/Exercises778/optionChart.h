#pragma once

static void optionWriteTopBoilerPlateOfLineChart(std::ostream& out);

static void optionWriteBottomBoilerPlateOfLineChart(std::ostream& out);

static void optionWriteDataOfLineChart(std::ostream& out, std::vector<double>& spotPrices, std::vector<double>& callValues);

void optionChart(const std::string& file, std::vector<double>& spotPrices, std::vector<double>& callValues);