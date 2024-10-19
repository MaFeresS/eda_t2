#include "image/image.hpp"
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
        visited=new bool[w*h];
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

    void Image::makeVisited(){
        visited=new bool[width*height];
        std::memset(visited,false,width*height);
        //std::cout<<visited[0]<<std::endl;
    }
    
    int Image::getValue(int row, int col){
        //std::cout<<"getVAlue"<<std::endl;
        int pos = row*width + col;
        //std::cout<<data[pos];
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
        makeVisited();
        int id=0;
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){;
                if((!getVisited(j,i)) && getValue(j,i)==1){
                    std::cout<<"get4"<<std::endl;
                    regions.insertLast(regionMaker(j,i,id));
                    id++;
                }
            }
        }
        return regions;
    }

    Region Image::regionMaker(int x, int y, int id){
        std::cout<<"regMake"<<std::endl;
        Point2D start(x,y);
        ListOfPoint2D points=DFS(start);
        std::cout<<"DFS made"<<std::endl;
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
        while(!pointStack.empty()){
            currentPoint=pointStack.top();
            neighbor=DFSfindNeighbor(currentPoint);
            //std::cout<<pointStack.size()<<std::endl;
            if(neighbor.getY()==-1 && neighbor.getX()==-1){
                std::cout<<"pop"<<std::endl;
                pointStack.pop();
            }
            else{
                //std::cout<<"push"<<std::endl;
                pointStack.push(neighbor);
                visitPixel(neighbor.getY(),neighbor.getX());
                //add Node to listofPoin2D as Point2D
                pointsInRegion.insertLastNode(neighbor);
            }
        }
        std::cout<<"stackempty"<<std::endl;
        return pointsInRegion;
    }

    bool Image::getVisited(int row, int col){
        int pos = row*width + col;
        //std::cout<<"; position "<<pos;
        return visited[pos];
    }

    void Image::visitPixel(int row, int col){
        int pos = row*width + col;
        visited[pos]=true;
    }

    Point2D Image::DFSfindNeighbor(Point2D current){
        int cord[2]={current.getY(),current.getX()};
        Point2D neighbor;

        //std::cout<<"visited list: "<<visited<<std::endl;
        if(checkIfNeighbor(cord[0]-1,cord[1]-1)){
            neighbor.setX(cord[0]-1);
            neighbor.setY(cord[1]-1);
        } //check like above for all directions, if neighbor has cord (-1,-1), there is no neighbor.
        else if(checkIfNeighbor(cord[0]-1,cord[1])){
            neighbor.setX(cord[0]);
            neighbor.setY(cord[1]-1);
        }
        else if(checkIfNeighbor(cord[0]-1,cord[1]+1)){
            neighbor.setX(cord[0]+1);
            neighbor.setY(cord[1]-1);
        }
        else if(checkIfNeighbor(cord[0]+1,cord[1]-1)){
            neighbor.setX(cord[0]-1);
            neighbor.setY(cord[1]+1);
        }
        else if(checkIfNeighbor(cord[0]+1,cord[1])){
            neighbor.setX(cord[0]);
            neighbor.setY(cord[1]+1);
        }
        else if(checkIfNeighbor(cord[0]+1,cord[1]+1)){
            neighbor.setX(cord[0]+1);
            neighbor.setY(cord[1]+1);
        }
        else if(checkIfNeighbor(cord[0],cord[1]-1)){
            neighbor.setX(cord[0]-1);
            neighbor.setY(cord[1]);
        }
        else if(checkIfNeighbor(cord[0],cord[1]+1)){
            neighbor.setX(cord[0]+1);
            neighbor.setY(cord[1]);
        }
        else{
            std::cout<<"no neighbor"<<std::endl;
            neighbor.setX(-1);
            neighbor.setY(-1);
        }
        return neighbor;
    }

    bool Image::checkIfNeighbor(int y, int x){
        if(0<=x && x<=width && 0<=y && y<=height){
            //std::cout<<"in check"<<std::endl;
            std::cout<<"visited: "<<!getVisited(x,y)<<std::endl;
            std::cout<<"value: "<<getValue(x,y)<<std::endl;
            if((!getVisited(y,x)) && (getValue(y,x)==1)){
                std::cout<<"in nei"<<std::endl;
                return true;
            }
            else{
                return false;
            }
        }
        return false;
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
