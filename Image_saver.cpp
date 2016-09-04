//
// Created by Sanyog Chhetri on 02/09/16.
//

#include "Image_saver.h"

using namespace std;
using namespace cv;

void training_img_saver(int a)
{
	char name[100];
	float value = 0;
	ofstream imgs_arr("/Users/sanyogchhetri/ClionProjects/Backpropagation/imgs_arr.txt");
	for(int i = 1; i <= a; i++)
	{
		// seem it doesn't notify me when the file doesn't exist need to add if loop with exit
		sprintf(name, "/Users/sanyogchhetri/ClionProjects/Backpropagation/Images/Shirts/Validation_data/Shirt%d.png", i);
		Mat src = imread(name,CV_LOAD_IMAGE_GRAYSCALE);
		for(int j = 0; j < src.cols; j++)
		{
			for(int k = 0; k < src.rows; k++)
			{
				value = float(src.at<uint8_t>(j,k))/255;
				imgs_arr << value << " ";
			}
		}
	}
	imgs_arr.close();
}

vector<float> training_img_saver_reder()//can change it to template function
{
	vector<float> tmp;
	float value = 0;
	ifstream img_readr("/Users/sanyogchhetri/ClionProjects/Backpropagation/imgs_arr.txt");
	while(!img_readr.eof())
	{
		img_readr >> value;
		tmp.push_back(value);
	}
	return tmp;
}

vector<float>weights_reader(int a,int inputs,int hid_num, int out_num)
{
	vector<float> tmp(0,0);
	float value = 0;
	ifstream weightsreader("/Users/sanyogchhetri/ClionProjects/Backpropagation/weights_value.txt");
	while(!weightsreader.eof())
	{
		weightsreader >> value;
		tmp.push_back(value);
	}
	auto first = tmp.begin()+(((inputs*hid_num)+(out_num*hid_num)+hid_num+out_num)*a);
	auto last = tmp.begin()+(((inputs*hid_num)+(out_num*hid_num)+hid_num+out_num)*(a+1));
	vector<float> tmp_tmp(first,last);
	return tmp_tmp;
}

void validation_img_saver(int a)
{
	char name[100];
	float value = 0;
	ofstream imgs_arr("/Users/sanyogchhetri/ClionProjects/Backpropagation/Val_imgs_arr.txt");
	for(int i = 1; i <= a; i++)
	{
		// seem it doesn't notify me when the file doesn't exist need to add if loop with exit
		sprintf(name, "/Users/sanyogchhetri/ClionProjects/Backpropagation/Images/Shirts/Testing_data/Shirts%d.png", i);
		Mat src = imread(name,CV_LOAD_IMAGE_GRAYSCALE);
		for(int j = 0; j < src.cols; j++)
		{
			for(int k = 0; k < src.rows; k++)
			{
				value = (float)(src.at<uchar>(j,k))/255;
				imgs_arr << value << " ";
			}
		}
	}
	imgs_arr.close();
}

vector<float> Validation_img_reder()//can change it to template function
{
	vector<float> tmp;
	float value = 0;
	ifstream img_readr("/Users/sanyogchhetri/ClionProjects/Backpropagation/Val_imgs_arr.txt");
	while(!img_readr.eof())
	{
		img_readr >> value;
		tmp.push_back(value);
	}
	return tmp;
}