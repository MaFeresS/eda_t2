#include "image/image.hpp"
#include "image/listofpoint2d.hpp"
#include "image/listofregion.hpp"
#include "image/point2D.hpp"
#include <fstream>
#include <iostream>
#include <cassert>
#include <cstring>
#include <stack>

namespace image{

    Image::Image(): width(0), height(0), th_value(120), data(nullptr){

    }

    Image::Image(int w, int h): width(w), height(h), th_value(120),  data(nullptr){

    }

    Image::Image(int w, int h, uchar* _data): width(w), height(h), th_value(120), data(_data){
        threshold();
        bool* visited=new bool[w*h];
        std::memset(visited,false,w*h); //setup of visited array, unique per image
    }

    void Image::threshold(){
        if (data != nullptr) {
            for(int i = 0; i < height*width; i++){            
                if (static_cast<int>(data[i]) < th_value){
                    data[i] = static_cast<char>(0);
                }
                else{
                    data[i] = static_cast<char>(1);                    
                }
            }
        }
    }
    
    int Image::getValue(int row, int col){
        int pos = row*width + col;
        return static_cast<int>(data[pos]);
    }

    void Image::show(){
        std::cout << "----------------------" << std::endl;
        std::cout << "size [ (w: " << width << ") x   ( h:" << height << ")]" <<  std::endl;        
        std::cout << "---------------------" << std::endl;
        for(int i = 0 ; i < height ; i++ ){
            for(int j = 0; j < width; j++ ){
                //std::cout<< getValue(i,j) << " "; 
                if (getValue(i,j) == 0) {
                    std::cout<<" ";
                }
                else{
                    std::cout<<"*";
                }
            }
            std::cout<<std::endl;
        }
    }

    Image::~Image(){

    }

    Image* Image::readImage(std::string &path){

        Image* im = nullptr;
        std::ifstream fin(path, std::ios::binary);
        char info[54];
        // read the 54-byte header
        fin.read(info, 54);
        // extract image height and width from header
        int width = *(int*)&info[18];
        int height = *(int*)&info[22];
        short int planes = *(short int*)&info[26];
        short int bits = *(short int*)&info[28];
        int imagesize = *(int*)&info[34];
        int numcolors = *(int*)&info[46];
        assert(info[0]=='B' && info[1] =='M');
        assert(bits == 8);
        // std::cout<< "planes " << planes << std::endl;
        // std::cout<< "bits " << bits << std::endl;
        // std::cout<< "imagesize " << imagesize << std::endl;
        // std::cout<< "numcolors " << numcolors << std::endl;
        // std::cout<< info[0] << info[1] << std::endl;
        //reading colortable
        char  colors[numcolors*4];
        fin.read(colors, numcolors*4);        
        if (imagesize == height * width) {
            char* data = new char[imagesize];
            //read the pixel values
            fin.read(data, imagesize); 
            fin.close();
            char* ordered_data = new char[imagesize];
            //copy data in in a proper order            
            std::cout<< "----------------" <<std::endl;
            for(int i = 0; i < height ; i++){
                std::memcpy(ordered_data + width*i, data + width*(height - 1 - i ), width);
            }                    
            delete[]  data;            
            im = new Image(width, height, reinterpret_cast<uchar*>(ordered_data));        
        }
        assert(im != nullptr);
        return im;
    }

    ListOfRegion Image::getRegions(){
        ListOfRegion regions = ListOfRegion();
        int id=0;
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                if((!getVisited(i,j)) && getValue(i,j)==1){
                    regions.insertLast(regionMaker(j,i,id));
                    id++;
                }
            }
        }
        return regions;
    }

    Region Image::regionMaker(int x, int y, int id){
        Point2D start(x,y);
        ListOfPoint2D points=DFS(start);
        int size=points.getLen();
        Region region(id, size, points);
        std::cout<<"Region "<<id<<" -> size "<<size<<std::endl;
        return region;
    }

    ListOfPoint2D Image::DFS(Point2D start){
        //NodePoint2D startNode(start,nullptr);
        //ListOfPoint2D pointsInRegion(&startNode);
        ListOfPoint2D pointsInRegion = ListOfPoint2D();
        pointsInRegion.insertFirstNode(start);

        std::stack<Point2D> pointStack;
        pointStack.push(start);
        Point2D currentPoint;
        Point2D neighbor;
        int cord[2]={currentPoint.getX(),currentPoint.getY()};
        while(!pointStack.empty()){
            currentPoint=pointStack.top();
            neighbor=DFSfindNeighbor(currentPoint);
            if(neighbor.getX()==-1 && neighbor.getY()==-1){
                pointStack.pop();
            }
            else{
                pointStack.push(neighbor);
                visitPixel(neighbor.getY(),neighbor.getX());
                //add Node to listofPoin2D as Point2D
                pointsInRegion.insertLastNode(neighbor);
            }
        }
        return pointsInRegion;
    }

    bool Image::getVisited(int row, int col){
        int pos = row*width + col;
        return visited[pos];
    }

    void Image::visitPixel(int row, int col){
        int pos = row*width + col;
        visited[pos]=true;
    }

    Point2D Image::DFSfindNeighbor(Point2D current){
        int cord[2]={current.getY(),current.getX()};
        Point2D neighbor = Point2D();
        if((!getVisited(cord[0]-1,cord[1]-1)) && (getValue(cord[0]-1,cord[1]-1)==1)){
            neighbor.setX(cord[0]-1);
            neighbor.setY(cord[1]-1);
        } //check like above for all directions, if neighbor has cord (-1,-1), there is no neighbor.
        else if((!getVisited(cord[0]-1,cord[1])) && (getValue(cord[0]-1,cord[1])==1)){
            neighbor.setX(cord[0]-1);
            neighbor.setY(cord[1]);
        }
        else if((!getVisited(cord[0]-1,cord[1]+1)) && (getValue(cord[0]-1,cord[1]+1)==1)){
            neighbor.setX(cord[0]-1);
            neighbor.setY(cord[1]+1);
        }
        else if((!getVisited(cord[0]+1,cord[1]-1)) && (getValue(cord[0]+1,cord[1]-1)==1)){
            neighbor.setX(cord[0]+1);
            neighbor.setY(cord[1]-1);
        }
        else if((!getVisited(cord[0]+1,cord[1])) && (getValue(cord[0]+1,cord[1])==1)){
            neighbor.setX(cord[0]+1);
            neighbor.setY(cord[1]);
        }
        else if((!getVisited(cord[0]+1,cord[1]+1)) && (getValue(cord[0]+1,cord[1]+1)==1)){
            neighbor.setX(cord[0]+1);
            neighbor.setY(cord[1]+1);
        }
        else if((!getVisited(cord[0],cord[1]-1)) && (getValue(cord[0],cord[1]-1)==1)){
            neighbor.setX(cord[0]);
            neighbor.setY(cord[1]-1);
        }
        else if((!getVisited(cord[0],cord[1]+1)) && (getValue(cord[0],cord[1]+1)==1)){
            neighbor.setX(cord[0]);
            neighbor.setY(cord[1]+1);
        }
        else{
            std::cout<<"no neighbor"<<std::endl;
            neighbor.setX(-1);
            neighbor.setY(-1);
        }
        return neighbor;
    }

    void Image::showRegion(Region region){
        std::cout<<"region "<<region.getID()<<std::endl<<"-----------"<<std::endl;
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                if(region.isPart(j,i)){
                    std::cout<<1;
                }
                else{
                    std::cout<<0;
                }
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
    }

}
