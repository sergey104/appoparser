#include <iostream>
#include <fstream>
#include <jsoncpp/json/json.h> // or jsoncpp/json.h , or json/json.h etc.
#include <list>
#include <vector>
using namespace std;
void trim(string &s)
{
string::size_type first = s.find_first_not_of(' ');
string::size_type last = s.find_last_not_of(' ');
if ((first==string::npos) && (last== string::npos)) //string contains only whitespaces
{
 s="";
 return;
}
if (first==string::npos) //there are no leading whitespaces
 first=0;
if (last==string::npos) //there are no trailing whitespaces
 last=s.length()-1;
s = s.substr(first, last-first+1);
}
int main() {
    ifstream ifs("/home/fil/appodeal.txt");
    std::string ss;
    list<string> myList, mList;
    while( std::getline(ifs, ss)) {
      if(ss.empty()) continue;
      if(ss == "-------") continue;
      
    Json::Reader reader;
    Json::Value obj;
    reader.parse(ss, obj); // reader can also read strings
    //cout << "id: " << obj["id"].asString() << endl;
    const Json::Value& app = obj["device"]; // array of characters
   // cout << "new id: " << app["id"].asString() << endl;
   // cout << "device ua: " << app["ua"].asString() << endl;
   string s = app["hwv"].asString();
   
   trim(s);
   myList.push_back(s);

    } 
    myList.sort();
    myList.unique();  
     
    list<string>::iterator it;
   for( it = myList.begin(); it != myList.end(); ++it) 
{
   cout << *it << endl;
}
}
    
