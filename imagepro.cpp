
#include "image/image.hpp"
#include <iostream>
#include <string>
#include <vector>
#include<bits/stdc++.h>



int main(int nargs, char** vargs){
    /*std::string filename("images/image_1.bmp");
    std::cout << filename << std::endl;
    image::Image* im = nullptr;
    im = image::Image::readImage(filename);
    im->show();
    return 0;*/
    //std::cout<<'Bieeeenvenidos al Himalaya!'<<std::endl;
    std::cout<<"Bienvenido a ImagePro"<<std::endl;
    while(true){
        std::string input;

        std::cout<<">> ";
        getline(std::cin,input);
        std::cout<<std::endl;
        std::vector<std::string> TheBetterInput;
        std::stringstream check(input);
        std::string temp;
        std::cout<<"Hello World1"<<std::endl;
        while(getline(check,temp,' ')){
            TheBetterInput.push_back(temp);
        }
        //std::cout<<TheBetterInput.size()<<std::endl;
        if(TheBetterInput[0].compare("exit")==0){
            std::cout<<TheBetterInput[0]<<std::endl;
            break;
        }
        else if(TheBetterInput.size()>1){
            if(TheBetterInput[2].compare("read")==0){
                std::cout<<"Hello World3"<<std::endl;
            }
            else if(TheBetterInput[0].compare("show")==0){
                std::cout<<"Hello World4"<<std::endl;
            }
            else if(TheBetterInput[0].compare("getRegions")==0){
                std::cout<<"Hello World5"<<std::endl;
            }
            else if(TheBetterInput[0].compare("showRegion")==0){
                std::cout<<"Hello World6"<<std::endl;
            }
            else{

            }
        }
        else{
            std::cout<<"Hello World7"<<std::endl;
        }
    }
}
