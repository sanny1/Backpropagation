#include <iostream>
#include "Neuron.h"
#include "Layers.h"
#include "image_saver.h"

using namespace std;
using namespace Ann;

//yes it works
// still needs working on hidden layers for deeper neural networks

int main()
{
	ofstream weights_value("/Users/sanyogchhetri/ClionProjects/Backpropagation/weights_value.txt");
	int stride = 100*100;// image dimension
	// need to be careful can easily input huge number without problem and the program will still run :(
	training_img_saver(3);
	vector<float> inputs = training_img_saver_reder();
	//input {0,0,0,1,1,0,1,1} training_img_saver_reder()
	vector<float> output = {0,1,1};
//	int a = 0;
//	for(int i = 0; i < 3; i++)
//	{
//		output.push_back(a);
//		a = ~a;
//	}
	float sum = 0;
	float check = 0.002;
	int hid = 32;
	int out = 1;
	vector<float> weights;
	Layer<float> *image = new Layer<float>(hid,out,stride);//(hidden, output, stride or how many variables are input)
	unsigned int count = 0;
	image->Set_Input_layer(inputs);
	image->Set_desired(output);
	do
	{
		cout << "[ ";
		image->reset_mse();
		for (int i = 0; i < (inputs.size()/stride); i++)
		{
			image->Hidden_Layer(stride,i);
			image->Output_Layer();
			image->Update(i);
			image->print_output();
			image->calculate_mse();
		}
		cout << "]" << " ";
		image->print_mse();
		sum = image->Get_mse(0);
		if(sum < check)
		{
			weights = image->Get_all_weights();
			for(auto &z: weights)
			{
				weights_value << (float)z << " ";
			}
//			check -= 0.001;
		}
		cout << endl;
		count ++;
	} while (sum > 0.001);
//	validation_img_saver(2);
//	inputs = Validation_img_reder();
//	image->Set_Input_layer(inputs);
//	vector<float> tmp;
//	cout << endl << "validation testing" << endl;
//	for(int i = 0; i < 3;i++)
//	{
//		tmp = weights_reader(i,stride,hid,out);
//		image->Set_weight(tmp);
//		cout << "[ ";
//		for(int j = 0; j < 2;j++)
//		{
//			image->Hidden_Layer(stride, i);
//			image->Output_Layer();
//			image->print_output();
//		}
//		cout << "]";
//	}
	cout << count;
	delete image;
	return 0;
}