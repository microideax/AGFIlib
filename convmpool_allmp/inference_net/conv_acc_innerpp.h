#ifndef _CONV_ACC_H_
#define _CONV_ACC_H_

#include <iostream>
#include <fstream>
#include "activation_functions.h"

#if _C_DEBUG_MODE_
#include <algorithm>
#endif

using namespace std;

template <typename T, typename W, typename G, int Tm, int Tn, int Tr, int Tc, int S_max, int K_max>
class conv_acc {

private:
	int conv_layer_number;

public:
	conv_acc() : conv_layer_number(0) {conv_layer_number = 0;};

	////------------------------------C++ debugging functions---------------------------------------////
	// Reset output buffer
	void out_buf_reset(G buf[][Tr][Tc]){
        for(int i = 0; i < Tm; i++){
            for(int j = 0; j < Tr; j++){
                for(int k = 0; k < Tc; k++){
                    buf[i][j][k] = G(0);
				}
			}
		}
	}
    // Reset weight buffer
    void w_buf_reset(int K, W buf[][Tm][K_max][K_max]){
        for(int i = 0; i < Tn; i++){
            for(int j = 0; j < Tm; j++){
                for(int k = 0; k < K; k++){
                    for(int l = 0; l < K; l++){
                        buf[i][j][k][l] = W(0);
                    }
				}
			}
		}
	}
    // Reset bias buffer
    void b_buf_reset(W buf[]){
        for(int i = 0; i < Tm; i++){
            buf[i]= W(0);
		}
	}
    ////-----------------------------Accelerator Functions---------------------------------------////
    // Load bias data
    void b_buf_load(W buf[], W *layer_bias, int bias_offset, int m){
        for(int i = 0; i < Tm; i++){
            buf[i] = *(layer_bias + bias_offset + i + m);
		}
	}
    // Load input data
    void in_buf_load(T buf[][(Tr-1)*S_max + K_max][(Tc-1)*S_max + K_max],T *in_data_1,T *in_data_2,T *in_data_3,T *in_data_4,T *in_data_5,T *in_data_6,T *in_data_7,T *in_data_8, int in_offset, int n, int r, int c, int S, int K, int P, int R_IN, int C_IN, int N) {
       for (int j = r * S - P; j < (r + Tr - 1) * S + K - P; j++) {
           for (int k = c * S - P; k < (c + Tc - 1) * S + K - P; k++) {
#pragma HLS PIPELINE
        		for (int i = 0; i < Tn; i+=8){
#pragma HLS UNROLL
                   	if ((n + Tn > N && i + 0 >= N - n ) || j < 0 || j >= R_IN || k < 0 || k >= C_IN) {
                       	buf[i + 0][j - r * S + P][k - c * S + P] = T(0);
                   	} else {
                       	buf[i + 0][j - r * S + P][k - c * S + P] = *(in_data_1 + in_offset + (i + n)/8 * R_IN * C_IN + j * C_IN + k);
               		}
                   	if ((n + Tn > N && i + 1 >= N - n ) || j < 0 || j >= R_IN || k < 0 || k >= C_IN) {
                       	buf[i + 1][j - r * S + P][k - c * S + P] = T(0);
                   	} else {
                       	buf[i + 1][j - r * S + P][k - c * S + P] = *(in_data_2 + in_offset + (i + n)/8 * R_IN * C_IN + j * C_IN + k);
               		}
                   	if ((n + Tn > N && i + 2 >= N - n ) || j < 0 || j >= R_IN || k < 0 || k >= C_IN) {
                       	buf[i + 2][j - r * S + P][k - c * S + P] = T(0);
                   	} else {
                       	buf[i + 2][j - r * S + P][k - c * S + P] = *(in_data_3 + in_offset + (i + n)/8 * R_IN * C_IN + j * C_IN + k);
               		}
                   	if ((n + Tn > N && i + 3 >= N - n ) || j < 0 || j >= R_IN || k < 0 || k >= C_IN) {
                       	buf[i + 3][j - r * S + P][k - c * S + P] = T(0);
                   	} else {
                       	buf[i + 3][j - r * S + P][k - c * S + P] = *(in_data_4 + in_offset + (i + n)/8 * R_IN * C_IN + j * C_IN + k);
               		}
                   	if ((n + Tn > N && i + 4 >= N - n ) || j < 0 || j >= R_IN || k < 0 || k >= C_IN) {
                       	buf[i + 4][j - r * S + P][k - c * S + P] = T(0);
                   	} else {
                       	buf[i + 4][j - r * S + P][k - c * S + P] = *(in_data_5 + in_offset + (i + n)/8 * R_IN * C_IN + j * C_IN + k);
               		}
                   	if ((n + Tn > N && i + 5 >= N - n ) || j < 0 || j >= R_IN || k < 0 || k >= C_IN) {
                       	buf[i + 5][j - r * S + P][k - c * S + P] = T(0);
                   	} else {
                       	buf[i + 5][j - r * S + P][k - c * S + P] = *(in_data_6 + in_offset + (i + n)/8 * R_IN * C_IN + j * C_IN + k);
               		}
                   	if ((n + Tn > N && i + 6 >= N - n ) || j < 0 || j >= R_IN || k < 0 || k >= C_IN) {
                       	buf[i + 6][j - r * S + P][k - c * S + P] = T(0);
                   	} else {
                       	buf[i + 6][j - r * S + P][k - c * S + P] = *(in_data_7 + in_offset + (i + n)/8 * R_IN * C_IN + j * C_IN + k);
               		}
                   	if ((n + Tn > N && i + 7 >= N - n ) || j < 0 || j >= R_IN || k < 0 || k >= C_IN) {
                       	buf[i + 7][j - r * S + P][k - c * S + P] = T(0);
                   	} else {
                       	buf[i + 7][j - r * S + P][k - c * S + P] = *(in_data_8 + in_offset + (i + n)/8 * R_IN * C_IN + j * C_IN + k);
               		}
				}
			}
		}
	}


