#include <iostream>    
#include <algorithm>    
#include <stack>    
#include <math.h>    
using namespace std;    
/*function of this program: build a 2d tree using the input training data  
 the input is exm_set which contains a list of tuples (x,y)  
 the output is a 2d tree pointer*/    
const int k=2;  

struct data    
{    
    double number[k];    
};    
    
struct Tnode    
{    
    struct data dom_elt;    
    int split;    
    struct Tnode * left;    
    struct Tnode * right;    
};
struct Tnode* newnode(double arr[])
{
    struct Tnode* temp = new Tnode;
    for(int i=0;i<k;i++)
       temp->dom_elt.number[i]=arr[i];
    temp->left=temp->right=NULL;
    temp->split=0;
    return temp;
}
void sorting(data exm_set[], int size, int &split){
    data tmp;
    for (int i=0;i<size-1;i++)
    {
       for(int j=size-1;j>i;j--){
          if(exm_set[j].number[split]<exm_set[j-1].number[split])
          {
          tmp=exm_set[j];
          exm_set[j]=exm_set[j-1];
          exm_set[j-1]=tmp;
          }
        }
    }

}     
         
bool equal(data a, data b){    
    for(int i=0;i<k;i++){
        if(a.number[i]!=b.number[i])
        {
            return false;
        }
    }
    return true;
}    
    
void ChooseSplit(data exm_set[], int size, int &split, data &SplitChoice){    
    /*compute the variance on every dimension. Set split as the dismension that have the biggest  
     variance. Then choose the instance which is the median on this split dimension.*/    
    /*compute variance on the x,y dimension. DX=EX^2-(EX)^2*/    
    double tmp1,tmp2;
    double v1,v2;   
    tmp1 = tmp2 = 0;
    v1 = v2 = 0;
    split=0; 
    for (int j=0;j<k;j++){    
    for (int i=0;i<size;i++)    
    {    
        tmp1 += 1.0 / (double)size * exm_set[i].number[j] * exm_set[i].number[j];    
        tmp2 += 1.0 / (double)size * exm_set[i].number[j];    
    }    
    v1 = tmp1 - tmp2 * tmp2;  //compute variance on the x dimension        
    tmp1 = tmp2 = 0;
    if(v1>v2)
    {
    split=j;
    v2=v1;
    }
    
    }    //compute variance on the y dimension        
    sorting(exm_set,size, split);    

    //set the split point value
    for(int l=0;l<k;l++)
    {
         SplitChoice.number[l] = exm_set[size / 2].number[l];
    }    
}       
Tnode* build_kdtree(data exm_set[], int size, Tnode* T)
{    
    //call function ChooseSplit to choose the split dimension and split point    
    if (size == 0){    
        return NULL;    
    }    
    else{    
        int split;    
        data dom_elt;    
        ChooseSplit(exm_set, size, split, dom_elt);    
        data exm_set_right [100];    
        data exm_set_left [100];    
        int sizeleft ,sizeright;    
        sizeleft = sizeright = 0;        
            for (int i = 0; i < size; ++i)    
            {    
                    
                if (!equal(exm_set[i],dom_elt) && exm_set[i].number[split] <= dom_elt.number[split])    
                {   for(int l=0;l<k;l++) 
                    {
                      exm_set_left[sizeleft].number[l] = exm_set[i].number[l]; 
                    } 
                    sizeleft++;    
                }    
                else if (!equal(exm_set[i],dom_elt) && exm_set[i].number[split]> dom_elt.number[split])    
                {   for(int l=0;l<k;l++) 
                    {
                      exm_set_right[sizeright].number[l] = exm_set[i].number[l]; 
                    }  
                    sizeright++;    
                }    
            }    
            
        
        T = new Tnode;
        for(int m=0;m<k;m++) {
          T->dom_elt.number[m] = dom_elt.number[m];     
        }    
        T->split = split;    
        T->left = build_kdtree(exm_set_left, sizeleft, T->left);    
        T->right = build_kdtree(exm_set_right, sizeright, T->right);    
        return T;    
            
    }  
}
//build KD tree
/////////////////////////////////////////////////////////////////////////////////////////////
//Search
bool arePointsSame(double point1[], double point2[])
{
    // Compare individual pointinate values
    for (int i = 0; i < k; ++i)
        if (point1[i] != point2[i])
            return false;
  
    return true;
}
bool searchRec(Tnode* root, double point[])
{
    if (root == NULL)
        return false;
    if (arePointsSame(root->dom_elt.number, point))
        return true;
    // Current dimension is computed using current depth and total
    // dimensions (k)
    int cd = root->split;
  
    // Compare point with root with respect to cd (Current dimension)
    if (point[cd] < root->dom_elt.number[cd])
        return searchRec(root->left, point);
  
    return searchRec(root->right, point);
} 
bool search(Tnode* root, double point[]){
    return searchRec(root, point);
}
//Search
/////////////////////////////////////////////////////////////////////////////////////////
//insert
Tnode *insertRec(Tnode* root, double point[])
{
    if (root == NULL)
    {
        return newnode(point);
    }
    
    int cd = root->split;
  
    // Compare point with root with respect to cd (Current dimension)
    if (point[cd] < root->dom_elt.number[cd])
        root->left = insertRec(root->left, point);
    else
        root->right= insertRec(root->right,point);
    return root;
} 
Tnode* insert(Tnode* root, double point[],data exm_set[],int id){
    for(int i=0;i<k;i++){
        exm_set[id].number[i]=point[i];
        }
    return insertRec(root, point);
}
int insertnew(Tnode* root, double point[],data exm_set[],int id){
    insert(root,point,exm_set,id);
    return id+1;
}
//insert
//////////////////////////////////////////////////////////////////////////////////////
//delete
Tnode *minNode(Tnode *x, Tnode *y, Tnode *z, int d)
{
    Tnode *tmp = x;
    if (y != NULL && y->dom_elt.number[d] < tmp->dom_elt.number[d])
       tmp = y;
    if (z != NULL && z->dom_elt.number[d] < tmp->dom_elt.number[d])
       tmp = z;
    return tmp;
}
Tnode *findMinRec(Tnode* root, int d)
{

    if (root == NULL)
        return NULL;
  
    int cd = root->split;
  
    // Compare point with root with respect to cd (Current dimension)
    if (cd == d)
    {
        if (root->left == NULL)
            return root;
        return findMinRec(root->left, d);
    }

    // If current dimension is different then minimum can be anywhere
    // in this subtree
    return minNode(root,findMinRec(root->left, d),findMinRec(root->right, d), d);
}
Tnode *findMin(Tnode* root, int d)
{
    return findMinRec(root, d);
}//find minimum in d th dimension
void copyPoint(double p1[], double p2[])
{
   for (int i=0; i<k; i++)
       p1[i] = p2[i];
}
Tnode *deleteNodeRec(Tnode *root, double point[])
{
    // Given point is not present
    if (root == NULL)
        return NULL;
  
    // Find dimension of current node
    int cd = root->split;
  
    // If the point to be deleted is present at root
    if (arePointsSame(root->dom_elt.number, point))
    {
        // 2.b) If right child is not NULL
        if (root->right != NULL)
        {
            // Find minimum of root's dimension in right subtree
            Tnode *min = findMin(root->right, cd);
  
            // Copy the minimum to root
            copyPoint(root->dom_elt.number, min->dom_elt.number);
  
            // Recursively delete the minimum
            root->right = deleteNodeRec(root->right, min->dom_elt.number);
        }
        else if (root->left != NULL) // same as above
        {
            Tnode *min = findMin(root->left, cd);
            copyPoint(root->dom_elt.number, min->dom_elt.number);
            root->right = deleteNodeRec(root->left, min->dom_elt.number);
        }
        else // If node to be deleted is leaf node
        {
            delete root;
            return NULL;
        }
        return root;
    }
    if (point[cd] < root->dom_elt.number[cd])
        root->left = deleteNodeRec(root->left, point);
    else
        root->right = deleteNodeRec(root->right, point);
    return root;
}
 Tnode* deleteNode(Tnode *root, double point[])
{
   return deleteNodeRec(root, point);
}
int deletedata(data exm_set[],double point1[],int id){
    for(int i=0;i<id;i++){
        if(arePointsSame(exm_set[i].number,point1))
           {
               for(int j=i;j<id-1;j++){
               exm_set[i]=exm_set[i+1];
               }
             break;
           }
    }
    return id-1;
}
//delete
////////////////////////////////////////////////////////////////////////////////////
//update
Tnode* update(data exm_set[],int id,Tnode* root){
    root=NULL;
    return build_kdtree(exm_set, id, root);
}
//update
       
