
#include "image/image.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <map>
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
    std::map<std::string, image::Image> imageDic;
    std::cout<<"Bienvenido a ImagePro"<<std::endl;
    while(true){
        std::string input;

        std::cout<<">> ";
        getline(std::cin,input);
        std::cout<<std::endl;
        std::vector<std::string> TheBetterInput;
        std::stringstream check(input);
        std::string temp;

        //std::cout<<"Hello World1"<<std::endl;

        while(getline(check,temp,' ')){
            TheBetterInput.push_back(temp);
        }
        //std::cout<<TheBetterInput.size()<<std::endl;
        if(TheBetterInput[0].compare("exit")==0){
            std::cout<<TheBetterInput[0]<<std::endl;
            break;
        }
        else if(TheBetterInput.size()>1){
            if(TheBetterInput[0].compare("show")==0 && !imageDic.empty()){
                //std::cout<<"Hello World4"<<std::endl;
                image::Image* im=&(imageDic.at(TheBetterInput[1])); //im = puntero de imagen ya leida, recogida con el TheBetterInput[1]
                im->show();
            }
            else if(TheBetterInput[0].compare("getRegions")==0 && !imageDic.empty()){
                std::cout<<"gR1"<<std::endl;
                image::Image* im=&(imageDic.at(TheBetterInput[1])); //im = imagen recogida con TheBetterInput[1]
                std::cout<<"gR2"<<std::endl;
                image::ListOfRegion regions = im->getRegions();
                std::cout<<"gR3"<<std::endl;
                std::cout<<"La imagen de "<<TheBetterInput[1]<<" tiene "<<regions.getLengthRegion()<<" regiones"<<std::endl;
                image::NodeRegion* nodereg = regions.gethead();
                std::cout<<"gR4"<<std::endl;
                /*for(int i=0;i<regions.getLengthRegion();i++){
                    image::Region reg = nodereg->getRegion();
                    std::cout<<"Region "<<i+1<<" -> size "<<reg.getsize()<<std::endl;
                    image::NodeRegion* nodereg = nodereg->getNext();
                }*/
            }
            else if(TheBetterInput[0].compare("showRegion")==0 && !imageDic.empty()){
                //TheBetterInput[1]=nombre imagen; THeBetterInput[2]=indice región
                image::Image* im=&(imageDic.at(TheBetterInput[1])); //get image
                image::ListOfRegion regions = im->getRegions(); //podriamos hacer esto solo si detectamos que las regiones no fueron creadas, eficiencia, no necesidad.
                image::NodeRegion* nodereg = regions.gethead();
                while(nodereg->getNext()!=nullptr){
                    image::Region regi =nodereg->getRegion();
                    if(regi.getID() == stoi(TheBetterInput[2])){
                        im->showRegion(regi);
                        break;
                    }
                    else{
                        nodereg = nodereg->getNext();
                    }
                }
            }
            else if(TheBetterInput[2].compare("read")==0){
                //std::cout<<"Hello World3"<<std::endl;
                std::string filename(TheBetterInput[3]);
                image::Image* im = image::Image::readImage(filename);
                //im = image::Image::readImage(filename);
                imageDic[TheBetterInput[0]]=*im;
                //codigo que inserte TheBetterInput[0] y im en un vector? clase? nodo?

            }
            else{
                std::cout<<"Comando invalido o falta de imagen."<<std::endl;
            }
        }
        else{
            
        }
    }
}
