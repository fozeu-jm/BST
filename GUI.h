//
// Created by kwd on 23/10/2019.
//

#ifndef RECTANGLES_GUI_H
#define RECTANGLES_GUI_H
#include "BST.h"
using namespace std;

class GUI: public GlutWindow {
    BST* bst;
    int insertnumber = 28;
public:
    GUI(BST* tree,int argc,char **argv):GlutWindow(argc,argv,"BST-12",900,900) {
        bst = tree;
    };

    void onStart() override;
    void onDraw() override;
    void onQuit() override;
    void onMouseMove(double cx,double cy) override;
    void onMouseDown(int button,double cx,double cy) override;
    void drawnodes(vector<Node*> &fn,int level,int height);
    void looping();

};

void GUI::onStart() {
    glClearColor(0.9,0.9,0.9,1.0);
}

void GUI::onQuit() {

}

void GUI::onDraw() {

    looping();

    glColor3ub(255,80,67);//red
    fillEllipse(0.9,0.95,0.02,0.02);

    glColor3ub(255,255,255);
    drawText(0.9,0.95-0.006,to_string(insertnumber),ALIGN_CENTER);

}

void GUI::looping() {
    vector<Node*> fn;
    vector<bool> verifs;

    for(int i =0; i < bst->getHeight();i++){
        bst->getNodesAtLvl(bst->getRoot(),i,-1,fn);
        drawnodes(fn,i,bst->getHeight());
        fn.clear();
    }

}

void GUI::drawnodes(vector<Node *> &fn, int level,int height) {


    for(int i = 0; i<fn.size();i++){

        glColor3ub(30,144,255);
        fillEllipse(fn[i]->getX(),fn[i]->getY(),0.02,0.02);

        glColor3ub(255,255,255);
        drawText(fn[i]->getX(),fn[i]->getY()-0.006,to_string(fn[i]->getKey()),ALIGN_CENTER);


        glColor3ub(30,144,255);
        if(fn[i]->getRightChild() != nullptr){
            glColor3ub(30,144,255);
            line(fn[i]->getX(),fn[i]->getY()-0.01,fn[i]->getRightChild()->getX(),fn[i]->getRightChild()->getY());
        }else{
            glColor3ub(255,80,67);//red
            box(fn[i]->getX()+0.0190, fn[i]->getY()-0.008, 0.008, 0.015);
        }

        if(fn[i]->getLeftChild()!=nullptr){
            glColor3ub(30,144,255);
            line(fn[i]->getX(),fn[i]->getY()-0.01,fn[i]->getLeftChild()->getX(),fn[i]->getLeftChild()->getY());
        }else{
            glColor3ub(0,96,76);//green color
            box(fn[i]->getX()-0.027, fn[i]->getY()-0.008, 0.008, 0.015);
        }

    }


    //drawText(0.5,0.1,to_string(15),ALIGN_CENTER);
}

void GUI::onMouseMove(double cx,double cy) {

}

void GUI::onMouseDown(int button, double cx, double cy) {


    double max_X = 0.9+0.02;
    double min_X = 0.9-0.02;

    double max_Y = 0.95+0.02;
    double min_Y = 0.95-0.02;

    if(cx <= max_X && cx>= min_X && cy <= max_Y && cy >= min_Y){
        bst->insert(insertnumber);
        bst->placingNodes();
    }



    Node* node = bst->getNodeInPosition(cx,cy);
    if(node != nullptr){
        cout<<"You just clicked on node "<<node->getKey()<<endl;
        bst->remove(node->getKey());
        bst->placingNodes();
    }else{
        cout<<"Empty space"<<endl;
    }
}

#endif //RECTANGLES_GUI_H
