
#ifndef _CONFIG_H_
#define _CONFIG_H_


//define data type
typedef float data_type;
typedef float data_type_w;
typedef float data_type_o;

// C++ compilation debug mode
#define _HLS_MODE_  1

// C++ compilation debug mode
//#define _BATCH_MODE_ 1
#ifdef _BATCH_MODE_
#define _KERNEL_DEBUG_ 0
#else
#define _KERNEL_DEBUG_ 1
#endif
#ifdef _HLS_MODE_
#define _C_DEBUG_MODE_ 0
#else
#define _C_DEBUG_MODE_ 1
#endif


//network configuration PARAMETERS
int weight_bias_record = 0;
int weight_bias_count_1 = 0;
int weight_bias_count_2 = 0;


int nn_in_data_size_conv[2] = {28, 14};
int nn_in_number_conv[2] = {1, 6};
int nn_out_number_conv[2] = {6, 16};
int nn_channel_size_conv[2] = {5, 5};
int nn_padding_conv[2] = {2, 0};
int nn_group_conv[2] = {1, 1};
int nn_in_data_size_pooling[2] = {28, 10};
int nn_in_number_pooling[2] = {6, 16};
int nn_channel_size_pooling[2] = {2, 2};
int nn_in_data_size_fc[1] = {5};
int nn_in_number_fc[1] = {16};
int nn_out_number_fc[1] = {10};
int nn_channel_size_fc[1] = {5};


#endif
