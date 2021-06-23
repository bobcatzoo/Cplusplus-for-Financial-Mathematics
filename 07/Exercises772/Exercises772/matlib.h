#pragma once

double mean_(const std::vector<double>& vec);

double standardVariation(const std::vector<double>& vec, std::string option = "sample");

double max_(const std::vector<double>& vec);

double min_(const std::vector<double>& vec);

std::vector<double> randuniform(int n);

std::vector<double> randn(int n);

std::vector<double> BoxMuller(int n);