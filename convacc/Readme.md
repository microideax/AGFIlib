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
data_type_w *conv_weight_port -- m_axi depth=8192 //connected to aws DDR memory space
data_type_w *conv_bias_port  -- m_axi depth=8192 //connected to aws DDR memory space
data_type_o   temp_out_0_1[8192] -- bram
data_type_o   temp_out_1_1[8192] -- bram

Dataflow optimization: None
Input/output function pipelining: Yes
Description: Input buffers are doubled with ping-pong buffer, output buffers are not.
Addition: No URAM is used in this acc system, only on-chip BRAMs are involved


# Final timing
CP required:    10.000
CP achieved post-synthesis:    3.912


# In system address mapping
check excel file.
# System architecture
check pdf file.


# Evaluation comments
Test points:
(1) whether m_axi could read from DDR memory
(2) if acc_param bram interface could work properly
(3) input/output thorughput testing

{
    "FpgaImageId": "afi-05a48546759c44f0f", 
    "FpgaImageGlobalId": "agfi-067a323d7ff7c0f0c"
}
{
    "FpgaImages": [
        {
            "UpdateTime": "2017-11-05T04:30:53.000Z", 
            "Name": "conv-input-pp", 
            "FpgaImageGlobalId": "agfi-067a323d7ff7c0f0c", 
            "Public": false, 
            "State": {
                "Code": "pending"
            }, 
            "OwnerId": "373589651276", 
            "FpgaImageId": "afi-05a48546759c44f0f", 
            "CreateTime": "2017-11-05T04:30:53.000Z", 
            "Description": "conv-input-ping-pong-buffered"
        }
    ]
}



2. BLOCKRAM
-----------
+-------------------+--------+-------+-----------+-------+
|     Site Type     |  Used  | Fixed | Available | Util% |
+-------------------+--------+-------+-----------+-------+
| Block RAM Tile    | 1515.5 |     0 |      2160 | 70.16 |
|   RAMB36/FIFO*    |   1251 |   265 |      2160 | 57.92 |
|     FIFO36E2 only |     24 |       |           |       |
|     RAMB36E2 only |   1227 |       |           |       |
|   RAMB18          |    529 |     9 |      4320 | 12.25 |
|     RAMB18E2 only |    529 |       |           |       |
| URAM              |      0 |     0 |       960 |  0.00 |
+-------------------+--------+-------+-----------+-------+


3. ARITHMETIC
+----------------+------+-------+-----------+-------+
|    Site Type   | Used | Fixed | Available | Util% |
+----------------+------+-------+-----------+-------+
| DSPs           | 1464 |     3 |      6840 | 21.40 |
|   DSP48E2 only | 1464 |       |           |       |
+----------------+------+-------+-----------+-------+

