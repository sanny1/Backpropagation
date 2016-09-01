#include <iostream>
#include "Neuron.h"
#include "Layers.h"

using namespace std;
using namespace Ann;

//yes it works

int main()
{
	vector<float> mse = {0, 0, 0, 0};
	vector<float> mse2 = {0, 0, 0, 0};
//	vector<vector<float>> previous_it(4, vector<float>(2, 0));
//	vector<vector<float>> previous_it1(4, vector<float>(2, 0));
//	vector<vector<float>> previous_it2(4, vector<float>(2, 0));
//	vector<float> inpu = {1, 1};
//	vector<float> inpu1 = {0, 1};
//	vector<float> inpu2 = {1, 0};
//	vector<float> inpu3 = {0, 0};
	vector<float> inputs = {0,0,0,1,1,0,1,1};
	vector<int> output = {0, 1, 1, 0};
	vector<int> output2 = {0,0,1,1};
//	Neuron *N = new Neuron(inpu.size(), -1);//hidden
//	Neuron *N1 = new Neuron(inpu.size(), -1);
//	Neuron *O = new Neuron(2, -1);//output
//	Neuron *O2 = new Neuron(2, -1);//output
	float sum = 0;
	float summ = 0;
	float temp_hid = 0;
//	O->Set_Desired_Output(output);
//	O2->Set_Desired_Output(output2);
	int stride = 2;
	Layer<float> *image = new Layer<float>(2,1,stride);//(hidden, output, stride or how many variables are input)

	unsigned int count = 0;
	image->Set_Input_layer(inputs);
	image->Set_desired(output);
//	{
//		for(int j = 0; j < 105000; j++)
	do
	{
		sum = 0;
		summ = 0;
		cout << "[ ";
		image->reset_mse();
		for (int i = 0; i < (inputs.size()/stride); i++)
		{
			image->Hidden_Layer(stride,i);
			image->Output_Layer(i);
			image->Update();
			image->print_output();
			image->calculate_mse();
		}
		cout << "]" << " ";
		image->print_mse();
		sum = image->Get_mse(0);
//		for (auto &z : O->Get_Hidden_Grad())
//		{
//			cout << " " << (z);
//		}
//		for (int i = 0; i < mse.size(); i++)
//		{
//			sum += (mse.at(i) * mse.at(i));
//		}
//		for (int i = 0; i < mse2.size(); i++)
//		{
//			summ += (mse2.at(i) * mse2.at(i));
//		}
//		cout << " " << sum / 4;
//		cout << " " << summ/4;
		cout << endl;
		count ++;
//}
	} while (sum > 0.001);
	cout << count;
//	delete N, N1, O;
	return 0;
}