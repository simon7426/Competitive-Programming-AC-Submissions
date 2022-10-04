#include<cstdio>
#include<cmath>
#include<cctype>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<list>
#include<set>
#include<utility>
#include<map>
#include<queue>
#include<deque>
#include<stack>
#include <iterator> //iterators
#include<stdio.h>
#include<limits.h>



using namespace std;



struct node
{
	int roll;
	node *left, *right;
	node() //initialize the node using null
	{
		left=NULL;
		right=NULL;
	}
};
node *root,currt;

int maxDepth(struct node* node)
{
   if (node==NULL)
       return 0;
   else
   {
       /* compute the depth of each subtree */
       int lDepth = maxDepth(node->left);
       int rDepth = maxDepth(node->right);

       /* use the larger one */
       if (lDepth > rDepth)
           return(lDepth+1);
       else return(rDepth+1);
   }
}
void insert(int roll)
{
	if(root==NULL) //first node in tree
	{
		root=new node();
		root->roll=roll;
	}
	else
	{
		node *current=root,*parent;
		while(current!=NULL)
		{
				if(roll<current->roll)
				{
					parent=current; //keep track of parent node
					current=current->left;
				}
				else
				{
					parent=current;
					current=current->right;
				}
		}
		node *newnode=new node();
		newnode->roll=roll;
		if(newnode->roll<parent->roll) parent->left=newnode;
		else parent->right=newnode;
	}
}



 struct node* find(int roll){
   struct node *current = root;
   printf("Visiting elements: ");

   while(current->roll != roll){

      if(current != NULL) {
         printf("%d ",current->roll);}

         if(current->roll > roll){
            current = current->left;
         }
         else {
            current = current->right;
         }

         if(current == NULL){
            return NULL;
         }
      }

   return current;
}

struct node * minValueNode(struct node* node)
{
    struct node* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

struct node* deleteNode(struct node* root, int roll)
{

    if (root == NULL) return root;

    if (roll < root->roll)
        root->left = deleteNode(root->left, roll);

    else if (roll > root->roll)
        root->right = deleteNode(root->right, roll);

    else
    {

        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }


        struct node* temp = minValueNode(root->right);

        root->roll = temp->roll;

        root->right = deleteNode(root->right, temp->roll);
    }
    return root;
}

void print_preorder(node *current)
{
	if(current==NULL) return;
	cout<<current->roll<<endl;
	print_preorder(current->left);

	print_preorder(current->right);

	//cout<<current->roll<<endl;
	//print_preorder(current->right);

}
int main()
{

    insert(2);
    insert(1);
    insert(3);
    insert(4);
    insert(5);
    //insert(60);
    //insert(80);
    //deleteNode(root,20);
    //deleteNode(root,50);
    //find(500);
    //cout<<root->roll<<endl;
    cout<<maxDepth(root);
    return 0;
}

