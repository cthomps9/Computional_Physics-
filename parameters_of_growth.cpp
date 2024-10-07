//  file: Parameters_of_growth.cpp:  
//
//  Test program for the calculation of the parameters that will go into the final growth equation.   
//                                          
//
//  Programmer:  Cristopher Thompson  thompson.3962@osu.edu
//
//  Revision history:
//      04/10/2024 -- Struggling to understand how to implement the x and y into the code. 
//      04/11/2024 -- Code struggles to use the alpha function and the beta function. 
//      04/17/2024 -- Code runs now well I had to move the alpha and beta functions within the loop.
//
//*******************************************************************
// include files
#include <iostream>		// cout and cin
#include <iomanip>		// manipulators like setprecision
#include <fstream>
#include <cmath>                // Contains the constant value like pi
using namespace std;		// we need this when .h is omitted
//*********************** main ******************************
int
main (void)
{
  ofstream out_value_of_R ("RadiusandAlpha.dat");
  ofstream out_value_of_B ("Beta.dat");
  double pi = M_PI;
  double R0 = 25; // This value was chosen base on the energy value of the simple membrane as define
                  // in the paper "A Novel method for measuring the bending rigidity of model lipids 
                  // membrane by simulating tethers 


  // Dependence of the actin polymerization factor, alpha, on the radial coordinate R.
  //Creating a dataset of Radius values from 1 to 100.
  out_value_of_R << "r" << "    " << "alpha" << endl;
  for (int i = 0; i <=100; i += 1)
    {
      double alpha = ((1/pi)*atan((i - R0)/0.1*R0) + 0.5) * ((1/pi)*atan((i - R0)/0.1*R0) + 0.5);
      out_value_of_R << scientific << setprecision (4) << i << "   " << alpha << endl;
    } 
  out_value_of_R.close();

  // Dependence of the actin polymerizatin factor the change in distance of the pit becoming more 
  // parallel and perpendicular. 
  out_value_of_B << "x" << "                 " << "y" << "                   " << "beta" << endl;
  // Creates an array of numbers from 1 to 100 for the x and y positions
  for (int i = 0; i <=100; i += 1)
    {
      double arr_for_x = i;
      double arr_for_y = i;
      double beta = exp(-(arr_for_y/arr_for_x) * (arr_for_y/arr_for_x));
      out_value_of_B << scientific << setprecision (4) << arr_for_x << "        " << arr_for_y << "         "  << beta << endl;
    } 
  out_value_of_B.close();

  return (0);
}

