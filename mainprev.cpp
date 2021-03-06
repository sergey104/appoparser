#include <iostream>
#include <fstream>
#include <jsoncpp/json/json.h> // or jsoncpp/json.h , or json/json.h etc.
#include <list>
#include <vector>
#include <iostream>
#include <map>

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

std::string format_string(string s, int n) 
{
	if(s.size() >= n) return s;
	int i = n - s.size();
	for(int j = 0; j < i; j++) s.push_back(' ');
	return s;
	
}
int main() {
	setlocale(LC_ALL,"");
    ifstream ifs("/home/fil/big.txt");
    std::string ss;
    list<string> hwvList, uaList, idList, dimList, languageList, carrierList, modelList, makeList, connectiontypeList;
    list<string> devicetypeList, flashverList, countryList, cityList, nameList, zipList;
    
    list<string> appidList, appnameList, apppublishernameList, appverList, appstoreUrlList;
    list <string> appcatList, appsectioncatList, apppagecatList, appbundleList, appdomainList, appkeywordsList, appcontentList, appextList;
    list<int> apppaidList, appprivacypolicyList;
    list<string> useryobList, userkeywordsList, usergenderList;
    
    while( std::getline(ifs, ss)) {
      if(ss.empty()) continue;
      if(ss == "-------") continue;
  

    Json::Reader reader;
    Json::Value obj;
    reader.parse(ss, obj); // reader can also read strings
    const Json::Value& idd = obj["id"];
    idList.push_back(idd.asString());
    //cout << "id: " << obj["id"].asString() << endl;
    
    //DEVICE + USER
    
    const Json::Value& device = obj["device"]; // array of characters
    
    const Json::Value& geo = device["geo"];
    
    
        
    //APPLICATION
    
    const Json::Value& app = obj["app"];
    const Json::Value& publisher = app["publisher"];
    const Json::Value& cat = app["cat"];
    const Json::Value& sectioncat = app["sectioncat"];
    const Json::Value& pagecat = app["pagecat"];
    const Json::Value& ext = app["ext"];
    const Json::Value& content = app["content"];
    
    
    //USER
    
    const Json::Value& user = obj["user"];
    const Json::Value& data = user["data"];
    const Json::Value& root1 = data[0];

  //dev

   string s = device["hwv"].asString();
   string s1 = device["ua"].asString();
   string dim = device["h"].asString() + " x " + device["w"].asString();
   string language = device["language"].asString();
   string carrier = device["carrier"].asString();
   string model = device["model"].asString();
   string make = device["make"].asString();
   string connectiontype = device["connectiontype"].asString();
   string devicetype = device["devicetype"].asString();
   string flashver = device["flashver"].asString();
   string country = geo["country"].asString();
   string city = geo["city"].asString();
   string zip = geo["zip"].asString();
   string name = root1["name"].asString();
   
   //app
   
   
   
   string appid = app["id"].asString();
   string appname = app["name"].asString();
   string appstoreUrl = app["storeUrl"].asString();
   string appbundle = app["bundle"].asString();
   string appver = app["ver"].asString();
   int apppaid = app["paid"].asInt();
   int appprivacypolicy = app["privacypolicy"].asInt();
   string appcat = cat[0].asString();
   string appsectioncat = sectioncat[0].asString();
   string apppagecat = pagecat[0].asString();
   string apppublishername = publisher["name"].asString();
   string appdomain = app["domain"].asString();
   string appkeywords = app["keywords"].asString();
   
   //user
   
   string useryob = user["yob"].asString();
   string userkeywords = user["keywords"].asString();
   string usergender = user["gender"].asString();
   
   
  
   
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
   trim(zip);

   trim(appid);
   trim(appname);
   trim(appbundle);
   trim(appstoreUrl);
   trim(appver);
   trim(appcat);
   trim(apppublishername);
   
   trim(useryob);
   trim(usergender);


   if((&s != 0) && (s != "")) hwvList.push_back(s);
   if((&s1 != 0) && (s1 != "")) uaList.push_back(s1);
   if((&dim != 0) && (dim != "")) dimList.push_back(dim );
   if((&carrier != 0) && (carrier != "")) carrierList.push_back(carrier);
   if((&model != 0) && (model != "")) modelList.push_back(model);
   if((&make != 0) && (make != "")) makeList.push_back(make);
   if((&connectiontype != 0) && (connectiontype != "")) connectiontypeList.push_back(connectiontype);
   if((&devicetype != 0) && (devicetype != "")) devicetypeList.push_back(devicetype);
   if((&flashver != 0) && (flashver != "")) flashverList.push_back(flashver);
   if((&country != 0) && (country != "")) countryList.push_back(country);
   if((&city != 0) && (city != "")) cityList.push_back(city);
   if((&name != 0) && (name != "")) nameList.push_back(name);
   if((&zip != 0) && (zip != ""))  zipList.push_back(zip);
   
   if((&appid != 0) && (appid != ""))  appidList.push_back(appid);
   if((&appname != 0) && (appname != ""))  appnameList.push_back(appname);
   if((&apppublishername != 0) && (apppublishername != ""))  apppublishernameList.push_back(apppublishername);
   if((&appbundle != 0) && (appbundle != ""))  appbundleList.push_back(appbundle);
   if((&appver != 0) && (appver != ""))  appverList.push_back(appver);
   if((&appdomain != 0) && (appdomain != ""))  appdomainList.push_back(appver);
   if((&appcat != 0))  appcatList.push_back("1");
   if((&appsectioncat != 0))  appsectioncatList.push_back("1");
   if((&apppagecat != 0))  apppagecatList.push_back("1");
   if((&ext != 0))  appextList.push_back("1");
   if((&content != 0))  appcontentList.push_back("1");
   
   if((&appstoreUrl != 0) && (appstoreUrl != ""))  appstoreUrlList.push_back(appstoreUrl);
   if((&apppaid !=NULL))  apppaidList.push_back(apppaid);
   if((&appprivacypolicy != NULL))  apppaidList.push_back(apppaid);
   
   if((&useryob != 0))  useryobList.push_back(useryob);
   if((&userkeywords != 0) && (userkeywords != ""))  userkeywordsList.push_back(userkeywords);
   if((&usergender != 0) && (usergender != ""))  usergenderList.push_back(usergender);
   
   if((&language != 0) && (language != "")) languageList.push_back(language);
  

    } 
    
        
    hwvList.sort();
    int hwvf = hwvList.size();
    hwvList.unique(); 
    
    uaList.sort();
    int uaf = uaList.size();
    uaList.unique(); 
    
    dimList.sort();
    int dimf = dimList.size();
    dimList.unique();
    
    languageList.sort();
    int languagef = languageList.size();
 //   languageList.unique();
    
    carrierList.sort();
    int carrierf = carrierList.size();
//    carrierList.unique();
    
    modelList.sort();
    int modelf = modelList.size();
 //   modelList.unique();
    
    makeList.sort();
    int makef = makeList.size();
 //   makeList.unique();
    
    connectiontypeList.sort();
    int connectiontypef = connectiontypeList.size();
 //   connectiontypeList.unique();
    
    devicetypeList.sort();
    int devicetypef = devicetypeList.size();
 //   devicetypeList.unique();
    
    flashverList.sort();
    int flashverf = flashverList.size();
 //   flashverList.unique();
    
    countryList.sort();
    int countryf = countryList.size();
 //   countryList.unique();
    
    cityList.sort();
    int cityf = cityList.size();
 //   cityList.unique();
    
    nameList.sort();
    int namef = nameList.size();
//    nameList.unique();
    
    zipList.sort();
    int zipf = zipList.size();
 //   zipList.unique();
    
    ////////app
    
    appidList.sort();
    int appidf = appidList.size();
 //   appidList.unique();
    
    appnameList.sort();
    int appnamef = appnameList.size();
 //   appnameList.unique();
    
    apppublishernameList.sort();
    int apppublishernamef = apppublishernameList.size();
 //   apppublishernameList.unique();
    
    appverList.sort();
    int appverf = appverList.size();
 //   appverList.unique();
    
    apppagecatList.sort();
    int apppagecatf = apppagecatList.size();
 //   appcatList.unique();
 
     appsectioncatList.sort();
    int appsectioncatf = appsectioncatList.size();
 //   appcatList.unique();
 
     appcatList.sort();
    int appcatf = appcatList.size();
 //   appcatList.unique();
    
    apppaidList.sort();
    int apppaidf = apppaidList.size();
 //   apppaidList.unique();
    
    appstoreUrlList.sort();
    int appstoreUrlf = appstoreUrlList.size();
//    appstoreUrlList.unique();
    
    appbundleList.sort();
    int appbundlef = appbundleList.size();
 //   appbundleList.unique();
    
    //user
    
    useryobList.sort();
    int useryobf = useryobList.size();
//    useryobList.unique();
    
    userkeywordsList.sort();
    int userkeywordsf = userkeywordsList.size();
 //   userkeywordsList.unique();
    
    usergenderList.sort();
    int usergenderf = usergenderList.size();
//    usergenderList.unique();
    
    cout << "Total number of jason requests: " <<  idList.size() << endl;
    cout << "-----------------------------------\n" << "HWV field" << endl;
    double f = hwvf*100/idList.size() ;
    cout << "HWV - " << "Hardware version of the device (e.g., “5S” for iPhone 5S)." << endl << "frequency: " << f << "%" <<  endl;
    list<string>::iterator it;

    cout << "-----------------------------------\n" << "UA field"  << endl; 
    f = uaf*100/idList.size() ;
    cout << "UA - " << "Browser user agent string." << endl << "frequency: " << f << "%" <<  endl;
 
    
    cout << "-----------------------------------\n" << "Dimensions field h x w"  << endl; 
    f = dimf*100/idList.size() ;
    cout << "Dimensions h and w - " << "Physical height of the screen in pixels X Physical width of the screen in pixels" << endl << "frequency: " << f << "%" <<  endl;

    cout << "-----------------------------------\n" << "Language field"  << endl; 
    f = languagef*100/idList.size() ;
    cout << "language - " << "Browser language using ISO-639-1-alpha-2." << endl << "frequency: " << f << "%" <<  endl;

    
    cout << "-----------------------------------\n" << "Carrier field"  << endl; 
    f = carrierf*100/idList.size() ;
    cout << "carrier - " << "Carrier or ISP (e.g., “VERIZON”). “WIFI” is often used in mobile to indicate high bandwidth (e.g., video friendly vs. cellular)." << endl << "frequency: " << f << "%" <<  endl;

    cout << "-----------------------------------\n" << "Model field"  << endl; 
    f = modelf*100/idList.size() ;
    cout << "model - " << "Device model (e.g., “iPhone”)." << endl << "frequency: " << f << "%" <<  endl;
 
    cout << "-----------------------------------\n" << "Connectiontype field"  << endl; 
    f = connectiontypef*100/idList.size() ;
    cout << "connectiontype - " << "Network connection type. Refer to List 5.20"<< endl << "frequency: " << f << "%" <<  endl;
    cout << "0 Unknown" << endl; 
    cout << "1 Ethernet"<< endl; 
    cout << "2 WIFI"<< endl; 
    cout << "3 Cellular Network – Unknown Generation"<< endl; 
    cout << "4 Cellular Network – 2G"<< endl; 
    cout << "5 Cellular Network – 3G"<< endl; 
    cout << "6 Cellular Network – 4G" << endl  << endl; 

    cout << "-----------------------------------\n" << "Device field"  << endl; 
    f = devicetypef*100/idList.size() ;
    cout << "devicetype - " << "The general type of device" << endl << "frequency: " << f << "%" <<  endl;

    
    cout << "-----------------------------------\n" << "Flashver field" << endl; 
    f = flashverf*100/idList.size() ;
    cout << "flashver - " << "Version of Flash supported by the browser." << endl << "frequency: " << f << "%" <<  endl;
 
    cout << "-----------------------------------\n" << "Country field"  << endl; 
    f = countryf*100/idList.size() ;
    cout << "country - " << "Country code using ISO-3166-1-alpha-3.." << endl << "frequency: " << f << "%" <<  endl;
 
    cout << "-----------------------------------\n" << "City field"  << endl; 
    f = cityf*100/idList.size() ;
    cout << "city - " << "City using United Nations Code for Trade & Transport Locations" << endl << "frequency: " << f << "%" <<  endl;

    cout << "-----------------------------------\n" << "User name field"  << endl; 
    f = namef*100/idList.size() ;
    cout << "user name - " << "Exchange-specific name for the data provider." << endl << "frequency: " << f << "%" <<  endl;
 
    
    cout << "-----------------------------------\n" << "ZIP field"  << endl; 
    f = zipf*100/idList.size() ;
    cout << "zip code - " << "User zip code" << endl << "frequency: " << f << "%" <<  endl;

//Application output

cout << "Information about app section" << endl;
    
    cout << "-----------------------------------\n" << "Application id field"  << endl; 
    f = appidf*100/idList.size() ;
    cout << "app id - " << "Application id" << endl << "frequency: " << f << "%" <<  endl;
 
    cout << "-----------------------------------\n" << "Application name field"  << endl; 
    f = appnamef*100/idList.size() ;
    cout << "app name- " << "App name (may be aliased at the publisher’s request)" << endl << "frequency: " << f << "%" <<  endl;
    
    cout << "-----------------------------------\n" << "Application publisher name field"  << endl; 
    f = apppublishernamef*100/idList.size() ;
    cout << "app publisher name- " << "Details about the Publisher (Section 3.2.8) of the app." << endl << "frequency: " << f << "%" <<  endl;
    
        cout << "-----------------------------------\n" << "Application ver field"  << endl; 
    f = appverf*100/idList.size() ;
    cout << "app ver - " << "Application version" << endl << "frequency: " << f << "%" <<  endl;
    
        cout << "-----------------------------------\n" << "Application cat field"  << endl; 
    f = appcatf*100/idList.size() ;
    cout << "app cat - " << "Array of IAB content categories of the app. Refer to List 5.1." << endl << "frequency: " << f << "%" <<  endl;
    
        cout << "-----------------------------------\n" << "Application paid field"  << endl; 
    f = apppaidf*100/idList.size() ;
    cout << "app paid - " << "0 = app is free, 1 = the app is a paid version." << endl << "frequency: " << f << "%" <<  endl;
    
        cout << "-----------------------------------\n" << "Application bundle field"  << endl; 
    f = appbundlef*100/idList.size() ;
    cout << "app bundle - " << "Application bundle or package name (e.g., com.foo.mygame);intended to be a unique ID across exchanges" << endl << "frequency: " << f << "%" <<  endl;
    
        cout << "-----------------------------------\n" << "Application storeUrl field"  << endl; 
    f = appstoreUrlf*100/idList.size() ;
    cout << "app storeUrl - " << "App store URL for an installed app; for QAG 1.5 compliance." << endl << "frequency: " << f << "%" <<  endl;
    
    
    ///////////////////////////////////

    cout << "-----------------------------------\n" << "User year of birth"  << endl; 
    f = useryobf*100/idList.size() ;
    cout << "user yob " << "User year of birth" << endl << "frequency: " << f << "%" <<  endl;

    cout << "-----------------------------------\n" << "User keywords"  << endl; 
    f = userkeywordsf*100/idList.size() ;
    cout << "user keywords " << "User keywords" << endl << "frequency: " << f << "%" <<  endl;
 
    cout << "-----------------------------------\n" << "User gender"  << endl; 
    f = usergenderf*100/idList.size() ;
    cout << "user gender" << "User gender" << endl << "frequency: " << f << "%" <<  endl;
 
    
	
	
    
    
}
    

