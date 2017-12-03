
#ifndef _CONSTRUCT_NET_H_
#define _CONSTRUCT_NET_H_
#include <iostream>
#include <ap_fixed.h>
#include "config.h"
#include "acc_instance.h"

using namespace std;

void   inference_net(
    int ctrl_cmd_in[4],  // CONV_EN, POOL_EN, CONV_DIR, POOL_DIR
    int conv_param_in[16],
    int pool_param_in[16],
    data_type_w conv_weight_port[32*8*11*11],
        data_type_w conv_bias_port[64],
        data_type_o   temp_out_0_1[59168],
        data_type_o   temp_out_1_1[12544]){

#if _HLS_MODE_
#pragma HLS INTERFACE s_axilite port=return bundle=CRTL_BUS
#pragma HLS INTERFACE bram port=ctrl_cmd_in
#pragma HLS INTERFACE bram port=conv_param_in
#pragma HLS INTERFACE bram port=pool_param_in
#pragma HLS INTERFACE bram port=conv_weight_port
#pragma HLS INTERFACE bram port=conv_bias_port
#pragma HLS INTERFACE bram port=temp_out_0_1
#pragma HLS INTERFACE bram port=temp_out_1_1
#endif

#if _C_DEBUG_MODE_
#if _KERNEL_DEBUG_
   cout << "starting forward network process..........................." << endl;
   cout << "..........................................................." << endl;
#endif
#endif

/*
   int shift_weight_conv1_1 = 0;
   int shift_bias_conv1_1 = 0;

   int shift_weight_conv2_1 = 150;
   int shift_bias_conv2_1 = 6;

   int shift_weight_fc1 = 0;
   int shift_bias_fc1 = 0;


   conv_layer_new(1, 5, 6, 28, 28, 28, 28, 1, 2, 1, conv_weight_port, conv_bias_port, shift_weight_conv1_1, shift_bias_conv1_1, 0, 0,  temp_out_0_1,  temp_out_1_1);

   max_pool_layer_new(28, 28, 6, 2, 14, 14, 2, 0, 1,  temp_out_1_1,  temp_out_0_1);

   conv_layer_new(6, 5, 16, 14, 14, 10, 10, 1, 0, 1, conv_weight_port, conv_bias_port, shift_weight_conv2_1, shift_bias_conv2_1, 0, 0,  temp_out_0_1,  temp_out_1_1);

   max_pool_layer_new(10, 10, 16, 2, 5, 5, 2, 0, 1,  temp_out_1_1,  temp_out_0_1);

   conv_layer_new(16, 5, 10, 5, 5, 1, 1, 5, 0, 1, fc_weight_port, fc_bias_port, shift_weight_fc1, shift_bias_fc1, 0, 0,  temp_out_0_1,  temp_out_1_1);

   for (int i = 0; i < 10; i++) {
      fc_3_out_a[i+0] = temp_out_1_1[i/1];
      
   }
*/

    int conv_param[16];
    int pool_param[16];
    int ctrl_cmd[16];

    for(int i = 0; i<16; i++){
        conv_param[i] = conv_param_in[i];
    }
    for(int i = 0; i<16; i++){
        pool_param[i] = pool_param_in[i];
    }
    for(int i =0; i<4; i++){
        ctrl_cmd[i] = ctrl_cmd_in[i];
    }

    bool conv_enable = (bool)ctrl_cmd[0];
    bool pool_enable  = (bool)ctrl_cmd[1];

    if (conv_enable) {
        conv_layer_new(conv_param[0], conv_param[1], conv_param[2], conv_param[3], conv_param[4],
                       conv_param[5], conv_param[6], conv_param[7], conv_param[8], (bool) conv_param[9],
                       conv_weight_port, conv_bias_port,
                       conv_param[10], conv_param[11], conv_param[12], conv_param[13],
                       temp_out_0_1, temp_out_1_1);
    }
    if (pool_enable){
        max_pool_layer_new(pool_param[0], pool_param[1], pool_param[2], pool_param[3],
                           pool_param[4], pool_param[5], pool_param[6], pool_param[7],
                           pool_param[8], temp_out_1_1, temp_out_0_1);
    }

#if _C_DEBUG_MODE_
#if _KERNEL_DEBUG_
   cout << "Finished forward network process .........................." << endl;
   cout << "..........................................................." << endl;
#endif
#endif
}

#endif //_CONSTRUCT_NET_H_
