// Confidence intervals  and hypothesis testing
// z-critical and t-critical
#include "basics.h"
#include <string>
#include <vector>
struct Bound
{
	double lower;
	double upper;
};

struct CriticalZ
{
	// TODO: add more options in case users need them
	double z99;
	double z95;
	double z90;
	double z85;
	double z80;
};

struct Chi
{
	double expected;
	double observed;
};

// functionality for confidence intervals
class Cinterval
{
  private:
	const CriticalZ crit = {2.576, 1.960, 1.645, 1.440, 1.282};
	const double getZcritical(std::string percent);
	Bound calculateCI_Z(std::string percent,
	                    double point_estimate,
	                    double sd,
	                    const int sample_size);

	Bound calculateCI_T(double point_estimate, double sd, const int sample_size, double tcrit);
	Bound calculateCI_Proportion(std::string percent, double p_hat, const int sample_size);
	// TODO: two sample proportion
	// TODO: IMPLEMENT THESE:
	Bound calculateCI_2Proportions(std::string percent,
	                               double p_hat,
	                               double p_hat2,
	                               const int sample_size,
	                               const int sample_size2);
	Bound calculateCI_2Z(std::string percent,
	                     double mean1,
	                     double mean2,
	                     double sd1,
	                     double sd2,
	                     const int sample_size,
	                     const int sample_size2);
	Bound calculateCI_2T(std::string percent,
	                     double mean1,
	                     double mean2,
	                     double sd1,
	                     double sd2,
	                     const int sample_size,
	                     const int sample_size2);

  public:
	// display functions
	const void displayCI_Z(std::string percent,
	                       double point_estimate,
	                       double sd,
	                       const int sample_size);
	const void displayCI_T(double point_estimate, double sd, const int sample_size, double tcrit);
	const void displayCI_Proportion(std::string percent, double p_hat, const int sample_size);
	// calculation functions
	double calculateSamplingDistributionSd(double sd, const int sample_size);
	const void displayCI_2Proportions(std::string percent,
	                                  double p_hat,
	                                  double p_hat2,
	                                  const int sample_size,
	                                  const int sample_size2);
};

// functionality for hypothesis testing

class HypTest
{
  private:
	double z_score;
	double z_stat;
	double t_score;
	std::vector<Chi> chi_values;
	double calculate2sampleZstat();
	double calculate2sampleTscore();
	double calculate2PairedsampleTscore();
	double calculate2zproportion();
	double calculatePhatC(double p_hat,
	                      double p_hat2,
	                      const int sample_size,
	                      const int sample_size2);
	double performChiSquare();

  public:
	// TODO: TWO sample, chi square , degrees of freedom, function to print a hypothesis tesing
	// report
	// print hypothesis test report
	// TODO:HAVE THE REPORT SHOW WHAT FORMULAS WERE USED AND HAVE THEM TAKE INPUT
	void printHypothesisReport_Z();
	void printHypothesisReport_T();
	void printHypothesisReport_P();
	void printHypothesisReport_2Z();
	void printHypothesisReport_2T();
	void printHypothesisReport_2P();
	void printChiTest();
	// calculations
	double calculateZscore(double point_estimate, double mean, double sd);
	double calculateZstat(double point_estimate, double mean, double sd, const int sample_size);
	double calculateTscore(double sampleMean, double popMean, double sd, const int sample_size);
};