    // Load weights to weight buffer
   void w_buf_load(W buf[][Tm][K_max][K_max], W *layer_weights_1, W *layer_weights_2, W *layer_weights_3, W *layer_weights_4,
                   W *layer_weights_5, W *layer_weights_6, W *layer_weights_7, W *layer_weights_8,
                   int weight_offset, int n, int m, int K, int N, int M){
       for(int k1 = 0; k1 < K; k1++){
           for(int k2 = 0; k2 < K; k2++){
        		for(int i = 0; i < Tm && i < M-m; i++){
        		    for(int j = 0; j < Tn && j < N - n; j+=8){
#pragma HLS PIPELINE
//                        if (n + Tn < N && j + 0 <= N - n )
                            buf[j+0][i][k1][k2] = *(layer_weights_1 + weight_offset/8 + (i+m)*N*K*K + (j+n)/8*K*K + k1*K + k2);
//                        if (n + Tn < N && j + 1 <= N - n )
                            buf[j+1][i][k1][k2] = *(layer_weights_2 + weight_offset/8 + (i+m)*N*K*K + (j+n)/8*K*K + k1*K + k2);
//                        if (n + Tn < N && j + 2 <= N - n )
                            buf[j+2][i][k1][k2] = *(layer_weights_3 + weight_offset/8 + (i+m)*N*K*K + (j+n)/8*K*K + k1*K + k2);
//                        if (n + Tn < N && j + 3 <= N - n )
                            buf[j+3][i][k1][k2] = *(layer_weights_4 + weight_offset/8 + (i+m)*N*K*K + (j+n)/8*K*K + k1*K + k2);
//                        if (n + Tn < N && j + 4 <= N - n )
                            buf[j+4][i][k1][k2] = *(layer_weights_5 + weight_offset/8 + (i+m)*N*K*K + (j+n)/8*K*K + k1*K + k2);
//                        if (n + Tn < N && j + 5 <= N - n )
                            buf[j+5][i][k1][k2] = *(layer_weights_6 + weight_offset/8 + (i+m)*N*K*K + (j+n)/8*K*K + k1*K + k2);
//                        if (n + Tn < N && j + 6 <= N - n )
                            buf[j+6][i][k1][k2] = *(layer_weights_7 + weight_offset/8 + (i+m)*N*K*K + (j+n)/8*K*K + k1*K + k2);
//                        if (n + Tn < N && j + 7 <= N - n )
                            buf[j+7][i][k1][k2] = *(layer_weights_8 + weight_offset/8 + (i+m)*N*K*K + (j+n)/8*K*K + k1*K + k2);
                   }
				}
			}
		}
	}
    // Convolution computation kernel
    void conv_engine(T in_buf[][(Tr-1)*S_max + K_max][(Tc-1)*S_max + K_max], W w_buf[][Tm][K_max][K_max], W b_buf[], G out_buf[][Tr][Tc], int S, int n, int r, int c, int K, int R_OUT, int C_OUT){
        for(int i=0; i<K; i++){
            for(int j=0; j<K; j++){
                for(int tr=0; tr<Tr; tr++){
                    for(int tc=0; tc<Tc; tc++){
#pragma HLS PIPELINE
                        for(int tm = 0; tm < Tm; tm++){
#pragma HLS UNROLL
                            for(int tn=0; tn<Tn; tn++){
#pragma HLS UNROLL
                                if(i==0&&j==0&&tn==0&&n==0)
                                    out_buf[tm][tr][tc] = b_buf[tm] + w_buf[tn][tm][i][j]*in_buf[tn][S*(tr)+i][S*(tc)+j];
                                else
                                    out_buf[tm][tr][tc] = out_buf[tm][tr][tc] + w_buf[tn][tm][i][j]*in_buf[tn][S*(tr)+i][S*(tc)+j];
                            }
                        }
                    }
                }
            }
        }
    }


