<span style="display: inline-block;">

# Table of Contents
Folder name: conv-input-pp
# Accelerator detail
Input number of ports: 1
Tm: 16
Tn: 16
Tr: 32
Tc: 32

Interface settings:
int param[16] -- bram
data_type_w *conv_weight_port -- m_axi depth=8192
data_type_w *conv_bias_port  -- m_axi depth=8192
data_type_o   temp_out_0_1[8192] -- bram
data_type_o   temp_out_1_1[8192] -- bram

Dataflow optimization: None
Input/output function pipelining: Yes
Description: Input buffers are doubled with ping-pong buffer, output buffers are not.
Addition: No URAM is used in this acc system, only on-chip BRAMs are involved




# Post-Synthesis Resource usage
SLICE:            0
LUT:         328952
FF:          269859
DSP:           5176
BRAM:           866
SRL:            102
# Final timing
CP required:    10.000
CP achieved post-synthesis:    3.912


# In system address mapping


# Available Resources on VU9P (AWS F1.2Xlarge)
1182k LUT
36.1Mb Dis RAM
75.9Mb BRAM
270Mb  UltraRAM
6840 DSPs


# Evaluation comments
This IP is used to test if the m_axi interface could read data from the off-chip DRAM, alternative solution is using on-chip bram instead.

{
    "FpgaImageId": "afi-0228ef0d9b56708ec", 
    "FpgaImageGlobalId": "agfi-0ed81ba243f5cefc2"
}
{
    "FpgaImages": [
        {
            "UpdateTime": "2017-11-03T05:37:35.000Z", 
            "Name": "conv-input-pp", 
            "FpgaImageGlobalId": "agfi-0ed81ba243f5cefc2", 
            "Public": false, 
            "State": {
                "Code": "pending"
            }, 
            "OwnerId": "373589651276", 
            "FpgaImageId": "afi-0228ef0d9b56708ec", 
            "CreateTime": "2017-11-03T05:37:35.000Z", 
            "Description": "conv-input-pingpong-buffered"
        }
    ]
}


2. BLOCKRAM
-----------
+-------------------+------+-------+-----------+-------+
|     Site Type     | Used | Fixed | Available | Util% |
+-------------------+------+-------+-----------+-------+
| Block RAM Tile    | 1105 |     0 |      2160 | 51.16 |
|   RAMB36/FIFO*    |  848 |     0 |      2160 | 39.26 |
|     RAMB36E2 only |  848 |       |           |       |
|   RAMB18          |  514 |     0 |      4320 | 11.90 |
|     RAMB18E2 only |  514 |       |           |       |
| URAM              |    0 |     0 |       960 |  0.00 |
+------------------------------------------------------+
3. ARITHMETIC
+----------------+------+-------+-----------+-------+
|    Site Type   | Used | Fixed | Available | Util% |
+----------------+------+-------+-----------+-------+
| DSPs           | 1452 |     0 |      6840 | 21.23 |
|   DSP48E2 only | 1452 |       |           |       |
+----------------+------+-------+-----------+-------+
