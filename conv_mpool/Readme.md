<span style="display: inline-block;">

# Table of Contents
Folder name conv_mpool

# Accelerator detail
Input number of ports: 1
Tm: 32
Tn: 8
Tr: 16
Tc: 16
S_max: 5
K_max: 11

# Interface type:
All Bram

# In system address mapping
Check excel file.
axi_bram_ctrl_0 -> conv_weight_port
axi_bram_ctrl_1 -> conv_bias_port
axi_bram_ctrl_2 -> out_buf_0
axi_bram_ctrl_3 -> out_buf_1
axi_bram_ctrl_4 -> ctrl_cmd_in
axi_bram_ctrl_5 -> conv_param_in
axi_bram_ctrl_6 -> pool_param_in
# System architecture
Check pdf file.


# Evaluation comments:
Control command format:
ctrl_param_in[4] = {conv_enable, pool_enable, null, null};
conv_param_in[16] = {N, K, M, Rin, Cin, R, C, S, P, act, w_offset, b_offset, in_offset, out_offset, w_out, b_out}
w_out and b_out must set to 1 for conv computing.
pool_param_in[16] = {N, K, Rin, Cin, R, C, S, P, act, 0, 0, 0, 0, 0, 0, 0};


Test Points:
{
    "FpgaImageId": "afi-0907a52d75474c730", 
    "FpgaImageGlobalId": "agfi-06997af67a5e70b36"
}
{
    "FpgaImages": [
        {
            "UpdateTime": "2017-11-28T02:59:56.000Z", 
            "Description": "conv+mpool with enable signal", 
            "FpgaImageGlobalId": "agfi-06997af67a5e70b36", 
            "Public": false, 
            "State": {
                "Code": "pending"
            }, 
            "OwnerId": "373589651276", 
            "FpgaImageId": "afi-0907a52d75474c730", 
            "CreateTime": "2017-11-28T02:59:56.000Z"
        }
    ]
}