    // Ouput out_buf data to output interface
    void output_res(G out_buf[][Tr][Tc],G *out_data_1,G *out_data_2,G *out_data_3,G *out_data_4,G *out_data_5,G *out_data_6,G *out_data_7,G *out_data_8, int out_offset, int n, int m, int r, int c, int N, int M, int R_OUT, int C_OUT, bool act){
        if (n >= N - Tn) {
            for (int j = r; j < r + Tr && j < R_OUT; j++) {
                for (int k = c; k < c + Tc && k < C_OUT; k++) {
                    for (int i = 0; i < Tm && i < M-m; i += 8) {
#pragma HLS PIPELINE
//#pragma HLS UNROLL
                        if (act) {
                        	if (i + 0 < M-m)
                            	*(out_data_1 + out_offset + ((i+m)/8) * R_OUT * C_OUT + j * C_OUT + k) = relu(out_buf[i + 0][j - r][k - c]);
                        	if (i + 1 < M-m)
                            	*(out_data_2 + out_offset + ((i+m)/8) * R_OUT * C_OUT + j * C_OUT + k) = relu(out_buf[i + 1][j - r][k - c]);
                        	if (i + 2 < M-m)
                            	*(out_data_3 + out_offset + ((i+m)/8) * R_OUT * C_OUT + j * C_OUT + k) = relu(out_buf[i + 2][j - r][k - c]);
                        	if (i + 3 < M-m)
                            	*(out_data_4 + out_offset + ((i+m)/8) * R_OUT * C_OUT + j * C_OUT + k) = relu(out_buf[i + 3][j - r][k - c]);
                        	if (i + 4 < M-m)
                            	*(out_data_5 + out_offset + ((i+m)/8) * R_OUT * C_OUT + j * C_OUT + k) = relu(out_buf[i + 4][j - r][k - c]);
                        	if (i + 5 < M-m)
                            	*(out_data_6 + out_offset + ((i+m)/8) * R_OUT * C_OUT + j * C_OUT + k) = relu(out_buf[i + 5][j - r][k - c]);
                        	if (i + 6 < M-m)
                            	*(out_data_7 + out_offset + ((i+m)/8) * R_OUT * C_OUT + j * C_OUT + k) = relu(out_buf[i + 6][j - r][k - c]);
                        	if (i + 7 < M-m)
                            	*(out_data_8 + out_offset + ((i+m)/8) * R_OUT * C_OUT + j * C_OUT + k) = relu(out_buf[i + 7][j - r][k - c]);
                        }
                        else {
                        	if (i + 0 < M-m)
                            	*(out_data_1 + out_offset + ((i+m)/8) * R_OUT * C_OUT + j * C_OUT + k) = out_buf[i + 0][j - r][k - c];
                        	if (i + 1 < M-m)
                            	*(out_data_2 + out_offset + ((i+m)/8) * R_OUT * C_OUT + j * C_OUT + k) = out_buf[i + 1][j - r][k - c];
                        	if (i + 2 < M-m)
                            	*(out_data_3 + out_offset + ((i+m)/8) * R_OUT * C_OUT + j * C_OUT + k) = out_buf[i + 2][j - r][k - c];
                        	if (i + 3 < M-m)
                            	*(out_data_4 + out_offset + ((i+m)/8) * R_OUT * C_OUT + j * C_OUT + k) = out_buf[i + 3][j - r][k - c];
                        	if (i + 4 < M-m)
                            	*(out_data_5 + out_offset + ((i+m)/8) * R_OUT * C_OUT + j * C_OUT + k) = out_buf[i + 4][j - r][k - c];
                        	if (i + 5 < M-m)
                            	*(out_data_6 + out_offset + ((i+m)/8) * R_OUT * C_OUT + j * C_OUT + k) = out_buf[i + 5][j - r][k - c];
                        	if (i + 6 < M-m)
                            	*(out_data_7 + out_offset + ((i+m)/8) * R_OUT * C_OUT + j * C_OUT + k) = out_buf[i + 6][j - r][k - c];
                        	if (i + 7 < M-m)
                            	*(out_data_8 + out_offset + ((i+m)/8) * R_OUT * C_OUT + j * C_OUT + k) = out_buf[i + 7][j - r][k - c];
                        }
                    }
                }
            }
        }
    }
///////////////////////------------------conv accelerator----------------//////////////////////////
    void conv_layer_acc(
            int N, //input feature number
            int K, //input kernel size
            int M, // output feature number
            int R_IN, // input Row
            int C_IN, // input column
            int R_OUT, // output Row
            int C_OUT,// output column
            int S, // stride size
            int P, // padding size
            bool act, // activation function bit (1-- with act, 0--without act)
            W *layer_weights_1, //w[M][N][K][K]
            W *layer_weights_2,
            W *layer_weights_3,
            W *layer_weights_4,
            W *layer_weights_5,
            W *layer_weights_6,
            W *layer_weights_7,
            W *layer_weights_8,
            W *layer_bias, // b[M]
            int weight_offset,
            int bias_offset,
            int in_offset,
            int out_offset,
            T *in_data_1, // in_data[N][(R-1)*S + K][(C-1)*S + K] --> [N][(R-1)*S + K - 2*P][(C-1)*S + K - 2*P]
            T *in_data_2, // in_data[N][(R-1)*S + K][(C-1)*S + K] --> [N][(R-1)*S + K - 2*P][(C-1)*S + K - 2*P]
            T *in_data_3, // in_data[N][(R-1)*S + K][(C-1)*S + K] --> [N][(R-1)*S + K - 2*P][(C-1)*S + K - 2*P]
            T *in_data_4, // in_data[N][(R-1)*S + K][(C-1)*S + K] --> [N][(R-1)*S + K - 2*P][(C-1)*S + K - 2*P]
            T *in_data_5, // in_data[N][(R-1)*S + K][(C-1)*S + K] --> [N][(R-1)*S + K - 2*P][(C-1)*S + K - 2*P]
            T *in_data_6, // in_data[N][(R-1)*S + K][(C-1)*S + K] --> [N][(R-1)*S + K - 2*P][(C-1)*S + K - 2*P]
            T *in_data_7, // in_data[N][(R-1)*S + K][(C-1)*S + K] --> [N][(R-1)*S + K - 2*P][(C-1)*S + K - 2*P]
            T *in_data_8, // in_data[N][(R-1)*S + K][(C-1)*S + K] --> [N][(R-1)*S + K - 2*P][(C-1)*S + K - 2*P]
            G *out_data_1, // out[M][R][C]
            G *out_data_2, // out[M][R][C]
            G *out_data_3, // out[M][R][C]
            G *out_data_4, // out[M][R][C]
            G *out_data_5, // out[M][R][C]
            G *out_data_6, // out[M][R][C]
            G *out_data_7, // out[M][R][C]
            G *out_data_8){ // out[M][R][C]

        /***************local data buffer******************************/
        T in_buf_1[Tn][(Tr-1)*S_max + K_max][(Tc-1)*S_max + K_max];
        T in_buf_0[Tn][(Tr-1)*S_max + K_max][(Tc-1)*S_max + K_max];
        W w_buf_1[Tn][Tm][K_max][K_max];
        W w_buf_0[Tn][Tm][K_max][K_max];
        W b_buf_1[Tm];
        W b_buf_0[Tm];
        G out_buf_1[Tm][Tr][Tc];
        G out_buf_0[Tm][Tr][Tc];

        /***************Ptr and buffer initialization******************************/
        bool in_buf_0_empty = 1;
        bool in_buf_1_empty = 1;
        bool out_buf_0_empty = 1;
        bool out_buf_1_empty = 1;
        int loadbufPtr = 0;
        int combufPtr = 0;
        int resbufPtr = 0;
        bool last_com = 0;
        bool last_load = 0;
        bool last_res = 0;

#if _HLS_MODE_
#pragma HLS ARRAY_PARTITION variable=in_buf_1 complete dim=1
#pragma HLS ARRAY_PARTITION variable=in_buf_0 complete dim=1
#pragma HLS ARRAY_PARTITION variable=w_buf_1 complete dim=1
#pragma HLS ARRAY_PARTITION variable=w_buf_1 complete dim=2
#pragma HLS ARRAY_PARTITION variable=w_buf_0 complete dim=1
#pragma HLS ARRAY_PARTITION variable=w_buf_0 complete dim=2
#pragma HLS ARRAY_PARTITION variable=b_buf_1 complete dim=1
#pragma HLS ARRAY_PARTITION variable=b_buf_0 complete dim=1
#pragma HLS ARRAY_PARTITION variable=out_buf_1 complete dim=1
#pragma HLS ARRAY_PARTITION variable=out_buf_0 complete dim=1
#endif

#if _C_DEBUG_MODE_
#if _KERNEL_DEBUG_
            cout << "Starting conv_acc_innerpp layer ...." << endl;
            //buffer local data initiallization: must do it in C++ debug!
            out_buf_reset(out_buf_1);
            out_buf_reset(out_buf_0);
            b_buf_reset(b_buf_1);
            b_buf_reset(b_buf_0);
            w_buf_reset(K, w_buf_1);
            w_buf_reset(K, w_buf_0);
#endif
#endif
		for(int r = 0; r < R_OUT; r += Tr){
			for(int c = 0; c < C_OUT; c += Tc){
				for(int m = 0; m < M; m += Tm){
					for(int n = 0; n < N; n += 2*Tn){
   //--------------------------Load input B W D in ping-pong manner-------------------------//
						while ((in_buf_0_empty | in_buf_1_empty)&& (!last_load)) {
							if (loadbufPtr == 1) {
                    			cout << "loading input buffer 1...." << endl;
                    			//load input bias
                        		b_buf_load(b_buf_1, layer_bias, bias_offset, m);
                        		// load input data
                        		in_buf_load(in_buf_1, in_data_1, in_data_2, in_data_3, in_data_4, in_data_5, in_data_6, in_data_7, in_data_8, in_offset, n+Tn, r, c, S, K, P, R_IN, C_IN, N);
                        		// load input weights
                        		w_buf_load(w_buf_1, layer_weights_1, layer_weights_2, layer_weights_3, layer_weights_4,
                                           layer_weights_5, layer_weights_6, layer_weights_7, layer_weights_8, weight_offset, n+Tn, m, K, N, M);
                        		in_buf_1_empty = 0;
                        		cout << "buffer 1 full" << endl;
                        		loadbufPtr = 0;
                        		if (n+2*Tn >= N) {last_load = 1;}
                        	} else {
                    			cout << "loading input buffer 0...." << endl;
                    			//load input bias
                        		b_buf_load(b_buf_0, layer_bias, bias_offset, m);
                        		// load input data
                        		in_buf_load(in_buf_0, in_data_1, in_data_2, in_data_3, in_data_4, in_data_5, in_data_6, in_data_7, in_data_8, in_offset, n, r, c, S, K, P, R_IN, C_IN, N);
                        		// load input weights
                        		w_buf_load(w_buf_0, layer_weights_1, layer_weights_2, layer_weights_3, layer_weights_4,
                                           layer_weights_5, layer_weights_6, layer_weights_7, layer_weights_8, weight_offset, n, m, K, N, M);
//#if _C_DEBUG_MODE_
//#if _KERNEL_DEBUG_
//                                cout << "weight buffer load test" << endl;
//                                for(int i=0; i<1; i++){
//                                    for(int j=0; j<6; j++){
//                                        for(int k1=0; k1<5; k1++){
//                                            for(int k2=0; k2<5; k2++){
//                                                cout<< w_buf_0[i][j][k1][k2] << "  ";
//                                            }
//                                            cout << endl;
//                                        }
//                                        cout << endl;
//                                    }
//                                    cout << endl;
//                                }cout<< endl;
//#endif
//#endif
                        		in_buf_0_empty = 0;
                        		cout << "buffer 0 full" << endl;
                        		loadbufPtr = 1;
                        		if (n+Tn >= N) {last_load = 1;}
							}
                       }
                       loadbufPtr = 0;
                       last_load = 0;
   //------------------------------compute buffered data -----------------------------------//
                    	while ((!in_buf_0_empty | !in_buf_1_empty)&& (!last_com)) {
                    		if (combufPtr == 1) {
                    			cout << "computing input buffer 1...." << endl;
                    			if(resbufPtr == 1){
                        			conv_engine(in_buf_1, w_buf_1, b_buf_1, out_buf_1, S, n+Tn, r, c, K, R_OUT, C_OUT);
                    				out_buf_1_empty = 0;
                    			}else{
                        			conv_engine(in_buf_1, w_buf_1, b_buf_1, out_buf_0, S, n+Tn, r, c, K, R_OUT, C_OUT);
                    				out_buf_0_empty = 0;
                    			}
                    			in_buf_1_empty = 1;
                    			combufPtr = 0;
                    			cout << "buffer 1 computed" << endl;
                    			if (n+2*Tn >= N) {last_com = 1;}
                    		} else {
                    			cout << "computing input buffer 0...." << endl;
                    			if(resbufPtr == 1){
                        			conv_engine(in_buf_0, w_buf_0, b_buf_0, out_buf_1, S, n, r, c, K, R_OUT, C_OUT);
                    				out_buf_1_empty = 0;
                    			}else{
                        			conv_engine(in_buf_0, w_buf_0, b_buf_0, out_buf_0, S, n, r, c, K, R_OUT, C_OUT);
                    				out_buf_0_empty = 0;
                    			}
                    			in_buf_0_empty = 1;
                    			combufPtr = 1;
                    			cout << "buffer 0 computed" << endl;
								if (n+Tn >= N) {last_com = 1;}
							}
                       }
                       combufPtr = 0;
                       last_com = 0;
   //---------------------------transfer output data----------------------------------------//
                    	while ((!out_buf_0_empty | !out_buf_1_empty)&& (!last_res)) {
                    		if (resbufPtr == 1) {
                    			cout << "output buffer 1...." << endl;
                    			// transfer output data
                    			if (n+Tn >= N) {
                    				last_res = 1;
                    				resbufPtr = 0;
                    				output_res(out_buf_1, out_data_1, out_data_2, out_data_3, out_data_4, out_data_5, out_data_6, out_data_7, out_data_8, out_offset, n, m, r, c, N, M, R_OUT, C_OUT, act);
                    			}else if (n+2*Tn >= N) {
                    				last_res = 1;
                    				resbufPtr = 0;
                    				output_res(out_buf_1, out_data_1, out_data_2, out_data_3, out_data_4, out_data_5, out_data_6, out_data_7, out_data_8, out_offset, n+Tn, m, r, c, N, M, R_OUT, C_OUT, act);
                    			}
                    			out_buf_1_empty = 1;
                    			cout << "buffer 1 res" << endl;
                    		} else {
                    			cout << "output buffer 0...." << endl;
                    			// transfer output data
                    			if (n+Tn >= N) {
                    				last_res = 1;
                    				resbufPtr = 1;
                    				output_res(out_buf_0, out_data_1, out_data_2, out_data_3, out_data_4, out_data_5, out_data_6, out_data_7, out_data_8, out_offset, n, m, r, c, N, M, R_OUT, C_OUT, act);
                    			}else if (n+2*Tn >= N) {
                    				last_res = 1;
                    				resbufPtr = 1;
                    				output_res(out_buf_0, out_data_1, out_data_2, out_data_3, out_data_4, out_data_5, out_data_6, out_data_7, out_data_8, out_offset, n+Tn, m, r, c, N, M, R_OUT, C_OUT, act);
                    			}
                    			out_buf_0_empty = 1;
								cout << "buffer 0 res" << endl;
							}
						}
						last_res = 0;
					}
				}
			}
		}
#if _C_DEBUG_MODE_
#if _KERNEL_DEBUG_
            cout << "Finished conv_acc_innerpp layer ...." << endl;
            ofstream conv_out;
            conv_out.open("conv_out_data.txt",ios::app);
            conv_out <<"conv output: "<< endl;
            for (int i = 0; i < M/8; i++) {
                for (int j = 0; j < R_OUT; j++) {
                    for(int k = 0; k < C_OUT; k++){
                        conv_out << *(out_data_1 + out_offset + i*R_OUT*C_OUT + j*C_OUT + k) << " ";
                    }conv_out << endl;
                }conv_out << endl;
                for (int j = 0; j < R_OUT; j++) {
                    for(int k = 0; k < C_OUT; k++){
                        conv_out << *(out_data_2 + out_offset + i*R_OUT*C_OUT + j*C_OUT + k) << " ";
                    }conv_out << endl;
                }conv_out << endl;
                for (int j = 0; j < R_OUT; j++) {
                    for(int k = 0; k < C_OUT; k++){
                        conv_out << *(out_data_3 + out_offset + i*R_OUT*C_OUT + j*C_OUT + k) << " ";
                    }conv_out << endl;
                }conv_out << endl;
                for (int j = 0; j < R_OUT; j++) {
                    for(int k = 0; k < C_OUT; k++){
                        conv_out << *(out_data_4 + out_offset + i*R_OUT*C_OUT + j*C_OUT + k) << " ";
                    }conv_out << endl;
                }conv_out << endl;
                for (int j = 0; j < R_OUT; j++) {
                    for(int k = 0; k < C_OUT; k++){
                        conv_out << *(out_data_5 + out_offset + i*R_OUT*C_OUT + j*C_OUT + k) << " ";
                    }conv_out << endl;
                }conv_out << endl;
                for (int j = 0; j < R_OUT; j++) {
                    for(int k = 0; k < C_OUT; k++){
                        conv_out << *(out_data_6 + out_offset + i*R_OUT*C_OUT + j*C_OUT + k) << " ";
                    }conv_out << endl;
                }conv_out << endl;
                for (int j = 0; j < R_OUT; j++) {
                    for(int k = 0; k < C_OUT; k++){
                        conv_out << *(out_data_7 + out_offset + i*R_OUT*C_OUT + j*C_OUT + k) << " ";
                    }conv_out << endl;
                }conv_out << endl;
                for (int j = 0; j < R_OUT; j++) {
                    for(int k = 0; k < C_OUT; k++){
                        conv_out << *(out_data_8 + out_offset + i*R_OUT*C_OUT + j*C_OUT + k) << " ";
                    }conv_out << endl;
                }conv_out << endl;
            }conv_out.close();
#endif
#endif
    }
};
#endif
