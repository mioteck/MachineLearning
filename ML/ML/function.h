#pragma once

#include <iostream>
#include <Dense>
#include <QR>

#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))

Eigen::MatrixXd CreateMatrix(float*, int);
float* InitWeight(int size);
float* ResolveRosenblatt(float*, int, int*, float);
void RuleRosenblatt(Eigen::VectorXd, float*, int, int, float);
float* ResolvePLA(float*, int, int*, float);
void RulePLA(Eigen::VectorXd row, float* w, int r, float s);
int Perceptron(Eigen::VectorXd, float*);
bool isClassified(int*, int*, int);
float* LinearRegressionResolve(float*, int, int, int*);
