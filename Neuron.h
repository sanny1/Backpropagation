//
// Created by Sanyog Chhetri on 18/12/15.
//

#ifndef BACKPROPAGATION_NEURON_H
#define BACKPROPAGATION_NEURON_H

#include <iostream>
#include <vector>

using namespace std;

namespace Ann
{
	class Neuron
	{
	private:
		float threshold;
		vector<float> input;
		vector<float> desired_output;
		vector<float> actual_output;
		vector<float> weight;
		vector<float> pre_it;
		vector<float> fak_weig;
	private:
		float error;
		float learning_rate;
		float error_gradient;
		vector<float> hidden_e_gradient;
		int bias;

	public:
		Neuron();
		Neuron(int size, int bias);
		virtual ~Neuron();
		void Activation_Func();
		void Error_Evalutation(int i);
		void Adjustment_Func();
	public:
		void Set_input(vector<float> input);
		void Set_Desired_Output(vector<float> desired);
		void Set_weight(vector<float> weig);
		int Get_Input_Size();
		vector<float> Get_input();
		void Set_Error_Gradient(float error_grad);
		vector<float> Get_Hidden_Grad();
		float Get_Actual_Output(); // change this to vector
		float Get_Error();
		float Get_Thres();
		vector<float> Get_Weight();
		void Set_pre_it(vector<float> pre);
	};
}


#endif //BACKPROPAGATION_NEURON_H
