#include <iostream>
#include <vector>  
#include <string>  
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct TNode
{
    int data;
    TNode* left;
    TNode* right;
};
void header(char *MIME_Type);
void start_page(char *Title);
void end_page();

TNode* newNode(int data);
 
TNode* sortedArrayToBST(vector<int> arr, int start, int end)
{
    if (start > end)
      return NULL;
 
    int mid = (start + end)/2;
    TNode *root = newNode(arr[mid]);
 
    root->left =  sortedArrayToBST(arr, start, mid-1);
 
    root->right = sortedArrayToBST(arr, mid+1, end);
 
    return root;
}
 
TNode* newNode(int data)
{
TNode* node = (TNode*)malloc(sizeof(TNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return node;
}
 
void preOrder(TNode* node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}
int main(int argc, char **argv, char **envp)
{
    int i;
    char *Qptr;
    int num;
    vector<int> value;
    Qptr = getenv("QUERY_STRING");
    if(Qptr != NULL)
    {
      string s = getenv("QUERY_STRING");
      string delimiter = ",";
      vector<string> Log;
      size_t pos = 0;
      string token;
      header("text/html");
      start_page("Hey");
      while ((pos = s.find(delimiter)) != string::npos) {
      token = s.substr(0, pos);
      Log.push_back(token);
      s.erase(0, pos + delimiter.length());
    }
    for (int i=0; i<Log.size(); i++)
    {
     int num = atoi(Log.at(i).c_str());
     value.push_back(num);
    }
    TNode *root = sortedArrayToBST(value, 0, 6);
    cout << "\n PreOrder Traversal of constructed BST\n";
    preOrder(root);
}
    else
    {
    cout << "No numbers";
    }
  end_page();
  return 0;
}

void header(char *MIME_Type)
{
  cout << "content-type:" << MIME_Type << "\n\n";
  return;
}

void start_page(char *Title)
{
  cout << "<html>";
  cout << "<head>";
  cout << "<title>" << Title << "</title>";
  cout << "<body>";
  return;
}

void end_page()
{
  cout << "</body>";
  cout << "</html>";
  return;
}
