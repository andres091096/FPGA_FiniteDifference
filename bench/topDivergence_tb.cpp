////////////////////////////////////////////////////////////////////////////////
// Company: Instituto Nacional de Astrofísica, Óptica y Electrónica
// Engineer: Andrés M. Manjarrés G.
//
// Create Date: 23.04.2021
// File Name: topDivergence_tb.cpp
// Project Name:
// Description:
//
// Dependencies: topDivergence.v
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
//
////////////////////////////////////////////////////////////////////////////////
// MIT License
//
// Copyright (c) 2021 Andrés Manjarrés
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>     /* calloc, exit, free */
#include <iostream>
#include <fstream>
#include "VtopDivergence.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
using namespace std;

// Fixed-point format: 1.15 (16-bit)
//typedef uint16_t fixed_point_t;
typedef unsigned int fixed_point_t;
#define FIXED_POINT_FRACTIONAL_BITS 14
#define FIXED_POINT_BITS 32
#define INPUT_SIZE 4096
#define I(ix,iy) (ix)+px*(iy)

// Converts float to 11.5 format
inline fixed_point_t float_to_fixed(float input)
{
    return (fixed_point_t)(round(input * (1 << FIXED_POINT_FRACTIONAL_BITS)));
}

inline float fixed_to_float(fixed_point_t input)
{
    int sign = input >> (FIXED_POINT_BITS - 1);
    if (sign == 1){
      input = input - 1;
      input = ~input;
      return -1*((float)input / (float)(1 << FIXED_POINT_FRACTIONAL_BITS));
    }
    else{
        return ((float)input / (float)(1 << FIXED_POINT_FRACTIONAL_BITS));
    }

}


float * Ux(float U[], int px, int py)
{
  static float  Ux_vec[INPUT_SIZE];  //n=4096 because the use of static I must put a constant size
  for (int iy = 0; iy < py; iy++) {
    for (int ix = 0; ix < px; ix++) {
        if (iy == py-1){
          Ux_vec[I(ix,iy)] = (U[I(ix,0)] - U[I(ix,iy)]);
        }else{
          Ux_vec[I(ix,iy)] = (U[I(ix,iy+1)] - U[I(ix,iy)]);
        }
    }
  }

  return Ux_vec;
}

float * Uy(float U[], int px, int py)
{
  static float  Uy_vec[INPUT_SIZE];  //n=4096 because the use of static I must put a constant size
  for (int iy = 0; iy < py; iy++) {
    for (int ix = 0; ix < px; ix++) {
      if (ix == px-1){ //Limite
        Uy_vec[I(ix,iy)] = (U[I(0,iy)] - U[I(ix,iy)]);
      }else{
        Uy_vec[I(ix,iy)] = (U[I(ix+1,iy)] - U[I(ix,iy)]);
      }
    }
  }
  return Uy_vec;
}

float * Div(float Ux[], float Uy[], int px, int py) {
  static float  div [INPUT_SIZE];  //n=4096 because the use of static I must put a constant size
  for (int i = 0; i < px*py; i++) {
    div[i] = 0;
  }

  for (int iy = 0; iy < py; iy++) {
    for (int ix = 0; ix < px; ix++) {
        if (iy == 0){ //Limite
          div[I(ix,iy)] += (Ux[I(ix,px-1)] - Ux[I(ix,iy)]); //DxUx;
          //printf("r_datax[%i] = %f = %f - %f\n", I(ix,iy), (Ux[I(ix,px-1)] - Ux[I(ix,iy)]), Ux[I(ix,iy-1)], Ux[I(ix,iy)]  );
        }else{
          div[I(ix,iy)] += (Ux[I(ix,iy-1)] - Ux[I(ix,iy)]); //DxUx;
          //printf("r_datax[%i] = %f = %f - %f\n", I(ix,iy), (Ux[I(ix,iy-1)] - Ux[I(ix,iy)]), Ux[I(ix,iy-1)], Ux[I(ix,iy)]  );
        }
        if (ix == 0){ //Limite
          div[I(ix,iy)] += (Uy[I(px-1,iy)] - Uy[I(ix,iy)]); //DyUy;
          //printf("r_datay[%i] = %f = %f - %f\n", I(ix,iy), (Uy[I(px-1,iy)] - Uy[I(ix,iy)]), Uy[I(px-1,iy)], Uy[I(ix,iy)]  );
        }else{
          div[I(ix,iy)] += (Uy[I(ix-1,iy)] - Uy[I(ix,iy)]); //DyUy;
          //printf("r_datay[%i] = %f = %f - %f\n", I(ix,iy), (Uy[I(ix-1,iy)] - Uy[I(ix,iy)]), Uy[I(ix-1,iy)], Uy[I(ix,iy)]  );
        }
        //printf("div[%i] = %f , %f, %f\n", I(ix,iy), div[I(ix,iy)], Ux[I(ix,iy)], Uy[I(ix,iy)]  );
    }
  }
  return div;
}

