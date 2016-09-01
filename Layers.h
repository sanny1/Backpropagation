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
	vector<Neuron> hidden_layer;
	vector<Neuron> output_layer;
	vector<int> desired;
	vector<float> previous_error;
private: // helpers
	int num_hid;
	int out_num;
	float mse;
public:
	Layer(int hidden, int out, int inputs) : hidden_layer(hidden, Neuron(inputs, -1)),
	                                         output_layer(out, Neuron(hidden, -1)), previous_error(out, 0)
	{
		num_hid = hidden;
		out_num = out;
	};

	virtual ~Layer()
	{
	};

	void Set_Input_layer(vector<typ> inpu)
	{
		inputs = inpu;
	};

	void Hidden_Layer(int stride, int locson)
	{
		auto first = inputs.begin() + (stride * locson);
		auto last = inputs.begin() + (stride * (locson + 1));
		vector<typ> tmp(first, last);
		for (int i = 0; i < num_hid; i++)
		{
			hidden_layer.at(i).Set_input(tmp);
			hidden_layer.at(i).Activation_Func();
		}
	};

	void Output_Layer(int desi)
	{
		vector<float> tmp(num_hid, 0);
		for (int i = 0; i < out_num; i++)
		{
			output_layer.at(i).Set_Desired_Output(desired);
			for (int j = 0; j < num_hid; j++)
			{
				tmp.at(j) = hidden_layer.at(j).Get_Actual_Output();
			}
			output_layer.at(i).Set_input(tmp);
			output_layer.at(i).Activation_Func();
			output_layer.at(i).Error_Evalutation(desi);
		}
	};

	void Update()
	{
		vector<float> tmp(num_hid, 0);
		for (int i = 0; i < out_num; i++)
		{
			output_layer.at(i).Adjustment_Func();
		}
		for (int i = 0; i < num_hid; i++)
		{
			for (int j = 0; j < out_num; j++)
			{
				tmp.at(i) += output_layer.at(j).Get_Hidden_Grad().at(i);
			}
			hidden_layer.at(i).Set_Error_Gradient(tmp.at(i));
			hidden_layer.at(i).Adjustment_Func();
		}
	};
public:
	void Set_desired(vector<int> des)
	{
		desired = des;
	};

	void print_output()
	{
		for (int i = 0; i < out_num; i++)
		{
			cout << output_layer.at(i).Get_Actual_Output() << " ";
		}
	};

	void calculate_mse()//inside for loop for inputs
	{
		for (int i = 0; i < out_num; i++)
		{
			previous_error.at(i) += (output_layer.at(i).Get_Error()*output_layer.at(i).Get_Error());
		}
	};

	void print_mse()
	{
		for (int i = 0; i < out_num; i++)
		{
			cout << previous_error.at(i)/desired.size();
		}
	};

	void reset_mse()
	{
		for (int i = 0; i < out_num; i++)
		{
			previous_error.at(i) = 0;
		}
	};

	float Get_mse(int i)// i represents which output
	{
		mse = previous_error.at(i)/desired.size() ;
		return mse;
	}
};

#endif //BACKPROPAGATION_LAYERS_H
