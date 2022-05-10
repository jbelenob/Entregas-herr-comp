#include <iostream>
#include <cstdlib>
#include <vector>
#include <numeric>
#include <chrono>
#include <cmath>

//OJO: Cambiar este include por la ruta adecuada según sea necesario.
#include <eigen3/Eigen/Dense>

double multiply(int size, int seed);
double compute_mean(const std::vector <double> &data);
double standard_deviation(const std::vector <double> &data, double mean);

int main(int argc, char **argv)
{
  std::cout.precision(16); std::cout.setf(std::ios::scientific);
  
  const int SIZE = std::atoi(argv[1]);
  const int REPS = std::atoi(argv[2]);
  int seed = std::atoi(argv[3]);

  //Aquí se guardarán los tiempos.
  std::vector <double> times(REPS, 0.0);
  
  for(int ii = 0; ii < REPS; ++ii)
    {
      times[ii] = multiply(SIZE,seed);

      //La semilla va incrementando por uno cada repetición.
      ++seed;
    }

  double mean = compute_mean(times);
  double std_dev = standard_deviation(times, mean);
  
  std::cout << SIZE << '\t' << mean << '\t' << std_dev << '\n';
  
  return 0;
}


double multiply(int size, int seed)
{
  //Se añadió esta linea para ir cambiando la semilla por cada repitición.
  srand(seed);
  
  // create matrices
  Eigen::MatrixXd A = Eigen::MatrixXd::Random(size, size);
  Eigen::MatrixXd B = Eigen::MatrixXd::Random(size, size);

  auto start = std::chrono::steady_clock::now();
  auto C{A*B}; // MULTIPLY
  double tmp = C(0, 0); // use the matrix to make eigen compute it
  auto end = std::chrono::steady_clock::now();

  //std::clog << tmp << std::endl; // use the matrix to make eigen compute it

  std::chrono::duration<double> elapsed_seconds = end-start;

  return elapsed_seconds.count();

}

double compute_mean(const std::vector <double> &data)
{
  return std::accumulate(data.begin(), data.end(), 0.0)/data.size();
}

double standard_deviation(const std::vector <double> &data, double mean)
{
  double std_dev = 0.0; 

  for(int kk = 0; kk < data.size(); ++kk)
    {
      std_dev += (data[kk] - mean)*(data[kk] - mean);
    }

  std_dev = std::sqrt(std_dev/data.size());

  return std_dev;
}
