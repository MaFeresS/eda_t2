
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
    //std::vector<std::string,image::Image*> imagelist;
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
            if(TheBetterInput[0].compare("show")==0){
                //std::cout<<"Hello World4"<<std::endl;
                image::Image* im ; //im = puntero de imagen ya leida, recogida con el TheBetterInput[1]
                im->show();
            }
            else if(TheBetterInput[0].compare("getRegions")==0){
                image::Image* im ; //im = imagen recogida con TheBetterInput[1]
                image::ListOfRegion regions = im->getRegions();
                std::cout<<"La imagen de "<<TheBetterInput[1]<<" tiene "<<regions.getLengthRegion()<<" regiones"<<std::endl;
                image::NodeRegion* nodereg = regions.gethead();
                for(int i=0;i<regions.getLengthRegion();i++){
                    image::Region reg = nodereg->getRegion();
                    std::cout<<"Region "<<i+1<<" -> size "<<reg.getsize()<<std::endl;
                    image::NodeRegion* nodereg = nodereg->getNext();
                }
            }
            else if(TheBetterInput[0].compare("showRegion")==0){
                //TheBetterInput[1]=nombre imagen; THeBetterInput[2]=indice región
                image::Image* im ; //get image
                image::ListOfRegion regions = im->getRegions();
                image::NodeRegion* nodereg = regions.gethead();
                while(nodereg->getNext()!=nullptr){
                    image::Region regi =nodereg->getRegion();
                    if(regi.getID() == stoi(TheBetterInput[2])){
                        //regi.showRegion(height,width); //get height and width
                    }
                }
            }
            else if(TheBetterInput[2].compare("read")==0){
                //std::cout<<"Hello World3"<<std::endl;
                std::string filename(TheBetterInput[3]);
                image::Image* im = nullptr;
                im = image::Image::readImage(filename);
                //codigo que inserte TheBetterInput[0] y im en un vector? clase? nodo?

            }
            else{

            }
        }
        else{
            std::cout<<"Hello World7"<<std::endl;
        }
    }
}
