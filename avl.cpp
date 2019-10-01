#include<bits/stdc++.h>
using namespace std;
struct node {
int key;
struct node *left;
struct node *right;
int height;
};

int heig(node*);
node *findmin(node*);

typedef struct node node;
//creating new node of tree
node *newnode(int key)
{
node *temp=new node;
//node *temp = (node*)malloc(sizeof(node));
temp->key=key;
temp->left=NULL;
temp->right=NULL;
temp->height=1;
return temp;
}

// right rotation  of avl tree
node *rightrotate(node *x)
{

node *y=x->left;
node *z=y->right;

y->right=x;
x->left=z;

x->height=std::max(heig(x->left),heig(x->right))+1;
y->height=std::max(heig(y->left),heig(x->right))+1;

return y;

}


// left rotation of avl tree
node *leftrotate(node *x)
{
node *y=x->right;
node *z=y->left;

y->left=x;
x->right=z;

//update heights
x->height=std::max(heig(x->left),heig(x->right))+1;
y->height=std::max(heig(y->left),heig(x->right))+1;


return y;
}

//return height
int heig(node *root)
{
if(root==NULL)return 0;
else return (root->height);

}



//check balancing of node
int balance(node *root)
{
return (heig(root->left)-heig(root->right));


}


//inserting in avl tree

node *insert(node *root,int key)
{
if(root==NULL)
{
return (newnode(key));
}
else if(key<root->key)
{
root->left=insert(root->left,key);
}
else
{
root->right=insert(root->right,key);
}

//update node height
root->height=1+std::max(heig(root->left),heig(root->right));

int bal=balance(root);


if(bal>1 && root->left->key >key) //LL Case only one single right rotation 
{
return rightrotate(root);
}

if(bal>1 && root->left->key<key)//LR Case 
{
root->left=leftrotate(root->left);
return rightrotate(root);
}

if(bal<-1 && root->right->key <key) // RR case only one single left rotation
{
return leftrotate(root);
}

if(bal<-1 && root->right->key >key)//RL Case
{
root->right=rightrotate(root->right);
return leftrotate(root);
}

return root;

}
// tree traversal 


void preorder(node *root)
{
if(root==NULL)return;
cout<<root->key<<" ";
preorder(root->left);
preorder(root->right);

}


//Deletion in BST


node * bstdel(node *root,int key)
{
if(root==NULL)return root;
else if (root->key > key)
{
root->left=bstdel(root->left,key);
}
else if(root->key<key)
{
root->right=bstdel(root->right,key);
}
else
{

//case 1:
if(root->left==NULL && root->right==NULL)
{

free(root);
node *temp=NULL;
return temp;
}


// case 2:
else if(root->left==NULL)
{
node *temp=root;
root=root->right;
free(temp);
return root;

}




//case 3:
else if(root->right==NULL)
{
node *temp=root;
root=root->left;
free(temp);
return root;
}



//case 4:
else {
node *temp=findmin(root->right);
root->key=temp->key;
root->right=bstdel(root->right,root->key);
}

}
 
}


node *findmin(node *root)
{
while(root->left!=NULL)
{
root=root->left;
}return root;



}

node *avldel(node *root,int key)
{
root=bstdel(root,key);

//update node height
root->height=1+std::max(heig(root->left),heig(root->right));

int bal=balance(root);


if(bal>1 && root->left->key >key) //LL Case only one single right rotation 
{
return rightrotate(root);
}

if(bal>1 && root->left->key<key)//LR Case 
{
root->left=leftrotate(root->left);
return rightrotate(root);
}

if(bal<-1 && root->right->key <key) // RR case only one single left rotation
{
return leftrotate(root);
}

if(bal<-1 && root->right->key >key)//RL Case
{
root->right=rightrotate(root->right);
return leftrotate(root);
}

return root;

}

int main()
{
node *root=NULL;
while(1)
{
cout<<"enter choices\n1:Insertion\n2:Deletion\n3:Display\n4:exit";
int n;
cin>>n;
int d;
switch(n)
{

case 1:cout<<"enter data\n";
cin>>d;
root=insert(root,d);
break;


case 2:cout<<"enter data\n";
cin>>d;
root=avldel(root,d);
break;


case 3:preorder(root);
break;

case 4:exit(0);

default:;



}


}



}
