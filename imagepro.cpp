
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
    std::string input;
    //std::cout<<'Bieeeenvenidos al Himalaya!'<<std::endl;
    std::cout<<'Bienvenido a ImagePro'<<std::endl;
    while(true){
        std::vector<std::string> TheBetterInput;
        std::stringstream checks(input);
        std::string temp;

        std::cout<<'>> '<<std::endl;
        std::cin>>input;
        std::cout<<std::endl;

        while(getline(checks,temp,' ')){
            TheBetterInput.push_back(temp);
        }
        if(input.find('exit')){
            break;
        }
        else if(TheBetterInput[2]=='read'){

        }
        else if(input.find('show ')){

        }
        else if(input.find('getRegions ')){

        }
        else if(input.find('showRegion ')){

        }
        else{
            continue;
        }
    }
}
