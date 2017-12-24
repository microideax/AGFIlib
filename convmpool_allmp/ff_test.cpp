
#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include <malloc.h>
#include "inference_net/config.h"
#include "inference_net/construct_net.h"
#include "inference_net/image_converter.h"
#include "inference_net/weight_bias_one_dim.h"
#include "inference_net/softmax_one_dim.h"
#include "inference_net/predict_one_dim.h"
#include "inference_net/accuracy_one_dim.h"
#include "inference_net/pow_function.h"
#include "inference_net/resize_image.h"

using namespace std;

const unsigned char * loadfile(const std::string &file, int &size) {
   std::ifstream fs(file.c_str(), std::ios::binary);
   fs.seekg(0, std::ios::end);
   size = fs.tellg();
   char * data = new char[size];
   fs.seekg(0);
   fs.read(data, sizeof(char) * size);
   fs.close();
   return (unsigned char *)data;
}

void print_array(int N, float *array_name){
    for(int i=0; i< N; i++){
        for(int j=0; j< N; j++){
            cout << array_name[i*N + j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {

   cout<< "Calculating memory space ... ... ... ..." << endl;

   // data size calculation
   unsigned int conv_weight_size = (32*8*16*16) * sizeof(data_type_w);
   unsigned int conv_bias_size = (256) * sizeof(data_type_w);
   unsigned int fc_weight_size = (4000) * sizeof(data_type_w);
   unsigned int fc_bias_size = (10) * sizeof(data_type_w);
   unsigned int fc_3_out_size = (10) * sizeof(data_type_o);
   unsigned int out_size_0_1 = (8192) * sizeof(data_type_o);
   unsigned int out_size_0_2 = (8192) * sizeof(data_type_o);
   unsigned int out_size_0_3 = (8192) * sizeof(data_type_o);
   unsigned int out_size_0_4 = (8192) * sizeof(data_type_o);
   unsigned int out_size_0_5 = (8192) * sizeof(data_type_o);
   unsigned int out_size_0_6 = (8192) * sizeof(data_type_o);
   unsigned int out_size_0_7 = (8192) * sizeof(data_type_o);
   unsigned int out_size_0_8 = (8192) * sizeof(data_type_o);
   unsigned int out_size_1_1 = (1024) * sizeof(data_type_o);
   unsigned int out_size_1_2 = (1024) * sizeof(data_type_o);
   unsigned int out_size_1_3 = (1024) * sizeof(data_type_o);
   unsigned int out_size_1_4 = (1024) * sizeof(data_type_o);
   unsigned int out_size_1_5 = (1024) * sizeof(data_type_o);
   unsigned int out_size_1_6 = (1024) * sizeof(data_type_o);
   unsigned int out_size_1_7 = (1024) * sizeof(data_type_o);
   unsigned int out_size_1_8 = (1024) * sizeof(data_type_o);

   // assign memory space to different ports
    data_type_w *conv_weight_mem_port = (data_type_w*)malloc(conv_weight_size);
    if (conv_weight_mem_port == NULL) {
        printf("False memory allocation of conv_weight_mem_port\n");
    }
    else {
        printf("conv weight memory location= 0x%x \n", conv_weight_mem_port);
    }
    data_type_w *conv_weight_mem_port_1 = (data_type_w*)malloc(conv_weight_size/8);
   if (conv_weight_mem_port_1 == NULL) {
      printf("False memory allocation of conv_weight_mem_port_1\n");
   }
   else {
      printf("conv weight memory location= 0x%x \n", conv_weight_mem_port_1);
   }
    data_type_w *conv_weight_mem_port_2 = (data_type_w*)malloc(conv_weight_size/8);
    if (conv_weight_mem_port_2 == NULL) {
        printf("False memory allocation of conv_weight_mem_port_2\n");
    }
    else {
        printf("conv weight memory location= 0x%x \n", conv_weight_mem_port_2);
    }
    data_type_w *conv_weight_mem_port_3 = (data_type_w*)malloc(conv_weight_size/8);
    if (conv_weight_mem_port_3 == NULL) {
        printf("False memory allocation of conv_weight_mem_port_3\n");
    }
    else {
        printf("conv weight memory location= 0x%x \n", conv_weight_mem_port_3);
    }
    data_type_w *conv_weight_mem_port_4 = (data_type_w*)malloc(conv_weight_size/8);
    if (conv_weight_mem_port_4 == NULL) {
        printf("False memory allocation of conv_weight_mem_port_4\n");
    }
    else {
        printf("conv weight memory location= 0x%x \n", conv_weight_mem_port_4);
    }
    data_type_w *conv_weight_mem_port_5 = (data_type_w*)malloc(conv_weight_size/8);
    if (conv_weight_mem_port_5 == NULL) {
        printf("False memory allocation of conv_weight_mem_port_5\n");
    }
    else {
        printf("conv weight memory location= 0x%x \n", conv_weight_mem_port_5);
    }
    data_type_w *conv_weight_mem_port_6 = (data_type_w*)malloc(conv_weight_size/8);
    if (conv_weight_mem_port_6 == NULL) {
        printf("False memory allocation of conv_weight_mem_port_6\n");
    }
    else {
        printf("conv weight memory location= 0x%x \n", conv_weight_mem_port_6);
    }
    data_type_w *conv_weight_mem_port_7 = (data_type_w*)malloc(conv_weight_size/8);
    if (conv_weight_mem_port_7 == NULL) {
        printf("False memory allocation of conv_weight_mem_port_7\n");
    }
    else {
        printf("conv weight memory location= 0x%x \n", conv_weight_mem_port_7);
    }
    data_type_w *conv_weight_mem_port_8 = (data_type_w*)malloc(conv_weight_size/8);
    if (conv_weight_mem_port_8 == NULL) {
        printf("False memory allocation of conv_weight_mem_port_8\n");
    }
    else {
        printf("conv weight memory location= 0x%x \n", conv_weight_mem_port_8);
    }
   data_type_w *conv_bias_mem_port = (data_type_w*)malloc(conv_bias_size);
   if (conv_bias_mem_port == NULL) {
      printf("False memory allocation of conv_bias_mem_port\n");
   }
   else {
      printf("conv bias memory location= 0x%x \n", conv_bias_mem_port);
   }
   data_type_w *fc_weight_mem_port = (data_type_w*)malloc(fc_weight_size);
   if (fc_weight_mem_port == NULL) {
      printf("False memory allocation of fc_weight_mem_port\n");
   }
   else {
      printf("fc_weight_mem_port memory location= 0x%x \n", fc_weight_mem_port);
   }
   data_type_w *fc_bias_mem_port = (data_type_w*)malloc(fc_bias_size);
   if (fc_bias_mem_port == NULL) {
      printf("False memory allocation of fc_bias_mem_port\n");
   }
   else {
      printf("fc_bias_mem_port memory location= 0x%x \n", fc_bias_mem_port);
   }
   data_type_o *fc_3_out_mem_int = (data_type_o*)malloc(fc_3_out_size);
   if (fc_3_out_mem_int == NULL) {
      printf("False memory allocation of fc_out_mem_int\n");
   }
   else {
      printf("fc_out_mem_int memory location= 0x%x \n", fc_3_out_mem_int);
   }
   data_type_o *temp_out_0_1 = (data_type_o *)malloc(out_size_0_1);
   if (temp_out_0_1 == NULL) {
      printf("False memory allocation of temp_out_0_1\n");
   }
   else {
      printf("temp_out_0_1 memory location= 0x%x \n", temp_out_0_1);
   }
   data_type_o *temp_out_0_2 = (data_type_o *)malloc(out_size_0_2);
   if (temp_out_0_2 == NULL) {
      printf("False memory allocation of temp_out_0_2\n");
   }
   else {
      printf("temp_out_0_2 memory location= 0x%x \n", temp_out_0_2);
   }
   data_type_o *temp_out_0_3 = (data_type_o *)malloc(out_size_0_3);
   if (temp_out_0_3 == NULL) {
      printf("False memory allocation of temp_out_0_3\n");
   }
   else {
      printf("temp_out_0_3 memory location= 0x%x \n", temp_out_0_3);
   }
   data_type_o *temp_out_0_4 = (data_type_o *)malloc(out_size_0_4);
   if (temp_out_0_4 == NULL) {
      printf("False memory allocation of temp_out_0_4\n");
   }
   else {
      printf("temp_out_0_4 memory location= 0x%x \n", temp_out_0_4);
   }
   data_type_o *temp_out_0_5 = (data_type_o *)malloc(out_size_0_5);
   if (temp_out_0_5 == NULL) {
      printf("False memory allocation of temp_out_0_5\n");
   }
   else {
      printf("temp_out_0_5 memory location= 0x%x \n", temp_out_0_5);
   }
   data_type_o *temp_out_0_6 = (data_type_o *)malloc(out_size_0_6);
   if (temp_out_0_6 == NULL) {
      printf("False memory allocation of temp_out_0_6\n");
   }
   else {
      printf("temp_out_0_6 memory location= 0x%x \n", temp_out_0_6);
   }
   data_type_o *temp_out_0_7 = (data_type_o *)malloc(out_size_0_7);
   if (temp_out_0_7 == NULL) {
      printf("False memory allocation of temp_out_0_7\n");
   }
   else {
      printf("temp_out_0_7 memory location= 0x%x \n", temp_out_0_7);
   }
   data_type_o *temp_out_0_8 = (data_type_o *)malloc(out_size_0_8);
   if (temp_out_0_8 == NULL) {
      printf("False memory allocation of temp_out_0_8\n");
   }
   else {
      printf("temp_out_0_8 memory location= 0x%x \n", temp_out_0_8);
   }
   data_type_o *temp_out_1_1 = (data_type_o *)malloc(out_size_1_1);
   if (temp_out_1_1 == NULL) {
      printf("False memory allocation of temp_out_1_1\n");
   }
   else {
      printf("temp_out_1_1 memory location= 0x%x \n", temp_out_1_1);
   }
   data_type_o *temp_out_1_2 = (data_type_o *)malloc(out_size_1_2);
   if (temp_out_1_2 == NULL) {
      printf("False memory allocation of temp_out_1_2\n");
   }
   else {
      printf("temp_out_1_2 memory location= 0x%x \n", temp_out_1_2);
   }
   data_type_o *temp_out_1_3 = (data_type_o *)malloc(out_size_1_3);
   if (temp_out_1_3 == NULL) {
      printf("False memory allocation of temp_out_1_3\n");
   }
   else {
      printf("temp_out_1_3 memory location= 0x%x \n", temp_out_1_3);
   }
   data_type_o *temp_out_1_4 = (data_type_o *)malloc(out_size_1_4);
   if (temp_out_1_4 == NULL) {
      printf("False memory allocation of temp_out_1_4\n");
   }
   else {
      printf("temp_out_1_4 memory location= 0x%x \n", temp_out_1_4);
   }
   data_type_o *temp_out_1_5 = (data_type_o *)malloc(out_size_1_5);
   if (temp_out_1_5 == NULL) {
      printf("False memory allocation of temp_out_1_5\n");
   }
   else {
      printf("temp_out_1_5 memory location= 0x%x \n", temp_out_1_5);
   }
   data_type_o *temp_out_1_6 = (data_type_o *)malloc(out_size_1_6);
   if (temp_out_1_6 == NULL) {
      printf("False memory allocation of temp_out_1_6\n");
   }
   else {
      printf("temp_out_1_6 memory location= 0x%x \n", temp_out_1_6);
   }
   data_type_o *temp_out_1_7 = (data_type_o *)malloc(out_size_1_7);
   if (temp_out_1_7 == NULL) {
      printf("False memory allocation of temp_out_1_7\n");
   }
   else {
      printf("temp_out_1_7 memory location= 0x%x \n", temp_out_1_7);
   }
   data_type_o *temp_out_1_8 = (data_type_o *)malloc(out_size_1_8);
   if (temp_out_1_8 == NULL) {
      printf("False memory allocation of temp_out_1_8\n");
   }
   else {
      printf("temp_out_1_8 memory location= 0x%x \n", temp_out_1_8);
   }
#if _KERNEL_DEBUG_
   cout << "FC mem init\n";
   memset(fc_3_out_mem_int, 0, fc_3_out_size);
   memset(temp_out_0_1, 0, out_size_0_1);
   memset(temp_out_0_2, 0, out_size_0_2);
   memset(temp_out_0_3, 0, out_size_0_3);
   memset(temp_out_0_4, 0, out_size_0_4);
   memset(temp_out_0_5, 0, out_size_0_5);
   memset(temp_out_0_6, 0, out_size_0_6);
   memset(temp_out_0_7, 0, out_size_0_7);
   memset(temp_out_0_8, 0, out_size_0_8);
   memset(temp_out_1_1, 0, out_size_1_1);
   memset(temp_out_1_2, 0, out_size_1_2);
   memset(temp_out_1_3, 0, out_size_1_3);
   memset(temp_out_1_4, 0, out_size_1_4);
   memset(temp_out_1_5, 0, out_size_1_5);
   memset(temp_out_1_6, 0, out_size_1_6);
   memset(temp_out_1_7, 0, out_size_1_7);
   memset(temp_out_1_8, 0, out_size_1_8);
#endif

   //net weight src *****************************
#if _HLS_MODE_
   const char* weight_src = "net_weights.txt";
#else
   const char* weight_src = "net_inputs/net_weights.txt";
#endif
#if _KERNEL_DEBUG_
#if _HLS_MODE_
   string image_dir = "3.bmp";
#else
   string image_dir = "./net_inputs/test_imgs/3.bmp";
#endif
   int w;
   int h;
   int channels;
   int size;
   const unsigned char * data = loadfile(image_dir, size);
   const unsigned char * image_orig = stbi_load_from_memory(data, size, &w, &h, &channels, 1);
   int in_data_size=0;
   ofstream indata;
   indata.open("in_data.txt");
   for (int i = 0; i < 1; i++) {
      for (int j = 0; j < 28; j++) {
         for (int k = 0; k < 28; k++) {
            indata << image_orig[i *28*28 + 28*j + k] << " ";
         }

         indata << endl;
      }

      indata << endl;
   }
   indata.close();

   cout << "Writing data to input data memory space ... ... ..." << endl;
   for (int i = 0; i < 1; i++) {
      for (int j = 0; j < 28; j++) {
         for (int k = 0; k < 28; k++) {
            temp_out_0_1[in_data_size] = (data_type)image_orig[i*28*28 + 28*j + k];
            in_data_size++;
         }

      }

   }
   cout << "Finished writing data to input data memory space ... ..." << endl;
#endif
   char tan_h = 't';
   char relu = 'r';
   char none = 'i';
   int in_number_conv = 0;
   int in_number_fc = 0;
   int in_number_pooling = 0;

   // Prepare weights and bias for conv layer 1
   float *conv_1_weight2D = (float*)malloc(150 * sizeof(float));
   memset(conv_1_weight2D, 0, 150 * sizeof(float));
   load_weight_conv(
weight_src, 
conv_1_weight2D,
 weight_bias_record,
 nn_channel_size_conv, 
 nn_in_number_conv,
 nn_out_number_conv,
 in_number_conv);
   int conv_weight_num=0;
   cout << "Loading conv weight 1 to memory space, starting at: " <<conv_weight_num << '\n';
   for (int i = 0; i < 150; i++) {
      conv_weight_mem_port_1[conv_weight_num] = (data_type_w)conv_1_weight2D[i];
      conv_weight_num++;
   }
   free(conv_1_weight2D);
   float *conv_1_bias2D = (float*)malloc(6 * sizeof(float));
   memset(conv_1_bias2D, 0, 6 * sizeof(float));
   load_bias_conv(
weight_src, 
conv_1_bias2D,
 weight_bias_record,
 nn_channel_size_conv, 
 nn_in_number_conv,
 nn_out_number_conv,
 in_number_conv);
   int conv_bias_num=0;
   cout << "Loading conv bias 1 to memory space, starting at: " <<conv_bias_num << '\n';
   for (int i = 0; i < 6; i++) {
      conv_bias_mem_port[conv_bias_num] = (data_type_w)conv_1_bias2D[i];
      conv_bias_num++;
   }
   free(conv_1_bias2D);
   in_number_conv++;

   // Prepare weights and bias for conv layer 2
   float *conv_2_weight2D = (float*)malloc(2400 * sizeof(float));
   memset(conv_2_weight2D, 0, 2400 * sizeof(float));
   load_weight_conv(
weight_src, 
conv_2_weight2D,
 weight_bias_record,
 nn_channel_size_conv, 
 nn_in_number_conv,
 nn_out_number_conv,
 in_number_conv);
   cout << "Loading conv weight 2 to memory space, starting at: " <<conv_weight_num << '\n';
   for (int i = 0; i < 2400; i++) {
      conv_weight_mem_port[conv_weight_num] = (data_type_w)conv_2_weight2D[i];
      conv_weight_num++;
   }
   free(conv_2_weight2D);
   float *conv_2_bias2D = (float*)malloc(16 * sizeof(float));
   memset(conv_2_bias2D, 0, 16 * sizeof(float));
   load_bias_conv(
weight_src, 
conv_2_bias2D,
 weight_bias_record,
 nn_channel_size_conv, 
 nn_in_number_conv,
 nn_out_number_conv,
 in_number_conv);
   cout << "Loading conv bias 2 to memory space, starting at: " <<conv_bias_num << '\n';
   for (int i = 0; i < 16; i++) {
      conv_bias_mem_port[conv_bias_num] = (data_type_w)conv_2_bias2D[i];
      conv_bias_num++;
   }
   free(conv_2_bias2D);
   in_number_conv++;

   cout<<"Finished loading conv weight into memory! Total: " <<conv_weight_num  << "... ... ..."<<endl;
   cout<<"Finished loading conv bias into memory! Total: " <<conv_bias_num  << "... ... ..."<<endl;

   // Prepare weights and bias for fc layer 1
   float *fc_1_weight2D = (float*)malloc(4000 * sizeof(float));
   memset(fc_1_weight2D, 0, 4000 * sizeof(float));
   load_weight_fc(
weight_src, 
fc_1_weight2D,
 weight_bias_record,
 nn_channel_size_fc, 
 nn_in_number_fc,
 nn_out_number_fc,
 in_number_fc);
   int fc_weight_num=0;
   cout << "Loading fc weight 1 to memory space, starting at: " <<fc_weight_num << '\n';
   for (int i = 0; i < 4000; i++) {
      fc_weight_mem_port[fc_weight_num] = (data_type_w)fc_1_weight2D[i];
      fc_weight_num++;
   }
   free(fc_1_weight2D);
   float *fc_1_bias2D = (float*)malloc(10 * sizeof(float));
   memset(fc_1_bias2D, 0, 10 * sizeof(float));
   load_bias_fc(
weight_src, 
fc_1_bias2D,
 weight_bias_record,
 nn_channel_size_fc, 
 nn_in_number_fc,
 nn_out_number_fc,
 in_number_fc);
   int fc_bias_num=0;
   cout << "Loading fc bias 1 to memory space, starting at: " <<fc_bias_num << '\n';
   for (int i = 0; i < 10; i++) {
      fc_bias_mem_port[fc_bias_num] = (data_type_w)fc_1_bias2D[i];
      fc_bias_num++;
   }
   free(fc_1_bias2D);
   in_number_fc++;

   cout<<"Finished loading fc weight into memory! Total: " <<fc_weight_num  << "... ... ..."<<endl;
   cout<<"Finished loading fc bias into memory! Total: " <<fc_bias_num  << "... ... ..."<<endl;

#if _KERNEL_DEBUG_
   float fc_3_out[10] = { 0 };
   clock_t start, finish, inf_start, inf_finish;
   double totaltime, inf_time;
   start = clock();
#endif

    int dir_control_1[4] = {1, 1, 0, 1};
    int dir_control_2[4] = {1, 1, 0, 1};
    int dir_control_3[4] = {1, 0, 0, 0};

    int conv_param_1[16] = {1, 5, 6,  28, 28, 28, 28, 1, 2, 1, 0,  0, 0, 0, 1, 1};
    int pool_param_1[16] = {28, 28, 6,  2, 14, 14, 2,  0, 1, 0, 0,  0, 0, 0, 0, 0};
    int conv_param_2[16] = {6,  5, 16, 14, 14, 10, 10, 1, 0, 1, 0,  6, 0, 0, 1, 1};
    int pool_param_2[16] = {10, 10, 16, 2, 5,  5,  2,  0, 1, 0, 0,  0, 0, 0, 0, 0};
    int conv_param_3[16] = {16, 5, 10, 5,  5,  1,  1,  5, 0, 1, 0,  0, 0, 0, 1, 1};

inference_net( dir_control_1, conv_param_1, pool_param_1,
               conv_weight_mem_port_1, conv_weight_mem_port_2, conv_weight_mem_port_3, conv_weight_mem_port_4,
               conv_weight_mem_port_5, conv_weight_mem_port_6, conv_weight_mem_port_7, conv_weight_mem_port_8,
               conv_bias_mem_port,
            temp_out_0_1, temp_out_0_2, temp_out_0_3, temp_out_0_4, temp_out_0_5, temp_out_0_6, temp_out_0_7, temp_out_0_8,
            temp_out_1_1, temp_out_1_2, temp_out_1_3, temp_out_1_4, temp_out_1_5, temp_out_1_6, temp_out_1_7, temp_out_1_8);

    data_type_w  weight_temp[6][16][5][5];
    for (int i = 0; i < 6; i++) {
        for(int j = 0; j < 16; j++){
            for(int k1 = 0; k1 < 5; k1++){
                for(int k2 = 0; k2 < 5; k2++){
                    weight_temp[i][j][k1][k2] = (data_type_w)conv_2_weight2D[i*16*5*5 + j*5*5 + k1*5 + k2];
                }
            }
        }
    }
    for(int j=0; j<16; j++){
        for(int k1=0; k1 <5; k1++){
            for(int k2=0; k2<5; k2++){
                *(conv_weight_mem_port_1 + j*5*5 + k1*5 + k2) = weight_temp[0][j][k1][k2];
                *(conv_weight_mem_port_2 + j*5*5 + k1*5 + k2) = weight_temp[1][j][k1][k2];
                *(conv_weight_mem_port_3 + j*5*5 + k1*5 + k2) = weight_temp[2][j][k1][k2];
                *(conv_weight_mem_port_4 + j*5*5 + k1*5 + k2) = weight_temp[3][j][k1][k2];
                *(conv_weight_mem_port_5 + j*5*5 + k1*5 + k2) = weight_temp[4][j][k1][k2];
                *(conv_weight_mem_port_6 + j*5*5 + k1*5 + k2) = weight_temp[5][j][k1][k2];
            }
        }
    }

inference_net( dir_control_1, conv_param_2, pool_param_2,
               conv_weight_mem_port_1, conv_weight_mem_port_2, conv_weight_mem_port_3, conv_weight_mem_port_4,
               conv_weight_mem_port_5, conv_weight_mem_port_6, conv_weight_mem_port_7, conv_weight_mem_port_8,
               conv_bias_mem_port,
            temp_out_0_1, temp_out_0_2, temp_out_0_3, temp_out_0_4, temp_out_0_5, temp_out_0_6, temp_out_0_7, temp_out_0_8,
            temp_out_1_1, temp_out_1_2, temp_out_1_3, temp_out_1_4, temp_out_1_5, temp_out_1_6, temp_out_1_7, temp_out_1_8);

 /*
inference_net( dir_control_3, conv_param_3, pool_param_1, fc_weight_mem_port, fc_bias_mem_port,
            temp_out_0_1, temp_out_0_2, temp_out_0_3, temp_out_0_4, temp_out_0_5, temp_out_0_6, temp_out_0_7, temp_out_0_8,
            temp_out_1_1, temp_out_1_1, temp_out_1_3, temp_out_1_4, temp_out_1_5, temp_out_1_6, temp_out_1_7, temp_out_1_8);
*/
/*
   //Inference network process
   inference_net(
   //layer weights and bias inputs
   conv_weight_mem_port,
   conv_bias_mem_port,
//   fc_weight_mem_port,
//   fc_bias_mem_port,
#if _KERNEL_DEBUG_
   //output fc data
//   fc_3_out_mem_int,
   temp_out_0_1,
   temp_out_0_2,
   temp_out_0_3,
   temp_out_0_4,
   temp_out_0_5,
   temp_out_0_6,
   temp_out_0_7,
   temp_out_0_8,

   temp_out_1_1,
   temp_out_1_2,
   temp_out_1_3,
   temp_out_1_4,
   temp_out_1_5,
   temp_out_1_6,
   temp_out_1_7,
   temp_out_1_8);
*/
    cout<< "Print temp_out_1_1: " << endl;
    print_array(10, temp_out_1_1);

    cout<< "Print temp_out_1_2: " << endl;
    print_array(10, temp_out_1_2);

    cout<< "Print temp_out_1_3: " << endl;
    print_array(10, temp_out_1_3);

    cout<< "Print temp_out_1_4: " << endl;
    print_array(10, temp_out_1_4);

    cout<< "Print temp_out_1_5: " << endl;
    print_array(10, temp_out_1_5);

    cout<< "Print temp_out_1_6: " << endl;
    print_array(10, temp_out_1_6);

    cout<< "Print temp_out_1_7: " << endl;
    print_array(10, temp_out_1_7);

   finish = clock();
   totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
   cout <<"predicted time is: " << totaltime << " s" << endl;
   for (int i = 0; i < 10/8; i++) {
      fc_3_out[i+0]=(float)(temp_out_1_1[i]);
      fc_3_out[i+1]=(float)(temp_out_1_2[i]);
      fc_3_out[i+2]=(float)(temp_out_1_3[i]);
      fc_3_out[i+3]=(float)(temp_out_1_4[i]);
      fc_3_out[i+4]=(float)(temp_out_1_5[i]);
      fc_3_out[i+5]=(float)(temp_out_1_6[i]);
      fc_3_out[i+6]=(float)(temp_out_1_7[i]);
      fc_3_out[i+7]=(float)(temp_out_1_8[i]);
   }
   for (int i=0; i< 10; i++) {
       cout << temp_out_0_1[i] << "  ";
   }
   cout << endl;
   softmax(fc_3_out, 10);
   predict(fc_3_out, 10);
//#endif

   return 0;

}