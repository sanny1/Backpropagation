//
// Created by Sanyog Chhetri on 31/08/16.


#include "Layers.h"
// currently no point in doing template it seems as I need to make the neuron.cpp as welflexible
template<typename typ>
Layer<typ>::Layer(int hidden, int out, int input) : hidden_layer(hidden, Neuron(input, -1)),
                                                    output_layer(out, Neuron(hidden, -1)), previous_error(out, 0),reset_vect(0,0)
{
	num_hid = hidden;
	out_num = out;
	inps = input;
}

template<typename typ>
void Layer<typ>::Set_Input_layer(vector<typ> inpu)
{
	inputs = inpu;
}

template<typename typ>
void Layer<typ>::Hidden_Layer(int stride, int locson)// locson will be the i in the main.cpp
{
	auto first = inputs.begin() + (stride * locson);
	auto last = inputs.begin() + (stride * (locson + 1));
	vector<typ> tmp(first, last);
	for (int i = 0; i < num_hid; i++)
	{
		hidden_layer.at(i).Set_input(tmp);
		hidden_layer.at(i).Activation_Func();
	}
}

template<typename typ>
void Layer<typ>::Set_desired(vector<float> des)
{
	desired = des;
	for (int i = 0; i < out_num; i++)
	{
		auto first = desired.begin() + (i * (desired.size() / out_num));
		auto last = desired.begin() + ((i + 1) * (desired.size() / out_num));
		vector<float> tmp(first, last);
		output_layer.at(i).Set_Desired_Output(tmp);
	}
}

template<typename typ>
void Layer<typ>::Output_Layer()//desi is the current the request from the main to select the desired output
{
	vector<float> tmp(num_hid, 0);
	for (int i = 0; i < out_num; i++)
	{
		for (int j = 0; j < num_hid; j++)
		{
			tmp.at(j) = hidden_layer.at(j).Get_Actual_Output();
		}
		output_layer.at(i).Set_input(tmp);
		output_layer.at(i).Activation_Func();
	}
}

template<typename typ>
void Layer<typ>::Update(int desi)
{
	vector<float> tmp(num_hid, 0);
	for (int i = 0; i < out_num; i++)
	{
		output_layer.at(i).Error_Evalutation(desi);
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
}

template<typename typ>
void Layer<typ>::print_output()
{
	for (int i = 0; i < out_num; i++)
	{
		cout << output_layer.at(i).Get_Actual_Output() << " ";
	}
}

template<typename typ>
void Layer<typ>::calculate_mse()
{
	for (int i = 0; i < out_num; i++)
	{
		previous_error.at(i) += (output_layer.at(i).Get_Error() * output_layer.at(i).Get_Error());
	}
}

template<typename typ>
void Layer<typ>::print_mse()
{
	for (int i = 0; i < out_num; i++)
	{
		cout << previous_error.at(i) / desired.size() << " ";
	}
}

template<typename typ>
void Layer<typ>::reset_mse()
{
	for (int i = 0; i < out_num; i++)
	{
		previous_error.at(i) = 0;
	}
}

template<typename typ>
float Layer<typ>::Get_mse(int i)
{
	mse = previous_error.at(i) / desired.size();
	return mse;
}

template<typename typ>
vector<float> Layer<typ>::Get_all_weights()
{
	weights = reset_vect;
	vector<float> tmp(0,0);
	for(int j = 0; j < num_hid; j ++)
	{
		tmp = hidden_layer.at(j).Get_Weight();
		weights.insert(weights.end(),tmp.begin(),tmp.end());
	}
	for(int j = 0; j < out_num; j ++)
	{
		tmp = output_layer.at(j).Get_Weight();
		weights.insert(weights.end(),tmp.begin(),tmp.end());
	}
	return weights;
}

template <typename typ>// only chunks of weigh can be transfered.
void Layer<typ>::Set_weight(vector<float> weig)
{
	for(int i = 0; i < num_hid; i++)
	{
		auto first = weig.begin() + ((inps+1)*i);
		auto last = weig.begin() + ((inps+1)*(i+1)+1);
		vector<float> tmp(first,last);
		hidden_layer.at(i).Set_weight(tmp);
	}
	for(int i = 0; i < out_num; i++)
	{
		auto first = weig.begin() + ((inps*num_hid)+(i*(num_hid+1)));
		auto last = weig.begin() + ((inps*num_hid)+((i+1)*(num_hid+1)));
		vector<float> tmp(first,last);
		output_layer.at(i).Set_weight(tmp);
	}
}

template class Layer<float>;