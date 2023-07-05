#include <iostream>
using namespace std ;
#include <queue>
#include <vector>

class binary_tree_node {
   public :
       int data;
       binary_tree_node* left;
       binary_tree_node* right;


       binary_tree_node (int data) {
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
       }

      ~binary_tree_node() {
        delete left;
        delete right;
      }
};


// take input
 binary_tree_node *take_input_levelwise() {
    int rootdata;

   // cout << "Enter root data : " << endl;
    cin >> rootdata;

   if(rootdata == -1) {
    return NULL;
   }
    binary_tree_node *root = new binary_tree_node (rootdata);
    queue<binary_tree_node*> pending_nodes;
    pending_nodes.push(root);

    while(pending_nodes.size() != 0) {
         binary_tree_node *front  = pending_nodes.front();
     pending_nodes.pop();
        // cout << "Enter left children of " << front -> data << endl;
         int leftchild;
         cin >> leftchild;
         if(leftchild != -1) {
            binary_tree_node *child = new binary_tree_node(leftchild);
            front -> left = child;
            pending_nodes.push(child);
         }


         //cout << "Enter right children of " << front -> data << endl;
         int rightchild;
         cin >> rightchild;
         if(rightchild != -1) {
            binary_tree_node *childd = new binary_tree_node(rightchild);
            front ->right = childd;
            pending_nodes.push(childd);
         }
    }
 return root;
}


bool binary_search(binary_tree_node*root , int x) {
    bool flag = false;
   if(root == NULL) {
    return flag;
   }

   if( root -> data == x) {
        flag = true;
    return flag;
   }

   else if( root -> data < x) {
    binary_search(root -> right , x);
   }

   else {
    binary_search( root -> left , x);
   }

}


 void print_levelwise(binary_tree_node *root) {
    if (root == NULL) {
        return;
    }

    queue<binary_tree_node*> pending_nodes;
    pending_nodes.push(root);

    while (!pending_nodes.empty()) {
        int level_size = pending_nodes.size();

        for (int i = 0; i < level_size; i++) {
            binary_tree_node *front = pending_nodes.front();
            pending_nodes.pop();

            cout << front->data << " : ";

            if (front->left != NULL) {
                cout << "L - " << front->left->data << ", ";
                pending_nodes.push(front->left);
            }

            if (front->right != NULL) {
                cout << "R - " << front->right->data << ", ";
                pending_nodes.push(front->right);
            }

            cout << endl;
        }


    }
}


// print all nodes data in given range

void print_nodes_data_in_range(binary_tree_node *root , int n, int m) {
   if (root == NULL) {
      return;
   }

   if (root->data > n) {
      print_nodes_data_in_range(root->left, n, m);
   }

   if (root->data >= n && root->data <= m) {
      cout << root->data << " ";
   }

   if (root->data < m) {
      print_nodes_data_in_range(root->right, n, m);
   }

}

int left_max(binary_tree_node *root){
    int leftmax = INT_MIN;
    if( root -> data > leftmax )  {
        leftmax = root -> data;
    }



}

int minimum(binary_tree_node * root) {
       if( root == NULL) {
        return  INT_MAX;
       }

       return min( root -> data , minimum( root -> left) , minimum ( root -> right));

}

int maximum(binary_tree_node * root) {
  if( root == NULL) {
    return INT_MAX;

    return max( root -> data , maximum( root -> left) , maximum(root -> right));
  }



}

bool isBST(binary_tree_node *root) {
        if( root == NULL) {
            return true;
        }
         int leftmax = maximum ( root -> left);
         int  rightmin = minimum ( root -> right);

         bool ans = ( leftmax < root -> data) && ( rightmin > root -> data) && ( isBST( root ->left)) && (isBST(root -> right));

}

int  main() {
  binary_tree_node *root = take_input_levelwise();
 // print_levelwise(root);
 /* int x;
  cin >> x;

   cout << "the element " << x << "is : ";
   cout << binary_search(root ,x);


 int n; cin >> n;
 int m ; cin >> m;
 print_nodes_data_in_range(root , n , m);
*/

cout << isBST( root ) ;

}
