#ifndef _ACC_INSTANCE_H_
#define _ACC_INSTANCE_H_

#include "conv_acc_innerpp.h"
#include "max_pool_acc_innerpp.h"
#include "config.h"

conv_acc<data_type, data_type_w, data_type_o, 32, 8, 16, 16, 5, 5> convAcc1;

void conv_layer_new(
   int N,
   int K,
   int M,
   int R_IN,
   int C_IN,
   int C_OUT,
   int R_OUT,
   int S,
   int P,
   bool act,
   data_type_w *layer_weights_1,
   data_type_w *layer_weights_2,
   data_type_w *layer_weights_3,
   data_type_w *layer_weights_4,
   data_type_w *layer_weights_5,
   data_type_w *layer_weights_6,
   data_type_w *layer_weights_7,
   data_type_w *layer_weights_8,
   data_type_w *layer_bias,
   int weight_offset,
   int bias_offset,
   int in_offset,
   int out_offset,
   data_type *in_data_1,
   data_type *in_data_2,
   data_type *in_data_3,
   data_type *in_data_4,
   data_type *in_data_5,
   data_type *in_data_6,
   data_type *in_data_7,
   data_type *in_data_8,
   data_type_o *out_data_1,
   data_type_o *out_data_2,
   data_type_o *out_data_3,
   data_type_o *out_data_4,
   data_type_o *out_data_5,
   data_type_o *out_data_6,
   data_type_o *out_data_7,
   data_type_o *out_data_8) {

   convAcc1.conv_layer_acc(N, K, M, R_IN, C_IN, C_OUT, R_OUT, S, P, act,
                           layer_weights_1, layer_weights_2, layer_weights_3, layer_weights_4, layer_weights_5, layer_weights_6, layer_weights_7, layer_weights_8,
                           layer_bias, weight_offset, bias_offset, in_offset, out_offset,
                           in_data_1, in_data_2, in_data_3, in_data_4, in_data_5, in_data_6, in_data_7, in_data_8,
                           out_data_1, out_data_2, out_data_3, out_data_4, out_data_5, out_data_6, out_data_7, out_data_8);

}

max_pool_acc<data_type, data_type_w, data_type_o, 16, 16, 16, 2, 2> maxPoolAcc1;

void max_pool_layer_new(
   int R_in,
   int C_in,
   int N,
   int K,
   int R,
   int C,
   int S,
   int P,
   bool act,
   data_type *in_data_1,
   data_type *in_data_2,
   data_type *in_data_3,
   data_type *in_data_4,
   data_type *in_data_5,
   data_type *in_data_6,
   data_type *in_data_7,
   data_type *in_data_8,
   data_type_o *out_data_1,
   data_type_o *out_data_2,
   data_type_o *out_data_3,
   data_type_o *out_data_4,
   data_type_o *out_data_5,
   data_type_o *out_data_6,
   data_type_o *out_data_7,
   data_type_o *out_data_8) {

#pragma HLS RESOURCE variable=in_data_1 core=RAM_1P_BRAM
#pragma HLS RESOURCE variable=in_data_2 core=RAM_1P_BRAM
#pragma HLS RESOURCE variable=in_data_3 core=RAM_1P_BRAM
#pragma HLS RESOURCE variable=in_data_4 core=RAM_1P_BRAM
#pragma HLS RESOURCE variable=in_data_5 core=RAM_1P_BRAM
#pragma HLS RESOURCE variable=in_data_6 core=RAM_1P_BRAM
#pragma HLS RESOURCE variable=in_data_7 core=RAM_1P_BRAM
#pragma HLS RESOURCE variable=in_data_8 core=RAM_1P_BRAM
   maxPoolAcc1.max_pool_layer_acc(R_in, C_in, N, K, R, C, S, P, act, in_data_1, in_data_2, in_data_3, in_data_4, in_data_5, in_data_6, in_data_7, in_data_8, out_data_1, out_data_2, out_data_3, out_data_4, out_data_5, out_data_6, out_data_7, out_data_8);

}



#endif