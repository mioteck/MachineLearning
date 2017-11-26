#pragma once

#include <iostream>
#include <array>
#include <Dense>
#include <QR>

template<typename T>
Eigen::MatrixXd CreateMatrixEntries(T*, int, int);
template<typename T>
Eigen::MatrixXd CreateMatrix(T*, int, int);

float* InitWeight(int size);
float* ResolveRosenblatt(float*, int, int, int*, float);
void RuleRosenblatt(Eigen::VectorXd, float*, int, int, float);
float* ResolvePLA(float*, int, int, int*, float);
void RulePLA(Eigen::VectorXd row, float* w, int r, float s);
int Perceptron(Eigen::VectorXd, float*);
bool isClassified(int*, int*, int);
float* LinearRegressionResolve(float*, int, int, int*);