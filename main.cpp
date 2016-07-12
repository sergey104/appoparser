#include <cstdlib>
#include <iostream>
#include <fstream>
#include <jsoncpp/json/json.h> // or something
#include <map>

using namespace std;

void Indent(ostream& ofs, int indent) {
    for (int i=0; i<indent; i++)
      ;//  ofs << ' ';
}
map <string, int> mmap;
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
void MyPrint(ostream& ofs, const Json::Value& val, int indent=0, std::string name="") {
    switch (val.type()) {
        case Json::nullValue: //ofs << "null"; 
	  break;
        case Json::booleanValue: // ofs << (val.asBool() ? "true" : "false"); 
	  break;
        case Json::intValue: //ofs << val.asLargestInt(); 
	  break;
        case Json::uintValue: // ofs << val.asLargestUInt(); 
	  break;
        case Json::realValue: //ofs << val.asDouble(); 
	  break;
        case Json::stringValue: //ofs << '"' << val.asString() << '"'; 
	  break; 
        case Json::arrayValue: {
            Json::ArrayIndex size = val.size();
	    
            if (size == 0)
               ;// ofs << "[]";
            else {
             //   ofs << "[\n";
                int newIndent = indent + 4;
                for (Json::ArrayIndex i=0; i<size; i++) {
                    Indent(ofs, newIndent);
                    MyPrint(ofs, val[i], newIndent,name);
                  //  ofs << (i + 1 == size ? "\n" : ",\n");
                }
                Indent(ofs, indent);
              //  ofs << ']';
            }
            break;
        } 
        case Json::objectValue: {
            if (val.empty())
            ; //   ofs << "{}";
            else {
             //   ofs << "{\n";
                int newIndent = indent + 4;
                vector<string> keys = val.getMemberNames();
                for (size_t i=0; i<keys.size(); i++) {
                    Indent(ofs, newIndent);
                    const string& key = keys[i];
		    string z = name+"."+key;
               //     ofs << '"' << key << '"' << " : ";
		    mmap[z]++;
                    MyPrint(ofs, val[key], newIndent, z);
                 //   ofs << (i + 1 == keys.size() ? "\n" : ",\n");
                }
                Indent(ofs, indent);
               // ofs << '}';
            }
            break;
        }
        default :
            cerr << "Wrong type!" << endl;
            exit(0);
    }
}

int main() {
    ifstream ifs("/home/fil/big.txt");
    std::string ss;
    long count = 0;
    while( std::getline(ifs, ss)) {
      if(ss.empty()) continue;
     // if(ss == "-------") continue;
  

    Json::Reader reader;
    Json::Value val;
    reader.parse(ss, val); // reader can also read strings
    
   // ifs >> val;
    MyPrint(cout, val,0,"");
    count++;
    }
    map <string,int>::iterator cur;
	cout << "count: " << count-1 << endl;

	double z =0.0;
	for (cur=mmap.begin();cur!=mmap.end();cur++)
	{
		z = (*cur).second*100.0/(count-1);
		char buff[100];
		sprintf(buff,"%2.3f",z);
		//cout << (*cur).first << endl;
		cout << format_string((*cur).first+" : ", 50) << buff << "%"<<endl;//count+=(*cur).second;
	}
}
