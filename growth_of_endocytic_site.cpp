//  file: growth_of_endocytic_site.cpp:  
//
//  Test program for the calculation of the growth profile of actin over
//  time.                                                                  
//
//  Programmer:  Cristopher Thompson  thompson.3962@osu.edu
//
//  Revision history:
//      04/05/2024 -- Struggling to put equations and values in a linear code-like order
//      04/10/2024 -- Trying to add more variables in the code to make it more robust.
//      04/13/2024 -- The .dat file spacing between variables needs to be better organized. 
//      04/16/2024 -- This code cannot pick and chose the correct line to read from.
//      04/19/2024 -- This code runs fine now and produces the correct data. 
//
//*******************************************************************
// include files
#include <iostream>		// cout and cin
#include <iomanip>		// manipulators like setprecision
#include <fstream>
#include <vector>               // Imports vector that could have been used to store values.
#include <cmath>                // Contains the constant value like pi
using namespace std;		// we need this when .h is omitted
//*********************** main ******************************
int
main (void)
{
  ofstream out_value ("dataset.dat");
  out_value << "t            alpha       beta        gamma       eta         growth" << endl;
  ifstream fileRA("RadiusandAlpha.dat");
  //The code below picks out the fourth value in the second column
  std::string line;
  for (int i = 0; i <4; ++i)
    { 
      std::getline(fileRA, line); // reading a row and stores in a variable called "line"
    }
  std::istringstream ss(line);
  double col2; // Assuming the second column contains double values
  for (int i = 0; i < 2; ++i) 
    {
      ss >> col2; // Extract the next value from the second column
    }
      
  // Now you have the fourth value from the second column
  double alpha = col2;
  std::cout << "Fourth value in the second column: " << alpha << std::endl;
  ifstream fileB("Beta.dat");
  //The code below picks out the fourth value in the third column
  for (int i = 0; i <4; ++i)
    { 
      std::getline(fileB, line); // reading a row and stores in a variable called "line"
    }
  //std::istringstream ss2(line); // treat ss2 simliar as you would for reading in a file.
  ss.seekg(0);
  ss.str(line); // adds a new line
  double col3; // Assuming the third column contains double values
  cout << ss.str() << endl; 
  for (int i = 0; i < 3; ++i) 
    {
      ss >> col3; // Extract the next value from the third column
      cout << col3 << endl;
    }
      
  // Now you have the fourth value from the third column
  double beta = col3;
  std::cout << "Fourth value in the third column: " << beta << std::endl;

  for (int q = 1; q <=10; q += 1)
    { 
      double t = q; //time variable
      //
 
      // where
      double sigma_0 = std::pow(10, 4); // stall stress
      double sigma_zz = sigma_0 * 0.5; // Max growth rate as a component of Cauchy Stress
      double eta = 1 + (0.5 * log(0.05) - 1) * ((2 * sigma_zz) - (sigma_0)); // Equation that takes into account 
                                                                             //of the limiting negative growth rate
                                                                             // at large opposing forces on the maximum 
                                                                             //growth rate. and the different
                                                                             // components of cauchy stress. 
      double gamma = (1/(1 + exp(-2 * eta))) + ( -0.05/(1 + exp(2 * eta))); // actin polmerization factor on stress.

      //Equation for baseline growth rate given to us by the paper
      double growth = (alpha * beta * gamma) * (t);
      out_value << scientific << setprecision (4)
		<< t << "   " << alpha << "  " 
		<< beta << "  " << gamma << "  "
		<< eta << "  " << growth << endl;
    } 
  out_value.close();

  return (0);
}

