#include<iostream>
#include<cstdlib>

using namespace std;

class bstnode
{
public:
  int key;
  bstnode *left,*right;
  bstnode()
  {
    key=0;
    left='\0';
    right='\0';
  }
  bstnode(int a,bstnode *p='\0',bstnode *q='\0')
  {
    key=a;
    left=p;
    right=q;
  }
};
class bst
{
public:
  bstnode *root;
  int i;
  bst()
  {
    root='\0';
    i=0;
  }
  int isempty()
  {
    if(root=='\0')
      return 1;
    else
      return 0;
  }

  void insert(int el)
  {
    bstnode *prev,*p=root;
    while(p!=NULL)
    {
      prev=p;
      if(p->key==el)
      {
        cout<<"Duplicate elements are not allowed\n";
        return;
      }
      else if(p->key<el)
        p=p->right;
      else
        p=p->left;
    }
    if(root==NULL)
      root=new bstnode(el);
    else if(el>prev->key)
      prev->right=new bstnode(el);
    else
      prev->left=new bstnode(el);
  }

  void inorder(bstnode *p);
  void preorder(bstnode *p)
  {
    if(p!=0)
    {
      i++;
      cout<<p->key<<"\t";
      preorder(p->left);
      preorder(p->right);
    }
  }
  void postorder(bstnode *p)
  {
    if(p!=0)
    {
      postorder(p->left);
      postorder(p->right);
      cout<<p->key<<"\t";
    }
  }
  void delcopying(bstnode* &node);
  void delmerging(bstnode* &node);
  void findbycopying(int el);
  void findbymerging(int el);
};

void bst::delmerging(bstnode* &node)
{
  bstnode *tmp=node;
  if(node!=0)
  {
    if(node->right==NULL)
      node=node->left;
    else if(node->left==NULL)
      node=node->right;
    else
    {
      tmp=node->left;
      while(tmp->right!=0)
        tmp=tmp->right;
      tmp->right=node->right;
      tmp=node;
      node=node->left;
    }
    delete tmp;
  }
}

void bst::findbymerging(int el)
{
  bstnode *node=root,*prev=0;
  while(node!=NULL)
  {
    if(node->key==el)
      break;
    prev=node;
    if(node->key<el)
      node=node->right;
    else
      node=node->left;
  }
  if(node!=NULL && node->key==el)
  {
    if(node==root)
      delmerging(root);
    else if(prev->left==node)
      delmerging(prev->left);
    else if(prev->right==node)
      delmerging(prev->right);
  }
  else if(root!=0)
    cout<<"Element not found\n";
  else
    cout<<"Tree is empty\n";
}

void bst::inorder(bstnode *p)
{
  if(p!=NULL)
  {
    inorder(p->left);
    cout<<p->key<<"\t";
    inorder(p->right);
  }
}

void bst::delcopying(bstnode* &node)
{
  bstnode *prev,*tmp=node;
  if(node->right==0)
    node->left;
  else if(node->left==0)
    node=node->right;
  else
  {
    tmp=node->left;
    prev=node;
    while(tmp->right!=0)
    {
      prev=tmp;
      tmp=tmp->right;
    }
    node->key=tmp->key;
    if(prev==node)
      prev->left=tmp->left;
    else
      prev->right=tmp->left;
  }
  delete tmp;
}

void bst::findbycopying(int el)
{
  bstnode *node=root,*prev=0;
  while(node!=NULL)
  {
    if(node->key==el)
      break;
    prev=node;
    if(node->key<el)
      node=node->right;
    else
      node=node->left;
  }
  if(node!=NULL && node->key==el)
  {

    delcopying(node);
  }
  else if(root!=0)
    cout<<"Element not found\n";
  else
    cout<<"Tree is empty\n";
}

int main()
{
  bst B;
  int el,ch;
  cout<<" 1.Insert\n 2.Inorder\n 3.Preorder\n 4.Postorder\n 5.Delete by copying\n 6.Delete by merging\n";
  for(;;)
  {
    cout<<"Enter your choice\n";
    cin>>ch;
    switch(ch)
    {
      case 1: cout<<"Enter the element \n";
      cin>>el;
      B.insert(el);
      break;
      case 2: B.inorder(B.root);
      cout<<endl;
      break;
      case 3:B.i=0;
      B.preorder(B.root);
      cout<<endl;
      break;
      case 4: B.postorder(B.root);
      cout<<endl;
      break;
      case 5: cout<<"Enter the element \n";
      cin>>el;
      B.findbycopying(el);
      break;
      case 6: cout<<"Enter the element \n";
      cin>>el;
      B.findbymerging(el);
      break;
      default:exit(1);
    }
  }
}
