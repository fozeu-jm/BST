//
// Created by kwd on 17/10/2019.
//

#ifndef BST_EX11_BST_H
#define BST_EX11_BST_H

using namespace std;

#include <vector>
#include <algorithm>
#include "Nodes.h"
#include <cmath>

class BST{
Node* root;
public:
    BST(Node* rt):root(rt){

    }
    BST():root(nullptr){}

    bool insert(int k){
        if(findKey(k)){
            return false;
        }else{
            place(new Node(k),root);
            return true;
        }
    }

    template <typename T, size_t N>
    int inserts(T (&tabKey)[N]){
        if(root!= nullptr){
            for(int i =0; i<N; i++){
                insert(tabKey[i]);
            }
        }else{
            setRoot(new Node(tabKey[0]));
            for(int i =0; i<N; i++){
                insert(tabKey[i]);
            }
        }

        return 0;
    }

    void place(Node* item, Node* parent){

            if(item->getKey() > parent->getKey()){
                if(parent->getRightChild() == nullptr){
                    parent->setRightChild(item);
                    item->setParent(parent);
                }else{
                    place(item,parent->getRightChild());
                }
            }else{
                    if(parent->getLeftChild() == nullptr){
                        parent->setLeftChild(item);
                        item->setParent(parent);
                    }else{
                        place(item,parent->getLeftChild());
                    }
            }
    }

    Node *getRoot() const {
        return root;
    }

    void setRoot(Node *root) {
        BST::root = root;
    }

    void DFT_print(){
        Node* right = root->getRightChild();//  25
        Node* left = root->getLeftChild();//  8
        std::vector<int> leftbranch;
        std::vector<int> rightbranch;
        add_leftRight(left,leftbranch);
        sort(leftbranch.begin(),leftbranch.end());

        add_leftRight(right,rightbranch);
        sort(rightbranch.begin(),rightbranch.end());

        for(int k : leftbranch){
            cout<<"("<<k<<")"<<endl;
        }
        cout<<"("<<root->getKey()<<")"<<endl;

        for(int k : rightbranch){
            cout<<"("<<k<<")"<<endl;
        }
    }

    void add_leftRight(Node* node,vector<int> &branch){
        branch.push_back(node->getKey());
        if(node->getLeftChild() != nullptr){
            add_leftRight(node->getLeftChild(),branch);
        }

        if(node->getRightChild() != nullptr){
            add_leftRight(node->getRightChild(),branch);
        }
    }

    int nbNodes(){
        int nbNodes = 0;
        counting(root,nbNodes);
        return nbNodes;
    }

    void counting(Node* node, int &count){
        count++;
        if(node->getLeftChild() != nullptr){
            counting(node->getLeftChild(),count);
        }

        if(node->getRightChild() != nullptr){
            counting(node->getRightChild(),count);
        }
    }

    int getHeight(){
        int maxheight= -1;
        calculateHeight(root,-1,maxheight);
        return maxheight=maxheight+1;
    }

    void calculateHeight(Node* node,int parent_height,int &maxheight){
        bool found = true;

        if(parent_height+1 > maxheight){
            maxheight = parent_height+1;
        }

        if(node->getLeftChild() != nullptr){
            parent_height = parent_height + 1;
            calculateHeight(node->getLeftChild(),parent_height,maxheight);
        }else{
            found=false;
        }

        if(node->getRightChild() != nullptr){
            if(!found){
                parent_height = parent_height + 1;
            }
            calculateHeight(node->getRightChild(),parent_height,maxheight);
        }else{
        }
    }

    int getNbChildrenAtLevel(int level){
        int nbChildern=0;
        levelling(root,level,-1,nbChildern);
        return nbChildern;
    }



    void levelling(Node* node,int levelRQ,int parent_height,int &count){
        bool found = true;

        if(parent_height+1 == levelRQ){
            count++;
            //cout<<"Node at level "<<levelRQ<<" with parent level: "<<parent_height<<" ==> "<<node->getKey()<<"=====>"<<node->getParent()->getKey()<<endl;

        }

        if(node->getLeftChild() != nullptr){
            parent_height = parent_height + 1;
            levelling(node->getLeftChild(),levelRQ,parent_height,count);
        }else{
            found=false;
        }

        if(node->getRightChild() != nullptr){
            if(!found){
                parent_height = parent_height + 1;
            }
            levelling(node->getRightChild(),levelRQ,parent_height,count);
        }else{
        }

    }

