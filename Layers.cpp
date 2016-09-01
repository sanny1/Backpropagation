//
// Created by Sanyog Chhetri on 31/08/16.
//

#include "Layers.h"

//template <typename typ>
//Layer<typ>::Layer(int hidden, int out, int input): hidden_layer(hidden,Neuron(input,-1)), output_layer(out,Neuron(hidden,-1)),previous_error(out,0)
//{
//	num_hid = hidden;
//	out_num = out;
//}
//
//template <typename typ>
//void Layer<typ>::Set_Input_layer(vector<typ> inpu)
//{
//	inputs = inpu;
//}
//
//template <typename typ>
//void Layer<typ>::Hidden_Layer(int stride,int locson)// locson will be the i in the main.cpp
//{
//	auto first = inputs.begin() + (stride*locson);
//	auto last = inputs.begin() + (stride*(locson+1));
//	vector<typ> tmp(first,last);
//	for(int i = 0; i < num_hid;i++)
//	{
//		hidden_layer.at(i).Set_input(tmp);
//		hidden_layer.at(i).Activation_Func();
//	}
//}
//
//template <typename typ>
//void Layer<typ>::Set_desired(vector<int> des)
//{
//	desired = des;
//}
//
//template <typename typ>
//void Layer<typ>::Output_Layer(int desi)//desi is the current the request from the main to select the desired output
//{
//	vector<float> tmp(num_hid,0);
//	for(int i = 0; i < out_num;i++)
//	{
//		output_layer.at(i).Set_Desired_Output(desired);
//		for(int j = 0; j < num_hid; j++)
//		{
//			tmp.at(j) = hidden_layer.at(j).Get_Actual_Output();
//		}
//		output_layer.at(i).Set_input(tmp);
//		output_layer.at(i).Activation_Func();
//		output_layer.at(i).Error_Evalutation(desi);
//	}
//}
//
//template <typename typ>
//void Layer<typ>::Update()
//{
//	vector<float> tmp(out_num,0);
//	for(int i = 0; i < out_num; i++)
//	{
//		output_layer.at(i).Adjustment_Func();
//	}
//	for(int i = 0; i < num_hid; i ++)
//	{
//		for(int j = 0; j < out_num; j++)
//		{
//			tmp.at(i) += output_layer.at(j).Get_Hidden_Grad().at(i);
//		}
//		hidden_layer.at(i).Set_Error_Gradient(tmp.at(i));
//		hidden_layer.at(i).Adjustment_Func();
//	}
//}
//
//template <typename typ>
//void Layer<typ>::print_output()
//{
//	for(int i = 0; i < out_num; i++)
//	{
//		cout << output_layer.at(i).Get_Actual_Output();
//	}
//}
//
//template <typename typ>
//void Layer<typ>::calculate_mse()
//{
//	for(int i = 0; i < out_num; i++)
//	{
//		previous_error.at(i) += output_layer.at(i).Get_Error();
//	}
//}
//
//template <typename typ>
//void Layer<typ>::print_mse()
//{
//	for(int i = 0; i < out_num; i++)
//	{
//		cout << previous_error.at(i);
//	}
//}
//
//template <typename typ>
//void Layer<typ>::reset_mse()
//{
//	for(int i = 0; i < out_num; i++)
//	{
//		previous_error.at(i) = 0;
//	}
//}
