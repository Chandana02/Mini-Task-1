#include <iostream>
#include <vector>  
#include <string>  
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void header(char *MIME_Type);
void start_page(char *Title);
void end_page();

int main()
{
  header("text/html");
  start_page("BST");
  cout << "<form method=\"get\" action=\"BST.exe\">";
  cout << "<input type=\"text\" name=\"numbers\">";
  cout << "<br><br>";
  cout << "<input type=\"submit\" name=\"submit\" value=\"Get the tree\">";
  end_page();
  return 0;
}

void header(char *MIME_Type)
{
  cout << "content-type:%s\n\n", MIME_Type;
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
