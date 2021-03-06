#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
	VectorXd rmse;

	if (estimations.size() == 0 || (estimations.size() != ground_truth.size()))
	{
		std::cout << "CalculateRMSE() - Error: Vector sizes are not equal and greater than zero.";
		return rmse;
	}
	int length = estimations.size();
	int size = estimations[0].size();
	rmse = VectorXd::Zero(size);

	for (unsigned int i = 0; i < estimations.size(); i++) 
	{
		VectorXd resids = (estimations[i] - ground_truth[i]);
		resids = (resids.array() * resids.array());
		rmse += resids;
	}

	rmse = rmse / length;
	rmse = rmse.array().sqrt();

	//return the result
	return rmse;
}