    bool isBST(){
        bool letfverif= true;
        bool rightverif= true;
        verify_leftbranches(root,letfverif);
        verify_rightbranches(root,rightverif);
        if(letfverif && rightverif){
            return true;
        }else{
            return false;
        }
    }

    void verify_leftbranches(Node* node,bool &leftverif){
        if(node->getLeftChild() != nullptr){
            if(node->getKey() <= root->getKey()) {
                if ( node->getLeftChild()->getKey() < node->getKey() && node->getLeftChild()->getKey() < root->getKey() ) {
                    verify_leftbranches(node->getLeftChild(), leftverif);
                } else {
                    leftverif = false;
                }
            }else{

                if( node->getLeftChild()->getKey() < node->getKey() && node->getLeftChild()->getKey() > root->getKey() ) {
                    verify_leftbranches(node->getLeftChild(), leftverif);
                }else{
                    leftverif = false;
                }
            }
        }
        if(node->getRightChild() != nullptr){
            verify_leftbranches(node->getRightChild(),leftverif);
        }
    }

    void verify_rightbranches(Node* node, bool &rightverif){

        if(node->getLeftChild() != nullptr){
            verify_rightbranches(node->getLeftChild(),rightverif);
        }

        if(node->getRightChild() != nullptr){
            if(node->getKey() >= root->getKey()){
                if(node->getRightChild()->getKey() > node->getKey() && node->getRightChild()->getKey() > root->getKey() ){
                    verify_rightbranches(node->getRightChild(),rightverif);
                }else{
                    rightverif = false;
                }
            }else{
                if(node->getRightChild()->getKey() > node->getKey() && node->getRightChild()->getKey() < root->getKey() ) {
                    verify_rightbranches(node->getRightChild(), rightverif);
                }else{
                    rightverif = false;
                }
            }

        }
    }

    bool findKey(int k){
        bool found = false;
        finder(root,k,found);
        return found;
    }

    Node*find(int k){
        Node* node = nullptr;
        finding(root,k,node);
        return ( ( node != nullptr ) ?  node :  nullptr );
    }

    void finding(Node* node, int value,Node* &knot){
        if(node->getKey()==value){
            knot = node;
        }else{
            if(node->getLeftChild() != nullptr){
                finding(node->getLeftChild(),value,knot);
            }

            if(node->getRightChild() != nullptr){
                finding(node->getRightChild(),value,knot);
            }
        }
    }

    void finder(Node* node, int value, bool &found){
        if(node->getKey()==value){
            found=true;
        }else{
            if(node->getLeftChild() != nullptr){
                finder(node->getLeftChild(),value,found);
            }

            if(node->getRightChild() != nullptr){
                finder(node->getRightChild(),value,found);
            }
        }
    }


    void replacer(Node* node, int value,int newer){
        if(node->getKey()==value){
            node->setKey(newer);
        }else{
            if(node->getLeftChild() != nullptr){
                replacer(node->getLeftChild(),value,newer);
            }

            if(node->getRightChild() != nullptr){
                replacer(node->getRightChild(),value,newer);
            }
        }
    }

    bool isFull(){
        bool verifier = true;
        full_verifier(root,verifier);
        return verifier;
    }

    void full_verifier(Node* node, bool &verifier){
        if(node->getRightChild() != nullptr && node->getLeftChild() != nullptr){
            if(node->getLeftChild() != nullptr){
                full_verifier(node->getLeftChild(),verifier);
            }

            if(node->getRightChild() != nullptr){
                full_verifier(node->getRightChild(),verifier);
            }
        }else{
            verifier=false;
        }
    }

