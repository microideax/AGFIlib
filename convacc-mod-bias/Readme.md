<span style="display: inline-block;">

# Table of Contents
Folder name: conv-pp-wbctrl
# Accelerator detail
Input number of ports: 1
Tm: 32
Tn: 8
Tr: 32
Tc: 32
S:  5
K:  11

Interface settings:
int param[16] -- bram
data_type_w   conv_weight_port[8192] -- bram
data_type_w   conv_bias_port[64]  -- bram
data_type_o   temp_out_0_1[8192] -- bram
data_type_o   temp_out_1_1[8192] -- bram

Dataflow optimization: None
Input/output function pipelining: Yes(inner most loop)
Description: Input buffers and output buffers are doubled with ping-pong buffer.
Addition: No URAM is used in this acc system, only on-chip BRAMs are involved




# In system address mapping
check excel file.
# System architecture
check pdf file.


# Evaluation comments
Test points:
(1) input/output data read/write speed
(2) conv processing speed with different acc_params
(3) if bias is not added into the final results

{
    "FpgaImageId": "afi-025131473acb472bf", 
    "FpgaImageGlobalId": "agfi-034cc8adae3595d78"
}

{
    "FpgaImages": [
        {
            "UpdateTime": "2017-11-13T10:11:32.000Z", 
            "Name": "conv-bram-bias-modified", 
            "FpgaImageGlobalId": "agfi-034cc8adae3595d78", 
            "Public": false, 
            "State": {
                "Code": "pending"
            }, 
            "OwnerId": "373589651276", 
            "FpgaImageId": "afi-025131473acb472bf", 
            "CreateTime": "2017-11-13T10:11:32.000Z", 
            "Description": "conv bram with modified bias port"
        }
    ]
}






