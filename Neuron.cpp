//
// Created by Sanyog Chhetri on 18/12/15.
//

#include "Neuron.h"
#include <random>

using namespace Ann;
using namespace std;


Neuron::Neuron(int size,int Bias): actual_output(1,0), weight(size,0), input(size,0), hidden_e_gradient(size,0)
{
	default_random_engine generator(rand());
	uniform_real_distribution<float> wei(0,3.4);//0 to 2.4 distribution seems to work better than 0 1
	for(int i = 0; i < size; i++)
	{
		weight.at(i) = wei(generator);
	}
	threshold = 0.7;
	//changing the threshold makes it easier for the neural network to calculate
	//wei(generator) this creates a threshold for every neuron
	//0.7 was the right threshold for the program to run
	bias = Bias;//not being used
	learning_rate = 0.3;//0.3 seems to output the fastest in this set up
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
	for(int i = 0; i < input.size(); i++)
	{
		sum += (input.at(i)*weight.at(i))- threshold;
		//	sum += bias*(weight.at(0));
	}
	actual_output.at(0) = 1/(1+exp(-sum));//haven't initialised however many outputs
//	cout << " This is actual "
//	<< actual_output.at(0) << endl;
}

void Neuron::Error_Evalutation(int i)
{
	error = desired_output.at(i)-actual_output.at(0);
	error_gradient = actual_output.at(0)*(1-actual_output.at(0))*error;
	float sum = 0;
	for(int j = 0; j < 2; j++)
	{
		sum += weight.at(j)*error_gradient;
	}
	for(int k = 0; k < input.size(); k++)
		hidden_e_gradient.at(k) = input.at(k)*(1-input.at(k))*sum;
//	cout << " this is error " << error_gradient << endl;
}

void Neuron::Adjustment_Func()
{
	fak_weig = weight;
	for(int i = 0; i < weight.size(); i++)
	{
		fak_weig.at(i) = ((learning_rate*input.at(i)*error_gradient)+(0.0*pre_it.at(i))) ;
		weight.at(i) +=fak_weig.at(i);
	}
}

vector<float> Neuron::Get_Weight()
{
	return fak_weig;
}

void Neuron::Set_Error_Gradient(float error_grad)
{
	error_gradient = error_grad;
}

vector<float> Neuron::Get_Hidden_Grad()
{
	return hidden_e_gradient;
}

void Neuron::Set_Desired_Output(vector<int> desired)
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