    bool isComplete(){
        int h = getHeight();
        bool lvl_verif = true;
        for(int i=0;i<h-1;i++){
            int chld_lvl = getNbChildrenAtLevel(i);
            if(pow(2, i)!=chld_lvl){
                lvl_verif= false;
                break;
            }
        }
        if(lvl_verif){
            vector<Node*> fn;
            vector<bool> verifs;
            getNodesAtLvl(root,h-2,-1,fn);
            for(Node* item : fn){
                if( item->getRightChild()!= nullptr ){
                    verifs.push_back(true);
                }
                if( item->getLeftChild() != nullptr ){
                    verifs.push_back(true);
                }
                if(item->getLeftChild() == nullptr && item->getRightChild()== nullptr ){
                    verifs.push_back(false);
                }
            }
            int test = -1;
            complete_verif(verifs,0,test);
            if(test==404){
                return false;
            }else{
                return true;
            }
        }else{
            return false;
        }
    }

    void complete_verif(vector<bool> &verifs,int i,int &test){

        if(test == 0){
            if(verifs[i] == false){
                complete_verif(verifs,i=i+1, test);
            }else{
                test = 404;
            }
        }else{
            if(verifs[i] == false ){
                test = 0;
                complete_verif(verifs,i=i+1, test);
            }else{
                complete_verif(verifs,i=i+1, test);
            }
        }
    }

    void getNodesAtLvl(Node* node,int levelRQ,int parent_height,vector<Node*> &fn ){
        bool found = true;

        if(parent_height+1 == levelRQ){
            fn.push_back(node);
        }

        if(node->getLeftChild() != nullptr){
            parent_height = parent_height + 1;
            getNodesAtLvl(node->getLeftChild(),levelRQ,parent_height,fn);
        }else{
            found=false;
        }

        if(node->getRightChild() != nullptr){
            if(!found){
                parent_height = parent_height + 1;
            }
            getNodesAtLvl(node->getRightChild(),levelRQ,parent_height,fn);
        }else{
        }
    }

    void remove(int k){
        if(find(k)->getParent() != nullptr){
            bool it_exist = findKey(k);
            if(it_exist){
                remover(root,k);
            }
        }
    }

    void remover(Node* node,int value){
        if(node->getKey()==value){
            /************************another case*******************************************/
            if(node->getRightChild() == nullptr && node->getLeftChild() == nullptr){
                Node* parent = node->getParent();

                if(parent->getLeftChild() != nullptr && parent->getLeftChild()->getKey() == node->getKey()){
                    parent->setLeftChild(nullptr);
                    node->setParent(nullptr);
                    free(node);
                }

                if(parent->getRightChild() != nullptr && parent->getRightChild()->getKey() == node->getKey()){
                    parent->setRightChild(nullptr);
                    node->setParent(nullptr);
                    free(node);
                }
            }
            /************************another case*******************************************/
            if(node->getRightChild() != nullptr && node->getLeftChild() == nullptr){

                Node* rightchild = node->getRightChild();
                Node* parent = node->getParent();
                // separation process begins
                rightchild->setParent(nullptr);//remove entering links
                if( node->getKey() > parent->getKey() ){
                    if(parent->getRightChild() != nullptr){
                        parent->setRightChild(nullptr);
                        parent->setRightChild(rightchild);
                    }
                }else{
                    if(parent->getLeftChild() != nullptr) {
                        parent->setLeftChild(nullptr);
                        parent->setLeftChild(rightchild);
                    }
                }
                rightchild->setParent(parent);

                free(node);
            }
            /************************another case*******************************************/
            if(node->getLeftChild() != nullptr && node->getRightChild() == nullptr){
                Node* leftchild = node->getLeftChild();
                Node* parent = node->getParent();
                // separation process begins
                leftchild->setParent(nullptr);//remove entering links
                if( node->getKey() > parent->getKey() ){
                    parent->setRightChild(nullptr);
                    parent->setRightChild(leftchild);
                }else{
                    parent->setLeftChild(nullptr);
                    parent->setLeftChild(leftchild);
                }
                leftchild->setParent(parent);

                free(node);
            }
            /************************final case*******************************************/
            if(node->getLeftChild() != nullptr && node->getRightChild() != nullptr){
                int max = -1;
                maxBranchValue(node->getLeftChild(),max);
                Node* max_copy = new Node(0);
                max_copy->setKey(find(max)->getKey());

                remove(find(max)->getKey());

                if(node->getLeftChild() != nullptr){
                    Node* leftchild = node->getLeftChild();
                    Node* rightchild = node->getRightChild();
                    Node* parent = node->getParent();

                    leftchild->setParent(nullptr);//remove entering links
                    rightchild->setParent(nullptr);

                    if( node->getKey() > parent->getKey() ){
                        parent->setRightChild(nullptr);
                        parent->setRightChild(max_copy);
                    }else{
                        parent->setLeftChild(nullptr);
                        parent->setLeftChild(max_copy);
                    }
                    leftchild->setParent(max_copy);
                    rightchild->setParent(max_copy);

                    max_copy->setRightChild(rightchild);
                    max_copy->setLeftChild(leftchild);
                    max_copy->setParent(parent);

                    free(node);
                }else{
                    Node* rightchild = node->getRightChild();
                    Node* parent = node->getParent();

                    rightchild->setParent(nullptr);

                    if( node->getKey() > parent->getKey() ){
                        parent->setRightChild(nullptr);
                        parent->setRightChild(max_copy);
                    }else{
                        parent->setLeftChild(nullptr);
                        parent->setLeftChild(max_copy);
                    }
                    rightchild->setParent(max_copy);

                    max_copy->setRightChild(rightchild);
                    max_copy->setParent(parent);

                    free(node);
                }

            }

        }else{
            if(node->getLeftChild() != nullptr){
                remover(node->getLeftChild(),value);
            }

            if(node->getRightChild() != nullptr){
                remover(node->getRightChild(),value);
            }
        }
    }

