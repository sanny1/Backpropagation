//
// Created by Sanyog Chhetri on 31/08/16.
//

#ifndef BACKPROPAGATION_LAYERS_H
#define BACKPROPAGATION_LAYERS_H

#include "Neuron.h"

using namespace std;
using namespace Ann;

template<class typ>
class Layer
{
private:
	vector<typ> inputs;
	vector<float> weights;
	vector<Neuron> hidden_layer;
	vector<Neuron> output_layer;
	vector<float> desired;
	vector<float> previous_error;
	vector<float> reset_vect;
private: // helpers
	int num_hid;
	int out_num;
	int inps;
	float mse;
public:
	Layer(int hidden, int out, int inputs);
	virtual ~Layer(){};
	void Set_Input_layer(vector<typ> inpu);
	void Hidden_Layer(int stride, int locson);
	void Output_Layer();
	void Update(int desi);
public:
	void Set_desired(vector<float> des);
	void Set_weight(vector<float> weig);
	void print_output();
	void calculate_mse();//inside for loop for inputs
	void print_mse();
	void reset_mse();
	float Get_mse(int i);// i represents which output
	vector<float> Get_all_weights();
};

#endif //BACKPROPAGATION_LAYERS_H
