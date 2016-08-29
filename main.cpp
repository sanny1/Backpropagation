#include <iostream>
#include "Neuron.h"
#include <cmath>

using namespace std;
using namespace Ann;

//yes it works

int main()
{
	vector<float> mse = {0, 0, 0, 0};
	vector<vector<float>> previous_it(4,vector<float>(2,0));
	vector<vector<float>> previous_it1(4,vector<float>(2,0));
	vector<vector<float>> previous_it2(4,vector<float>(2,0));
	vector<float> inpu = {1, 1};
	vector<float> inpu1 = {0, 1};
	vector<float> inpu2 = {1, 0};
	vector<float> inpu3 = {0, 0};
	vector<vector<float>> inputs = {inpu, inpu1, inpu2, inpu3};
	vector<int> output = {0, 1, 1, 0};
	Neuron *N = new Neuron(inpu.size(), -1);//hidden
	Neuron *N1 = new Neuron(inpu.size(), -1);
	Neuron *O = new Neuron(2, -1);//output
	float sum = 0;
	O->Set_Desired_Output(output);
	for(int j = 0; j < 105000; j++)
	{
//	do
//	{
	sum = 0;
		cout << "[ ";
	for (int i = 0; i < inputs.size(); i++)
	{
		N->Set_input(inputs.at(i));//hidden layer
		N1->Set_input(inputs.at(i));//hidden layer
		N->Activation_Func();
		N1->Activation_Func();
		vector<float> temp_input = {N->Get_Actual_Output(), N1->Get_Actual_Output()};
		O->Set_input(temp_input);
		O->Activation_Func();
		O->Error_Evalutation(i);
//		O->Set_pre_it(previous_it.at(i));
		O->Adjustment_Func();
		N->Set_Error_Gradient(O->Get_Hidden_Grad().at(0));
		N1->Set_Error_Gradient(O->Get_Hidden_Grad().at(1));
//		N->Set_pre_it(previous_it1.at(i));
//		N1->Set_pre_it(previous_it2.at(i));
		N->Adjustment_Func();
		N1->Adjustment_Func();
		cout << O->Get_Actual_Output() << " ";
//		if (O->Get_Actual_Output() > O->Get_Thres())
//		{
//			cout << "1";
//		}
//		else if (O->Get_Actual_Output() <= O->Get_Thres())
//		{
//			cout << "0";
//		}
		mse.at(i) = O->Get_Error();
//		previous_it.at(i) = O->Get_Weight();
//		previous_it1.at(i) = N->Get_Weight();
//		previous_it2.at(i) = N1->Get_Weight();
	}
	cout << "]";
	for (auto &z : O->Get_Hidden_Grad())
	{
		cout << " " << (z);
	}
	for (int i = 0; i < mse.size(); i++)
	{
		sum += (mse.at(i) * mse.at(i));
	}
	cout << " " << sum/4;
	cout << endl;
}
//	} while (sum/4 > 0.001);

//	delete N, N1, O;
	return 0;
}