    void maxBranchValue(Node* node, int &prev_max){
        if(node->getKey() > prev_max){
            prev_max= node->getKey();
        }
        if(node->getLeftChild() != nullptr){
            maxBranchValue(node->getLeftChild(),prev_max);
        }

        if(node->getRightChild() != nullptr){
            maxBranchValue(node->getRightChild(),prev_max);
        }
    }

    void placingNodes(){
        vector<Node*> fn;

        for(int i =0; i < getHeight();i++){
            getNodesAtLvl(getRoot(), i,-1,fn);
            placeNodes(fn, i,getHeight());
            fn.clear();
        }
    }

    void placeNodes(vector<Node *> &nodesAtParticularLevel, int level,int height){

        double window_width = 1.0;

        double NbNodesAtParticularlevel = nodesAtParticularLevel.size();

        double ZoneofNode = window_width / NbNodesAtParticularlevel;

        double middleOf_ZoneofNode = ZoneofNode/2.0;

        /******************************************************************************************************/

        double window_height = 0.98;

        double zoneofNodeY_axis = window_height / height;

        double middleOf_ZoneofNodeY_axis = zoneofNodeY_axis/2.0;

        double Y_coordinates = 1-((level*zoneofNodeY_axis)+middleOf_ZoneofNodeY_axis);

        for(int i = 0; i < NbNodesAtParticularlevel; i++){
            double X_coordinate = (i*ZoneofNode)+middleOf_ZoneofNode;
            nodesAtParticularLevel[i]->setX(X_coordinate);
            nodesAtParticularLevel[i]->setY(Y_coordinates);
        }
    }

    Node* getNodeInPosition(double x, double y){
        int key = -15;
        locateNode(root, key, x , y);
        if(key == -15){
            return nullptr;
        }else{
            return find(key);
        }

    }

    void locateNode(Node* node, int &key,double x, double y){
        double max_X = node->getX()+0.02;
        double min_X = node->getX()-0.02;

        double max_Y = node->getY()+0.02;
        double min_Y = node->getY()-0.02;

        if(x <= max_X && x>= min_X && y <= max_Y && y >= min_Y){
            key = node->getKey();
        }else{
            if(node->getLeftChild() != nullptr){
                locateNode(node->getLeftChild(),key,x,y);
            }

            if(node->getRightChild() != nullptr){
                locateNode(node->getRightChild(),key,x,y);
            }
        }

    }

};

#endif //BST_EX11_BST_H
