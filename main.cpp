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
    list<string> hwvList, uaList, idList, dimList, languageList, carrierList, modelList, makeList, connectiontypeList;
    list<string> devicetypeList, flashverList, countryList, cityList, nameList;
    while( std::getline(ifs, ss)) {
      if(ss.empty()) continue;
      if(ss == "-------") continue;
      
    Json::Reader reader;
    Json::Value obj;
    reader.parse(ss, obj); // reader can also read strings
    const Json::Value& idd = obj["id"];
    idList.push_back(idd.asString());
    //cout << "id: " << obj["id"].asString() << endl;
    const Json::Value& app = obj["device"]; // array of characters
    
    const Json::Value& geo = app["geo"];
    
    const Json::Value& user = obj["user"];
    const Json::Value& data = user["data"];
    const Json::Value& root1 = data[0];
   // cout << data << endl;
    
    cout << "new id: " << app["id"].asString() << endl;
    cout << "device ua: " << app["ua"].asString() << endl;

   string s = app["hwv"].asString();
   string s1 = app["ua"].asString();
   string dim = app["h"].asString() + " x " + app["w"].asString();
   string language = app["language"].asString();
   string carrier = app["carrier"].asString();
   string model = app["model"].asString();
   string make = app["make"].asString();
   string connectiontype = app["connectiontype"].asString();
   string devicetype = app["devicetype"].asString();
   string flashver = app["flashver"].asString();
   
   string country = geo["country"].asString();
   string city = geo["city"].asString();
   
   string name = root1["name"].asString();
   
   trim(s);
   trim(s1);
   trim(carrier);
   trim(language);
   trim(model);
   trim(make);
   trim(connectiontype);
   trim(devicetype);
   trim(flashver);
   trim(country);
   trim(city);
   trim(name);

   hwvList.push_back(s);
   uaList.push_back(s1);
   dimList.push_back(dim );
   carrierList.push_back(carrier);
   modelList.push_back(model);
   makeList.push_back(make);
   connectiontypeList.push_back(connectiontype);
   devicetypeList.push_back(devicetype);
   flashverList.push_back(flashver);
   countryList.push_back(country);
   cityList.push_back(city);
   nameList.push_back(name);
   
  languageList.push_back(language);

    } 
    hwvList.sort();
    hwvList.unique(); 
    uaList.sort();
    uaList.unique(); 
    dimList.sort();
    dimList.unique();
    languageList.sort();
    languageList.unique();
    carrierList.sort();
    carrierList.unique();
    modelList.sort();
    modelList.unique();
    makeList.sort();
    makeList.unique();
    connectiontypeList.sort();
    connectiontypeList.unique();
    devicetypeList.sort();
    devicetypeList.unique();
    flashverList.sort();
    flashverList.unique();
    countryList.sort();
    countryList.unique();
    cityList.sort();
    cityList.unique();
    nameList.sort();
    nameList.unique();
     
    list<string>::iterator it;
    for( it = hwvList.begin(); it != hwvList.end(); ++it) 
    {
    cout << *it << endl;
    }

    for( it = uaList.begin(); it != uaList.end(); ++it) 
    {
     cout << *it << endl;
    }
    for( it = dimList.begin(); it != dimList.end(); ++it) 
    {
     cout << *it << endl;
    }
    
    for( it = languageList.begin(); it != languageList.end(); ++it) 
    {
    cout << *it << endl;
    }
    
    for( it = carrierList.begin(); it != carrierList.end(); ++it) 
    {
    cout << *it << endl;
    }
    for( it = modelList.begin(); it != modelList.end(); ++it) 
    {
    cout << *it << endl;
    }
    for( it = makeList.begin(); it != makeList.end(); ++it) 
    {
    cout << *it << endl;
    }
    for( it = connectiontypeList.begin(); it != connectiontypeList.end(); ++it) 
    {
    cout << *it << endl;
    }
    for( it = devicetypeList.begin(); it != devicetypeList.end(); ++it) 
    {
    cout << *it << endl;
    }
    for( it = flashverList.begin(); it != flashverList.end(); ++it) 
    {
    cout << *it << endl;
    }
    cout << "country" << endl;
    for( it = countryList.begin(); it != countryList.end(); ++it) 
    {
    cout << *it << endl;
    }
    cout << "city field" << endl;
    for( it = cityList.begin(); it != cityList.end(); ++it) 
    {
    cout << *it << endl;
    } 
    cout << "user name field" << endl;
    for( it = nameList.begin(); it != nameList.end(); ++it) 
    {
    cout << *it << endl;
    } 
    cout << "2" << idList.size() << endl;
}
    