void tick(int tickcount, VtopDivergence *tb, VerilatedVcdC* tfp) {

	tb->eval();
	if(tfp)
				tfp->dump(tickcount * 10-2);
	tb->i_clk=1;
	tb->eval();
	if(tfp)
				tfp->dump(tickcount * 10);
	tb->i_clk=0;
	tb->eval();

	if(tfp){
				tfp->dump(tickcount * 10+5);
				tfp->flush();
			}
}
int main(int argc, char const *argv[]) {
  int check_status = 0;
	Verilated::commandArgs(argc, argv);
	VtopDivergence *tb = new VtopDivergence; // Instantiate our design

  //Generate a trace
	Verilated::traceEverOn(true);
	VerilatedVcdC* tfp = new VerilatedVcdC;
	tb->trace(tfp,99);
	tfp->open("topDivergence_trace.vcd");
  unsigned tickcount=0;

	tick(++tickcount,tb,tfp);
	tb->i_reset = 1;
  tb->i_start = 0;
	tick(++tickcount,tb,tfp);
	tb->i_reset = 0;
	tick(++tickcount,tb,tfp);


  uint8_t         f;
  fixed_point_t f_hardware;
  float         U_in[INPUT_SIZE];

  int i = 0;
  std::ifstream fin("data/U.bin", std::ios::binary);
  while (fin.read(reinterpret_cast<char*>(&f), sizeof(uint8_t))){
    U_in[i]  = f;
    i=i+1;
  }
  fin.close();

  float *Uy_out;
  float *Ux_out;
  Uy_out = Uy(U_in, 64, 64);
  Ux_out = Ux(U_in, 64, 64);
  float Ux_in[INPUT_SIZE];
  float Uy_in[INPUT_SIZE];
  ofstream myFile;
  myFile.open("Ux_fixed_point.mem", ios::out );
  ofstream myFile2;
  myFile2.open("Uy_fixed_point.mem", ios::out );
  float r1, r2;
  for (int i = 0; i < INPUT_SIZE; i++) {
    /*
    r1 = -50.5 + static_cast <float> (rand()) / ( static_cast <float> (RAND_MAX/(255.0+50.5)));
    r2 = 80.5 + static_cast <float> (rand()) / ( static_cast <float> (RAND_MAX/(255.0-80.5)));
    Ux_in[i] = r1;
    Uy_in[i] = r2;
    myFile << hex << float_to_fixed(r1) << "\n";
    myFile2 << hex << float_to_fixed(r2) << "\n";
    */

    Ux_in[i] = *(Ux_out+i);
    Uy_in[i] = *(Uy_out+i);
    myFile << hex << float_to_fixed(*(Ux_out+i)) << "\n";
    myFile2 << hex << float_to_fixed(*(Uy_out+i)) << "\n";
  }
  myFile << dec;
  myFile.close();
  myFile2 << dec;
  myFile2.close();

  float *div_out;
  div_out = Div(Ux_in, Uy_in, 64, 64);


  tick(++tickcount,tb,tfp);
  tb->i_start = 1;
  tick(++tickcount,tb,tfp);
  tb->i_start = 0;


  float tol_err = 1e-2;
  float diff;
  float cpu_version[INPUT_SIZE];
  float rtl_version[INPUT_SIZE];
  int j = 0;
  int err_count = 0;
  for (int i = 0; i < 20000; i++) {
    tick(++tickcount,tb,tfp);
    if (tb->o_valid){

      cpu_version[j] = *(div_out+j);
      rtl_version[j] = fixed_to_float((fixed_point_t)tb->o_data);
      diff =  rtl_version[j] - cpu_version[j];
      if (abs(diff) > tol_err ){
        check_status = 1;
        err_count += 1;
        printf("Data Mismatch: data : %i : Expected %f -> Got %f \n", j, cpu_version[j] , rtl_version[j]);
      }
      j = j+1;
    }

  }

  if (j!=INPUT_SIZE){
    check_status = 1;
    printf("ERROR: data amount: Expected %i-> Got %i \n", INPUT_SIZE, j);
  }


  if (check_status) {
      printf("INFO: Test failed because %i errors\n", err_count);
      return EXIT_FAILURE;
  } else {
      printf("INFO: Test completed successfully.\n");
      ofstream WriteFile ("data/divU.bin", ios::out | ios::binary);
      WriteFile.write ((char*)&rtl_version, INPUT_SIZE*sizeof(float));
      WriteFile.close();
      return EXIT_SUCCESS;
  }

}
