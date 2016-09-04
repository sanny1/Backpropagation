//
// Created by Sanyog Chhetri on 18/12/15.
//

#include "Neuron.h"
#include <random>

using namespace Ann;
using namespace std;


Neuron::Neuron(int size, int Bias) : actual_output(1, 0), weight(size + 1, 0), input(size, 0),
                                     hidden_e_gradient(size, 0)
{
	default_random_engine generator(rand());
	uniform_real_distribution<float> wei(-0.5,0.5);
	for (int i = 0; i < (size + 1); i++)
	{
		weight.at(i) = wei(generator);
	}
	threshold = 0.7;
	bias = Bias;//bais is what was needed to help me
	learning_rate = 0.1;//0.3 seems to output the fastest in this set up
	// learning rate changes the speed but comes at a price of
	// missing the right value and might skip it
}

Neuron::~Neuron()
{
}

void Neuron::Set_input(vector<float> inputs)
{
	input = inputs;
}

int Neuron::Get_Input_Size()
{
	return input.size();
}

void Neuron::Activation_Func()
{
	float sum = 0;
	for (int i = 0; i < (input.size()); i++)//change this and the error gradient function for better
	{
		sum += (input.at(i) * weight.at(i+1));
		//	sum += bias*(weight.at(0));
	}
	sum += bias * weight.at(0);
	actual_output.at(0) = (2 / (1 + exp(-sum)))-1;//haven't initialised however many outputs
//	cout << " This is actual "
//	<< actual_output.at(0) << endl;
}

void Neuron::Error_Evalutation(int i)
{
	error = desired_output.at(i) - actual_output.at(0);
	error_gradient = (1 - (actual_output.at(0)*actual_output.at(0))) * error;
	float sum = 0;
//	for(int j = 0; j < input.size(); j++)
//	{
//		sum += weight.at(j)*error_gradient;
//	}
//	sum = sum/input.size();
	for (int k = 0; k < input.size(); k++)
		hidden_e_gradient.at(k) = (1 - (input.at(k)*input.at(k))) * weight.at(k + 1) * error_gradient;
//	cout << " this is error " << error_gradient << endl;
}

// remember to implement momentum you need to add change in weigh member as well
// this is so you can store the weigh change and add it in the future iteration
void Neuron::Adjustment_Func()
{
	fak_weig = weight;
	for (int i = 0; i < weight.size(); i++)
	{
		if (i == 0)
		{
			weight.at(i) += learning_rate * bias * error_gradient;
		}
		else
		{
			fak_weig.at(i) = ((learning_rate * input.at(i-1) * error_gradient));
			weight.at(i) += fak_weig.at(i);
		}
	}
}

vector<float> Neuron::Get_Weight()
{
	return weight;
}

void Neuron::Set_Error_Gradient(float error_grad)
{
	error_gradient = error_grad;
}

vector<float> Neuron::Get_Hidden_Grad()
{
	return hidden_e_gradient;
}

void Neuron::Set_Desired_Output(vector<float> desired)
{
	desired_output = desired;
}

float Neuron::Get_Actual_Output()
{
	return actual_output.at(0);
}

float Neuron::Get_Error()
{
	return error;
}

float Neuron::Get_Thres()
{
	return threshold;
}

void Neuron::Set_pre_it(vector<float> pre)
{
	pre_it = pre;
}

void Neuron::Set_weight(vector<float> weig)
{
	weight = weig;
}

