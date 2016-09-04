//
// Created by Sanyog Chhetri on 02/09/16.
//

#ifndef BACKPROPAGATION_IMAGE_SAVER_H
#define BACKPROPAGATION_IMAGE_SAVER_H

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/types_c.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <fstream>
#include <vector>

void training_img_saver(int a);
void validation_img_saver(int a);
std::vector<float> training_img_saver_reder();
std::vector<float> Validation_img_reder();
std::vector<float> weights_reader(int a,int inputs,int hid_num, int out_num);

#endif //BACKPROPAGATION_IMAGE_SAVER_H
