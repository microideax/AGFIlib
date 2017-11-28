
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
//   data_type_w conv_weight_port[8*166*166],
   data_type_w conv_weight_port[32*8*11*11],
   data_type_w conv_bias_port[64],
//   data_type_w fc_weight_port[4000],
//   data_type_w fc_bias_port[10],
//   data_type_o   fc_3_out_a[10*1*1],
   data_type_o   temp_out_0_1[59168],
   data_type_o   temp_out_1_1[12544]){

#if _HLS_MODE_
#pragma HLS INTERFACE s_axilite port=return bundle=CRTL_BUS
#pragma HLS INTERFACE bram port=ctrl_cmd_in
#pragma HLS INTERFACE bram port=conv_param_in
#pragma HLS INTERFACE bram port=pool_param_in
//#pragma HLS INTERFACE m_axi depth=2550 port=conv_weight_port
//#pragma HLS INTERFACE m_axi depth=22   port=conv_bias_port
//#pragma HLS INTERFACE m_axi depth=4000 port=fc_weight_port
//#pragma HLS INTERFACE m_axi depth=10 port=fc_bias_port
//#pragma HLS INTERFACE m_axi depth=8192 port=conv_weight_port
//#pragma HLS INTERFACE m_axi depth=64 port=conv_bias_port
#pragma HLS INTERFACE bram port=conv_weight_port
#pragma HLS INTERFACE bram port=conv_bias_port
//#pragma HLS INTERFACE bram port=fc_weight_port
//#pragma HLS INTERFACE bram port=fc_bias_port
//#pragma HLS INTERFACE m_axi depth=10 port=fc_3_out_a
//#pragma HLS INTERFACE m_axi depth=4704 port=temp_out_0_1
//#pragma HLS INTERFACE m_axi depth=4704 port=temp_out_1_1
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
*/
   int shift_weight_conv2_1 = 150;
   int shift_bias_conv2_1 = 6;

   int shift_weight_fc1 = 0;
   int shift_bias_fc1 = 0;

   int conv_param[16];
   int pool_param[16];
   int ctrl_cmd[4];

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
/*
    data_type_o &conv_in_buf_ptr;
    data_type_o &conv_out_buf_ptr;
    data_type_o &pool_in_buf_ptr;
    data_type_o &pool_out_buf_ptr;
*/
//   conv_layer_new(1, 5, 6, 28, 28, 28, 28, 1, 2, 1, conv_weight_port, conv_bias_port, shift_weight_conv1_1, shift_bias_conv1_1, 0, 0,  temp_out_0_1,  temp_out_1_1);
/*
    if (ctrl_cmd[2] == true) {
        conv_in_buf_ptr = &temp_out_1_1;
        conv_out_buf_ptr= &temp_out_0_1;
    }
    else {
        conv_in_buf_ptr = &temp_out_0_1;
        conv_out_buf_ptr= &temp_out_1_1;
    }
    if (ctrl_cmd[3] == true) {
        pool_in_buf_ptr = &temp_out_1_1;
        pool_out_buf_ptr= &temp_out_0_1;
    }
    else {
        pool_in_buf_ptr = &temp_out_0_1;
        pool_out_buf_ptr= &temp_out_1_1;
    }
*/

    if (conv_enable) {
        /*
        conv_layer_new(conv_param[0], conv_param[1], conv_param[2], conv_param[3], conv_param[4],
                       conv_param[5], conv_param[6], conv_param[7], conv_param[8], (bool)conv_param[9],
                       conv_weight_port, conv_bias_port,
                       conv_param[10], conv_param[11], conv_param[12], conv_param[13],
                       conv_in_buf_ptr, conv_out_buf_ptr, conv_param[14], conv_param[15]);
        */

//        if (ctrl_cmd[2] == true) {
            conv_layer_new(conv_param[0], conv_param[1], conv_param[2], conv_param[3], conv_param[4],
                       conv_param[5], conv_param[6], conv_param[7], conv_param[8], (bool)conv_param[9],
                       conv_weight_port, conv_bias_port,
                       conv_param[10], conv_param[11], conv_param[12], conv_param[13],
                       temp_out_0_1, temp_out_1_1, conv_param[14], conv_param[15]);
/*
        } else {
            conv_layer_new(conv_param[0], conv_param[1], conv_param[2], conv_param[3], conv_param[4],
                       conv_param[5], conv_param[6], conv_param[7], conv_param[8], (bool)conv_param[9],
                       conv_weight_port, conv_bias_port,
                       conv_param[10], conv_param[11], conv_param[12], conv_param[13],
                       temp_out_1_1, temp_out_0_1, conv_param[14], conv_param[15]);
        }
*/
    }

//   max_pool_layer_new(28, 28, 6, 2, 14, 14, 2, 0, 1,  temp_out_1_1,  temp_out_0_1);
    if (pool_enable) {
        /*
        max_pool_layer_new(pool_param[0], pool_param[1], pool_param[2], pool_param[3],
                           pool_param[4], pool_param[5], pool_param[6], pool_param[7],
                           pool_param[8], pool_in_buf_ptr, pool_out_buf_ptr);
        */

//        if(ctrl_cmd[3] == true){

            max_pool_layer_new(pool_param[0], pool_param[1], pool_param[2], pool_param[3],
                               pool_param[4], pool_param[5], pool_param[6], pool_param[7],
                               pool_param[8], temp_out_1_1, temp_out_0_1);

/*
        }
        else {
            max_pool_layer_new(pool_param[0], pool_param[1], pool_param[2], pool_param[3],
                               pool_param[4], pool_param[5], pool_param[6], pool_param[7],
                               pool_param[8], temp_out_0_1, temp_out_1_1);
        }
*/
    }

/*
   conv_layer_new(6, 5, 16, 14, 14, 10, 10, 1, 0, 1, conv_weight_port, conv_bias_port, shift_weight_conv2_1, shift_bias_conv2_1, 0, 0,  temp_out_0_1,  temp_out_1_1, 1, 1);

   max_pool_layer_new(10, 10, 16, 2, 5, 5, 2, 0, 1,  temp_out_1_1,  temp_out_0_1);


   conv_layer_new(16, 5, 10, 5, 5, 1, 1, 5, 0, 1, fc_weight_port, fc_bias_port, shift_weight_fc1, shift_bias_fc1, 0, 0,  temp_out_0_1,  temp_out_1_1, 1, 1);
*/

/*
   for (int i = 0; i < 10; i++) {
      fc_3_out_a[i+0] = temp_out_1_1[i/1];
      
   }
*/

#if _C_DEBUG_MODE_
#if _KERNEL_DEBUG_
   cout << "Finished forward network process .........................." << endl;
   cout << "..........................................................." << endl;
#endif
#endif
}

#endif //_CONSTRUCT_NET_H_