int main(){    
    data exm_set[100]; //assume the max training set size is 100    
    double x,y;  
    int id=0;  
    exm_set[0].number[0]=3;
    exm_set[0].number[1]=6;
    exm_set[1].number[0]=17;
    exm_set[1].number[1]=15;
    exm_set[2].number[0]=13;
    exm_set[2].number[1]=15;
    exm_set[3].number[0]=6;
    exm_set[3].number[1]=12;
    exm_set[4].number[0]=9;
    exm_set[4].number[1]=1;
    exm_set[5].number[0]=2;
    exm_set[5].number[1]=7; 
    exm_set[6].number[0]=10;
    exm_set[6].number[1]=19; 
    id=7;  
    cout<<"Please input the training data in the form x y. One instance per line. Enter -1 -1 to stop."<<endl;    
    /*while (cin>>x>>y){    
        if (x == -1)    
        {    
            break;    
        }    
        else{    
            exm_set[id].x = x;    
            exm_set[id].y = y;    
            id++;    
        }    
    } */ 
    cout<<id;  
    struct Tnode * root = NULL;    
    root = build_kdtree(exm_set, id, root); 
    double point1[] = {0, 6};
    insertnew(root,point1,exm_set,id);
    root=deleteNode(root,point1);
    id=deletedata(exm_set,point1,id);
    root=update(exm_set, id, root);
    (search(root, point1))? cout << "Found\n": cout << "Not Found\n";
    cout<< root->left->left->dom_elt.number[0]<<root->left->left->dom_elt.number[1];
    cout<< root->split;  
    cout<< exm_set[7].number[0]<<exm_set[7].number[1];
    cout<<id;
}  