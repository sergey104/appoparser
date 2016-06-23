#include <iostream>
#include <fstream>
#include <jsoncpp/json/json.h> // or jsoncpp/json.h , or json/json.h etc.

using namespace std;

int main() {
    ifstream ifs("/home/fil/appodeal.txt");
    std::string ss;
    
    while( std::getline(ifs, ss)) {
      if(ss.empty()) continue;
      if(ss == "-------") continue;
      
    Json::Reader reader;
    Json::Value obj;
    reader.parse(ss, obj); // reader can also read strings
    cout << "id: " << obj["id"].asString() << endl;
    const Json::Value& app = obj["app"]; // array of characters
    cout << "new id: " << app["id"].asString() << endl;
    cout << "name: " << app["name"].asString() << endl;

    /*    cout << "Year: " << obj["year"].asUInt() << endl;
    const Json::Value& characters = obj["characters"]; // array of characters
    for (int i = 0; i < characters.size(); i++){
        cout << "    name: " << characters[i]["name"].asString();
        cout << " chapter: " << characters[i]["chapter"].asUInt();
        cout << endl;

	} */
    }
}
    
